Write a shell program for addition of two numbers.

read -p "Enter first number: " num1 
read -p "Enter second number: " num2 
sum=$(( $num1 + $num2 )) 
echo "Sum is: $sum"

Write a shell program for largest of numbers

echo "Enter Size(N)"
read N
i=1
max=0
echo "Enter Numbers"
while [ $i -le $N ]
do
  read num
  if [ $i -eq 1 ]  #set first number as max
  then
      max=$num
  else             #from number 2 update max if the num > max.
      if [ $num -gt $max ]
      then
        max=$num
      fi
  fi
  i=$((i + 1))  #increment i by 1
done
echo $max

Write a shell program for  Unix commands using case

echo "Enter number:"
read num
case $num in
  1)
    echo "You chose the number one!"
    ;;
  2)
    echo "You chose the number two!"
    ;;
  3)
    echo "You chose the number three!"
    ;;
  *)
    echo "You chose something else!"
    ;;
esac
echo "End of script."

Write a shell program for factorial of a number

echo "Enter a number"
read num
fact=1
while [ $num -gt 1 ]
do
  fact=$((fact * num))  #fact = fact * num
  num=$((num - 1))      #num = num - 1
done
echo $fact

Write a shell program for Fibonacci series  of a number

echo "Program to Find Fibonacci Series"
  echo "How many number of terms to be generated ?"
  read n
  x=0
  y=1
  i=2
  echo "Fibonacci Series up to $n terms :"
  echo "$x"
  echo "$y"
  while [ $i -lt $n ]
  do
      i=`expr $i + 1 `
      z=`expr $x + $y `
      echo "$z"
      x=$y
      y=$z
  done

Write a shell program for largest digit from a number

echo "Enter Size(N)"
read N
i=1
max=0
echo "Enter Numbers"
while [ $i -le $N ]
do
  read num
  if [ $i -eq 1 ]  #set first number as max
  then
      max=$num
  else             #from number 2 update max if the num > max.
      if [ $num -gt $max ]
      then
        max=$num
      fi
  fi
  i=$((i + 1))  #increment i by 1
done
echo $max

Write a shell program for reverse digit of a number

echo enter n
read n
num=0
while [ $n -gt 0 ]
do
num=$(expr $num \* 10)
k=$(expr $n % 10)
num=$(expr $num + $k)
n=$(expr $n / 10)
done
echo number is $num

Write a shell program for display student grade details

clear  
echo Enter the Student name
read name
echo Enter the Register number
read rno
echo Enter the Mark1
read m1
echo Enter the Mark2
read m2
echo Enter the Mark3
read m3
echo Enter the Mark4
read m4
echo Enter the Mark5
read m5
tot=$(expr $m1 + $m2 + $m3 + $m4 + $m5)
avg=$(expr $tot / 5)
echo "Student Name    : $name"
echo "Register Number : $rno"
echo "Mark1           : $m1"
echo "Mark2           : $m2"
echo "Mark3           : $m3"
echo "Mark4           : $m4"
echo "Mark5           : $m5"
echo "Total           : $tot"
echo "Average         : $avg"
if [ $m1 -ge 35 ] && [ $m2 -ge 35 ] && [ $m3 -ge 35 ] && [ $m4 -ge 35 ] && [ $m5 -ge 35 ]
then
 echo "Result          : Pass"
  
 if [ $avg -ge 90 ]
 then
  echo "Grade           : S"
 elif [ $avg -ge 80 ]
 then
         echo "Grade           : A"
 elif [ $avg -ge 70 ]
 then
         echo "Grade           : B"
 elif [ $avg -ge 60 ]
 then
         echo "Grade           : C"
 elif [ $avg -ge 50 ]
 then
         echo "Grade           : D"
 elif [ $avg -ge 35 ]
 then
         echo "Grade           : E"
 fi
 else
  echo "Result          : Fail"
 fi

Write a shell program for calculate sum of N Numbers

echo "Enter Size(N)"
read N

i=1
sum=0

echo "Enter Numbers"
while [ $i -le $N ]
do
  read num           #get number
  sum=$((sum + num)) #sum+=num
  i=$((i + 1))
done

echo $sum

Write a shell program for find second largest numbers

echo “Enter the number of elements:” read n
a=0
b=0
for ((i = 1 ; i <= n ; i++)) do
echo “Enter the number:” read no
if [ $no -gt $a ] then
b=$a a=$no
elif [ $no -gt $b ] then
b=$no
fi
done
echo “The second highest number is : $b”
