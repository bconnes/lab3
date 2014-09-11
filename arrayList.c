#include <stdlib.h>
#include <stdio.h>
#include "arrayList.h"

//getSize not accessed outside of this file so declare it to be static
//static essentially makes it private to this file 
static int getSize(primitiveType type);

/**
   initialize function will initialize an array when passed a type struct, either a short, int , or char, 
   and will set the size of the array to 4 'blocks' of type, and allocate the array to be of size 4.

   @params type - the type struct to create the array of (see arrayList.h)
   @return the arrayList that has been initialized
 **/

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

/**
   getSize will return the size (in bytes) of a primitiveType by matching it to the types of data it can be.

   @params type - the primitiveType struct to be operated upon
   @return the number of bytes that a single 'type' takes up
 **/

int getSize(primitiveType type)
{
  if(type == charType)
    return sizeof(char);
  else if(type == shortType)
    return sizeof(short);
  else
    return sizeof(int);
}

/**
   addElement function has two jobs - primarily, it will add an element to the end of an arrayList. However, if the arrayList
   is not large enough, it will double the size of the array, and then add the element to the end of the arrayList.

   @params arylstP - a pointer to an arrayList typedef (see arrayList.h)
   @params element - a void pointer to an element that is to be added to the arrayList
   @return the arrayList will have the element added to the end of the array, and (if necessary) the array will be doubled in size
 **/

void addElement(arrayList * arylstP, void * element)
{
  if((arylstP -> numElements) == (arylstP -> arraySize)){ // If the number of elements in our arrayList is equal to the size of the array..
    arrayList tmp = * arylstP; // Create a copy of the arrayList that was passed
    free(arylstP); // Free the space allocated by the old array
    arylstP -> array = (arrayList *) malloc(sizeof(tmp.array) * 2);   // Allocate space for twice the size of the previous array
    arylstP -> array = tmp.array; // Fill the new array with the values of the old array
 } 
  /*
    Here, the element if added based on its type. First, the void array is casted as the type of element it consists of,
    and the last element is grabbed by adding 'numElements' to that array. The element is added by dereferencing it after a cast.
   */
  int typeSize = getSize(arylstP -> type);
  if(typeSize == sizeof(char)){    
    *((char *) arylstP->array + (arylstP->numElements)) = * (char *) element;
    (arylstP->numElements)++;
  }
  else if(typeSize == sizeof(short)){
    *((short *) arylstP->array + (arylstP->numElements)) = * (short *) element;
    (arylstP->numElements)++;
  }
  else if(typeSize == sizeof(int)){
    *((int *) arylstP->array + (arylstP->numElements)) = * (int *) element;
    (arylstP-> numElements)++;
  } else {}
  return;
}

/**
   removeElement will remove the element in the arrayList arylstP points to, at the index passed,
   and move the rest of the array down to fill the hole made by the removal.

   @params arylstP - a pointer to an arrayList that will have an element removed
   @params index - the index to remove an element from
   @return the arrayList that arylstP points to will have an element removed from it
 **/
void removeElement(arrayList * arylstP, int index)
{
  int typeSize = getSize(arylstP->type);
  int i;
  /*
    Similarly to addElement, the array is grabbed the same way, by casting it as the type of elements it contains.
    An element is removed by being 'overwritten' by the elements in the spots after it.
   */
  if(typeSize == sizeof(char)){
    for(i = index; i < (arylstP -> numElements) - 1; i++)
      *((char *) arylstP-> array + i) = *((char *) arylstP-> array + (i + 1)); 
  } else if(typeSize == sizeof(short)){
    for(i = index; i < (arylstP -> numElements) - 1; i++)
      *((short *) arylstP-> array + i) = *((short *) arylstP -> array + i + 1);
  } else if(typeSize == sizeof(int)){
    for(i = index; i < (arylstP -> numElements) - 1; i++)
      *((int *) arylstP-> array + i) = *((int *) arylstP -> array + i + 1);
  } else {}
  (arylstP -> numElements)--;
   return;
}
      
/**
   printArray will print the array, based on the 'type' of array that arylstP points to

   @params arylstP - a pointer to the arrayList to be printed
   @return the arrayList will be printed
 **/
void printArray(arrayList * arylstP)
{
   int i;
   printf("array size: %d, num elements: %d contents: ", 
          arylstP->arraySize, arylstP->numElements);
   for (i = 0; i < arylstP->numElements; i++)
   {
      if (arylstP->type == charType)
         //fill in the missing code that gets the element and &s it with 0xff
	printf("%02x ", (*((char *) arylstP -> array + i)) & 0xff);
      else if (arylstP->type == shortType)
         //fill in the missing code that gets the element and &s it with 0xffff
	printf("%04x ", (*((short *) arylstP -> array + i)) & 0xffff);
      else if (arylstP->type == intType)
         //fill in the missing code that gets the element and &s it with 0xffffffff
	printf("%08x ", (*((int * ) arylstP -> array + i)) & 0xffffffff);
   }
   printf("\n");
}

