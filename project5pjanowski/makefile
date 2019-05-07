all:	worker.c master.c
	gcc -g worker.c -o worker
	gcc -g master.c -o master

worker:	worker.c
	gcc -g worker.c -o worker

master: master.c
	gcc -g master.c -o master
