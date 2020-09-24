std_msgs/Header header

float64 kMinSteer=-0.3491 # -20 degree
float64 kMaxSteer=0.3491  #  20 degree

float64 kMinThrottle=-1.0
float64 kMaxThrottle=2.0

# in rad, < 0: turn left, > 0: turn right
float64 steer

# < 0: backward, > 0: forward
float64 throttle