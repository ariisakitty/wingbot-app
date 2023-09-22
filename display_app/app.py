from flask import Flask, render_template, jsonify, request
import threading
import rclpy
from rclpy.node import Node
from bridge_interface.msg import Robot2Server

app = Flask(__name__)
# app.config['SERVER_NAME'] = '127.0.0.1:5000'  # Set the SERVER_NAME configuration

# Initialize state
state = "default"
prev_state = "default"
gate = None
prev_gate = None

# ROS2 callback function for updating state
def r2s_callback(msg):
    global state
    global gate

    if msg.gate == "":
        gate = None
    else:
        gate = msg.gate

    if msg.estop == True:
        state = "estop"
    elif msg.is_engaged == True:
        state = "engage"
    elif msg.is_activated == True:
        state = "activate"
    else:
        state = "default"
    print(f"[display_app::r2s_callback] prev_state: {prev_state} / state: {state} / prev_gate: {prev_gate} / gate: {gate}")

def robot_listener():
    rclpy.init()
    node = rclpy.create_node('robot_listener')
    subscriber = node.create_subscription(Robot2Server, 'robot2server', r2s_callback, 10)
    rclpy.spin(node)

@app.route('/get_state')
def get_state():
    print(f"state: {state}, prev_state: {prev_state}, prev_gate: {prev_gate}, gate: {gate}")
    return jsonify({'state': state, 'prev_state': prev_state, 'prev_gate': prev_gate, 'gate': gate})

@app.route ('/update_state', methods=['POST'])
def update_state():
    global prev_state
    global prev_gate

    data = request.get_json()  # Import 'request' from Flask
    prev_state = data['state']  # Update the prev_state variable
    prev_gate = data['gate']
    return jsonify({'message': 'State updated successfully'})

# @app.route('/get_prev_state')
# def get_prev_state():
#     print(f"prev_state: {prev_state}")
#     return jsonify({'prev_state': prev_state})

@app.route('/')
def index():
    return render_template('default.html', gate=gate)

@app.route('/default')
def default():
    return render_template('default.html', gate=gate)

@app.route('/activate')
def activate():
    return render_template('activate.html', gate=gate)

@app.route('/engage')
def engage():
    return render_template('engage.html', gate=gate)

@app.route('/estop')
def estop():
    return render_template('estop.html', gate=gate)

if __name__ == '__main__':
    # Start the ROS2 listener in a separate thread
    ros2_thread = threading.Thread(target=robot_listener)
    ros2_thread.start()
    
    # Start the Flask app
    app.run(port=5001)