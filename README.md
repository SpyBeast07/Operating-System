# Operating Systems
This repository contains implementations of various algorithms and concepts related to the Operating Systems course. The Operating System used in Linux.
All the codes are programmed in C language in a seperate file.

## File Descriptions
[Assignment 1](Assignment1)<br>
Create a folder called assn1. Create subfolders called code and data in the folder assn1. In the data folder create a text file called students which has names and roll numbers of some students. First line should be name, second file should be roll number, third line name, 4th line roll no. and so on. Fill the file with data of atleast 5 students number of students. Roll number should be an integer.
In the code folder create a program that defines a struct Student, and a struct ListStudents which is a linked list of students. Read the data from the students file you created above and create the students and a linked list of all those students. Print the list of all students.
Bonus points: If you organise your program in multiple files and use Makefile for compilation.
**Run the Makefile in terminal to run the program.**

[Assignment 2](Assignment2)<br>
This assignment is in continuation of your first assignment and involves adding a few more features to that.
Add a function to search for  the student with a given roll number in the list of the students.
Add a function to delete the student with a given roll number. Make sure you not only delete the student from the list but also free up the memory taken by that student.
**Run the Makefile in terminal to run the program.**

[Assignment 3](Assignment3)<br>
1) Create some local variables in main and print their addresses.
2) Create an int array in main and print its address.
3) Declare functions fn and gn and create local variables in them and print their addresses.
4) Call fn from main. Call gn from fn. And examine the addresses.
5) Declare some more local  variables in main, and call fn again and see if the addresses are same.
6) Create a global variable and static variables in functions and print their addresses.
7) Use function pointers to print the addresses of the function fn and gn.
8) Use function pointers to print the addresses of the function printf.
9) Use malloc to allocate some memory and print the address obtained.
10) Do char *s1="John" and char s2[]="John". Print the addresses of s1 and s2. Which of these is a writable address.
Pointer Arithmetic:
11) Create an int, save its address in an int pointer. Print this address. Add one to this pointer and print the new address.
12) Define a struct containing an int and an int array of size 5. Create one struct like this and save its memory address in a pointer. Print this address. Increment the pointer by 1 and print the address again.
13) Create a pointer to a pointer. Save the address of the previous pointer in it and print this. Increment it by one and print it again.

[Signal Handling and Scheduling](Signals_and_Scheduler)<br>
1) Write a program that runs an infinite loop printing "Hello"  every second. Register a signal handler such that the program does not exit on ctrl-c.
2) In you favourite programming language (Python, C++, Java, C) write an FCFS and an SJF scheduler. Your program should read from a file that has a table of jobs arrival_times and execution_times. Your program should output the jobs scheduled in order with their start and end times. Your program should also incorporate idle times in the schedule. It should calculate the average  turnaround time of the schedule as well.

[User & Forking](User_&_Forking)<br>
1) Create a program that prints numbers 1,2,.... on screen along with the PID of the program. Use usleep to print these numbers slowly. Use a fork before the print statement to create a new process and see what happens. Before starting the printing use getchar and
ask the user to press a key to continue.
On a separate terminal use ps or pstree to see which processes are active when.
2) Define an int x=10 and then fork. Save the return value of fork in a variable called r.
Print the value and the address of x. Also print the value and address of r.
3) Define a structure person containing name and age.
Create a person on heap using malloc.
Fork. Modify the age in child process. Print the memory address of the this person and the name and age and check what happens.
4) Create a user called xyz using the command
sudo useradd -m xyz
Create its passwd using the command
sudo passwd xyz
(As the original user) create a folder called usertest. Go to this folder. Create a program hello that prints "Hello World" on the screen. Create another program bye that prints "Goodbye World" on the screen.
remove the execute permission for others from bye using chmod.
now switch to user xyz and go to the above folder and try to run the programs.
**You can see the proper organization of the answers in the [word file](User_&_Forking/OS_assn-Users_and_forking.docx)

[Assn-Thread_Hello_World.c](Assn-Thread_Hello_World.c)<br>
1) Create a program with a child thread that prints "child" 10000 times at intervals of 0.1 seconds.  The main program should print "parent" 10000 times.. 
Observe the behaviour of the program if you<br>
(i) dont join the child thread<br>
(ii) join the child thread<br>
2) Create a thread function that takes a string name and a number N and prints the name N times. You can run an empty loop 1000000 times after the print statement to have some interval between the print outputs. (Dont use sleep as that may mess up the scheduling)
Create 5 threads which run this function with different arguments. Observe their behaviour with and without join.
3) Create a function that takes an integer array and the length of the array and finds the sum of the array in a multithreaded manner. Each thread should add a maximum of 50 elements. (So if your input array has 5000 elements your function should create 100 threads.)

[Assn-Stack_concurrency.c](Assn-Stack_concurrency.c)<br>
1) Create a simple stack data structure that is capable of holding up to 50000 integers. (Use a simple array based implementation that contains a buffer array of size 50000 allocated on heap and a position variable to keep track of the location of the top of the stack in the buffer.) Implement the push and pop functions for this stack. Also implement a function to print all the elements of the stack.
2) Create main program that creates and initialises one stack called st. Create two threads t1 and t2 where t1 pushes numbers 1 to 10000 in st and t2 pushes numbers -1 to -10000 in st. Make sure that you join both the threads so that they run completely. How many total elements should have been pushed to the stack? How many elements actually have been pushed to the stack? If you are seeing a discrepancy explain what is causing it? If you were pushing smaller number of elements (say t1 pushes 1 to 100 and t2 pushes -1 to -100) do you still see the discrepancy? Explain.
3) The discrepancy you see above is caused because of concurrency issues. How can this problem be resolved using locks? Implement the lock based solution and check that the discrepancy disappears.

[BankerAlgo.c](BankerAlgo.c)<br>
An implementation of the Banker's Algorithm for deadlock avoidance in operating systems.

[PriorityQueueSJF.c](PriorityQueueSJF.c)<br>
Implementation of the Shortest Job First (SJF) scheduling algorithm using a priority queue.

[RoundRobin.c](RoundRobin.c)<br>
Implementation of the Round Robin scheduling algorithm for time-sharing systems.

## Miscellaneous
[Stop_at_q_instead_ctrlC.c](Stop_at_q_instead_ctrlC.c)<br>
A program that modifies the default signal handling behavior to stop at 'q' instead of Ctrl+C.

[jobs.txt](jobs.txt)<br>
A text file containing job definitions or configurations used in some of the scheduling or process management programs.
