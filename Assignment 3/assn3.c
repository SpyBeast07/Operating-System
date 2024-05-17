#include <stdio.h>
#include <stdlib.h>

int global_var;

int fn() {
	int fna;
	printf("Address of fna in function fn(): %p\n", &fna);
	
	gn();

	static int st_var;
	printf("Address of static variable st_var: %p\n", &st_var);
}
int gn() {
	int gna;
	printf("Address of gna in function gn(): %p\n", &gna);
}

int main() {
	// 1
	printf("Question 1\n");
	int x;
	printf("Variable x is: %d\n", x);
	printf("Adderess of x is: %p\n\n", &x);

	//2
	printf("Question 2\n");
	int arr[5];
	printf("Addresses of array arr is: %p\n\n", &arr);

	//3
	printf("Question 3\n");
	printf("Calling function fn()\n");
	fn();
	printf("Address of function fn(): %p\n", &fn);
	printf("Address of function gn(): %p\n", &gn);
	gn();
	printf("\n");

	// 4
	printf("Question 4\n");
	printf("Calling function fn() from main and gn() from fn(). \n");
	fn();
	printf("Address of function fn(): %p\n", &fn);
	printf("Address of function gn(): %p\n", &gn);
	printf("\n");

	// 5
	printf("Question 5\n");
	int y, z;
	printf("Calling function fn() again. \n");
	fn();
	printf("Address of function fn(): %p\n", &fn);
	printf("Address of function gn(): %p\n", &gn);
	printf("\n");

	//6
	printf("Question 6\n");
	printf("Calling function fn() again. \n");
	fn();
	printf("Address of global variable global_var: %p\n\n", &global_var);

	// 7
	printf("Question 7\n");
	void (*fn_ptr)() = (void*)fn;
    void (*gn_ptr)() = (void*)gn;
    printf("Function pointers to fn and gn:\n");
    printf("fn_ptr: %p\ngn_ptr: %p\n\n", &fn_ptr, &gn_ptr);

	// 8
	printf("Question 8\n");
	int (*printf_ptr)() = (void*)printf;
    printf("Function pointer to printf:\n");
    printf("printf_ptr: %p\n\n", (void*)printf_ptr);

	// 9
	printf("Question 9\n");
	int *dynamic_var = (int*)malloc(sizeof(int));
    printf("Malloc to allocate memory:\n");
    printf("Address of dynamic_var: %p\n\n", &dynamic_var);
    free(dynamic_var);

	// 10 
	printf("Question 10\n");
	char *s1 = "John";
	char s2[] = "John";
	printf("Address of s1 is: %p\n", &s1);
	printf("Address of s2 is: %p\n", &s2);
	printf("s2 is writable\n\n");

	// 11
	printf("Question 11\n");
	int num = 10;
    int *num_ptr = &num;
    printf("Address of num pointer: %p\n", (void*)num_ptr);
    num_ptr++;
    printf("Address of num pointer after adding 1: %p\n\n", (void*)num_ptr);

	// 12
	printf("Question 12\n");
	struct MyStruct {
        int a;
        int arr[5];
    };
    struct MyStruct myStruct;
    struct MyStruct *struct_ptr = &myStruct;
    printf("Address of struct pointer: %p\n", (void*)struct_ptr);
    struct_ptr++;
    printf("Address of struct pointer after incrementing by 1: %p\n\n", (void*)struct_ptr);

	// 13
	printf("Question 13\n");
	int **double_ptr = &num_ptr;
    printf("Address of pointer of num pointer: %p\n", (void*)double_ptr);
    double_ptr++;
    printf("Address of pointer of num pointer after incrementing by 1: %p\n\n", (void*)double_ptr);

    return 0;
}