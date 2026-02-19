*This project has been created as part of the 42 curriculum by mchiaram.*

## Description
This project aims to broaden knowledge of system administration using Docker Compose. The objective is to configure a small infrastructure running NGINX, WordPress and MariaDB under specific rules.
Each service must run inside its own dedicated container, communicating with one another via a dedicated network.
The only service accessible to the user is NGINX, which acts as entrypoint and routes requests to the other two services if needed

## Instructions
To build and execute the project run the `make` command from the repository root. The infrastructure will be built using `docker compose`. Ensure that the `/etc/hosts` and `.env` files are properly configured before execution.

## Resources
* [Official Docker Compose documentation](https://docs.docker.com/compose/intro/compose-application-model/)
* [nginx configuration tutorial](https://nginx.org/en/docs/beginners_guide.html)
* [Inception guide from Forstman1 github](https://github.com/Forstman1/inception-42)
* **AI USAGE**: I used AI to better understand the syntax of the NGINX configuration file and how to properly handle PID 1 inside Bash scripts. Overall, AI helped accelerate and deepen my study of the project by answering specific questions that would have otherwise taken significantly more time to research online.

### Virtual Machines vs Docker
Virtual Machines emulate the entire hardware and guest OS resulting in a heavier workload for the host machine. Docker, on the other hand, shares the host's kernel and virtualizes at the OS level, providing a lighter and faster solution.

### Secrets vs Environment Variables
Environment variables can be easily read by anyone inspecting the container (docker inspect). Docker Secrets, instead, are a more secure mechanism for handling highly sensitive data. They are not stored in the container's configuration but are mounted directly into the container's in-memory filesystem.

### Docker Network vs Host Network
Using a Docker bridge network isolates the containers from the host, creating a private network. Within this network, containers communicate securely using hostnames without exposing unnecessary ports to the outside world.

### Docker Volumes vs Bind Mounts
Bind Mounts link a specific directory on the host machine to the container. They rely on the host's filesystem structure and OS, making them less portable. Docker Volumes, on the other hand, are entirely managed by Docker and stored in a dedicated, isolated area of the host filesystem. Volumes are the recommended approach because they offer better performance, are easier to back up or migrate, and provide greater security since non-Docker processes cannot easily interfere with the data.