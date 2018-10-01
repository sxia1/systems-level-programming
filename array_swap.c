#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  
  int arrA[10];
  
  srand(time(NULL));

  for(int i =0; i<10; i++){
    arrA[i] = rand();
  }

  arrA[9] = 0;

  printf("Print Array A\n");
  for(int i = 0; i < 10; i++){
    printf("Index:%d %d\n", i, arrA[i]);
  }

  int arrB[10];

  int *ap = arrA;
  int *bp = arrB + 9;

  for(int i = 0; i < 10; i++){
    *bp = *ap;
    ap ++;
    bp --;
  }
  
  printf("Print Array B\n");
  for(int i = 0; i < 10; i++){
    printf("Index:%d %d\n", i, arrB[i]);
  }
}
