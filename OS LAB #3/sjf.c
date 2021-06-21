#include <stdio.h>

struct PCB
{
    int pid, wait, burst, turnaround;
};

void main()
{
    int i,j=1,n,sum=0,w_total=0,t_total=0;
    
    float w_avg=0.0, t_avg=0.0;
    struct PCB p[10], temp;

    printf("Enter total number of processes:");
    scanf("%d", &n);

    for (i=0; i<n; i++)
    {
        printf("Enter burst time for process %d : \n", i+1);
        scanf("%d", &p[i].burst);
        p[i].pid = i+1;

    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<n-i-1;j++)
        {
            if (p[j].burst>p[j+1].burst)
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }

    }
    for (i=0; i<n; i++)
    {
        p[i].wait = sum; 
        sum += p[i].burst;
        p[i].turnaround = sum;
    }

    printf("PID\tBurst\tWait\tTurnaround\n");
    for (i=0; i<n; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].burst, p[i].wait, p[i].turnaround);
        w_total += p[i].wait;
        t_total += p[i].turnaround;
        
    }

    w_avg = w_total/(float)n;
    t_avg = t_total/(float)n;

    printf("\nTotal waiting time: %d", w_total);
    printf("\nAverage average time: %f", w_avg);

    printf("\nTotal turnaround time: %d", t_total);
    printf("\nAverage turnaround time: %f", t_avg);


}
