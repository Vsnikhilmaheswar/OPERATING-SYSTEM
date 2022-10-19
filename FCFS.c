//******************************//
//AUTHOR  : VS NIKHIL MAHESWAR  //
//DATE    : 19th JUNE 2022      //
//PROGRAM : FCFS IMPLEMENTATION //
//******************************//
#include<stdio.h>
#include <stdlib.h>
struct fcfs {
    
    int pid;
    int btime;
    int wtime;
    int ttime;
    
}

   p[10];
    int main() {
        
        int i,n;
        int totwtime = 0, totttime = 0;
        printf("\n FCFS SCHEDULING...\n");
        printf("Enter the num of process");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            printf("enter the process id ");
            scanf("%d",&p[i].pid);
            printf( " Burst time of the process");
            scanf("%d",&p[i].btime);    
        }
       
        
    for (i = 0; i <n; i++)
    {
     
    
    
            p[i].wtime=p[i-1].wtime+p[i-1].btime;
            p[i].ttime=p[i].wtime+p[i].btime;
            totttime+=p[i].ttime;
            totwtime+=p[i].wtime;
    }    
    printf("0 ");
    for(i=0;i<n;i++)
    {
        printf(" p%d | %d ",p[i].pid,p[i].ttime);
    }
        printf("\n Total waiting time:%d\n",totwtime);
        printf("\n Average waiting time:%d\n",totwtime/n);
        printf("\n Total turn around time:%d\n",totttime);
        printf("\n Average turn around time:%d\n",totwtime/n);
    }
