#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <string.h>

typedef struct {
    char name;
    int arrival_time;
    int execution_time;
    int start_time;
    int end_time;
} Job;

void signalhandler(int sig) {
    printf("\nCaught signal %d\n", sig);
}

int ques1() {
    signal(SIGINT, signalhandler);

    while (1) {
        printf("Hello\n");
        sleep(1);
    }

    return 0;
}

void bubsort_fcfs(Job jobs[], int num_jobs) {
    // Bubble sort based on arrival time
    for (int i = 0; i < num_jobs - 1; i++) {
        for (int j = 0; j < num_jobs - i - 1; j++) {
            if (jobs[j].arrival_time > jobs[j + 1].arrival_time) {
                // Swap jobs
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

void bubsort_sjf(Job jobs[], int num_jobs) {
    // Bubble sort based on execution time
    for (int i = 0; i < num_jobs - 1; i++) {
        for (int j = 0; j < num_jobs - i - 1; j++) {
            // Sort by execution time, then arrival time for jobs with same execution time
            if (jobs[j].execution_time > jobs[j + 1].execution_time || (jobs[j].execution_time == jobs[j + 1].execution_time && jobs[j].arrival_time > jobs[j + 1].arrival_time) || (jobs[j].execution_time == jobs[j + 1].execution_time && jobs[j].arrival_time == jobs[j + 1].arrival_time && jobs[j].name > jobs[j + 1].name)) {
                // Swap jobs
                Job temp = jobs[j];
                jobs[j] = jobs[j + 1];
                jobs[j + 1] = temp;
            }
        }
    }
}

void fcfs(Job jobs[], int num_jobs) {
    Job jobs2[num_jobs];
    for (int i = 0; i < num_jobs; i++) {
        jobs2[i] = jobs[i];
    }

    bubsort_fcfs(jobs2, num_jobs);
    
    int n = num_jobs;
    int curr = 0;
    int count = 0;

    printf("%-12s %-12s %-12s %-12s %-12s %-12s\n", "Jobs", "Arrival", "Execution", "Start", "End", "Turnaround Time");

    while (curr<n) {        
        if (count < jobs2[curr].arrival_time) {
            printf("%-12s %-12s %-12s %-12d %-12d %-12s\n", "idle", "-", "-", count, jobs2[curr].arrival_time, "-");
            count = jobs2[curr].arrival_time;            
        }
        jobs2[curr].start_time = count;
        jobs2[curr].end_time = jobs2[curr].start_time + jobs2[curr].execution_time;
        printf("%-12c %-12d %-12d %-12d %-12d %-12d\n", jobs2[curr].name, jobs2[curr].arrival_time, jobs2[curr].execution_time, jobs2[curr].start_time, jobs2[curr].end_time, (jobs2[curr].end_time - jobs2[curr].arrival_time));
        count = jobs2[curr].end_time;

        curr++;
    }

    float turn_around_avg = 0;
    for (int i=0; i<n; i++) {
        turn_around_avg += (jobs2[i].end_time - jobs2[i].arrival_time);
    }
    printf("--------------------------------------------------------------------------------\nAverage Turnaround Time for FCFS: %.2f\n------------------------------------", (turn_around_avg/n));
}

void sjf(Job jobs[], int num_jobs) {
    Job jobs2[num_jobs];
    for (int i = 0; i < num_jobs; i++) {
        jobs2[i] = jobs[i];
    }

    bubsort_sjf(jobs2, num_jobs);
    
    int n = num_jobs;
    int curr = 0;
    int count = 0;

    printf("%-12s %-12s %-12s %-12s %-12s %-12s\n", "Jobs", "Arrival", "Execution", "Start", "End", "Turnaround Time");

    while (curr<n) {        
        if (count < jobs2[curr].arrival_time) {
            printf("%-12s %-12s %-12s %-12d %-12d %-12s\n", "idle", "-", "-", count, jobs2[curr].arrival_time, "-");
            count = jobs2[curr].arrival_time;            
        }
        jobs2[curr].start_time = count;
        jobs2[curr].end_time = jobs2[curr].start_time + jobs2[curr].execution_time;
        printf("%-12c %-12d %-12d %-12d %-12d %-12d\n", jobs2[curr].name, jobs2[curr].arrival_time, jobs2[curr].execution_time, jobs2[curr].start_time, jobs2[curr].end_time, (jobs2[curr].end_time - jobs2[curr].arrival_time));
        count = jobs2[curr].end_time;

        curr++;
    }

    float turn_around_avg = 0;
    for (int i=0; i<n; i++) {
        turn_around_avg += (jobs2[i].end_time - jobs2[i].arrival_time);
    }
    printf("--------------------------------------------------------------------------------\nAverage Turnaround Time for SJF: %.2f\n------------------------------------\n", (turn_around_avg/n));
}

int ques2() {
    // Job jobs[] = {
    // {'A', 10, 2, -1, -1},
    // {'B', 7, 2, -1, -1},
    // {'C', 23, 12, -1, -1},
    // {'D', 1, 8, -1, -1},
    // {'E', 60, 3, -1, -1}
    // };

    // Job jobs[] = {
    //     {'A', 1, 7, -1, -1},
    //     {'B', 3, 3, -1, -1},
    //     {'C', 6, 2, -1, -1},
    //     {'D', 7, 10, -1, -1},
    //     {'E', 9, 8, -1, -1}
    // };
    
    FILE *file = fopen("jobs.txt", "r");
    if (file == NULL){
        printf("Error in opening a file.\n");
        return 1;
    }

    int n = 0;
    char str[50];
    while (fgets(str, 50, file) != NULL) {
        // printf("%s", str);
        n++;
    }
    printf("\nNo. of number of lines in the file are: %d\n------------------------------------------\n", n);
    // printf("%s\n", 12*"-");
    rewind(file);

    Job *jobs = (Job*) malloc(n * sizeof(Job));
    if (jobs == NULL){
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Skipping 1st line
    n -= 1;
    
    // Skipping 1st line
    fgets(str, 50, file);
    for (int i = 0; i < n; i++){
        fgets(str, 50, file);
        sscanf(str, "%c,%d,%d", &jobs[i].name,&jobs[i].arrival_time,&jobs[i].execution_time);
    }
    
    // display the content
    printf("%-12s %-12s %-12s\n", "Jobs", "Arrival", "Execution");
    for (int i = 0; i<n; i++){
        printf("%-12c %-12d %-12d\n", jobs[i].name, jobs[i].arrival_time, jobs[i].execution_time);
    }
    printf("------------------------------------------\n\n");

    fclose(file);

    printf("Scheduling tasks using FCFS scheduling \n--------------------------------------------------------------------------------\n");
    fcfs(jobs, n);

    printf("\n\nScheduling tasks using SJF scheduling \n--------------------------------------------------------------------------------\n");
    sjf(jobs, n);

    free(jobs);

    return 0;
}

int main() {
    ask:
        printf("Enter 1 to run question 1 and 2 for question 2: ");
        int x;
        scanf("%d", &x);

    switch(x) {
        case 1: ques1();
        break;

        case 2: ques2();
        break;

        default:
            printf("Wrong input\n");
            goto ask;
    }
    
    return 0;
}