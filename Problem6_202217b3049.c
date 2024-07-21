#include <stdio.h>

// Function to calculate waiting time and turnaround time
void calculateTimes(int n, int burst_time[], int arrival_time[], int waiting_time[], int turnaround_time[]) {
    int completion_time[10];
    completion_time[0] = arrival_time[0] + burst_time[0];
    
    for (int i = 1; i < n; i++) {
        if (arrival_time[i] > completion_time[i-1]) {
            completion_time[i] = arrival_time[i] + burst_time[i];
        } else {
            completion_time[i] = completion_time[i-1] + burst_time[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = completion_time[i] - arrival_time[i];
        waiting_time[i] = turnaround_time[i] - burst_time[i];
    }
}

int main() {
    int n, i;
    int burst_time[10], arrival_time[10], waiting_time[10], turnaround_time[10];
    float total_wt = 0, total_tt = 0;

    // Initialize arrays
    for(i = 0; i < 10; i++) {
        burst_time[i] = 0;
        arrival_time[i] = 0;
        waiting_time[i] = 0;
        turnaround_time[i] = 0;
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times: ");
    for(i = 0; i < n; i++)
        scanf("%d", &burst_time[i]);

    printf("Enter the arrival times: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arrival_time[i]);

    // Calculate waiting time and turnaround time
    calculateTimes(n, burst_time, arrival_time, waiting_time, turnaround_time);

    // Calculate total waiting time and total turnaround time
    for(i = 0; i < n; i++) {
        total_wt += waiting_time[i];
        total_tt += turnaround_time[i];
    }

    // Calculate average waiting time and average turnaround time
    float avg_wt = total_wt / n;
    float avg_tt = total_tt / n;

    // Display results
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i, waiting_time[i], turnaround_time[i]);
    }
    printf("The average waiting time is %f\n", avg_wt);
    printf("The average turnaround time is %f\n", avg_tt);

    return 0;
}
