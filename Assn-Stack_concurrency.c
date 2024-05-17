#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

typedef struct Stack {
    int *arr;
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(50000 * sizeof(int));
    stack->top = -1;
    return stack;
}

void push(Stack* stack, int data) {
    if (stack->top == 50000 - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = data;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    int data = stack->arr[stack->top];
    stack->top--;
    return data;
}

void printStack(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int ques1() {
    Stack* myStack = createStack();
    int num;

    ask:
        printf("\nEnter 1 to push, 2 to pop, 3 to print stack and 4 to exit: ");
        int x;
        scanf("%d", &x);

    switch(x) {
        case 1:
            printf("Enter number of items to push: ");
            scanf("%d", &num);
            printf("Enter number to push: ");
            int temp;
            scanf("%d", &temp);
            for (int i = 0; i < num; i++) {
                push(myStack, temp);
            }
        break;

        case 2: 
            printf("Enter number of items to pop: ");
            scanf("%d", &num);
            for (int i = 0; i < num; i++) {
                pop(myStack);
            }
            printf("%d items poped\n", num);
        break;

        case 3: printStack(myStack);
        break;

        case 4: break;

        default:
            printf("Wrong input\n");
            goto ask;
    }
    if (x != 4) {
        goto ask;
    }
    
    return 0;
}

void* thread1_func(void* arg) {
    Stack* st = (Stack*)arg;
    // int num;
    // printf("Enter number to push from 1 to ?: ");
    // scanf("%d", &num);
    for (int i = 1; i <= 10000; i++) {
        push(st, i);
    }
    return NULL;
}

void* thread2_func(void* arg) {
    Stack* st = (Stack*)arg;
    // int num;
    // printf("Enter number to push from -1 to ?: ");
    // scanf("%d", &num);
    for (int i = -1; i >= -10000; i--) {
        push(st, i);
    }
    return NULL;
}

int ques2() {
    Stack* st = createStack();
    pthread_t t1, t2;

    // pthread_mutex_t mutex;
    // pthread_mutex_init(&mutex, NULL);  // NULL for default attributes

    pthread_create(&t1, NULL, thread1_func, st);
    pthread_create(&t2, NULL, thread2_func, st);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printStack(st);

    printf("Stack size: %d\n", st->top + 1);

    free(st->arr);
    free(st);

    return 0;
}

typedef struct Stack2 {
    int *buffer;
    int top;
    pthread_mutex_t mutex; // Mutex for thread safety
} Stack2;

Stack2* createStack2() {
    Stack2* stack = (Stack2*)malloc(sizeof(Stack2));
    stack->buffer = (int*)malloc(50000 * sizeof(int));
    stack->top = -1;
    pthread_mutex_init(&stack->mutex, NULL);
    return stack;
}

void push2(Stack2* stack, int data) {
    pthread_mutex_lock(&stack->mutex);  // Lock mutex before critical section
    if (stack->top == 50000 - 1) {
        printf("Stack Overflow\n");
    } else {
        stack->top++;
        stack->buffer[stack->top] = data;
    }
    pthread_mutex_unlock(&stack->mutex); // Unlock mutex after critical section
}

int pop2(Stack2* stack) {
    pthread_mutex_lock(&stack->mutex);
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1; // Or any invalid value to indicate underflow
    }
    int data = stack->buffer[stack->top];
    stack->top--;
    pthread_mutex_unlock(&stack->mutex);
    return data;
}

void printStack2(Stack2* stack) {
    pthread_mutex_lock(&stack->mutex);
    if (stack->top == -1) {
        printf("Stack is empty\n");
    } else {
        for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->buffer[i]);
        }
    }
    printf("\n");
    pthread_mutex_unlock(&stack->mutex);
}

void* thread1_func2(void* arg) {
    Stack2* st = (Stack2*)arg;
    for (int i = 1; i <= 10000; i++) {
        push2(st, i);
    }
    return NULL;
}

void* thread2_func2(void* arg) {
    Stack2* st = (Stack2*)arg;
    for (int i = -1; i >= -10000; i--) {
        push2(st, i);
    }
    return NULL;
}

int ques3() {
    Stack2* st = createStack2();

    pthread_t t1, t2;

    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);  // NULL for default attributes

    pthread_create(&t1, NULL, thread1_func2, st);
    pthread_create(&t2, NULL, thread2_func2, st);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printStack2(st); // The output will likely be interleaved due to concurrency

    printf("Stack size: %d\n", st->top + 1);

    // Free the allocated memory
    free(st->buffer);
    free(st);
    pthread_mutex_destroy(&st->mutex);

    return 0;
}

int main() {
    ask:
        printf("Enter 1-3, which question to run: ");
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