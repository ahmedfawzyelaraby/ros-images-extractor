FROM ubuntu:18.04

RUN apt update && apt -y install git curl wget cmake build-essential lsb-core unzip && apt clean

WORKDIR /
RUN wget https://sourceforge.net/projects/boost/files/boost/1.62.0/boost_1_62_0.tar.gz && \
    tar -xzvf boost_1_62_0.tar.gz && cd boost_1_62_0 && mkdir build && \
    ./bootstrap.sh --with-libraries=filesystem --with-libraries=program_options && \
    ./b2 install -j$(nproc) && cd ../ && \rm -rf boost_1_62_0 && rm -rf boost_1_62_0.tar.gz

WORKDIR /
RUN wget https://github.com/opencv/opencv/archive/3.4.8.zip && unzip 3.4.8.zip && \
    cd opencv-3.4.8 && mkdir build && cd build && cmake .. && make -j2 && make install && \
    cd ../../ && rm -rf opencv-3.4.8 && rm -rf 3.4.8.zip

WORKDIR /
RUN sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list' && \
    apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654 && \
    apt update && apt -y install ros-melodic-desktop-full && rosdep init && rosdep update && apt -y install python-rosinstall \
    python-rosinstall-generator python-wstool build-essential && apt clean