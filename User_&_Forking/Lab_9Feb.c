#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

struct person {
    char* name;
    int age;
};

int ques1() {
    pid_t pid;

    printf("Press any key to start...\n");
    getchar();

    pid = fork();

    int i = 1;
    while (1) {
        // pid = fork();
        printf("PID: %d, %d\n", getpid(), i);
        usleep(1000000); // Sleep for 1 seconds
        i++;
    }

    return 0;
}

int ques2() {
    pid_t r;

    int x=10;

    r = fork();

    printf("PID of x: %d, Address of x: %p, x=%d\n", getpid(), &x, x);
    printf("Address of r: %p, Value of r=%d\n", &r, r);
}

int ques3() {
    // Create a person on the heap using malloc
    struct person *p = (struct person *)malloc(sizeof(struct person));
    if (p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    p->name = "Kushagra";
    p->age = 20;

    pid_t pid = fork();
    
    if (pid == 0) { // Child process
        p->age += 1;

        printf("Child Process - PID: %d\n", pid);
        printf("Address of p: %p\n", (void *)p);
        printf("Name: %s, Age: %d\n", p->name, p->age);
    }
    else { // Parent process
        printf("Parent Process - PID: %d\n", pid);
        printf("Address of p: %p\n", (void *)p);
        printf("Name: %s, Age: %d\n", p->name, p->age);
    }

    free(p);

    return 0;
}

int main() {
    ask:
        printf("Enter no of question to run(1/2/3): ");
        int x;
        scanf("%d", &x);

    switch(x) {
        case 1: ques1();
        break;

        case 2: ques2();
        break;

        case 3: ques3();
        break;

        default:
            printf("Wrong input\n");
            goto ask;
    }

    return 0;
}