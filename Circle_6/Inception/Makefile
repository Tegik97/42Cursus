NAME = inception
COMPOSE = ./srcs/docker-compose.yml

all: up

up:
	@echo "Starting up Inception..."
	@mkdir -p /home/mchiaram/data/mariadb
	@mkdir -p /home/mchiaram/data/wordpress
	@docker compose -f $(COMPOSE) up -d --build

down:
	@echo "Shutting down Inception..."
	@docker compose -f $(COMPOSE) down

stop:
	@echo "Pausing Inception..."
	@docker compose -f $(COMPOSE) stop

start:
	@echo "Resuming Inception..."
	@docker compose -f $(COMPOSE) start

clean: down
	@echo "Container and network clean up..."
	@docker system prune -a --force

fclean: clean
	@echo "Data and volumes TOTAL DESTRUCTION..."
	@sudo rm -rf /home/mchiaram/data/mariadb/*
	@sudo rm -rf /home/mchiaram/data/wordpress/*
	@docker volume rm $$(docker volume ls -q) 2>/dev/null || true

re: fclean all

.PHONY: all up down stop start clean fclean re