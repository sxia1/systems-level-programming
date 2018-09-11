//Sophia Xia
//Systems pd4
//Work 01: If you're feeling rusty, apply eul.
//2018-09-08

#include <stdio.h>
#include <stdlib.h>

//Problem 1: Multiples of 3 and 5
//Find the sum of all the multiples of 3 or 5 below 1000.
int mult_h(int a, int b){
  int ctr = 1;
  int ret_val = 0;
  while(a * ctr < b){
    ret_val += (a*ctr);
    ctr ++;
  }
  return ret_val;
}

int mult(int a, int b, int c){
  int ret_val = 0;
  ret_val = mult_h(a,c) + mult_h(b,c) - mult_h(a*b,c);
  return ret_val;
}


//Problem 5: Smallest Multiple
//What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
int gcd(int a, int b){
  if(b != 0){
    return gcd(b, a % b);
  }
  return a;
}
int smallest_multiple(int lower, int upper){
  int ret_val = 1;
  for(int i = lower; i <= upper; i++){
    ret_val *= i /gcd(ret_val, i);
  }
  return ret_val;
}


//Problem 6: Sum Square Difference
//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
int sum_square_difference(int a, int b){
  int sum_of_squares = 0;
  int square_of_sum = 0;
  for(int i = a; i < b + 1; i++){
    sum_of_squares += (i*i);
    square_of_sum += i;
  }
  square_of_sum *= square_of_sum;
  return square_of_sum - sum_of_squares;
}


//Main Function
int main(){
  
  //Problem 1 Testing--------------------------------------
  printf("%d\n", mult(3,5,10)); //23
  printf("%d\n", mult(3,5,1000)); //233168

  //Problem 5 Testing--------------------------------------
  printf("%d\n", gcd(2,10)); //2
  printf("%d\n", gcd(111,27)); //3
  printf("%d\n", gcd(888,16)); //8
  printf("%d\n", gcd(17,85)); //17

  printf("%d\n", smallest_multiple(1,10)); //2520
  printf("%d\n", smallest_multiple(1,20)); //232792560
  
  //Problem 6 Testing--------------------------------------
  printf("%d\n", sum_square_difference(1,10)); //2640
  printf("%d\n", sum_square_difference(1,100)); //25164150

  return 0;
}
