FROM docker.io/gcc:15.2.0

VOLUME /workspace
WORKDIR /build

RUN apt-get update && apt-get install -y cmake ninja-build openssh-server