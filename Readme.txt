**___The Program is written with Qt5 C++__** 

To set up the learner interface, compile the program and add a port.txt file in the installation directory with just one line of text including the name of the dedicated port of the KATIB device. 

**___For Developers__** 
* Change databse credentials but set up the new databse with the same design as below. (Coordinates are stored with x and y separated by a cooma and each coordinate separated by a space).
* Database Design: 
	Table: admin
		contains username, password and Email of admin 
	
	Table: tasks
		contains task_name,Letter_Name,Description, and coordinates
	
	Table:student
		contains last_name,first_name,middle_name,username,password, Age, Email,task_assigned 
	
	Table:tasksAttempted
		contains taskid, studentid,coordinates,score,comments 




**__** 
Use Instructor Interface to Set tasks to students, create new tasks, and grade the tasks
The Learner interface should run on the KATIB device 