#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

//function protocalls
void forkProcess();
void orphanProcess();

int main(int argc, char **argv){
  
  printf("\nThe argument you specified is: %s",argv[1]);
  
  char *args = argv[1];
  
  //printf(args);
  //printf("\n here %d \n", strcmp(args, "fork"));
  
  printf("\n\n");
  
  if(strcmp(args, "fork") == 0){
    forkProcess();
  }else if(strcmp(args, "orphan") == 0){
    orphanProcess();
  }else{
    printf("Incorrect argument specified\n");
  }
  
  
  return 0;
}

//function to show how the creation of a seperate process works
//in UNIX using the fork system call called by specifying "fork" 
//as the second argument on the command line
void forkProcess(){
  pid_t pid;
  
  //this will fork a child process 
  pid = fork();
  
  //check if the pid after forking is less than zero
  //implying an error has occured during the system call
  //if such a case happens there will be an error printed to
  //the user to standard output and the program will exit with exit code 1
  if(pid < 0){
    printf("\n");
    fprintf(stderr, "Exit due to failing to fork the child process\n");
    printf("\n");
    exit(-1);
  }
  //if the pid is 0 then we are in the child process
  else if(pid == 0){
    //using execlp lets the child process have a new program loaded 
    //into its address space with all new code and data segment
    execlp("/bin/ls", "ls", NULL);
  }
  //this will be the parents process and itll wait for the child
  //to finish its jobs before priting and exiting normally
  else{
    wait(NULL);
    printf("\n");
    printf("Inside parent process, Child finished sucessfully with PID #: %d\n", getpid());
    printf("\n");
    exit(0);
  }
  
}

//function to demonstrate an orphan process on the unix system
//A process becomes an orphan process when the parent process 
//finishes execution while the child process is still running
//and therefor hence the name orphan
void orphanProcess(){
  printf("Before fork\n");
  //first creating the child process
  int pid = fork();
  
  //go insdie parent if pid is greater then zero
  if (pid > 0){
    printf("\nCurrently in parent process PID#: %d\n", getpid());
    printf("\nThis is the parent of the parent process PID#: %d\n", getppid());
  }
  //if pid is zero then we are in the child process
  else if(pid == 0){
    
    printf("\nStarting child process with PID#: %d\n", getpid());
    printf("\nThis is the parent of this child process PID#: %d\n", getppid());
    sleep(30);
    printf("\nIn the child process PID#: %d\n", getpid());
  }
  
}
