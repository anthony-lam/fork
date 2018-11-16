#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  int parent_pid = getpid();
  int child = fork();
  int child2;
  int status;
  printf("Before fork");
  if (child == 0){
    sleep(5);
  }
  else{
    child2 = fork();
    if (child2 == 0){
    }
    else{
      wait(status);
      printf("The time was %d", WEXITSTATUS(status));
      return 0;
    }
  return 0;
}
