//Sophia Xia
//W_02: Get to the point

#include <stdio.h>
#include <stdlib.h>

/* Notes:
   pointer ++ will go to the next byte
   (*pointer) ++ will add 1 to what is being pointed at
      brackets required (or *pointer += 1)
   %u is the placeholder for UNSIGNED ints */

int main(){

  unsigned int num = 3500000000;
  char * pnum = & num;

  printf("Print num in hex %x\n", num);

  for(int i = 0; i < 4; i++){
    printf("print byte %d: %hhx\n", i +1, *pnum);
    pnum ++;  
  }

  //reset pnum
  pnum = & num;

  //Increment each byte by 1
  for(int i = 0; i < 4; i++){
    (*pnum) ++;
    printf("print byte %d: %hhx\n", i +1, *pnum);
    pnum ++;
  }
 
  printf("Print num in hex %x\n", num);
  printf("Print num in int %u\n", num);

  //reset num and pnum
  num = 3500000000;
  pnum = &num;
  
  //Increment each byte by 16
  for(int i = 0; i < 4; i++){
    *pnum += 16;
    printf("print byte %d: %hhx\n", i +1, *pnum);
    pnum ++;
  }

  printf("Print num in hex %x\n", num);
  printf("Print num in int %u\n", num);
  
}

