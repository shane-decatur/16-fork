#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
  printf("parent process %d started\n",getpid());

  int f1 = fork();
  int f2;
  if (f1){
    f2 = fork();
  }
  srand(getpid());
  if (f1 && f2){
    int status;
    int pid = wait(&status);
    printf("child process %d finished after sleeping for %d seconds\n",pid,WEXITSTATUS(status));
    printf("parent process finished\n");
    return 0;
  }
  else{
    printf("child process %d started\n",getpid());
    int sleep_time;
    sleep_time =rand()%4+2;
    sleep(sleep_time);
    printf("child process %d finished\n",getpid());
    return sleep_time;
  }
}
