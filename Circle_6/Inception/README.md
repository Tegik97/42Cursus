# Inception - 42 Project

*This project has been created as part of the 42 curriculum by mchiaram.*

## Project Overview
This project aims to broaden knowledge of system administration using Docker. The objective is to build a small, secure infrastructure running NGINX, WordPress, and MariaDB under strict constraints.

Each service runs in a dedicated container, isolated within a private network. NGINX acts as the sole entry point, routing HTTPS requests to other services while ensuring all communications are encrypted via TLSv1.2 or TLSv1.3.

## Instructions
1. **Prerequisites**: Ensure you are on a Debian/Ubuntu VM.
2. **Setup**: 
   - Add `127.0.0.1 mchiaram.42.fr` to your `/etc/hosts`.
   - Create a `.env` file in `srcs/` with your credentials.
3. **Run**: Execute `make` from the root directory to build and start the infrastructure.

## Design Choices & Comparisons
In accordance with the project requirements (Chapter VI), here is an analysis of the technologies used:

### Virtual Machines vs Docker
Virtual Machines (VMs) emulate entire hardware sets and guest operating systems, resulting in high resource overhead. **Docker**, on the other hand, virtualizes at the OS level, sharing the host's kernel. This makes Docker containers significantly lighter, faster to start, and more portable for microservices architectures.

### Docker Secrets vs Environment Variables
While Environment Variables are practical, they can be exposed via `docker inspect`. In this project, we use them for basic configuration, but for a production-grade environment, **Docker Secrets** would be the preferred choice as they are encrypted at rest and mounted into the container's in-memory filesystem, never touching the disk.

### Docker Network vs Host Network
We use a **Docker Bridge Network** to isolate containers from the host. This provides an internal DNS (allowing containers to communicate via service names like `mariadb`) and ensures that only necessary ports (like 443 via NGINX) are exposed to the outside world, minimizing the attack surface.

### Docker Volumes vs Bind Mounts
In this project, we utilize **Named Volumes with bind-mount configurations**. While standard Docker Volumes are entirely managed by Docker in a hidden area of the host filesystem, we specifically configure them to point to `/home/mchiaram/data/` as required by the subject. 

This approach combines the portability of Named Volumes (referenced by name in the services) with the explicit data persistence of Bind Mounts, ensuring that our WordPress and MariaDB data are easily accessible and persistent on the host machine even if the containers or Docker networks are removed.

## Resources & AI Usage
* [Official Docker Documentation](https://docs.docker.com/)
* [NGINX TLS Configuration Guide](https://nginx.org/en/docs/http/configuring_https_it.html)

**AI Disclosure**: I used AI (Gemini) to clarify complex NGINX syntax and to optimize the signal handling (PID 1) in my entrypoint scripts. This helped accelerate the learning process regarding container lifecycle management and secure protocol implementation.