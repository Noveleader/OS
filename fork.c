Create process and print parent ID and child ID

#include<stdio.h
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t p;
p=fork();
if(p==0) //child
{
printf("I am child having PID %d\n",getpid());
printf("My parent PID is %d\n",getppid());
}
else //parent
{
printf("I am parent having PID %d\n",getpid());
printf("My child PID is %d\n",p);
}
}

Create an orphan process program

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
pid_t p;
p=fork();
if(p==0)
{
sleep(5); //child goes to sleep and in the mean time parent terminates
printf("I am child having PID %d\n",getpid());
printf("My parent PID is %d\n",getppid());
}
else
{
printf("I am parent having PID %d\n",getpid());
printf("My child PID is %d\n",p);
}
}

Write a C program using Wait() system call

#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
int main()
{
pid_t p;
printf("before fork\n");
p=fork();
if(p==0)//child
{
printf("I am child having id %d\n",getpid());
printf("My parent's id is %d\n",getppid());
}
else//parent
{
wait(NULL);
printf("My child's id is %d\n",p);
printf("I am parent having id %d\n",getpid());
}
printf("Common\n");
}

Create a process and compute factorial in child and Fibonacci in parent as executable

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
int n;
int a=0,b=1,c=1;
pid_t p;
scanf("%d",&n);
int m=n;
p=fork();
if(p==0)//child
{
printf("I am child having id %d\n",getpid());
for (int i=1;i<n+1;i++){
c*=i;
}
printf("Factorial of %d is: %d\n",m,c);
}
else{//parent
printf("I am parent having id %d\n",getpid());
printf("Fibonacci sequence upto %d: ",m);
if (m==1){
printf("%d ",a);
}
else if (m==2){
printf("%d %d",a,b);
}
else {
printf("%d ",a);
printf("%d ",b);
for(int i=0;i<n-2;i++){
if(a>b){
b+=a;
printf("%d ",b);}
else{
a+=b;
printf("%d ",a);}
}
printf("\n");
}
}
}

Create a process and let the child do some task like computing sum of N numbers

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
int n,sum=0;
pid_t p;
scanf("%d",&n);
int a[n];
for (int i=0;i<n;i++){
scanf("%d",&a[i]);
}
p=fork();
if(p==0)//child
{
printf("I am child having id %d\n",getpid());
for (int i=0;i<n;i++){
sum+=a[i];
}
printf("Sum of the entered %d numbers is: %d\n",n,sum);
}
else{//parent
printf("I am parent having id %d\n",getpid());
}
}

Palindrome and odd or even as parent and child with fork

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
int n, reversed = 0, remainder, original;
scanf("%d", &n);
original = n;
pid_t p;
p=fork();
if(p==0)//child
{
printf("I am child having id %d\n",getpid());
if(n%2==0){
printf("%d is an even number\n",n);
}
else{
printf("%d is an odd number\n",n);
}
}
else{//parent
printf("I am parent having id %d\n",getpid());
// reversed integer is stored in reversed variable
while (n != 0) {
remainder = n % 10;
reversed = reversed * 10 + remainder;
n /= 10;
}

// palindrome if orignal and reversed are equal
if (original == reversed)
printf("%d is a palindrome\n", original);
else
printf("%d is not a palindrome\n", original);
}
}
