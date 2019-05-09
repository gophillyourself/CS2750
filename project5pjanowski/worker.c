// Phillip Janowski
// CS2750 Project 5
// Takes and integer as an arg and passes it down to a worker
// worker.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHMKEY 1392
#define BUFF_SZ sizeof ( int )

int greatestPrimeNum(int number);

int main (int argc, char * argv[]) { 
	
	char usage[] = "Usage: worker [-h | [-n number]]\n-h | displays this message\n-n | number to share with worker, defaults to 100";
	int number;
	int o;
	//check for 0 args
	if (argc <= 1) {
		printf("%s\n", usage);
		exit(1);
	}
	
	while(( o = getopt (argc, argv, "n:h:")) != -1) {
		switch (o) {
			case 'h':
				printf("%s\n", usage);
				exit (0);
			
			case 'n':
				number = atoi(optarg);
				break;
		}	
	}

	int shmid = shmget ( SHMKEY, BUFF_SZ, 0666 | IPC_CREAT);
    if (shmid == -1) {
		fprintf(stderr, "[worker] Error in shmget\n");
		exit (1);
	}
	//attach to shared memory and make sure it happened
	int * cint = (int * ) (shmat (shmid, 0, 0));
	if (*cint != 0) {
		printf("[worker] 0 was not found in the shared memory\n Exiting\n");
		exit(1);
	} else {
		printf("[worker] 0 was found in the shared memory\n Continuing\n");
	}
	//get greatest prime less than the inputted number
	int greatest = greatestPrimeNum(number);
	//set it and make sure the master gets set back
	*cint = greatest;
	int count = 0;
	//wait for it to get set back for 10 seconds
	while (*cint != 0 || count >= 10) {
		sleep(1);
		count++;
	}
	//let everyone know if the shared memory was or wasn't reset by the master program
	if (*cint == 0) {
		printf("[worker] Shared memory has been set back to 0\n");
	} else {
		printf("[worker] Shared memory was never set back to 0\n");
	}
	//detach because this program is over
    shmdt(cint);
    return 0;
}

int greatestPrimeNum(int number) {
	int greatest = number;
	int tempNum = number;	
	int isPrime = 1;
	printf("greatest Prime\n");
	//loop over every number less than the greatest
	while (greatest > 1) {
		isPrime = 0;
		printf("greatest = %d\n", greatest);
		//all primes are not event
		if (greatest % 2 != 0) {
			int dividend = 3;
			//this should count up to half the value because its faster but it doesn't work
			//so here we are
			while (dividend <= greatest) {
				if (dividend == greatest) {
					return greatest;
				}
				//break out of the loop if the current number isn't prime
				if (greatest % dividend == 0) {
					isPrime = 0;
					break;
				}
				dividend++;
			}
		}
		if (isPrime == 1) {
			break;
		}
		greatest = greatest - 1;
	}
	return 1;
}
