## 1. Install Arduino IDE

## 2. Install `rosserial`

```shell
$ sudo apt install ros-melodic-rosserial ros-melodic-rosserial-arduino
```

## 3. Install ros_lib into Arduino Environment

```shell
$ cd <sketchbook>/libraries
$ rm -rf ros_lib
$ rosrun rosserial_arduino make_libraries.py .
```

