up :
	docker-compose -f ./srcs/docker-compose.yml up -d

down : 
	docker-compose -f ./srcs/docker-compose.yml down

rm :
	docker ps -qa | xargs docker rm -f
rmi :
	docker images -q | xargs docker rmi -f

fclean : rm rmi
	docker volume ls -q | xargs docker volume rm

re : fclean up

.PHONY : up down rm rmi re fclean
