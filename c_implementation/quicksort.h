#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//void * memcpy ( void * destination, const void * source, size_t num );

extern int (*compare)(void *, void *);
extern const size_t (*getSize)();
extern void (*printElement)(void *);

void swap(void *n1, void *n2, size_t typeSize)
{  
  void *tmp = malloc(typeSize);
  
  memcpy(tmp, n1, typeSize); //equivalent to tmp = *n1
    
  memcpy(n1, n2, typeSize);   //*n1 = *n2;
  memcpy(n2, tmp, typeSize); //*n2 = tmp;
}

//equivalent to &a[index]
void* getPointerAt(void *a, int index, size_t typeSize)
{
  return ((char*)a) + index * typeSize; //move from a[0] each character by index * typeSize bytes
}

void printArray(void *a, int len)
{
  int i;
  for(i = 0; i <= len; ++i)
    {
      printElement(getPointerAt(a, i, getSize())); printf(" ,");
    }
    

  printf("\n");
}


int partition(void *a, int lo, int hi)
{
  int i, j;
  void *alo, *ai, *aj;
  void *n1, *n2;
  const size_t typeSize = getSize();
  
  void *pivot = malloc(typeSize);   
  
  alo = getPointerAt(a, lo, typeSize); //&a[lo]
  memcpy(pivot, alo, typeSize); //int pivot = a[lo];
  
  i = lo;
  j = lo + 1;
  
  for(; j <= hi; ++j)
    {
      aj = getPointerAt(a, j, typeSize); //a[j]
      
      if(compare(aj, pivot) <= 0) //if(a[j] <= pivot) implies a[j] - pivot <= 0
        {
          n1 = getPointerAt(a, i + 1, typeSize);
          n2 = getPointerAt(a, j, typeSize);
          
          swap(n1, n2, typeSize);		//swap(a[i + i], a[j]);
          ++i;
        }
    }

  alo = getPointerAt(a, lo, typeSize); //a[lo]
  ai = getPointerAt(a, i, typeSize); //a[i]
  swap(alo, ai, typeSize);                 //swap(a + lo, a + i);
  
  return i; //i is the position of the partition
}

void quicksort(void *a, int lo, int hi)
{
  int pivot;
  
  if(lo >= hi)
    return;
  
  pivot = partition(a, lo, hi);
  quicksort(a, lo, pivot - 1);
  quicksort(a, pivot + 1, hi);
}
