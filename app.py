from flask import Flask, render_template, request
from datetime import datetime
import threading
import time
import tools, msg_processing

app = Flask(__name__)

r2s_msg = {
    "loc": {
        "lat": None,
        "lng": None
    },
    "gate": None,
    "e-stop": False,
    "fod": [],
    "left": [],
    "right": [],
    "is_activated": False,
    "is_engaged": False
}

s2r_msg = {
    "gate": None,
    "activate": False,
    "engage": False
}

robot_readiness = {
    "status": None,
    "location": {
        "lat": None,
        "lng": None
    },
    "e_stop": False
}
gate_readiness = {
    "gate": None,
    "FOD": False,
    "FOD_location": []
}
wingwalking = {
    "is_activated": False,
    "is_engaged": False,
    "left": None,
    "left_location": [],
    "right": None,
    "right_location": []
}

counter = 0
def toggle_r2s():
    global r2s_msg
    global robot_readiness, gate_readiness, wingwalking
    global counter

    if counter == 0:
        counter = 1
    elif counter == 1:
        r2s_msg = tools.r2s_msg_1
        counter = 2
    elif counter == 2:
        r2s_msg = tools.r2s_msg_2
        counter = 3
    elif counter == 3:
        r2s_msg = tools.r2s_msg_3
        counter = 4
    elif counter == 4:
        r2s_msg = tools.r2s_msg_4
        counter = 5
    elif counter == 5:
        r2s_msg = tools.r2s_msg_5
        counter = 6
    elif counter == 6:
        r2s_msg = tools.r2s_msg_6
        counter = 7
    elif counter == 7:
        r2s_msg = tools.r2s_msg_7
        counter = 8
    elif counter == 8:
        r2s_msg = tools.r2s_msg_8
        counter = 9
    elif counter == 9:
        r2s_msg = tools.r2s_msg_9
        counter = 10
    elif counter == 10:
        r2s_msg = tools.r2s_msg_10
        counter = 11
    elif counter == 11:
        r2s_msg = tools.r2s_msg_11
        counter = 0

    print(f"[{counter}] / r2s_msg: {r2s_msg}")
    
    robot_readiness, gate_readiness, wingwalking = msg_processing.input_proc(r2s_msg)
    print(f"robot_readiness: {robot_readiness}")
    print(f"gate_readiness: {gate_readiness}")
    print(f"wingwalking: {wingwalking}")
    
    threading.Timer(5, toggle_r2s).start()
toggle_r2s()

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

# @app.route('/', methods=['POST'])
# def handle_message():
#     global robot_readiness
#     data = request.get_json()
#     # message = data['message']
#     if 'activate' in data:
#         print('Received activate message:', data['activate'])
#     elif 'engage' in data:
#         print('Received engage message:', data['engage'])
#     return 'Message received'

if __name__ == '__main__':
    app.run(port=5001)
    # app.run(host='0.0.0.0', port=5000)

