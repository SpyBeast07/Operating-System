#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void *child_thread(void *arg) {
    for (int i = 0; i < 10000; i++) {
        printf("child\n");
        sleep(0.1); // Sleep for 0.1 seconds
    }
    return NULL;
}

// name_data
struct name_data {
    char *name;
    int N;
};

void *print_name(void *arg) {
    struct name_data *data = (struct name_data *)arg;  // Cast the argument

    for (int i = 0; i < data->N; i++) {
        printf("%s\n", data->name);
        // Simulate some work without sleep
        for (int j = 0; j < 1000000; j++) {
            ; // Empty loop for interval
        }
    }

    free(data->name);  // Free the allocated memory for the name
    free(data);        // Free the entire data structure
    return NULL;
}

int ques1() {
    pthread_t thread;

    ask:
        printf("Enter 1 not to join the child thread, and 2 to join it: ");
        int s;
        scanf("%d", &s);

    switch(s) {
        case 1: {
            // (i) Without joining the child thread
            for (int i = 0; i < 10000; i++) {
                printf("parent\n");
            }
        }
        break;

        case 2: {
            // Create the child thread
            pthread_create(&thread, NULL, child_thread, NULL);

            // (ii) With joining the child thread
            pthread_join(thread, NULL); // Wait for the child thread to finish
            for (int i = 0; i < 10000; i++) {
                printf("parent\n");
            }

        }
        break;

        default:
            printf("Wrong input\n");
            goto ask;
    }

    return 0;
}

int ques2() {
    pthread_t threads[5];

    ask:
        printf("Enter 1 not to join the child thread, and 2 to join it: ");
        int s;
        scanf("%d", &s);

    switch(s) {
        case 1: {
            // Create 5 threads with different names and print counts
            for (int i = 0; i < 5; i++) {
                char *name = (char *)malloc(sizeof("Thread X") + 2);
                sprintf(name, "Thread %d", i + 1);
                int N = 5;  // Number of times to print the name

                struct name_data *data = (struct name_data *)malloc(sizeof(struct name_data));
                data->name = name;
                data->N = N;

                pthread_create(&threads[i], NULL, print_name, data);
            }

            for (int i = 0; i < 5; i++) {
                pthread_join(threads[i], NULL);
            }
        }
        break;

        case 2: {
            // Create 5 threads with different names and print counts
            for (int i = 0; i < 5; i++) {
                char *name = (char *)malloc(sizeof("Thread X") + 2);
                sprintf(name, "Thread %d", i + 1);
                int N = 5;  // Number of times to print the name

                struct name_data *data = (struct name_data *)malloc(sizeof(struct name_data));
                data->name = name;
                data->N = N;

                pthread_create(&threads[i], NULL, print_name, data);
            }
        }
        break;

        default:
            printf("Wrong input\n");
            goto ask;
    }

    return 0;
}

struct thread_data {
    int *arr;             // Pointer to the original integer array
    int start;             // Starting index for the thread's portion of the array
    int end;               // Ending index (exclusive) for the thread's portion
    int partial_sum;       // Stores the sum of elements calculated by the thread
};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Initialize mutex
int thread_count = 0;

void *calculate_sum_threaded(void *args) {
    // Cast argument to correct structure
    struct thread_data *data = (struct thread_data *)args;

    int sum = 0;
    for (int i = data->start; i < data->end; i++) {
        sum += data->arr[i];
    }

    // Store partial sum in the thread_data structure
    data->partial_sum = sum;

    // Perform some work
    pthread_mutex_lock(&mutex);  // Lock mutex before incrementing
    thread_count++;
    pthread_mutex_unlock(&mutex);  // Unlock mutex after incrementing

    return NULL;
}

int calculate_sum(int arr[], int length) {
    int num_threads = (length + 49) / 50;  // Ensure at least one thread

    pthread_t threads[num_threads];
    struct thread_data thread_data[num_threads];

    int chunk_size = length / num_threads;
    int start = 0;
    for (int i = 0; i < num_threads; i++) {
        thread_data[i].arr = arr;
        thread_data[i].start = start;
        thread_data[i].end = start + chunk_size;

        // Adjust end for the last thread to cover any remaining elements
        if (i == num_threads - 1) {
            thread_data[i].end = length;
        }

        start += chunk_size;

        pthread_create(&threads[i], NULL, calculate_sum_threaded, &thread_data[i]);
    }

    int total_sum = 0;
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);  // Wait for each thread to finish
        total_sum += thread_data[i].partial_sum;  // Combine partial sums
    }

    return total_sum;
}

int ques3() {
    int length;
    printf("Enter length of array: ");
    scanf("%d", &length);

    // Allocate memory dynamically for safety
    int *arr = (int *)malloc(length * sizeof(int));

    printf("Enter the element to fill array with: ");
    int num;
    scanf("%d", &num);
    for (int i = 0; i < length; i++) {
        arr[i] = num;
    }

    int total_sum = calculate_sum(arr, length);

    printf("\nTotal sum: %d\n", total_sum);  // Print the result

    free(arr);  // Free the dynamically allocated memory

    printf("Total threads created: %d\n", thread_count);

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