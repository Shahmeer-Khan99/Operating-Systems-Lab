#include <stdio.h>

struct PCB
{
    int pid, burst, turnaround;
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
        printf("Enter burst time for process %d : \n", i+1);
        scanf("%d", &p[i].burst);
        p[i].pid = i+1;

    }

    for (i=0; i<num; i++)
    {
        sum += p[i].burst;
        p[i].turnaround = sum; 
    }

    sum = 0;
    printf("PID\tBurst\tTurnaround\n");
    for (i=0; i<num; i++)
    {
        printf("%d\t%d\t%d\n", p[i].pid, p[i].burst, p[i].turnaround);
        sum += p[i].turnaround;
        
    }

    avg = sum/(float)num;
    printf("\nTotal turnaround time: %f", sum);
    printf("\nAverage turnaround time: %f", avg);


}
