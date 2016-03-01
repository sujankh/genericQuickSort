#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "quicksort.h"

int (*compare)(void *, void *);
const size_t (*getSize)();
void (*printElement)(void *);


int compareInt(void *n1, void *n2)
{
  int num1 = *(int*)n1,
    num2 = *(int*)n2;

  return num1 - num2;
}

const size_t intSize()
{
  return sizeof(int);
}

void printInt(void *num)
{
  printf("%d", *(int*)num);
}

int main()
{ 
  int a[] = { 6, 10, 13, 5, 8, 3, 2, 11 };
  compare = compareInt; //Our comparator function to compare two ints
  getSize = intSize;
  printElement = printInt;
  
  quicksort(a, 0, 7);
  
  printArray(a, 7);
  return 0;
}
