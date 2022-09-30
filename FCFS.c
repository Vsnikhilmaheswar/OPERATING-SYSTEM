//******************************//
//AUTHOR  : VS NIKHIL MAHESWAR  //
//DATE    : 19th JUNE 2022      //
//PROGRAM : FCFS IMPLEMENTATION //
//******************************//
#include<stdio.h>
int wt[4];
int TAT[3];
void WAIT(int process,int bur[])//calculating waiting time
{
int i;
wt[0]=0;
for(i=1;i<process;i++)
{
wt[i]=wt[i-1]+bur[i-1];
}
}
void TURNATIME(int process,int burstt[]) // calculating the turn around time
{
    int K,sum=0;
        
    for ( K= 0; K < process; K++)
    {
      sum=sum+burstt[K];
      TAT[K]=sum;   
    }
    
}


void display(int wt[],int process,int burst[],int TAT[]) // display the results
{
    int j;
 printf("PROCESS         BURST          W.T          T.A.T\n");

    for ( j = 0; j < process; j++)
{
    printf("%d\t\t%d\t\t%d\t\t%d",j,burst[j],wt[j],TAT[j]);
    printf("\n");
}
}
// main funtion
int main()
{   int process;
    printf("enter the number of process");
    scanf("%d",&process);
    int i, burst[process];
    printf("enter the %d process",process);
    for ( i = 0; i <process; i++)
    {
        scanf("%d",&burst[i]);
    }
float awt=0,atat=0;
    WAIT(process,burst);
       TURNATIME(process,burst);
   display(wt,process,burst,TAT);

   for ( i = 0; i < process; i++)
   {
      awt=awt+wt[i];
      atat=atat+TAT[i]; 
   }
   printf("total waiting time = %f \n",awt);
   printf("total turn around time = %f \n",atat);
   printf("avg waiting time = %f\n",awt/process);
   printf("avg turn around time = %f",atat/process);
 printf("\n");
   printf("______________________________\n");
   printf("|0 ");
   for(i=0;i<process;i++)
   {
   printf("p%d  %d|",i,TAT[i]);
   
   } 
printf("\n");
printf("-------------------------------");
}
