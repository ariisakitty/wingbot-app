from flask import Flask, render_template, jsonify, request
import threading
from msg import s2r, robot_readiness, gate_readiness, wingwalking
from msg import r2s_app_callback
from bridge_node import run_bridge_node
import rclpy

app = Flask(__name__)
# app.config['SERVER_NAME'] = '0.0.0.0:5000'  # Set the SERVER_NAME configuration

bridge_node = None

@app.route('/')
def index():
    return render_template('index.html', robot_readiness=robot_readiness, gate_readiness=gate_readiness, wingwalking=wingwalking)

@app.route('/get_robot_readiness')
def get_robot_readiness():
    return robot_readiness

@app.route('/get_gate_readiness')
def get_gate_readiness():
    return gate_readiness

@app.route('/get_wingwalking_status')
def get_wingwalking_readiness():
    return wingwalking

# Route to handle the "activate" message
@app.route('/activate', methods=['POST'])
def handle_activate_message():
    global s2r, bridge_node
    data = request.get_json()
    s2r['activate'] = data['activate']
    bridge_node.set_s2r(s2r)
        
    return 'Activate message received'

# Route to handle the "engage" message
@app.route('/engage', methods=['POST'])
def handle_engage_message():
    global s2r, bridge_node
    data = request.get_json()
    s2r['engage'] = data['engage']
    bridge_node.set_s2r(s2r)

    return 'Engage message received'

# Route to handle the "gate" message
@app.route('/gate', methods=['POST'])
def handle_gate_message():
    global s2r, bridge_node
    data = request.get_json()
    s2r['gate'] = data['gate']
    bridge_node.set_s2r(s2r)
        
    return 'Gate message received'

# Route to handle the "engage" message
@app.route('/estop', methods=['POST'])
def handle_estop_message():
    global s2r, bridge_node
    data = request.get_json()
    s2r['estop'] = data['estop']
    bridge_node.set_s2r(s2r)

    return 'Estop message received'

if __name__ == '__main__':
    bridge_node = run_bridge_node(r2s_app_callback)
    bridge_thread = threading.Thread(target=rclpy.spin, args=(bridge_node,))
    bridge_thread.start()
    app.run(host='0.0.0.0', port=5000)
