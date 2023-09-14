#include <stdio.h> 
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h> 

int main(int argc, char **argv){
	int n = atoi(argv[1]); // Converts number into an integer from command 
	// Loop to create n child processes 
	for (int i = 0; i < n; i++) {
		pid_t pid = fork(); // creates multiple processes 
		if (pid < 0) { // Negative value indicates error in forking
		       perror("Forking process failure"); // error messsage
		       exit(EXIT_FAILURE); 
		} else if (pid == 0) { // 0 indicates i nthe child process 
		printf("WORKER PID: %d PPID: %d Iteration: %d before sleeping\n", getpid(), getppid(), i+1);
		sleep(1); // sleeps for 1 second 
	       	printf("WORKER PID: %d PPID: %d Iteration: %d after sleeping\n", getpid(), getppid(), i+1); 	
		exit(0); 
		} else { 
		int status; 
		waitpid(pid, &status, 0); // function that makes parent process wait for child processes to finish before continuing next iteration. This prevents orphaned processes. 
		}
	}
  
	return 0; 
}

