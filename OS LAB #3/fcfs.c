#include <stdio.h>

struct PCB
{
    int pid, arrival, burst, turnaround;
};

void main()
{
    int i,j,num;
    
    float avg=0.0, sum=0.0;
    struct PCB p[10], temp;

    printf("Enter total number of processes:");
    scanf("%d", &num);

    for (i=0; i<num; i++)
    {
        printf("Enter arrival time and burst time for process %d : \n", i+1);
        scanf("%d %d", &p[i].arrival,&p[i].burst);
        p[i].pid = i+1;

    }

    for (i=0;i<num;i++)
    {
        for (j=0;j<num-i-1;j++)
        {
            if (p[j].arrival>p[j+1].arrival)
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }

    }

    for (i=0; i<num; i++)
    {
        sum += p[i].burst;
        p[i].turnaround = sum; 
    }

    sum = 0;
    printf("PID\tArrival\tBurst\tTurnaround\n");
    for (i=0; i<num; i++)
    {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival,p[i].burst, p[i].turnaround);
        sum += p[i].turnaround;
        
    }

    avg = sum/(float)num;
    printf("\nTotal turnaround time: %f", sum);
    printf("\nAverage turnaround time: %f", avg);


}
