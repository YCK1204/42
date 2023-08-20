FROM debian:11

RUN mkdir -p /copy

COPY ./conf/default.conf /copy/default

RUN apt update; \
    apt install -y openssl nginx 

COPY ./tools/setting.sh /setting.sh

RUN chmod 777 /setting.sh

ENTRYPOINT ["sh", "/setting.sh"]
