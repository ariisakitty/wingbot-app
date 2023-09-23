from flask import Flask, render_template, jsonify, request
from ros2_handler import ros2_publisher

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/feed', methods=['POST'])
def feed_endpoint():
    ros2_publisher.publish_messages()
    return 'Published robot location topics'

@app.route('/spawn', methods=['POST'])
def spawn_vehicles_endpoint():
    ros2_publisher.spawn_vehicle_on_vsr()
    return 'Spawned vehicles on VSR'

@app.route('/remove', methods=['POST'])
def remove_vehicles_endpoint():
    ros2_publisher.remove_vehicle_on_vsr()
    return 'Removed vehicles on VSR'

if __name__ == '__main__':
    app.run(host='127.0.0.1', port=5002)


# map center point (B8): 39.050953175675694, -84.65801653406541
# left: (39.050841067691984, -84.65810003637769), (39.050925698245166, -84.65811843519225), (39.05100483321613, -84.65814674106082), (39.051127931883634, -84.65819061515711), (39.05118728295021, -84.65825713394823)
# right: (39.05093009463476, -84.65797690584944), (39.05103121152008, -84.65786085178831), (39.051091661762825, -84.65781839298546), (39.051152111953805, -84.65779716358402), (39.05118178748317, -84.65777168830232)
# left ww obj: (39.051210363907074, -84.65846659737564)