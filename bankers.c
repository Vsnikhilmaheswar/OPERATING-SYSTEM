#include <stdio.h>
int main()
{

 
    int n, m, i, j, k,r,c;
    printf("Enter the number of process ");
    scanf("%d",&n);
       printf("Enter the Number of resources ");
    scanf("%d",&m);
int alloc[n][m];
for(r=0;r<n;r++)
{
printf("enter allocation of p%d ",r);
 for(c=0;c<m;c++)
  {
    scanf("%d",&alloc[r][c]);
  }
}

 
    int max[n][m];
 for(r=0;r<n;r++)
{
printf("enter max of p%d ",r);
 for(c=0;c<m;c++)
  {
    scanf("%d",&max[r][c]);
  }
}
int avail[m];

printf("enter Available Resources");
for(c=0;c<m;c++)
{
scanf("%d",&avail[c]);
}
      // n number of process
      //m no of Resources
 
    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < m; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
 
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                         break;
                    }
                }
 
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }
   
      int flag = 1;
       
      for(int i=0;i<n;i++)
    {
      if(f[i]==0)
      {
        flag=0;
         printf("The following system is not safe");
        break;
      }
    }
     printf("allocation\n");
     
      for(r=0;r<n;r++)
 {
     for(c=0;c<m;c++)
    {
      printf("%d ",alloc[r][c]);
 
    }
     printf("\n");
}    
printf("max\n");
for(r=0;r<n;r++)
 {
     for(c=0;c<m;c++)
    {
      printf("%d ",max[r][c]);

    }
      printf("\n");
}
printf("need\n");
for(r=0;r<n;r++)
 {
     for(c=0;c<m;c++)
    {
      printf("%d ",need[r][c]);
    }
       printf("\n");
}

      if(flag==1)
    {
      printf("Following is the SAFE Sequence\n");
      for (i = 0; i < n - 1; i++)
        printf(" P%d ->", ans[i]);
      printf(" P%d", ans[n - 1]);
    }
     
 
    return (0);
}
