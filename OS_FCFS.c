#include <stdio.h>

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n, i;
    struct process p[10];
    int currentTime = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
    }

    for (i = 0; i < n; i++) {
        if (currentTime < p[i].at)
            currentTime = p[i].at;

        currentTime += p[i].bt;
        p[i].ct = currentTime;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        avgWT += p[i].wt;
        avgTAT += p[i].tat;
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
