FROM debian:11

RUN apt update; \
    apt install -y php-mysql php-mbstring  php-mysql curl systemd mariadb-server

RUN sed -i 's/127.0.0.1/0.0.0.0\nsocket = \/run\/mysqld\/mysqld.sock\nport = 3306/g' /etc/mysql/mariadb.conf.d/50-server.cnf

EXPOSE 3306

COPY ./tools/setting.sh /setting.sh

RUN chmod 777 setting.sh

ENTRYPOINT ["sh", "/setting.sh"]
