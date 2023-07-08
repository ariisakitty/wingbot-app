# import time

# # counter = 0
# # init_time = datetime.now()
# # def toggle_r2s():
# #     global r2s_msg
# #     global robot_readiness, gate_readiness, wingwalking
# #     global counter

# #     if counter == 0:
# #         counter = 1
# #     elif counter == 1:
# #         r2s_msg = test_script.r2s_msg_1
# #         counter = 2
# #     elif counter == 2:
# #         r2s_msg = test_script.r2s_msg_2
# #         counter = 3
# #     elif counter == 3:
# #         r2s_msg = test_script.r2s_msg_3
# #         counter = 4
# #     elif counter == 4:
# #         r2s_msg = test_script.r2s_msg_4
# #         counter = 5
# #     elif counter == 5:
# #         r2s_msg = test_script.r2s_msg_5
# #         counter = 6
# #     elif counter == 6:
# #         r2s_msg = test_script.r2s_msg_6
# #         counter = 7
# #     elif counter == 7:
# #         r2s_msg = test_script.r2s_msg_7
# #         counter = 8
# #     elif counter == 8:
# #         r2s_msg = test_script.r2s_msg_8
# #         counter = 9
# #     elif counter == 9:
# #         r2s_msg = test_script.r2s_msg_9
# #         counter = 10
# #     elif counter == 10:
# #         r2s_msg = test_script.r2s_msg_10
# #         counter = 11
# #     elif counter == 11:
# #         r2s_msg = test_script.r2s_msg_11
# #         counter = 0

# #     # print(f"[{counter}] / r2s_msg: {r2s_msg}")
    
# #     robot_readiness, gate_readiness, wingwalking = msg_processing.input_proc(r2s_msg)
# #     # print(f"robot_readiness: {robot_readiness}")
# #     # print(f"gate_readiness: {gate_readiness}")
# #     # print(f"wingwalking: {wingwalking}")
    
# #     threading.Timer(5, toggle_r2s).start()
# # toggle_r2s()

# def s2r_receiver(input): 
#     print(f"s2r_msg: {input}")

# r2s_msg_1 = {
#     "loc": {
#         "lat": 39.049363,
#         "lng": -84.654340
#     },
#     "gate": None,
#     "e-stop": False,
#     "fod": [],
#     "left": [],
#     "right": [],
#     "is_activated": False,
#     "is_engaged": False
# }
# r2s_msg_2 = {
#     "loc": {
#         "lat": 39.04960844154871,
#         "lng": -84.6545837816287
#     },
#     "gate": "A14",
#     "e-stop": False,
#     "fod": [],
#     "left": [],
#     "right": [],
#     "is_activated": False,
#     "is_engaged": False
# }
# r2s_msg_3 = {
#     "loc": {
#         "lat": 39.049363,
#         "lng": -84.654340
#     },
#     "gate": "A14",
#     "e-stop": False,
#     "fod": [
#         {
#             "lat": 39.04964018403017,
#             "lng": -84.65421236479904
#         },
#         {
#             "lat": 39.04950317919271,
#             "lng": -84.65405445409232
#         }],
#     "left": [],
#     "right": [],
#     "is_activated": False,
#     "is_engaged": False
# }
# r2s_msg_4 = {
#     "loc": {
#         "lat": 39.04960844154871,
#         "lng": -84.6545837816287
#     },
#     "gate": "A14",
#     "e-stop": False,
#     "fod": [],
#     "left": [],
#     "right": [],
#     "is_activated": False,
#     "is_engaged": False
# }
# r2s_msg_5 = {
#     "loc": {
#         "lat": 39.049363,
#         "lng": -84.654340
#     },
#     "gate": "A14",
#     "e-stop": False,
#     "fod": [],
#     "left": [],
#     "right": [],
#     "is_activated": True,
#     "is_engaged": False
# }
# r2s_msg_6 = {
#     "loc": {
#         "lat": 39.04960844154871,
#         "lng": -84.6545837816287
#     },
#     "gate": "A14",
#     "e-stop": False,
#     "fod": [],
#     "left": [
#         {
#             "lat": 39.04921202412433,
#             "lng": -84.65387185629405
#         },
#         {
#             "lat": 39.04921805843844,
#             "lng": -84.6535513388822
#         }
#     ],
#     "right": [
#         {
#             "lat": 39.04921504128145,
#             "lng": -84.6546993739756
#         }
#     ],
#     "is_activated": True,
#     "is_engaged": False
# }
# r2s_msg_7 = {
#     "loc": {
#         "lat": 39.049363,
#         "lng": -84.654340
#     },
#     "gate": "A14",
#     "e-stop": False,
#     "fod": [],
#     "left": [],
#     "right": [
#         {
#             "lat": 39.04921504128145,
#             "lng": -84.6546993739756
#         }
#     ],
#     "is_activated": True,
#     "is_engaged": False
# }
# r2s_msg_8 = {
#     "loc": {
#         "lat": 39.04960844154871,
#         "lng": -84.6545837816287
#     },
#     "gate": "A14",
#     "e-stop": False,
#     "fod": [],
#     "left": [],
#     "right": [],
#     "is_activated": False,
#     "is_engaged": False
# }
# r2s_msg_9 = {
#     "loc": {
#         "lat": 39.049363,
#         "lng": -84.654340
#     },
#     "gate": "A14",
#     "e-stop": True,
#     "fod": [],
#     "left": [],
#     "right": [],
#     "is_activated": False,
#     "is_engaged": False
# }
# r2s_msg_10 = {
#     "loc": {
#         "lat": 39.049363,
#         "lng": -84.654340
#     },
#     "gate": "A14",
#     "e-stop": False,
#     "fod": [],
#     "left": [],
#     "right": [],
#     "is_activated": False,
#     "is_engaged": False
# }
# r2s_msg_11 = {
#     "loc": {
#         "lat": None,
#         "lng": None
#     },
#     "gate": None,
#     "e-stop": False,
#     "fod": [],
#     "left": [],
#     "right": [],
#     "is_activated": False,
#     "is_engaged": False
# }