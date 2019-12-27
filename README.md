# ROSBag Images Extractor
This repository contains C++ based ROS code implementation that is able to extract images from a ROSBag file and save them as png images to the disk.
## Getting Started
You can use the code in two different ways, either natively on your machine or inside a docker image. These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. **Please be noted that this code is tested on Ubuntu OS only**.
### Prerequisites
#### Native
- Aptitude Dependencies
```bash
$ sudo apt update
$ sudo apt -y install git curl wget cmake build-essential lsb-core unzip
```
- Boost
```bash
$ wget https://sourceforge.net/projects/boost/files/boost/1.62.0/boost_1_62_0.tar.gz
$ tar -xzvf boost_1_62_0.tar.gz
$ cd boost_1_62_0
$ mkdir build
$ ./bootstrap.sh --with-libraries=filesystem --with-libraries=program_options
$ sudo ./b2 install -j$(nproc)
```
- OpenCV
```bash
$ wget https://github.com/opencv/opencv/archive/3.4.8.zip
$ unzip 3.4.8.zip
$ cd opencv-3.4.8
$ mkdir build
$ cd build
$ cmake ..
$ make -j
$ sudo make install
```
#### Inside Docker
```bash
$ sudo apt update
$ sudo apt -y install apt-transport-https ca-certificates curl software-properties-common
$ curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
$ sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu bionic stable"
$ sudo apt update
$ apt-cache policy docker-ce
$ sudo apt install docker-ce
$ sudo usermod -aG docker ${USER}
$ su - ${USER}
```
### Installation
#### Native
You can skip this step and use the already built executable in github actions.
```bash
$ git clone https://github.com/ahmedfawzyelaraby/ros-images-extractor.git
$ cd ros-images-extractor
$ mkdir build
$ cd build
$ cmake ..
$ make -j
```
#### Inside Docker
```bash
$ git clone https://github.com/ahmedfawzyelaraby/ros-images-extractor.git
$ cd ros-images-extractor
$ docker build . --file Dockerfile --tag rosbag-image-extractor-build
```
### Usage
#### Native
```bash
$ ./ros-bag-image-extractor -h # this command will get you the instructions you need to run the code.
```
#### Inside Docker
```bash
$ docker run -it rosbag-image-extractor-build bash
$ cd ./build
$ ./ros-bag-image-extractor -h # this command will get you the instructions you need to run the code.
```
