#!/bin/bash

service mariadb start

sleep 3

echo "CREATE DATABASE IF NOT EXISTS inception;
      CREATE USER IF NOT EXISTS 'yeckim_db'@'%' IDENTIFIED BY 'test1234!';
	  GRANT ALL PRIVILEGES ON *.* TO 'yeckim_db'@'%';
	  FLUSH PRIVILEGES;" | mysql -u root

mysqladmin shutdown


mysqld

