s2r = {
    "gate": None,
    "activate": False,
    "engage": False,
    "estop": False
}

robot_readiness = {
    "status": None,
    "location": {
        "lat": None,
        "lng": None
    },
    "estop": False
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

def r2s_app_callback(value):
    global robot_readiness, gate_readiness, wingwalking

    robot_readiness["estop"] = value.estop
    if (robot_readiness["estop"]):
        robot_readiness["status"] = "Stopped"
        robot_readiness["location"]["lat"] = value.loc.lat if value.is_on else None
        robot_readiness["location"]["lng"] = value.loc.lng if value.is_on else None

        gate_readiness["gate"] = None
        gate_readiness["FOD"] = False
        gate_readiness["FOD_location"] = []

        wingwalking["is_activated"] = False
        wingwalking["is_engaged"] = False
        wingwalking["left"] = None
        wingwalking["left_location"] = []
        wingwalking["right"] = None
        wingwalking["right_location"] = []

    else:
        robot_readiness["status"] = "Ready" if value.is_on else "Unavailable"
        robot_readiness["location"]["lat"] = value.loc.lat if value.is_on else None
        robot_readiness["location"]["lng"] = value.loc.lng if value.is_on else None

        gate_readiness["gate"] = None if value.gate == "" else value.gate
        gate_readiness["FOD"] = False if len(value.fod) == 0 else True
        if gate_readiness["FOD"]:
            gate_readiness["FOD_location"] = []
            for i in range(len(value.fod)):
                gate_readiness["FOD_location"].append({"lat": value.fod[i].lat, "lng": value.fod[i].lng})
        else:
            gate_readiness["FOD_location"] = []

        wingwalking["is_activated"] = value.is_activated
        wingwalking["is_engaged"] = value.is_engaged
        wingwalking["left"] = False if len(value.left) == 0 else True
        if wingwalking["left"]:
            wingwalking["left_location"] = []
            for i in range(len(value.left)):
                wingwalking["left_location"].append({"lat": value.left[i].lat, "lng": value.left[i].lng})
        else:
            wingwalking["left_location"] = []
        wingwalking["right"] = False if len(value.right) == 0 else True
        if wingwalking["right"]:
            wingwalking["right_location"] = []
            for i in range(len(value.right)):
                wingwalking["right_location"].append({"lat": value.right[i].lat, "lng": value.right[i].lng}) 
        else:
            wingwalking["right_location"] = []


    # Handle the updated r2s_value as needed
    print(f"robot_readiness: {robot_readiness} / gate_readiness: {gate_readiness} / wingwalking: {wingwalking}")




