FROM ubuntu:18.04

RUN apt update && apt -y install git cmake build-essential lsb-core