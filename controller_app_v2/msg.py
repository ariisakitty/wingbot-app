s2r = {
    "gate": None,
    "activate": False,
    "engage": False,
    "estop": False
}

robot_readiness = {
    "robot_left": {
        "status": None,
        "location": {
            "lat": None,
            "lng": None
        },
        "estop": False
    },
    "robot_right": {
        "status": None,
        "location": {
            "lat": None,
            "lng": None
        },
        "estop": False
    }
}
gate_readiness = {
    "gate": None,
    "FOD": False,
    "FOD_location": []
}
wingwalking = {
    "is_at_ww_pos": False,
    "is_activated": False,
    "is_engaged": False,
    "left": None,
    "left_location": [],
    "right": None,
    "right_location": []
}

def r2s_app_callback(robot_left, robot_right):
    global robot_readiness, gate_readiness, wingwalking

    ## Need to separate robot_left and robot_right (9/23/23)   
    robot_readiness["robot_left"]["estop"] = robot_left.estop
    robot_readiness["robot_right"]["estop"] = robot_right.estop

    if (robot_readiness["robot_left"]["estop"]):
        robot_readiness["robot_left"]["status"] = "Stopped"
        robot_readiness["robot_left"]["location"]["lat"] = robot_left.loc.lat if robot_left.is_on else None
        robot_readiness["robot_left"]["location"]["lng"] = robot_left.loc.lng if robot_left.is_on else None

        robot_readiness["robot_right"]["status"] = "Stopped"
        robot_readiness["robot_right"]["location"]["lat"] = robot_right.loc.lat if robot_right.is_on else None
        robot_readiness["robot_right"]["location"]["lng"] = robot_right.loc.lng if robot_right.is_on else None

        gate_readiness["gate"] = None
        gate_readiness["FOD"] = False
        gate_readiness["FOD_location"] = []

        wingwalking["is_at_ww_pos"] = False
        wingwalking["is_activated"] = False
        wingwalking["is_engaged"] = False
        wingwalking["left"] = None
        wingwalking["left_location"] = []
        wingwalking["right"] = None
        wingwalking["right_location"] = []

    else:
        robot_readiness["robot_left"]["status"] = "Ready" if robot_left.is_on else "Unavailable"
        robot_readiness["robot_left"]["location"]["lat"] = robot_left.loc.lat if robot_left.is_on else None
        robot_readiness["robot_left"]["location"]["lng"] = robot_left.loc.lng if robot_left.is_on else None

        robot_readiness["robot_right"]["status"] = "Ready" if robot_right.is_on else "Unavailable"
        robot_readiness["robot_right"]["location"]["lat"] = robot_right.loc.lat if robot_right.is_on else None
        robot_readiness["robot_right"]["location"]["lng"] = robot_right.loc.lng if robot_right.is_on else None

        gate_readiness["gate"] = None if robot_left.gate == "" else robot_left.gate
        gate_readiness["FOD"] = False if len(robot_left.fod) == 0 else True
        if gate_readiness["FOD"]:
            gate_readiness["FOD_location"] = []
            for i in range(len(robot_left.fod)):
                gate_readiness["FOD_location"].append({"lat": robot_left.fod[i].lat, "lng": robot_left.fod[i].lng})
        else:
            gate_readiness["FOD_location"] = []

        wingwalking["is_at_ww_pos"] = robot_left.is_at_ww_pos
        wingwalking["is_activated"] = robot_left.is_activated
        wingwalking["is_engaged"] = robot_left.is_engaged
        wingwalking["left"] = False if len(robot_left.ww_obj) == 0 else True
        if wingwalking["left"]:
            wingwalking["left_location"] = []
            for i in range(len(robot_left.ww_obj)):
                wingwalking["left_location"].append({"lat": robot_left.ww_obj[i].lat, "lng": robot_left.ww_obj[i].lng})
        else:
            wingwalking["left_location"] = []
        wingwalking["right"] = False if len(robot_right.ww_obj) == 0 else True
        if wingwalking["right"]:
            wingwalking["right_location"] = []
            for i in range(len(robot_right.ww_obj)):
                wingwalking["right_location"].append({"lat": robot_right.ww_obj[i].lat, "lng": robot_right.ww_obj[i].lng}) 
        else:
            wingwalking["right_location"] = []


    # Handle the updated r2s_value as needed
    print(f"robot_readiness: {robot_readiness} / gate_readiness: {gate_readiness} / wingwalking: {wingwalking}")




