# shareFiles
Share files using client and server configuration

References:  http://www.linuxhowtos.org/C_C++/socket.htm

Steps to run:

Open a terminal and run server.c

$ gcc server.c

$ ./a.out PORT_NO
 
Open a new terminal and run clinet.c

$ gcc client.c

$ ./a.out localhost PORT_NO
