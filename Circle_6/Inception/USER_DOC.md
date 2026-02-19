# User Documentation

This guide provides simple instructions on how to use and interact with the infrastructure.

* **Services Provided**: The infrastructure hosts a fully functional and secure WordPress website. It is served via NGINX using HTTPS (TLSv1.2/1.3), supported by a persistent and isolated MariaDB database.

* **Starting and Stopping the Project**:
  * **To Start**: Run the `make` command in the root directory.
  * **To Stop**: Run `make stop` (to pause services) or `make down` (to shut down the infrastructure).

* **Accessing the Website and Admin Panel**:
  * **Website**: [https://mchiaram.42.fr]
  * **Administration Panel**: [https://mchiaram.42.fr/wp-admin]

* **Credential Management**: WordPress credentials are configured during the initial setup via environment variables. For security reasons, these are not stored in the public repository.

* **Status Check**: You can verify that the system is operational by visiting the website URL. If the services are running correctly, the browser will display a secure connection icon (the padlock) and the WordPress homepage.