#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(){
	pid_t processID = fork();
	
	if (processID == 0) {
		char* arguments[4];
		arguments[0]="./countprimes";
		arguments[1]="10";
		arguments[2]="30";
		arguments[3]=NULL;
		execvp("./countprimes",arguments);
	}
	
	else {
		int currentstat;
		waitpid(processID, &currentstat, 0);
		printf("test success");
	}
	return 0;
}
