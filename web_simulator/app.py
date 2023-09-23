from flask import Flask, render_template, jsonify, request

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/activate', methods=['POST'])
def handle_activate_message():
    global s2r, bridge_node
    data = request.get_json()
    s2r['activate'] = data['activate']
    bridge_node.set_s2r(s2r)
        
    return 'Activate message received'

if __name__ == '__main__':
    app.run(host='127.0.0.1', port=5002)
