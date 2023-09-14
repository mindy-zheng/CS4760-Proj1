#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// Function to display help message
void help() {
        printf("oss [-h] [-n proc] [-s simul] [-t iter]");
        printf("\n\t Help Menu \n");
        printf("     -----------------\n");
	printf(" -h option: displays help message\n"); 
	printf(" -n [proc]: number of total children to launch\n"); 
	printf(" -s [simul]: indicates how many children can run simultaneously\n"); 
	printf(" -t [iter]: calls worker.c and indiciates number of iterations\n"); 
}

int main(int argc, char** argv) {
        int opt; // integer input from command line 
	
	//Initializing variables to store command line arguments 
	int n = 0; // num of total children 
	int s = 0; // num of children running simultaneously
	int t = 0; // num of iterations 
	// Parse input 
	while ((opt = getopt(argc, argv, "hn:s:t:")) != -1) { //n, s, t required args
		switch(opt) {
		//print help message
		case 'h': 
			help(); 
			return EXIT_SUCCESS;
		case 'n': 
			n = atoi(optarg); 
			break;
		case 's': 
			s = atoi(optarg); 
			break; 
		case 't': 
			t = atoi(optarg); 
			break;
		default: 
			help(); 
			return EXIT_FAILURE;
		}
	}

	// Catch block to catch errors in arguments 
	if (n ==0 || s == 0 || t == 0) { 
		printf("You have to enter an argument for n, s, and/or t"); 
		help();
	        exit(0); 	
	} 

	// Loop to create max simultaneous proccesses (3 means no more than 3 children to run simultaneously) 
	int i = 0; 
	for (int i = 0; i < n; i++) { 
		if (i >= s) { // states n processes won't be over s, inputted by user
			wait(NULL); 
			i--; 
	}

	pid_t pid = fork(); 
	if (pid < 0) { 
		perror("Forking process failure"); // error messsage
                exit(EXIT_FAILURE);
	} else if (pid == 0) { // child process if fork() returns 0 
		char iter[10];  // holds char array of size 10 for string representation   
		sprintf(iter, "%d", t);	//sprintf converts int to string for execl funct to work. 	       
		// need to convert int to string   
		execl("./worker", "worker", iter, NULL); //	
	} else {
		i++; 
	}
	} 

	while (i > 0) {
		wait(NULL); 
		i--; 
	} 
		
	
        return EXIT_SUCCESS;
}


