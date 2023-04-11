
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
void philosopher(int i);
void think(int i);
void take_fork(int i, int x);
void eat(int i);
void put_fork(int i, int x);
void philosopher(int i)
{
 while(1)
 {
 int li,ri;
 li=i;
 ri=(i+1)%5;
 think(i);
 take_fork(i,ri);
 take_fork(i,li);
 eat(i);
 put_fork(i,ri);
 put_fork(i,li);
 }
}
void think(int i)
{
 printf("Philosopher %d is thinking.\n", i);
 sleep(3);
}
void take_fork(int i, int x)
{
 printf("Philosopher %d is hungry and wants to eat.\n", i);
 printf("Philosopher %d tries to pick up chopstick %d.\n", i,x);
 sleep(3);
}
void eat(int i)
{
 printf("Philosopher %d is eating.\n", i);
 sleep(3);
}
void put_fork(int i, int x)
{
 printf("Philosopher %d puts down chopstick %d.\n", i,x);
}
int main() {
 int i;
 for(i=0;i<5;i++)
 {
 if(fork()==0)
 {
 philosopher(i);
 }
 }
 return 0;
}