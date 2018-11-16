#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
	srand(time(NULL));
	printf("Before fork, parent pid %d\n", getpid());
	int child = fork();
	int child2;
	int status;
	if (!child){
		int secs = rand()%15+5;
		sleep(secs);
		printf("Child Process finished, pid was %d\n", getpid());
		return secs;
	}
	else{
		child2 = fork();
		if (!child2){
			int secs = rand()%15+5;
			sleep(secs);
			printf("Child Process finished, pid was %d\n", getpid());
			return secs;
		}
		else{
			int child_pid = wait(&status);
			printf("The pid of child was %d\n", child_pid);
			printf("The time was %d\n", WEXITSTATUS(status));
			return 0;
		}
		return 0;
	}
}
