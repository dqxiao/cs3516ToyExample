#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h> //
//#include <sys/select.h>
//#include <sys/types.h> // 
#include <unistd.h>

int main(void){
	
	// select monitor independent sets of file description
	// FD_ZERO: clear a set 
	// FD_SET: add given file description from a set 
	// FD_ISSET: test whether a file description is part of the set 
	
	fd_set rfds; //
	struct timeval tv; 
	int retval;
	char buffer[256];
	
	// wathc stdin (fd 0) to see when it has input 
	FD_ZERO(&rfds); 
	FD_SET(0,&rfds);
	
	// wait u to five second 
	tv.tv_sec=5;
	tv.tv_usec=0;
	
	//int select(int nfds, fd_set *readfds, fd_set *writefds,fd_set *exceptfds, struct timeval *timeout);
	retval = select(1, &rfds, NULL, NULL, &tv);
	
	if(retval==-1){
		perror("select()");
	}else{
		if(retval){
			printf("data is available now\n");
			int t=read(0,buffer,256);
			printf("receive:%s\n",buffer);
		}else{
			printf("no data with five second\n");
		}
	}
	
	exit(EXIT_SUCCESS);
}