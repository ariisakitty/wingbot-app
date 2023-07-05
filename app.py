from flask import Flask, render_template, request
from datetime import datetime
import threading
import time

app = Flask(__name__)

robot_readiness = {
    "status": "Ready",
    "location": {
        "lat": 39.049363,
        "lng": -84.654340
    }
}
def toggle_robot_readiness():
    global robot_readiness 

    if robot_readiness["status"] == "Ready":
        robot_readiness["status"] = "Unavailable"
        robot_readiness["location"]["lat"] = 39.04960844154871
        robot_readiness["location"]["lng"] = -84.6545837816287        
    else:
        robot_readiness["status"] = "Ready"
        robot_readiness["location"]["lat"] = 39.049363
        robot_readiness["location"]["lng"] = -84.654340
    print(robot_readiness)
    threading.Timer(5, toggle_robot_readiness).start()
toggle_robot_readiness()

gate_readiness = {
    "gate": "A14",
    "FOD": False,
    "FOD_location": [{
        "lat": None,
        "lng": None
        # "lat": 39.049363, 
        # "lng": -84.654340 
    }]
}
def toggle_gate_readiness ():
    global gate_readiness
    if gate_readiness["gate"] == "A14":
        gate_readiness["gate"] = "A16"
    else:
        gate_readiness["gate"] = "A14"

    if gate_readiness["FOD"]:
        gate_readiness["FOD"] = False
        gate_readiness["FOD_location"][0]["lat"] = None
        gate_readiness["FOD_location"][0]["lng"] = None
    else:
        gate_readiness["FOD"] = True
        gate_readiness["FOD_location"][0]["lat"] = 39.04964018403017
        gate_readiness["FOD_location"][0]["lng"] = -84.65421236479904
    print(gate_readiness)
    threading.Timer(8, toggle_gate_readiness).start()
toggle_gate_readiness()

ww_left = {
    "object": False,
    "object_location": {
        "lat": None,
        "lng": None
    }
}
ww_right = {
    "object": False,
    "object_location": {
        "lat": None,
        "lng": None
    }
}

@app.route('/')
def index():
    return render_template('index.html', robot_readiness=robot_readiness, gate_readiness=gate_readiness, ww_left=ww_left, ww_right=ww_right)

@app.route('/get_robot_readiness')
def get_robot_readiness():
    return robot_readiness

@app.route('/get_gate_readiness')
def get_gate_readiness():
    return gate_readiness

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
