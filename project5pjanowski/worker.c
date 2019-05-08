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

int main (int argc, char * argv[]) { 
	
	char usage[] = "Usage: worker [-h | [-n number]]\n-h | displays this message\n-n | number to share with worker, defaults to 100";
	int * number;
	int o;
	for (int i = 0; i < argc; i++) {
		printf("[worker] arg %d = %s\n", i, argv[i]);
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

	int shmid = shmget ( SHMKEY, BUFF_SZ, 0666 );
    printf("[worker] shmid = %d\n", shmid);
    if (shmid == -1) {
		fprintf(stderr, "Error in shmget\n");
		exit (1);
	}

	int * cint = (int * ) (shmat (shmid, 0, 0));
    printf("[worker] cint = %d\n", cint);
	printf("[worker] before cint = %d\n", cint);
    cint = number;
	printf("[worker] after cint = %d\n", cint);
    shmdt(cint);
    return 0;
}
