#include <stdio.h>

struct process
{
    char pid[5];
    int at, bt, pr;
    int wt, tat, ct;
};

int main()
{
    int n,i,j,time=0,completed=0;
    float total_wt=0,total_tat=0;

    struct process p[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter PID AT BT PR: ");
        scanf("%s %d %d %d",p[i].pid,&p[i].at,&p[i].bt,&p[i].pr);
    }

    int done[20]={0};

    while(completed<n)
    {
        int idx=-1;
        int highest=9999;

        for(i=0;i<n;i++)
        {
            if(p[i].at<=time && done[i]==0)
            {
                if(p[i].pr < highest)
                {
                    highest=p[i].pr;
                    idx=i;
                }
            }
        }

        if(idx!=-1)
        {
            time+=p[idx].bt;
            p[idx].ct=time;

            p[idx].tat=p[idx].ct-p[idx].at;
            p[idx].wt=p[idx].tat-p[idx].bt;

            total_wt+=p[idx].wt;
            total_tat+=p[idx].tat;

            done[idx]=1;
            completed++;
        }
        else
        {
            time++;
        }
    }

    printf("\nWaiting Time:\n");
    for(i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].wt);

    printf("\nTurnaround Time:\n");
    for(i=0;i<n;i++)
        printf("%s %d\n",p[i].pid,p[i].tat);

    printf("\nAverage Waiting Time: %.2f",total_wt/n);
    printf("\nAverage Turnaround Time: %.2f",total_tat/n);

    return 0;
}
