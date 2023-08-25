# Simple Web Stack

## Requirements:

* A LAMP Stack -> Linux Apache MySQL Python
* 3 Server (Linux OS)
* 1 Application Server (Python)
* 1 CodeBase
* 1 Web Server (Apache)
* 1 Database Server (MySQL)
* A domain name (www.foobar.com)

## General

* For adding 2 more servers:
  * reducing the load on individual serverse for handling traffick
* For adding load balancer:
  * distributes the traffic evenly between the 3 servers
* The load balancer is using the Round Robin distribution algorithm, this works by passing each connection to each server sequentially in order repeatedly until it forms a cycle
* The load balancer is enabling an Active-Active instead of Active-Passive setup.
	* Active-Active: Distributes traffic equally and simultaneously amongst servers
	* Active-Passive: Invloves a primary active server and one or more passive servers
* A Primary-Replica (Master Slave) database operation:
	* The Primary database is the authorative source of data, it handles all writing and updating of data in the server
	* The Replica database is a read only database that is the exact copy of the primary database. It is used to alleviate the primary database of read queries sent to the server.

## Issues with Infrastructure:

* lacks any server monitoring
* There is no secure connection to the server using HTTPS
* There is no firewalls set in place to ward of any unauthorized access to the server
