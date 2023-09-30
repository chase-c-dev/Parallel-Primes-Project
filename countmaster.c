#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
	int NUMBER_OF_CALLS = atoi(argv[3]);
	char *value1 = argv[1];
	char *value2 = argv[2];
	int allids[NUMBER_OF_CALLS];
	int total = 0;
	int temp = 0;
	int range = atoi(argv[2]);
	float increment = (atoi(argv[2]) - atoi(argv[1])) / ((float)NUMBER_OF_CALLS);
	sprintf(argv[2], "%d",(atoi(argv[1])+(int)increment));
	int primeHolder[22]; //array holds prime numbers may need to increase or create scaler for length
	int primeinc = 0;
	for (int i = 0; i < NUMBER_OF_CALLS*increment; i+=increment) {
		pid_t processID = fork();
		if (processID == 0) {
			sprintf(argv[1], "%d", atoi(argv[1]) + i);
			sprintf(argv[2], "%d", atoi(argv[2]) + i);
			if (range+2  <=  atoi(argv[2])){
				break;
			} else {
				primeHolder[(int)(i/increment)] = execvp("./countprimes", argv);
			}
		} else {
			allids[temp] = processID;
			temp++;
		}
	}
	for (int j = 0; j < temp; j++) { //replaced number of calls with temp
		int currentState;
		waitpid(allids[j], &currentState, 0);
		int res = WEXITSTATUS(currentState);
		total += res; 
		
	}

	printf("Total is %d\n", total);
	return 0;
}

