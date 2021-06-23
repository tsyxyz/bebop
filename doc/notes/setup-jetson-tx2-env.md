## 1. Install ZSH

```shell
$ sudo apt update
$ sudo apt install zsh curl git
# configure oh-my-zsh
$ sh -c "$(curl -fsSL https://raw.github.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"
```

When all is done, log out and log in again to make zsh as the default shell.

## 2. Install Arduino IDE

1. Download Arduino IDE for Linux AArch64, extract it and run `./install.sh`.

2. Create soft links to arduino tools:

```shell
$ sudo ln -s /home/tao/arduino-1.8.9/arduino /usr/local/bin/arduino
$ sudo ln -s /home/tao/arduino-1.8.9/arduino-builder /usr/local/bin/arduino-builder
```

## 3. Install ROS

```shell
$ sudo sh -c '. /etc/lsb-release && echo "deb http://mirrors.tuna.tsinghua.edu.cn/ros/ubuntu/ $DISTRIB_CODENAME main" > /etc/apt/sources.list.d/ros-latest.list'
$ sudo apt update
$ sudo apt-key adv --keyserver hkp://ha.pool.sks-keyservers.net:80 --recv-key 421C365BD9FF1F717815A3895523BAEEB01FA116
$ sudo apt update
$ sudo apt install ros-melodic-desktop
$ sudo rosdep init
$ rosdep update
$ echo "source /opt/ros/melodic/setup.zsh" >> ~/.zshrc
$ sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential
```

## 4. Add SSH pub key to github and configure git

```shell
$ ssh-keygen -t rsa -b 4096 -C "tsyxyz@hotmail.com"
$ eval "$(ssh-agent -s)"
$ ssh-add ~/.ssh/id_rsa
$ cat .ssh/id_rsa.pub
```

Copy the content of `~/.ssh/id_rsa.pub` and paste to github ssh key settings.

```shell
$ git config --global user.email "tsyxyz@hotmail.com"
$ git config --global user.name "tsyxyz"
```

## 5. Install QtCreator

```shell
$ sudo apt install qt5-default qtcreator
```

## 6. Configure QtCreator for ROS

1. Launch QtCreator.
2. Open `Projects`->`Build Settings`->`CMake`.
3. Add key `CMAKE_PREFIX_PATH`, value `/opt/ros/melodic`.
4. Click `Apply Configuration Changes`.
