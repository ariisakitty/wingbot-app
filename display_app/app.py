from flask import Flask, render_template, jsonify
import threading
import rclpy

app = Flask(__name__)

state = "activated"

@app.route('/')
def index():
    return render_template('index.html', state=state)

@app.route('/get_content/<state>')
def get_content(state):
    if state == 'default':
        return render_template('default.html')
    elif state == 'activated':
        return render_template('activate.html') # Renders activate.html template
    else:
        return jsonify(message='State not recognized')


if __name__ == '__main__':
    app.run(port=5001)