# Simple Web Stack

## Requirements:

* A LAMP Stack -> Linux Apache MySQL Python
* Seperated the database, application and web server into individual virutal environments
* Added a fourth server
* Added a load balancer that acts within conjunction with the previous in a cluster
* SSL Certification via HTTPS
* A Monitoring Sytem (Sumologic)
* 1 Application Server (Python)
* 1 CodeBase
* 1 Web Server (Apache)
* 1 Database Server (MySQL)
* A domain name (www.foobar.com)

## For added components:

* Why split the servers within one server ?
	* Isolation and Resource Allocation: When you split the components onto different virtual machines or containers within a single physical server, you can allocate resources more efficiently. The database server, app server, and web server might have different resource requirements. By isolating them, you can allocate CPU, memory, and disk space according to their specific needs, preventing resource contention.

	* Scalability: While having all components on a single server might be easier to manage in the beginning, it can become difficult to scale as your application grows. Splitting components allows you to scale each part independently. For example, you can scale the web server layer separately from the app and database layers, which can be crucial for managing high traffic loads.

	* Maintenance and Updates: Isolating components enables you to update or maintain them independently. If you need to update the database or the app server, you can do so without affecting the web server or the entire application. This minimizes downtime and reduces the risk of unexpected issues arising from updates.

	* Security: Segregating the components can enhance security. By isolating the database server from the web server, you reduce the attack surface. Compromising one component doesn't necessarily mean compromising the entire application. You can also apply different security measures to each component based on its requirements.

	* Performance: Separating the components can lead to better performance optimization. You can fine-tune the configuration of each component according to its workload and requirements. This can lead to better overall application performance.

	* Flexibility: Splitting components allows you to choose different technologies for each layer based on their strengths. For instance, you might choose a specialized database server for storage, a highly efficient app server, and a lightweight web server optimized for serving static content.

	* Development and Deployment: Having separate components can make the development and deployment process more manageable. Different teams can work on each component independently, and you can deploy updates or new features to specific components without affecting the entire application.

	* Fault Isolation: If one component fails or experiences issues, the impact can be limited to that particular component. The rest of the application can continue functioning without being affected by the failure.

* Why add an extra server ?
	* To further lessen traffic for each server
	* To have more back-up servers if more servers fail
* Why add an extra load-balancer?
	* Since we added an extra server, the load balancer has more servers to keep track of, so we added another to improve it's efficency in distributing traffic



