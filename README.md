# CS4760-Proj1
First project for Operating Systems class. Refresher of Linux and system programming in C

I have two separate executables: oss and worker. The only way to call worker is through oss. I have programmed it to where the arguments inputted by the user will call the worker executable. 

After compiling and running, there should no longer be any outstanding problems. The biggest problems I ran into were in both files for separate reasons. In the worker process, I was struggling due to the PPID resulting in 1 everytime. I had to search at great lengths to figure out the wait() function and its power in this situation. 
Another problem I encountered was converting integer to string for the execl function. I tried implementing and remember how iota worked, but after searching online, I found documentation for sprintf.  

To run and compile this: 
1) make all : this will compile all the source files into executables. 
2) ./oss -h : this will display a help message to help you further execute and start the program  
