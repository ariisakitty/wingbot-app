def input_proc(input):
    # input is a object (r2s_msg)
    # output is a object (r2s_msg_processed)

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

    robot_readiness["e_stop"] = input["e-stop"]
    if(robot_readiness["e_stop"]):
        robot_readiness["status"] = "Stopped"
        robot_readiness["location"] = input["loc"] if input["loc"]["lat"] is not None else {"lat": None, "lng": None}

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
        robot_readiness["status"] = "Ready" if input["loc"]["lat"] is not None else "Unavailable"
        robot_readiness["location"] = input["loc"] if robot_readiness["status"] == "Ready" else {"lat": None, "lng": None}

        gate_readiness["gate"] = input["gate"] if input["gate"] is not None else None
        gate_readiness["FOD"] = False if input["fod"] == [] else True
        gate_readiness["FOD_location"] = input["fod"] if gate_readiness["FOD"] else []

        wingwalking["is_activated"] = input["is_activated"]
        wingwalking["is_engaged"] = input["is_engaged"]
        wingwalking["left"] = False if input["left"] == [] else True
        wingwalking["left_location"] = input["left"] if wingwalking["left"] else []
        wingwalking["right"] = False if input["right"] == [] else True
        wingwalking["right_location"] = input["right"] if wingwalking["right"] else []

    return robot_readiness, gate_readiness, wingwalking