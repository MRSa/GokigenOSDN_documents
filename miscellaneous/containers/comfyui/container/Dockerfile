#FROM python:3.13-slim-trixie
FROM nvcr.io/nvidia/pytorch:26.07-py3

RUN  mkdir -p WORK
COPY ./entrypoint.sh /work/entrypoint.sh
RUN chmod a+x /work/entrypoint.sh
WORKDIR /work

## DEBUG ENTRY POINT
#ENTRYPOINT ["tail", "-f", "/dev/null"]
#ENTRYPOINT ["sleep", "infinity"]

## COMFYUI ENTRY POINT
ENTRYPOINT ["/work/entrypoint.sh"]
