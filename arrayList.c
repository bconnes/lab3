#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

arrayList * initialize(primitiveType type)
{
  arrayList * ary = (arrayList *) malloc(sizeof(arrayList));
  ary->arraySize = 4 * getSize(type);
  ary->numElements = 0;
  ary->type = type;
  ary->elementSize = getSize(type);
  ary->array = malloc(getSize(ary->type) * 4);
  return ary;
}

int getSize(primitiveType type)
{
  if(type == charType)
    return sizeof(char);
  else if(type == shortType)
    return sizeof(short);
  else
    return sizeof(int);
}

void addElement(arrayList * arylstP, void * element)
{
  if((arylstP -> numElements) == (arylstP -> arraySize)){
    arrayList tmp = * arylstP;
    free(arylstP);
    arylstP = (arrayList *) malloc(sizeof(tmp) * 2);
    arylstP -> array = tmp.array; 
  }
  primitiveType pt = arylstP -> type;
  (pt) arylstP->array + (arylstP->numElements + 1 = (pt) element;
  return;
}

void removeElement(arrayList * arylstP, int index)
{
   return;
}
      

void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         //fill in the missing code that gets the element and &s it with 0xff
         printf("%02x ", 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
         printf("%04x ", 0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
         printf("%08x ", 0xffffffff);
   }
   printf("\n");
}

