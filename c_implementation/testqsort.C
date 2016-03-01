#include <stdio.h>

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


int compareDouble(void *n1, void *n2)
{
  double num1 = *(double*)n1,
    num2 = *(double*)n2;

  return num1 - num2;
}

const size_t doubleSize()
{
  return sizeof(double);
}

void printDouble(void *num)
{
  printf("%lf", *(double*)num);
}

int main()
{
  double d[] = { 6.5, 10.4, 13.22, 5.54, 8.6, 3.5, 2.9, 11.3 };
 
  int a[] = { 6, 10, 13, 5, 8, 3, 2, 11 };
  compare = compareInt; //Our comparator function to compare two ints
  getSize = intSize;
  printElement = printInt;
  
  quicksort(a, 0, 7);  
  printArray(a, 7);

  //Now lets sort a double array
  compare = compareDouble; //Our comparator function to compare two ints
  getSize = doubleSize;
  printElement = printDouble;
  
  quicksort(d, 0, 7);  
  printArray(d, 7);
  
  return 0;
}
