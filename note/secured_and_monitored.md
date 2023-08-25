# Simple Web Stack

## Requirements:

* A LAMP Stack -> Linux Apache MySQL Python
* 3 Server (Linux OS)
* 3 FireWalls
* SSL Certification via HTTPS
* A Monitoring Sytem (Sumologic)
* 1 Application Server (Python)
* 1 CodeBase
* 1 Web Server (Apache)
* 1 Database Server (MySQL)
* A domain name (www.foobar.com)

## General

* Purpose of Firewalls: To ward off unauthorized access to the servers
* Purpose of HTTPS connection: 
	* It requires an SSL certification from the web server, so we know that the web server is trusted
	* The connection is encrypted using public keys, which avoids any hacking of personal data while being transferred to the server
* How is the monitoring tool collecting data?
	* It monitors the logs and draws and analytics from the log data and sends alerts based on it's analysis
* How to track QPS:
	* Set up monitoring services that track QPS
	* Long-Term Trends: Use historical data to analyze long-term trends in queries per second. This can help you identify patterns related to usage spikes, changes in application behavior, or growth

## Issues with Infrastructure:

* Terminating SSL at the load balancer:
	* If you terminate SSL connection at the load balancer, plain HTTP request go from the load balancer to the servers.
	* This a small window of vulnerability.
* Why having only one MySQL server capable of accepting writes is an issue?
	* Decreases server redundency, if primary server is down, you will be unable to update or write new data to database
	* Instances where the primary database is overloaded with write queries and replica databases have no authority to alleviate those write requests
* Why having servers with all the same components (database, web server and application server) might be a problem?
  * Scalability: Disallows for independant salability options (updgrades) which may cause SPOF.
  * Organization/ Management servers: If the servers share the same environment, it becomes more difficult to manage them individually



