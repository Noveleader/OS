Deadlock Detection Algorithm

#include <stdio.h>
#include <stdlib.h>

int arrmax[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input() {
int i, j;
printf("Enter the number of Processes\t");
scanf("%d", &n);
printf("Enter the number of Resource Instances\t");
scanf("%d", &r);
printf("Enter the Max Matrix\n");
for (i = 0; i < n; i++) {
for (j = 0; j < r; j++) {
scanf("%d", &arrmax[i][j]);
}
}
printf("Enter the Allocation Matrix\n");
for (i = 0; i < n; i++) {
for (j = 0; j < r; j++) {
scanf("%d", &alloc[i][j]);
}
}
printf("Enter the available Resources\n");
for (j = 0; j < r; j++) {
scanf("%d", &avail[j]);
}
}

void show() {
int i, j;
printf("Process\t Allocation\t Max\t Available\t");
for (i = 0; i < n; i++) {
printf("\nP%d\t", i);
for (j = 0; j < r; j++) {
printf("%d ", alloc[i][j]);
}
printf("\t\t");
for (j = 0; j < r; j++) {
printf("%d ", arrmax[i][j]);
}
printf("\t");
if (i == 0) {
for (j = 0; j < r; j++) {
printf("%d ", avail[j]);
}
}
}
}

void cal()
{
int finish[100], temp, need[100][100], flag = 1, k, c1 = 0;
int dead[100];
int safe[100];
int i, j;

for (i = 0; i < n; i++)
{
finish[i] = 0;
}

for (i = 0; i < n; i++)
{
for (j = 0; j < r; j++)
{
need[i][j] = arrmax[i][j] - alloc[i][j];
}
}

while (flag)
{
flag = 0;
for (i = 0; i < n; i++)
{
int c = 0;
for (j = 0; j < r; j++)
{
if ((finish[i] == 0) && (need[i][j] <= avail[j]))
{
c++;
if (c == r)
{
for (k = 0; k < r; k++)
{
avail[k] += alloc[i][j];
finish[i] = 1;
flag = 1;
}
safe[c1] = i;
c1++;
if (finish[i] == 1)
{
i = n;
}
}
}
}
}
}

printf("\n\nSafe sequence: ");
for (i = 0; i < n; i++)
{
if(safe[i]!=safe[i-1] || i==0){
printf("P%d ", safe[i]);
}
}

printf("\n\nTotal number of resources for each resource instance:\n");
for (j = 0; j < r; j++)
{
int total = 0;
for (i = 0; i < n; i++)
{
total += alloc[i][j];
}
printf("Resource %d: %d\n", j+1, total);
}

j = 0;
flag = 0;
for (i = 0; i < n; i++)
{
if (finish[i] == 0)
{
dead[j] = i;
j++;
flag = 1;
}
}
if (flag == 1)
{
printf("\nSystem is in deadlock and the deadlock processes are:\n");
for (i = 0; i < j; i++)
{
printf("P%d ", dead[i]);
}
printf("\n");
}
else
{
printf("\nNo deadlock occurs\n");
}
}

int main()
{
int i, j;
printf("Deadlock Detection Algorithm\n");
input();
show();
cal();
return 0;
}

Deadlock Detection Algorithm with Additional Allocation of Resources

#include <stdio.h>
#include <stdlib.h>

int arrmax[100][100];
int alloc[100][100];
int add[100][100];
int need[100][100];
int avail[100];
int n, r;

void input() {
int i, j;
printf("Enter the number of Processes\t");
scanf("%d", &n);
printf("Enter the number of Resource Instances\t");
scanf("%d", &r);
printf("Enter the Max Matrix\n");
for (i = 0; i < n; i++) {
for (j = 0; j < r; j++) {
scanf("%d", &arrmax[i][j]);
}
}
printf("Enter the Allocation Matrix\n");
for (i = 0; i < n; i++) {
for (j = 0; j < r; j++) {
scanf("%d", &alloc[i][j]);
}
}
printf("Enter the available Resources\n");
for (j = 0; j < r; j++) {
scanf("%d", &avail[j]);
}
printf("Enter the Additional Resouce Matrix\n");
for (i = 0; i < n; i++) {
for (j = 0; j < r; j++) {
scanf("%d", &add[i][j]);
alloc[i][j]+=add[i][j];
avail[j]-=add[i][j];
}
}
}

void show() {
int i, j;
printf("Process\t\t Allocation\t Max\t Available\t\t");
for (i = 0; i < n; i++) {
printf("\nP%d\t\t", i);
for (j = 0; j < r; j++) {
printf("%d ", alloc[i][j]);
}
printf("\t");
for (j = 0; j < r; j++) {
printf("%d ", arrmax[i][j]);
}
printf("\t");
if (i == 0) {
for (j = 0; j < r; j++) {
printf("%d ", avail[j]);
}
}
}
}

void cal()
{
int finish[100], temp, need[100][100], flag = 1, k, c1 = 0;
int dead[100];
int safe[100];
int i, j;

for (i = 0; i < n; i++)
{
finish[i] = 0;
}

for (i = 0; i < n; i++)
{
for (j = 0; j < r; j++)
{
need[i][j] = arrmax[i][j] - alloc[i][j];
}
}

while (flag)
{
flag = 0;
for (i = 0; i < n; i++)
{
int c = 0;
for (j = 0; j < r; j++)
{
if ((finish[i] == 0) && (need[i][j] <= avail[j]))
{
c++;
if (c == r)
{
for (k = 0; k < r; k++)
{
avail[k] += alloc[i][j];
finish[i] = 1;
flag = 1;
}
safe[c1] = i;
c1++;
if (finish[i] == 1)
{
i = n;
}
}
}
}
}
}

printf("\n\nSafe sequence: ");
for (i = 0; i < n; i++)
{
if(safe[i]!=safe[i-1] || i==0){
printf("P%d ", safe[i]);
}
}

printf("\n\nTotal number of resources for each resource instance:\n");
for (j = 0; j < r; j++)
{
int total = 0;
for (i = 0; i < n; i++)
{
total += alloc[i][j];
}
printf("Resource %d: %d\n", j+1, total);
}

j = 0;
flag = 0;
for (i = 0; i < n; i++)
{
if (finish[i] == 0)
{
dead[j] = i;
j++;
flag = 1;
}
}
if (flag == 1)
{
printf("\nSystem is in deadlock and the deadlock processes are:\n");
for (i = 0; i < j; i++)
{
printf("P%d ", dead[i]);
}
printf("\n");
}
else
{
printf("\nNo deadlock occurs\n");
}
}

int main()
{
int i, j;
printf("Deadlock Detection Algorithm\n");
input();
show();
cal();
return 0;
}

Producer Consumer Problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 10

int mutex = 1;
int full = 0;
int empty = BUFFER_SIZE;
int item_count = 0;
char buffer[BUFFER_SIZE][50];

void producer(char *item_name) {
--mutex;
++full;
--empty;

strcpy(buffer[item_count], item_name);
printf("\nProducer produces item %d: %s", item_count + 1, item_name);
++item_count;

++mutex;
}

void consumer() {
--mutex;
--full;
++empty;

printf("\nConsumer consumes item %d: %s", item_count, buffer[item_count-1]);
--item_count;

++mutex;
}

int main() {
int choice;
char item_name[50];

while (1) {
printf("\n1. Press 1 for Producer");
printf("\n2. Press 2 for Consumer");
printf("\n3. Press 3 for Exit");
printf("\nEnter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
if (mutex == 1 && empty != 0) {
printf("Enter item name: ");
scanf("%s", item_name);
producer(item_name);
} else {
printf("Buffer is full!\n");
}
break;

case 2:
if (mutex == 1 && full != 0) {
consumer();
} else {
printf("Buffer is empty!\n");
}
break;

case 3:
exit(0);
break;

default:
printf("Invalid choice!\n");
}
}

return 0;
}

Reader-Writer Problem

#include<semaphore.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
sem_t x,y;
pthread_t tid;
pthread_t writerthreads[100],readerthreads[100];
int readercount = 0;

void *reader(void* param)
{
sem_wait(&x);
readercount++;
if(readercount==1)
sem_wait(&y);
sem_post(&x);
printf("%d reader is inside\n",readercount);
usleep(3);
sem_wait(&x);
readercount--;
if(readercount==0)
{
sem_post(&y);
}
sem_post(&x);
printf("%d Reader is leaving\n",readercount+1);
return NULL;
}

void *writer(void* param)
{
printf("Writer is trying to enter\n");
sem_wait(&y);
printf("Writer has entered\n");
sem_post(&y);
printf("Writer is leaving\n");
return NULL;
}

int main()
{
int n2,i;
printf("Enter the number of readers:");
scanf("%d",&n2);
printf("\n");
int n1[n2];
sem_init(&x,0,1);
sem_init(&y,0,1);
for(i=0;i<n2;i++)
{
pthread_create(&writerthreads[i],NULL,reader,NULL);
pthread_create(&readerthreads[i],NULL,writer,NULL);
}
for(i=0;i<n2;i++)
{
pthread_join(writerthreads[i],NULL);
pthread_join(readerthreads[i],NULL);
}

}
