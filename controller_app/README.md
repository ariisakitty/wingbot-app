# wingbot-app

Requirements
1. ROS2 humble
2. Flask==2.3.2

Code structure
1. app: flask backend files, template html files, static images and css files
2. src: ROS2 custom msgs (LatLng.msg, Robot2Server.msg, Server2Robot.msg)

How to start
1. Go to @wingbot-app in a terminal
2. $colcon build --symlink-install
3. $source install/setup.bash
4. $python3 app/app.py
5. Open a browser and go to 127.0.0.1:5001 

ROS2 topics
1. /robot2server
2. /server2robot

Test scenarios - wingbot-app/test.txt