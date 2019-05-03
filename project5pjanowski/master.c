// Phillip Janowski
// CS2750 Project 5
// Takes and integer as an arg and passes it down to a worker
// master.c

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SHMKEY 1392
#define BUFF_SZ sizeof ( int )

int main (int argc, char * argv[]) {
	char usage[] = "Usage: master [-h | [-n number]]\n-h | displays this message\n-n | number to share with worker, defaults to 100";
	int number;
	int o;
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
	if (argc <= 1) {
		number = 100;
	}	
	printf("%d\n", number);
	int * shmid = shmget ( SHMKEY, BUFF_SZ, 0777 | IPC_CREAT );
	shmid = 0;
	if (shmid == -1) {
		cerr << "Error in shmget\n" << endl;
		exit (1);
	}

	int * shint = ( int * ) (shmat (shmid, 0, 0));
	shmdt(shint);
	shmctl(shmid, IPC_RMID, NULL);
	int pid = fork();
	// child
	if (pid == 0) {

	} else {
		execvp("worker", "-n", itoa(number));
	}
	getpid
	return 0;
}
