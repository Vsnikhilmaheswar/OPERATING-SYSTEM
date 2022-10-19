#include<stdio.h>
struct sjf
{
    int pid;
    int btime;
    int wtime;
    int ttime;
    int priority;
}
p[10];
int main()
{
    int i,n,j;
    struct sjf tmp;
    int totwtime=0,totttime=0;
    printf("enter the number of process");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter process id: P");
        scanf("%d",&p[i].pid);
        printf("enter burst time");
        scanf("%d",&p[i].btime);
        printf("enter priority");
        scanf("%d",&p[i].priority);
    }
    p[0].wtime=0;
    p[0].ttime=p[0].btime;
    for ( i = 0; i <n-1; i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i].priority>p[j].priority)
            {
             tmp=p[i];
             p[i]=p[j];
             p[j]=tmp;
            }
        }
    }
    for ( i = 0; i < n; i++)
    {
        p[i].wtime=p[i-1].wtime+p[i-1].btime;
        p[i].ttime=p[i].wtime+p[i].btime;
        totttime+=p[i].ttime;
        totwtime+=p[i].wtime;
    }

    printf("pid     burst   wt    tat\n");
for ( i = 0; i < n; i++)
{
printf("%d    %d     %d     %d\n",p[i].pid,p[i].btime,p[i].wtime,p[i].ttime);
}
printf("\n");
   printf("0 ");
    for(i=0;i<n;i++)
    {
        printf(" p%d | %d ",p[i].pid,p[i].ttime);
    }
     
}
