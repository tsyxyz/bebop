std_msgs/Header header

float64 MIN_STEER=-0.3491 # -20 degree
float64 MAX_STEER=0.3491  #  20 degree

float64 MIN_VELOCITY=-1.0
float64 MAX_VELOCITY=2.0

# in rad, < 0: turn left, > 0: turn right
float64 steer

# in m/s, < 0: backward, > 0: forward
float64 velocity