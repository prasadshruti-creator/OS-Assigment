#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#define max 30
int i,j,n,t,k,bt[max],wt[max],tat[max],rt[max],pr[max],pos;
float awt=0,atat=0;
void getInput();
void roundRobin();
void priorityScheduling();
void fCFS();
void calculateTime();
void getInput(){
printf("enter the no of process");
scanf("%d",&n);
printf("enter the burst time of the process");
for(i=0;i<n;i++)
{
scanf("%d",&bt[i]);
rt[i]=bt[i];
}
printf("enter the priority of the process");
for(i=0;i<n;i++)
{
scanf("%d",&pr[i]);
return ;
}
}
void calculateTime(){
int rp=n;

printf("process\t burst time\t waiting time\t turnaround time\n");

for (i=0;i<n;i++)
{
wt[i]=0;
tat[i]=0;
for(j=0;j<i;j++)
{

  if(bt[j]<=10)
     {
    wt[i]=wt[i]+bt[j];
    bt[j]=bt[j]-bt[j];
     }
   else 
    {
    wt[i]=wt[i]+10;
    bt[j]=bt[j]-10;
    rp--;
    }
  
}


tat[i]=wt[i]+bt[j];
awt=awt+wt[i];
atat=atat+tat[i];
printf("%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);

}

awt=awt/n;
atat=atat/n;
printf("Average waiting time=%f\n",awt);
printf("Average turnaround time=%f\n",atat);


}
void fCFS()
{
printf("FCFS Scheduling are:\n");
calculateTime();
}
void priorityScheduling(){
printf("priority scheduling\n");
for(i=0;i<n;i++)
 {
  pos=i;
  for(j=i+1;j<n;j++)
  {
   if (pr[j]<pr[pos]){
     pos=j;
          }
    }
  t=pr[i];
  pr[i]=pr[pos];
  pr[pos]=t;
  t=bt[i];
  bt[i]=bt[pos];
  bt[pos]=t;
  }
 calculateTime();
}
void roundRobin(){
int rp=n;
i=0;
int q=4;
t=0;
printf("0");
while(rp!=0)
{

wt[i]=0;
 if(rt[i]>q)
  {
   rt[i]=rt[i]-q;
  printf("|p[%d",(i+1));
printf("]\t");
  t=t+q;
 printf("%d",t);

  }
else if(rt[i]<=q && rt[i]>0)
  {
   t=t+rt[i];
  rt[i]=rt[i]-rt[i];
  printf("|p[%d",(i+1));
printf("]|");
  rp--;
  printf("%d",t);
tat[i]=t;
  
wt[i]=tat[i]-bt[i];

//printf("waiting time=%d\t",wt[i]);
atat=atat+tat[i];
awt=awt+wt[i];
}
i++;
if (i==n)
 {
 i=0;
 }
}
awt=awt/n;
atat=atat/n;
printf("Average waiting time=%f\n",awt);
printf("average turn around time=%f\n",atat);

}
void main()
{
getInput();

k=1;

while(k<=n){
 
switch(1){
//for lowest pririty range of queue
case 1: fCFS();
         
       
 //for middle pririty range of queue       
case 2:
       priorityScheduling();
       
       
//for highest pririty range of queue
case 3: roundRobin();
         break;
              
        
}
}
k++;
sleep(10);

}

