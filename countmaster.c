#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[]) {
	int NUMBER_OF_CALLS = atoi(argv[3]);
	char *value1 = argv[1];
	char *value2 = argv[2];
	for (int i = 0; i < NUMBER_OF_CALLS; i++) {
		pid_t processID = fork();
		if (processID == 0) {
		//	char* arguments[4];
		//	arguments[0]="./countprimes";
		//	arguments[1]="10";
		//	arguments[2]="30";
		//	arguments[3]=NULL;
		//	char *args[] = {value1, value2, NULL};
			execvp("./countprimes", argv);
		//	execvp("./countprimes",arguments);
		}
	
		else {
			int currentstat;
			waitpid(processID, &currentstat, 0);

			int  res = WEXITSTATUS(currentstat);
		//	printf("The  countprimes number is %d\n", res);
		}
	}
	return 0;
}
