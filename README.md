# Operating Systems
This repository contains implementations of various algorithms and concepts related to the Operating Systems course. The Operating System used in Linux.
All the codes are programmed in C language in a seperate file.

## File Descriptions
[Assignment 1](Assignment 1)
Create a folder called assn1. Create subfolders called code and data in the folder assn1. In the data folder create a text file called students which has names and roll numbers of some students. First line should be name, second file should be roll number, third line name, 4th line roll no. and so on. Fill the file with data of atleast 5 students number of students. Roll number should be an integer.
In the code folder create a program that defines a struct Student, and a struct ListStudents which is a linked list of students. Read the data from the students file you created above and create the students and a linked list of all those students. Print the list of all students.
Bonus points: If you organise your program in multiple files and use Makefile for compilation.
**Run the Makefile in terminal to run the program.**

[Assignment 2](Assignment 2)
This assignment is in continuation of your first assignment and involves adding a few more features to that.
Add a function to search for  the student with a given roll number in the list of the students.
Add a function to delete the student with a given roll number. Make sure you not only delete the student from the list but also free up the memory taken by that student.
**Run the Makefile in terminal to run the program.**

[Assignment 3](Assignment 3)
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

Signal Handling and Scheduling
Signals and Scheduler
Code and explanations related to signal handling and scheduling in operating systems, including various signal processing techniques and scheduling algorithms.
User & Forking
User & Forking
Demonstrations and implementations related to user processes and forking in Unix-like operating systems.
Concurrency and Multithreading
Assn-Stack_concurrency.c
An assignment focused on implementing stack operations with concurrency control mechanisms.

Assn-Thread_Hello_World.c
A simple "Hello World" program demonstrating the basics of multithreading in C.

Algorithms and Scheduling
BankerAlgo.c
An implementation of the Banker's Algorithm for deadlock avoidance in operating systems.

PriorityQueueSJF.c
Implementation of the Shortest Job First (SJF) scheduling algorithm using a priority queue.

RoundRobin.c
Implementation of the Round Robin scheduling algorithm for time-sharing systems.

Labs and Exercises
Lab_23Feb_Signals_and_Scheduler.c
Lab exercise from February 23rd focused on signal handling and scheduler implementation.

Lab_9Feb.c
Lab exercise from February 9th covering various operating system concepts and implementations.

Miscellaneous
Stop_at_q_instead_^C.c
A program that modifies the default signal handling behavior to stop at 'q' instead of Ctrl+C.

jobs.txt
A text file containing job definitions or configurations used in some of the scheduling or process management programs.

---

Feel free to customize any descriptions or add more details as needed!
