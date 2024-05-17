#include <stdio.h>
#include <stdbool.h>

int main()
{
	// P0, P1, P2, P3, P4 are the Process names here

	int n, m;

	// Input -> 5 3 0 1 0 2 0 0 3 0 2 2 1 1 0 0 2 7 5 3 3 2 2 9 0 2 2 2 2 4 3 3 3 3 2
	
	// Get number of processes and resources from user
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    // Allocate memory for allocation, max, and avail matrices
    int alloc[n][m];
    int max[n][m];
    int avail[m];

    // Get allocation matrix from user
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Get maximum needs matrix from user
    printf("Enter the maximum needs matrix:\n");
    for (int i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Get available resources from user
    printf("Enter the available resources: ");
    for (int j = 0; j < m; j++) {
        scanf("%d", &avail[j]);
    }

	printf("\n\n");
	
	// n = 5; // Number of processes
	// m = 3; // Number of resources
	// int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
	// 					{ 2, 0, 0 }, // P1
	// 					{ 3, 0, 2 }, // P2
	// 					{ 2, 1, 1 }, // P3
	// 					{ 0, 0, 2 }  // P4
	// 					};

	// int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
	// 				{ 3, 2, 2 }, // P1
	// 				{ 9, 0, 2 }, // P2
	// 				{ 2, 2, 2 }, // P3
	// 				{ 4, 3, 3 }  // P4
	// 				};

	// int avail[3] = { 3, 3, 2 }; // Available Resources

	// Printing the table of given inputs
	printf("%-10s%-18s%-18s%-18s\n", "Process", "Allocation", "Max", "Available");
	printf("%-10s%-18s%-18s%-18s\n", "-------", "---------------", "---------------", "---------------");
	printf("%-10s%-5s%-5s%-5s%-3s%-5s%-5s%-5s%-3s%-5s%-5s%-5s\n", "", "A", "B", "C", "", "A", "B", "C", "", "A", "B", "C");
	printf("%-10s%-18s%-18s%-18s\n", "-------", "---------------", "---------------", "---------------");

	for (int i = 0; i < n; i++) {
		printf("P%-9d", i);
		for (int j = 0; j < m; j++)
			printf("%-5d", alloc[i][j]);
		printf("%-3s", "");
		for (int j = 0; j < m; j++)
			printf("%-5d", max[i][j]);
		if (i == 0) {
			printf("%-3s", "");
			for (int j = 0; j < m; j++)
				printf("%-5d", avail[j]);
		}
		printf("\n");
	}
	printf("%-10s%-18s%-18s%-18s\n", "-------", "---------------", "---------------", "---------------");

	printf("\n\n");


	// f[n] array to track, which process has been visited
	int f[n];
	// Initializing f[n] with 0
	for (int k = 0; k < n; k++) {
		f[k] = 0;
	}

	// Making the neend matrix
	int need[n][m];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}

	// Main
	int work[n][m], ans[n], ind = 0;
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			if (f[i] == 0) {
				int flag = 0;
				// Checking if all the resources are available
				for (int j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}
				
				// Updating the available resources and marking the process as visited
				if (flag == 0) {
					ans[ind++] = i;
					for (int y = 0; y < m; y++)
						avail[y] += alloc[i][y];
						// work[i][y] = avail[y];
					f[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	for(int i=0;i<n;i++)
	{
		if(f[i]==0)
		{
			flag=0;
			printf("The following system is not safe");
			break;
		}
	}
	
	if(flag==1)
	{
		printf("Following is the SAFE Sequence\n");
		for (int i = 0; i < n - 1; i++)
			printf(" P%d ->", ans[i]);
			printf(" P%d", ans[n - 1]);
	}
	
	printf("\n\n");

	return (0);
}













































































// #include <stdio.h>
// #include <stdlib.h>
// #include <stdbool.h>

// #define MAX_RESOURCES 10
// #define MAX_PROCESSES 10

// bool is_safe_state(int n, int m, int available[], int need[][m], int current_allocation[][m], int safe_sequence[]) {
//     int work[m];
//     bool finish[n];
//     for (int i = 0; i < m; ++i) {
//         work[i] = available[i];
//     }
//     for (int i = 0; i < n; ++i) {
//         finish[i] = false;
//     }
//     int c = 0;
//     while (c < n) {
//         bool found = false;
//         for (int i = 0; i < n; ++i) {
//             if (!finish[i]) {
//                 bool can_allocate = true;
//                 for (int j = 0; j < m; ++j) {
//                     if (need[i][j] > work[j]) {
//                         can_allocate = false;
//                         break;
//                     }
//                 }
//                 if (can_allocate) {
//                     for (int j = 0; j < m; ++j)
//                         work[j] += current_allocation[i][j];
//                     finish[i] = true;
//                     safe_sequence[c++] = i;
//                     found = true;
//                 }
//             }
//         }
//         if (!found)
//             return false;
//     }
//     return true;
// }

// bool detect_deadlock(int n, int m, int available[], int need[][m], int allocation[][m], int requests[][m]) {
//     int temp_allocation[n][m];
//     int temp_need[n][m];
//     int temp_available[m];
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             temp_allocation[i][j] = allocation[i][j];
//             temp_need[i][j] = need[i][j];
//         }
//     }
//     for (int i = 0; i < m; ++i) {
//         temp_available[i] = available[i];
//     }
//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
//             temp_allocation[i][j] += requests[i][j];
//             temp_need[i][j] = need[i][j] - requests[i][j];
//             temp_available[j] -= requests[i][j];
//         }
//     }
//     int work[m];
//     bool finish[n];
//     for (int i = 0; i < m; ++i) {
//         work[i] = temp_available[i];
//     }
//     for (int i = 0; i < n; ++i) {
//         finish[i] = false;
//     }
//     int num_finished = 0;
//     while (num_finished < n) {
//         bool found = false;
//         for (int i = 0; i < n; ++i) {
//             if (!finish[i]) {
//                 bool can_allocate = true;
//                 for (int j = 0; j < m; ++j) {
//                     if (temp_need[i][j] > work[j]) {
//                         can_allocate = false;
//                         break;
//                     }
//                 }
//                 if (can_allocate) {
//                     for (int j = 0; j < m; ++j) {
//                         work[j] += temp_allocation[i][j];
//                     }
//                     finish[i] = true;
//                     found = true;
//                     num_finished++;
//                 }
//             }
//         }
//         if (!found) {
//             return true;
//         }
//     }
//     return false;
// }

// void print_table(int m, int n, int resource[], int current_allocation[][m], int maximum_need[][m], int need[][m], int available[]) {
//     printf("\n----------------------------------------------------\n");
//     printf("| Process | Current Allocation | Maximum Need | Available | Remaining Need |\n");
//     printf("----------------------------------------------------\n");
//     for (int i = 0; i < n; i++) {
//         printf("|    %d    |", i + 1);
//         printf("        ");
//         for (int j = 0; j < m; j++) {
//             printf(" %d ", current_allocation[i][j]);
//         }
//         printf("       |");
//         printf("      ");
//         for (int j = 0; j < m; j++) {
//             printf(" %d ", maximum_need[i][j]);
//         }
//         printf("      |");
//         printf("    ");
//         for (int j = 0; j < m; j++) {
//             printf(" %d ", need[i][j]);
//         }
//         printf("   |");
//         printf("     ");
//         if (i == 0) {
//             for (int j = 0; j < m; j++) {
//                 printf(" %d ", available[j]);
//             }
//         }
//         printf("    |\n");
//     }
//     printf("----------------------------------------------------\n");
// }

// int main() {
//     int m, n;

//     printf("Enter the no. of resources: ");
//     scanf("%d", &m);

//     printf("Enter the no. of threads or processes: ");
//     scanf("%d", &n);

//     int resource[m];
//     printf("Enter the total types of each resource.\n");
//     for (int i = 0; i < m; i++) {
//         printf("Total resource %d: ", i + 1);
//         scanf("%d", &resource[i]);
//     }

//     int current_allocation[n][m];
//     printf("Enter current allocation of each type by each thread:\n");
//     for (int i = 0; i < n; i++) {
//         printf("Threads or processes %d: ", i + 1);
//         for (int j = 0; j < m; j++) {
//             scanf("%d", &current_allocation[i][j]);
//         }
//     }

//     int maximum_need[n][m], need[n][m];
//     printf("Enter maximum needed resources of each type by each thread:\n");
//     for (int i = 0; i < n; i++) {
//         printf("Threads or processes %d: ", i + 1);
//         for (int j = 0; j < m; j++) {
//             scanf("%d", &maximum_need[i][j]);
//             need[i][j] = maximum_need[i][j] - current_allocation[i][j];
//         }
//     }

//     int available[m];
//     for (int i = 0; i < m; i++) {
//         available[i] = resource[i];
//         for (int j = 0; j < n; j++) {
//             available[i] -= current_allocation[j][i];
//         }
//     }

//     print_table(m, n, resource, current_allocation, maximum_need, need, available);

//     int request_thread;
//     printf("Enter the thread number making the request: ");
//     scanf("%d", &request_thread);

//     int request[m];
//     printf("Enter the resource request vector for thread %d:\n", request_thread);
//     for (int i = 0; i < m; i++) {
//         printf("Resource %d: ", i + 1);
//         scanf("%d", &request[i]);
//     }

//     bool can_allocate = true;
//         for (int i = 0; i < m; i++) {
//         if (request[i] > need[request_thread - 1][i] || request[i] > available[i]) {
//             can_allocate = false;
//             break;
//         }
//     }

//     if (can_allocate) {
//         for (int i = 0; i < m; i++) {
//             current_allocation[request_thread - 1][i] += request[i];
//             need[request_thread - 1][i] -= request[i];
//             available[i] -= request[i];
//         }

//         int safe_sequence[n];
//         for (int i = 0; i < n; i++) {
//             safe_sequence[i] = -1;
//         }

//         if (is_safe_state(n, m, available, need, current_allocation, safe_sequence)) {
//             printf("Request can be granted. System is in a safe state.\n");
//         }
//         else {
//             printf("Request cannot be granted. System would be in an unsafe state.\n");
//         }
//     }
//     else {
//         printf("Request cannot be granted. Not enough resources available.\n");
//     }

//     // Part c) Detect Deadlock
//     int requests[n][m];
//     printf("Enter the n by m matrix of requests:\n");
//     for (int i = 0; i < n; ++i) {
//         printf("For thread %d: ", i + 1);
//         for (int j = 0; j < m; ++j) {
//             scanf("%d", &requests[i][j]);
//         }
//     }

//     if (detect_deadlock(n, m, available, need, current_allocation, requests)) {
//         printf("Deadlock detected.\n");
//     }
//     else {
//         printf("No deadlock detected.\n");
//     }

//     return 0;
// }