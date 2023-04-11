#include <stdio.h>
// Function to find the waiting time for all processes
int waitingtime(int proc[], int n,
int burst_time[], int wait_time[]) {
// waiting time for first process is 0
wait_time[0] = 0;
// calculating waiting time
for (int i = 1; i < n ; i++ )
wait_time[i] = burst_time[i-1] + wait_time[i-1] ;
return 0;
}
// Function to calculate turn around time
int turnaroundtime( int proc[], int n,
int burst_time[], int wait_time[], int tat[]) {
// calculating turnaround time by adding
// burst_time[i] + wait_time[i]
int i;
for ( i = 0; i < n ; i++)
tat[i] = burst_time[i] + wait_time[i];
return 0;
}
//Function to calculate average time
int avgtime( int proc[], int n, int burst_time[]) {
int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
int i;
//Function to find waiting time of all processes
waitingtime(proc, n, burst_time, wait_time);
//Function to find turn around time for all processes
turnaroundtime(proc, n, burst_time, wait_time, tat);
//Display processes along with all details
printf("Processes  Burst   Waiting Turn around \n");
// Calculate total waiting time and total turn
// around time
for ( i=0; i<n; i++) {
total_wt = total_wt + wait_time[i];
total_tat = total_tat + tat[i];
printf(" %d\t  %d\t\t %d \t%d\n", i+1, burst_time[i], wait_time[i], tat[i]);
}
printf("Average waiting time = %f\n", (float)total_wt / (float)n);
printf("Average turn around time = %f\n", (float)total_tat / (float)n);
return 0;
}
// main function
int main() {
//process id's
int proc[] = { 1, 2, 3};
int n = sizeof proc / sizeof proc[0];
//Burst time of all processes
int burst_time[] = {5, 8, 12};
avgtime(proc, n, burst_time);
return 0;
}

Shortest-Job-Next (SJN) Scheduling

#include <stdio.h>
int main()
{
int A[100][4]; // Matrix for storing Process Id, Burst
// Time, Average Waiting Time & Average
// Turn Around Time.
int i, j, n, total = 0, index, temp;
float avg_wt, avg_tat;
printf("Enter number of process: ");
scanf("%d", &n);
printf("Enter Burst Time:\n");
// User Input Burst Time and alloting Process Id.
for (i = 0; i < n; i++) {
printf("P%d: ", i + 1);
scanf("%d", &A[i][1]);
A[i][0] = i + 1;
}
// Sorting process according to their Burst Time.
for (i = 0; i < n; i++) {
index = i;
for (j = i + 1; j < n; j++)
if (A[j][1] < A[index][1])
index = j;
temp = A[i][1];
A[i][1] = A[index][1];
A[index][1] = temp;

temp = A[i][0];
A[i][0] = A[index][0];
A[index][0] = temp;
}
A[0][2] = 0;
// Calculation of Waiting Times
for (i = 1; i < n; i++) {
A[i][2] = 0;
for (j = 0; j < i; j++)
A[i][2] += A[j][1];
total += A[i][2];
}
avg_wt = (float)total / n;
total = 0;
printf("P     BT     WT     TAT\n");
// Calculation of Turn Around Time and printing the
// data.
for (i = 0; i < n; i++) {
A[i][3] = A[i][1] + A[i][2];
total += A[i][3];
printf("P%d     %d     %d      %d\n", A[i][0],
A[i][1], A[i][2], A[i][3]);
}
avg_tat = (float)total / n;
printf("Average Waiting Time= %f", avg_wt);
printf("\nAverage Turnaround Time= %f", avg_tat);
}

Shortest Remaining Time First (Preemptive SJF) Scheduling

#include<stdio.h>
int main()
{
int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
float avg_wt,avg_tat;
printf("Enter number of process:");
scanf("%d",&n);

printf("\nEnter Burst Time:\n");
for(i=0;i<n;i++)
{
printf("p%d:",i+1);
scanf("%d",&bt[i]);
p[i]=i+1;         
}

//sorting of burst times
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
if(bt[j]<bt[pos])
pos=j;
}

temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;

temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}

wt[0]=0;            


for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];

total+=wt[i];
}

avg_wt=(float)total/n;      
total=0;

printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];   
total+=tat[i];
printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
}

avg_tat=(float)total/n;    
printf("\n\nAverage Waiting Time=%f",avg_wt);
printf("\nAverage Turnaround Time=%f\n",avg_tat);
}

Round Robin (RR) Scheduling

#include<stdio.h>

int main()
{
int i, limit, total = 0, x, counter = 0, time_quantum;
int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
float average_wait_time, average_turnaround_time;
printf("\nEnter Total Number of Processes:\t");
scanf("%d", &limit);
x = limit;
for(i = 0; i < limit; i++)
{
printf("\nEnter Details of Process[%d]\n", i + 1);

printf("Arrival Time:\t");

scanf("%d", &arrival_time[i]);

printf("Burst Time:\t");

scanf("%d", &burst_time[i]);

temp[i] = burst_time[i];
}

printf("\nEnter Time Quantum:\t");
scanf("%d", &time_quantum);
printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
for(total = 0, i = 0; x != 0;)
{
if(temp[i] <= time_quantum && temp[i] > 0)
{
total = total + temp[i];
temp[i] = 0;
counter = 1;
}
else if(temp[i] > 0)
{
temp[i] = temp[i] - time_quantum;
total = total + time_quantum;
}
if(temp[i] == 0 && counter == 1)
{
x--;
printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
wait_time = wait_time + total - arrival_time[i] - burst_time[i];
turnaround_time = turnaround_time + total - arrival_time[i];
counter = 0;
}
if(i == limit - 1)
{
i = 0;
}
else if(arrival_time[i + 1] <= total)
{
i++;
}
else
{
i = 0;
}
}

average_wait_time = wait_time * 1.0 / limit;
average_turnaround_time = turnaround_time * 1.0 / limit;
printf("\n\nAverage Waiting Time:\t%f", average_wait_time);
printf("\nAvg Turnaround Time:\t%f\n", average_turnaround_time);
return 0;
}

Priority Scheduling

#include <stdio.h>

void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}
int main()
{
int n;
printf("Enter Number of Processes: ");
scanf("%d",&n);

int burst[n],priority[n],index[n];
for(int i=0;i<n;i++)
{
printf("Enter Burst Time and Priority Value for Process %d: ",i+1);
scanf("%d %d",&burst[i],&priority[i]);
index[i]=i+1;
}
for(int i=0;i<n;i++)
{
int temp=priority[i],m=i;

for(int j=i;j<n;j++)
{
if(priority[j] > temp)
{
temp=priority[j];
m=j;
}
}

swap(&priority[i], &priority[m]);
swap(&burst[i], &burst[m]);
swap(&index[i],&index[m]);
}

int t=0;

printf("Order of process Execution is\n");
for(int i=0;i<n;i++)
{
printf("P%d is executed from %d to %d\n",index[i],t,t+burst[i]);
t+=burst[i];
}
printf("\n");
printf("Process Id\tBurst Time\tWait Time\n");
int wait_time=0;
int total_wait_time = 0;
for(int i=0;i<n;i++)
{
printf("P%d\t\t%d\t\t%d\n",index[i],burst[i],wait_time);
total_wait_time += wait_time;
wait_time += burst[i];
}

float avg_wait_time = (float) total_wait_time / n;
printf("Average waiting time is %f\n", avg_wait_time);

int total_Turn_Around = 0;
for(int i=0; i < n; i++){
total_Turn_Around += burst[i];
}
float avg_Turn_Around = (float) total_Turn_Around / n;
printf("Average TurnAround Time is %f\n",avg_Turn_Around);
return 0;
}
]
