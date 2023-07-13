from flask import Flask, render_template, request
import threading
import msg
from msg import r2s_msg, s2r_msg, robot_readiness, gate_readiness, wingwalking

from bridge_interface.msg import Server2Robot, Robot2Server
from bridge_node import run_bridge_node

app = Flask(__name__)

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
    global s2r
    data = request.get_json()
    s2r['activate'] = data['activate']
    
    print(f"s2r: {s2r}")
    

    return 'Activate message received'

# Route to handle the "engage" message
@app.route('/engage', methods=['POST'])
def handle_engage_message():
    global s2r
    data = request.get_json()
    s2r['engage'] = data['engage']

    print(f"s2r: {s2r}")

    return 'Engage message received'

# Route to handle the "gate" message
@app.route('/gate', methods=['POST'])
def handle_gate_message():
    global s2r
    data = request.get_json()
    s2r['gate'] = data['gate']
    
    print(f"s2r: {s2r}")
    
    return 'Gate message received'

# Route to handle the "engage" message
@app.route('/estop', methods=['POST'])
def handle_estop_message():
    global s2r
    data = request.get_json()
    s2r['estop'] = data['estop']

    print(f"s2r: {s2r}")

    return 'Estop message received'

if __name__ == '__main__':
    bridge_thread = threading.Thread(target=run_bridge_node)
    bridge_thread.start()
    app.run(port=5001)
    # app.run(host='0.0.0.0', port=5000)

