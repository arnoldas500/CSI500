# CSI500
//Arnoldas Kurbanovas
//ICSI500 final project
//This program is run in a unix command line
//by compiling using gcc finalProject.c
//which creates an executable named a.out
//to run the program after compiling the user needs to
//specify which function they would like to run as the 
//second argument: 
//to see the forkProcess() function run: ./a.out fork
//to see the orphanProcess() function run: ./a.out orphan
//When you run the orphan process you will have to wait
//up to 60 seconds after the program finished for the 
//child process to finish and for it to print its PID#
//as it is running independently of the parent and will
//finish after control is given back to the user in the terminal

The forkProcess() function:
//function to show how the creation of a seperate process works
//in UNIX using the fork system call called by specifying "fork" 
//as the second argument on the command line

The orphanProcess() function:
//function to demonstrate an orphan process on the unix system
//A process becomes an orphan process when the parent process 
//finishes execution while the child process is still running
//and therefor hence the name orphan
