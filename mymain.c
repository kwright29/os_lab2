// Author: Khloe Wright
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <sys/types.h>
#include  <sys/wait.h>
#include  <time.h>

#define MAX 2 


void ChildProcess(void) {
  int i; 
  int iterations;
  int time;
  
  iterations = rand() % 30 + 1;
  time = rand() % 10 + 1;

  for (i = 1; i <= iterations; i++) {
    printf("Child Pid: %d is going to sleep!\n", getpid());
    sleep(time);
    printf("Child Pid: is awake!\nWhere is my Parent: %d\n", getppid());
  }
  exit(0);
}

void ParentProcess(void) {
  int exitstatus; // creating exit statuses for child 1 & 2
  int child;
  int k;

  for (k = 0; k < MAX; k++) {
      child = wait(&exitstatus);
      printf("Child Pid: %d has completed\n", child);
  }
}

void main(void) {
  pid_t pid;
  int j;
  srand(time(NULL));

  for (j = 0; j < MAX; j++ ) {
      pid = fork();
      if (pid == 0) {
        ChildProcess();
      } else if (pid < 0) {
        printf("Error: Could not fork child processes.\n");
        exit(0);
      }
  }
  ParentProcess();
}

