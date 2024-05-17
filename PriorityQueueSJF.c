// #include <stdio.h>
// #include <stdlib.h>

// typedef struct {
//     char name;
//     int arrival_time;
//     int execution_time;
//     int start_time;
//     int end_time;
// } Job;

// typedef struct {
//     int prq[100];
//     int pr[100];
// } PQ;


// void bubsort_sjf(Job jobs[], int num_jobs) {
//     // Bubble sort based on execution time
//     for (int i = 0; i < num_jobs - 1; i++) {
//         for (int j = 0; j < num_jobs - i - 1; j++) {
//             // Sort by execution time, then arrival time for jobs with same execution time
//             if (jobs[j].arrival_time > jobs[j + 1].arrival_time) {
//                 // Swap jobs
//                 Job temp = jobs[j];
//                 jobs[j] = jobs[j + 1];
//                 jobs[j + 1] = temp;
//             }
//         }
//     }
// }

// void sjf(Job jobs[], int num_jobs) {
//     Job jobs2[num_jobs];
//     for (int i = 0; i < num_jobs; i++) {
//         jobs2[i] = jobs[i];
//     }

//     // sorting based on arrival time
//     bubsort_sjf(jobs2, num_jobs);

//     // Displaying content
//     // printf("%-12s %-12s %-12s\n", "Jobs", "Arrival", "Execution");
//     // for (int i = 0; i<num_jobs; i++){
//     //     printf("%-12c %-12d %-12d\n", jobs2[i].name, jobs2[i].arrival_time, jobs2[i].execution_time);
//     // }
//     // printf("------------------------------------------\n\n");
    
//     int n = num_jobs;
//     int time = 0;
//     int count = 0;
//     Job curr = jobs2[count];

//     printf("%-12s %-12s %-12s %-12s %-12s %-12s\n", "Jobs", "Arrival", "Execution", "Start", "End", "Turnaround Time");

//     while (count < n) {
//         if (curr.arrival_time >= time) {
//             printf("%-12s %-12s %-12s %-12d %-12d %-12s\n", "idle", "-", "-", time, curr.arrival_time, "-");
//             time = curr.arrival_time;
//         }
//         jobs2[count].start_time = time;
//         jobs2[count].end_time = jobs2[count].start_time + jobs2[count].execution_time;
//         printf("%-12c %-12d %-12d %-12d %-12d %-12d\n", jobs2[count].name, jobs2[count].arrival_time, jobs2[count].execution_time, jobs2[count].start_time, jobs2[count].end_time, (jobs2[count].end_time - jobs2[count].arrival_time));
//         time = jobs2[count].end_time;
        
//         count++;
//         curr = jobs2[count];

        
//         for (int i = count; i < num_jobs - 1; i++) {
//             for (int j = count; j < num_jobs - i - 1; j++) {
//                 if (curr.arrival_time > time) {
//                     break;
//                 }
//                 // todo: sort -- is execution same then  compare arrival times till it is less than time !!
//                 if (jobs2[count].arrival_time <= time && jobs2[count].arrival_time < jobs2[count+1].arrival_time) { // !Continue from here and think about condition
//                     // Swap jobs
//                     Job temp = jobs[j];
//                     jobs[j] = jobs[j + 1];
//                     jobs[j + 1] = temp;
//                 }
//             }
//         }
//     }

//     float turn_around_avg = 0;
//     for (int i=0; i<n; i++) {
//         turn_around_avg += (jobs2[i].end_time - jobs2[i].arrival_time);
//     }
//     printf("--------------------------------------------------------------------------------\nAverage Turnaround Time for SJF: %.2f\n------------------------------------\n", (turn_around_avg/n));
// }

// int main() {
//     // Job jobs[] = {
//     // {'A', 10, 2, -1, -1},
//     // {'B', 7, 2, -1, -1},
//     // {'C', 23, 12, -1, -1},
//     // {'D', 1, 8, -1, -1},
//     // {'E', 60, 3, -1, -1}
//     // };


//     FILE *file = fopen("jobs.txt", "r");
//     if (file == NULL){
//         printf("Error in opening a file.\n");
//         return 1;
//     }

//     int n = 0;
//     char str[50];
//     while (fgets(str, 50, file) != NULL) {
//         // printf("%s", str);
//         n++;
//     }
//     printf("\nNo. of number of lines in the file are: %d\n------------------------------------------\n", n);
//     // printf("%s\n", 12*"-");
//     rewind(file);

//     Job *jobs = (Job*) malloc(n * sizeof(Job));
//     if (jobs == NULL){
//         printf("Memory allocation failed.\n");
//         return 1;
//     }

//     // Skipping 1st line
//     n -= 1;
    
//     // Skipping 1st line
//     fgets(str, 50, file);
//     for (int i = 0; i < n; i++){
//         fgets(str, 50, file);
//         sscanf(str, "%c,%d,%d", &jobs[i].name,&jobs[i].arrival_time,&jobs[i].execution_time);
//     }
    
//     // display the content 
//     printf("%-12s %-12s %-12s\n", "Jobs", "Arrival", "Execution");
//     for (int i = 0; i<n; i++){
//         printf("%-12c %-12d %-12d\n", jobs[i].name, jobs[i].arrival_time, jobs[i].execution_time);
//     }
//     printf("------------------------------------------\n\n");

//     fclose(file);

//     printf("\nScheduling tasks using SJF scheduling \n--------------------------------------------------------------------------------\n");
//     sjf(jobs, n);

//     return 0;
// }























#include <stdio.h>
int main()
{
	int A[100][4]; 
	int i, j, n, total = 0, index, temp;
	float avg_wt, avg_tat;
	printf("Enter number of process: ");
	scanf("%d", &n);
	printf("Enter Burst Time:\n");
	// User Input Burst Time and alloting Process Id.
	for (i = 0; i < n; i++) {
		printf("P%d: ", i + 1);
		scanf("%d", &A[i][1]);
		A[i][0] = i + 1;
	}
	// Sorting process according to their Burst Time.
	for (i = 0; i < n; i++) {
		index = i;
		for (j = i + 1; j < n; j++)
			if (A[j][1] < A[index][1])
				index = j;
		temp = A[i][1];
		A[i][1] = A[index][1];
		A[index][1] = temp;

		temp = A[i][0];
		A[i][0] = A[index][0];
		A[index][0] = temp;
	}
	A[0][2] = 0;
	// Calculation of Waiting Times
	for (i = 1; i < n; i++) {
		A[i][2] = 0;
		for (j = 0; j < i; j++)
			A[i][2] += A[j][1];
		total += A[i][2];
	}
	avg_wt = (float)total / n;
	total = 0;
	printf("P	 BT	 WT	 TAT\n");
	// Calculation of Turn Around Time and printing the
	// data.
	for (i = 0; i < n; i++) {
		A[i][3] = A[i][1] + A[i][2];
		total += A[i][3];
		printf("P%d	 %d	 %d	 %d\n", A[i][0],
			A[i][1], A[i][2], A[i][3]);
	}
	avg_tat = (float)total / n;
	printf("Average Waiting Time= %f", avg_wt);
	printf("\nAverage Turnaround Time= %f", avg_tat);
	
	// This code is contributed by Akash kumar Thapa Magar
}