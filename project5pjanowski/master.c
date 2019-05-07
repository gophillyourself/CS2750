// Phillip Janowski
// CS2750 Project 5
// Takes and integer as an arg and passes it down to a worker
// master.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<sys/wait.h> 

#define SHMKEY 1392
#define BUFF_SZ sizeof ( int )

int main (int argc, char * argv[]) {
	char usage[] = "Usage: master [-h | [-n number]]\n-h | displays this message\n-n | number to share with worker, defaults to 100";
	int * number;
	char * numString;
	int o;
	while(( o = getopt (argc, argv, "n:h:")) != -1) {
		switch (o) {
			case 'h':
				printf("%s\n", usage);
				exit (0);
			
			case 'n':
				numString = optarg;
				number = atoi(optarg);
				break;
		}	
	}
	if (argc <= 1) {
		number = 100;
	}	
	printf("%d\n", number);
	int shmid = shmget ( SHMKEY, BUFF_SZ, 0777 | IPC_CREAT );
	if (shmid == -1) {
		fprintf(stderr, "Error in shmget\n");
		exit (1);
	}

	int * shint = ( int * ) (shmat (shmid, 0, 0));

	int pid = fork();
	printf("%d\n", pid);
	// child
	if (pid == 0) {
		char * execArg[] = { "./worker", "-n", numString};
		int execed = execvp(execArg[0], execArg);
		if(execed == -1) {
			perror("execvp failed\n");
			exit(1);
		}
	} else {
		printf("about to wait\n");
		printf("shint = %d\n", shint);
		printf("number = %d\n", number);
		
		wait(NULL);
		if( shint != number) {
			printf("the shared memory copy didn't work\n");
			printf("shint = %d\n", shint);
			printf("number = %d\n", number);
		}
		
		printf("done\n");

		printf("Inputted number = %d\n", shint);
		shint = 0;
		
		shmdt(shint);
		shmctl(shmid, IPC_RMID, NULL);
	}
	return 0;
}
