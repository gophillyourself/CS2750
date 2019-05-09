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
	if (argc < 1) {
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

	int * cint = (int * ) (shmat (shmid, 0, 0));
	if (*cint != 0) {
		printf("[worker] 0 was not found in the shared memory\n Exiting\n");
		exit(1);
	} else {
		printf("[worker] 0 was found in the shared memory\n Continuing\n");
	}
	int greatest = greatestPrimeNum(number);
	*cint = greatest;
	int count = 0;
	while (*cint != 0 || count >= 10) {
		sleep(1);
		count++;
	}
	if (*cint == 0) {
		printf("[worker] Shared memory has been set back to 0\n");
	} else {
		printf("[worker] Shared memory was never set back to 0\n");
	}
    shmdt(cint);
    return 0;
}

int greatestPrimeNum(int number) {
	int greatest = number;
	int tempNum = number;	
	int isPrime = 1;
	printf("greatest Prime\n");
	while (greatest > 1) {
		isPrime = 0;
		printf("greatest = %d\n", greatest);

		if (greatest % 2 != 0) {
			int dividend = 3;
			while (dividend <= greatest) {
				if (dividend == greatest) {
					return greatest;
				}
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
	return -1;
}
