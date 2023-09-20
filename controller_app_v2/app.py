from flask import Flask, render_template, jsonify, request

app = Flask(__name__)
app.config['SERVER_NAME'] = '127.0.0.1:5000'  # Set the SERVER_NAME configuration

@app.route('/')
def index():
    return render_template('index.html')

if __name__ == '__main__':
    # Start the ROS2 listener in a separate thread
    # ros2_thread = threading.Thread(target=robot_listener)
    # ros2_thread.start()
    
    # Start the Flask app
    app.run(port=5000)