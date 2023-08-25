# Simple Web Stack

## Requirements:

* A LAMP Stack -> Linux Apache MySQL Python
* 1 Server (Linux OS)
* 1 Application Server (Python)
* 1 CodeBase
* 1 Web Server (Apache)
* 1 Database Server (MySQL)
* A domain name (www.foobar.com)

## General

* What is a Server?
  * It is a hardware interface that provides **SERVICE** to a client, in this context our server is powered by Linux
* What is the role of a domain name?
  * To make it easier for accessibility purposes: remembering the website name
  * Translates web addresses to it's exact IP address
* What type of DNS record www is in www.foobar.com
  * CNAME record -> for aliases
* What is the role of the web server?
  * Hosts a website
  * Provides static content (HTML CSS MP4 MP3...) to the client
* What is the role of the application server?
  * Provides Dynamic content, handles requests that require logical processing, authentication, interaction with external API's and database management systems
* What is the role of the database?
  * Stores and Organizes data
* What is the server using to communicate with the computer of the user requesting the website?
  * HTTP (HyperText Transfer Protocol) | Port 80

## ISSUES WITH THIS INFRASTRUCTURE

* SPOF -> Single Point Of Failure
  * When updating a codebase, because they all share the same resources on a single server, there is going to be downtime during the process.
  * Incoming traffic can be too much for a single server to handle with limited ports, and limited cpu/gpu power.
  * Sharing a single power source, if the power source fails, the server will shutdown.
  * Resource Allocation: Some servers may require different resources. To ensure the servers are provided their appropriate resources can be harder if the servers are sharing the same environment.
  * Scalability: You are less able to scale each server independantly for example upgrading only the Application server

