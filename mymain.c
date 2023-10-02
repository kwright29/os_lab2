#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <sys/types.h>

void main(void) {
  pid_t pid;

  pid = fork();
  if (pid == 0) {
        ChildProcess();
  }
}

void ChildProcess(void) {
  int i; 
  int iterations;
  int time;
  
  iterations = rand() % 30;
  time = rand() % 10;

  for (i = 1; i <= iterations; i++) {
    printf("Child Pid: %d is doing to sleep!", getpid());
    sleep(time);
    printf("Child Pid: is awake!\nWhere is my Parent: %d", getppid());
  }
  exit(0);
}

