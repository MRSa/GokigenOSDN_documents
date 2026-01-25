FROM jenkins/ssh-agent

ENV PREREQUISITES "bash curl git"

RUN apt-get update && \
    apt-get install -y $PREREQUISITES && \
    apt-get install -y python3 python3-pip python3-venv

RUN mkdir -p /home/venv && \
    mkdir -p /work && \
    python3 -m venv /home/venv

RUN /home/venv/bin/pip install pyserial

WORKDIR /work

