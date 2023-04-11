Create two threads thread1 and thread2 and call functions fun1 and fun2 respectively.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *print_message_function(void *ptr){
char *message;
message=(char*)ptr;
printf("%s \n",message);
}
int main()
{
pthread_t thread1, thread2;
char *message1="thread 1";
char *message2="thread 2";
int ir1, ir2;
ir1=pthread_create(&thread1,NULL,print_message_function,(void*)message1);
ir2=pthread_create(&thread2,NULL,print_message_function,(void*)message2);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("Thread 1 returns : %d\n",ir1);
printf("Thread 2 returns : %d\n",ir2);
exit(0);
}

Create two threads thread1 and thread2 and call functions fun1 and fun2 respectively. Compute and print Fibonacci in fun1 and square of a number in fun2.

#include <stdio.h>                    
#include <stdlib.h>                  
#include <pthread.h>
void *fun1(void *ptr){
int value = *((int*)ptr),n1=0,n2=1,n3;
printf("Fibonacci series upto %d numbers is : ",value);
printf(" %d %d",0,1);
for (int i=2;i<value;i++){
n3 = n1 + n2;
printf(" %d",n3);
n1=n2;
n2=n3;
}
}
void *fun2(void *ptr){
int value = *((int*)ptr),sq;
sq=value*value;
printf("\nSquare of a %d is = %d\n", value, sq);
}
int main()
{
pthread_t thread1, thread2;
int n1;
scanf("%d",&n1);
int n2 = n1;
int ir1, ir2;
ir1=pthread_create(&thread1,NULL,fun1,(void*)&n1);
ir2=pthread_create(&thread2,NULL,fun2,(void*)&n2);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("\nThread 1 returns : %d\n",ir1);
printf("Thread 2 returns : %d\n",ir2);
exit(0);
}

Create two threads thread1 and thread2 and call functions fun1 and fun2 respectively. Compute and print Factorial in fun1 and prime number in fun2.

#include <stdio.h>
#include <stdlib.h>                         
#include <pthread.h>                            
void *fun1(void *ptr){
int value = *((int*)ptr),n1=1;
for (int i=1;i<=value;i++){
n1=n1*i;
}
printf("Factorial of %d is: %d\n",value,n1);
}
void *fun2(void *ptr){
int num = *((int*)ptr);
int i, p = 0;
   for(i=1; i<=num; i++)
   {
      if(num%i==0)
      {
         p++;
      }
   }
   if(p==2)
   {
      printf("Entered number is %d "\
             "and it is a prime number.\n",num);
   }
   else
   {
      printf("Entered number is %d "\
             "and it is not a prime number.\n",num);
   }
}
int main()
{
pthread_t thread1, thread2;
int n1;
scanf("%d",&n1);
int n2=n1;
int ir1, ir2;
ir1=pthread_create(&thread1,NULL,fun1,(void*)&n1);
ir2=pthread_create(&thread2,NULL,fun2,(void*)&n2);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("Thread 1 returns : %d\n",ir1);
printf("Thread 2 returns : %d\n",ir2);
exit(0);
}

Create two threads thread1 and thread2 and call functions fun1 and fun2 respectively. Compute and print Armstrong number or not in fun1 and reverse number in fun2.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *fun1(void *ptr){
int arms = *((int*)ptr);
   int check, rem, sum = 0;
   check = arms;
   while(check != 0) {
      rem = check % 10;
      sum = sum + (rem * rem * rem);
      check = check / 10;
   }

   if(sum == arms) 
      printf("%d is an armstrong number.\n", arms);
   else 
      printf("%d is not an armstrong number.\n", arms);
}
void *fun2(void *ptr){
int n = *((int*)ptr);
  int rev_num = 0;
  while (n != 0) {
    rev_num = rev_num * 10 + n % 10;
    n = n / 10;
  }
  printf("%d\n", rev_num);
}
int main()
{
pthread_t thread1, thread2;
int n1;
scanf("%d",&n1);
int n2 = n1;
int ir1, ir2;
ir1=pthread_create(&thread1,NULL,fun1,(void*)&n1);
ir2=pthread_create(&thread2,NULL,fun2,(void*)&n2);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("Thread 1 returns : %d\n",ir1);
printf("Thread 2 returns : %d\n",ir2);
exit(0);
}
