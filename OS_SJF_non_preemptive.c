#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int completed;
};

int main() {
    int n, i, completed = 0;
    int currentTime = 0, minBT, idx;
    float avgWT = 0, avgTAT = 0;

    struct process p[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].completed = 0;
    }

    while (completed < n) {
        minBT = 9999;
        idx = -1;

        for (i = 0; i < n; i++) {
            if (p[i].at <= currentTime && !p[i].completed && p[i].bt < minBT) {
                minBT = p[i].bt;
                idx = i;
            }
        }

        if (idx == -1) {
            currentTime++;
        } else {
            currentTime += p[idx].bt;
            p[idx].ct = currentTime;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = 1;

            avgWT += p[idx].wt;
            avgTAT += p[idx].tat;
            completed++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}
