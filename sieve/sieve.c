#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "sieve.h"

//SIEVE OF ERATOSTHENES

int sieve(int num){
  //create array
  int size = num*log(num)*1.15;
  printf("%d\n", size);
  int *arr = malloc(size * sizeof(int));
  //mark all as true for now
  for(int i = 0; i < size; i++){
    arr[i] = 1;
  }
  int ret_val;
  int ctr = -1;
  for(int i = 2; i < size; i ++){
    //if the index is prime
    if(arr[i] != 0){
      ctr ++;
      if(ctr == num){
	ret_val = i;
      }
      //mark all multiples as zero
      for(int j = 3*i; j < size; j += i){
	//printf("%d\n", j);
	arr[j] = 0;
      }
    }
  }
  free(arr);
  return ret_val;
}
