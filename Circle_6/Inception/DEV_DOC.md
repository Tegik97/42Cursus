# Developer Documentation

This guide describes how to configure and manage the development environment for the Inception project.

* **Environment Setup (Prerequisites)**:
  1. Ensure you are operating within a Debian/Ubuntu Virtual Machine.
  2. Modify the `/etc/hosts` file by adding the following line: `127.0.0.1 mchiaram.42.fr`.
  3. Create the `.env` file inside the `srcs/` directory using the provided `.env.example` template and fill in the required passwords.

* **Build and Run**:
  Use the `Makefile` located in the project's root directory. By running the `make` (or `make up`) command, the system will build the Docker images via `docker-compose` and start the containers in the background.

* **Commands to Manage Containers and Volumes**:
  * `docker ps`: Displays active containers and their current status.
  * `docker compose -f srcs/docker-compose.yml logs -f`: Monitors container logs in real time.
  * `make clean`: Stops the containers and performs a basic cleanup.
  * `make fclean`: Full system reset; stops containers and deletes all associated volumes and physical data.

* **Data Persistence**:
  Project data is physically stored on the host machine within the `/home/mchiaram/data/` directory. The database files are located in `.../data/mariadb`, while the website files are stored in `.../data/wordpress`. This configuration ensures that data persists even if the containers are destroyed or rebuilt.