FROM ubuntu:18.04

RUN apt update && apt -y install git curl wget cmake build-essential lsb-core && apt clean

WORKDIR /
RUN wget https://sourceforge.net/projects/boost/files/boost/1.62.0/boost_1_62_0.tar.gz && \
    tar -xzvf boost_1_62_0.tar.gz && cd boost_1_62_0 && mkdir build && \
    ./bootstrap.sh --with-libraries=all && ./b2 install -j$(nproc) && cd ../ && \
    rm -rf boost_1_62_0 && rm -rf boost_1_62_0.tar.gz