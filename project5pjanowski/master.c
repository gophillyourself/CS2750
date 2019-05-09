// Phillip Janowski
// CS2750 Project 5
// Takes and integer as an arg and passes it down to a worker
// to calculate the greatest prime number less than the inputted number
// master.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h> 
#include <string.h>

#define SHMKEY 1392
#define BUFF_SZ sizeof ( int )

int main (int argc, char * argv[]) {
	char usage[] = "Usage: master [-h | [-n number]]\n-h | displays this message\n-n | number to share with worker, defaults to 100";
	int number;
	char * numString;
	int o;
	while(( o = getopt (argc, argv, "n:h:")) != -1) {
		switch (o) {
			case 'h':
				printf("%s\n", usage);
				exit (0);
			
			case 'n':
				numString = (char*) malloc(sizeof(optarg));
				numString = optarg;
				number = atoi(optarg);
				break;
		}	
	}
	//set default values
	if (argc <= 1) {
		number = 100;
		numString = (char*) malloc(sizeof("100") + 1);
		numString = "100\0";
	}
	//create shared memory
    int shmid = shmget ( SHMKEY, BUFF_SZ, 0666 | IPC_CREAT );
	int * pint = (int * ) (shmat (shmid, 0, 0));
	//make sure the shmid gets set
	if (shmid == -1) {
		fprintf(stderr, "[master] Error in shmget\n");
		exit (1);
	}
    int pid = fork();
	// child
	if (pid == 0) {
		//set null terminated argv for worker
		char * execArg[] = { "./worker", "-n", numString, NULL };

		//exec worker
		int execed = execvp(execArg[0], execArg);
		if(execed == -1) {
			perror("[master] execvp failed\n");
			exit(1);
		}
	//parent
	} else {
		//initialize the shared memory
		*pint = 0;
		int count = 0;
		//wait for 10 seconds for the memory to get reset
		while (*pint == 0 || count >= 10) {
			sleep(1);
			count++;
		}
		//error statements
		if( *pint == 0) {
			printf("[master] The shared memory didn't get a value other than 0.\n");
		} else {
			printf("[master] Recieved %d as the greatest prime value less than the input in the shared memory\n", *pint);
		}
		//reset for the worker
		*pint = 0;
		//detach
		shmdt(pint);
		shmctl(shmid, IPC_RMID, NULL);
	}
	return 0;
}
