#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main(int argc, char *argv[]) {
	int NUMBER_OF_CALLS = atoi(argv[3]);
	char *value1 = argv[1];
	char *value2 = argv[2];
	int allids[NUMBER_OF_CALLS];
	int total = 0;
	int temp = 0;
	sprintf(argv[2], "%d", atoi(argv[2])/2);
	for (int i = 0; i < NUMBER_OF_CALLS*5; i+=5) {
		pid_t processID = fork();
		if (processID == 0) {
//			int new_low_counter = high_range - low_range + 1;
//			low_range += new_low_counter;
//			high_range += 5;
			sprintf(argv[1], "%d", atoi(argv[1]) + i);
			sprintf(argv[2], "%d", atoi(argv[2]) + i);
		//	argv[1] = 
		//	argv[2] = arg2s[i];
			execvp("./countprimes", argv);
		} else {
			allids[temp] = processID;
			temp++;
		}
	}
	for (int j = 0; j < NUMBER_OF_CALLS; j++) {
		int currentState;
		waitpid(allids[j], &currentState, 0);
		int res = WEXITSTATUS(currentState);
		 total += res; 
	}
	printf("Total is %d\n", total);
	return 0;
}
