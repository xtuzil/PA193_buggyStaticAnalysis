#include <string.h>
int Static[5];

int memcheckFailDemo(int* arrayStack, unsigned int arrayStackLen, int* arrayHeap, unsigned int arrayHeapLen) {
  int Stack[5];

  Static[100] = 0;  
  Stack[100] = 0;  

  for (int i = 0; i <= 5; i++) Stack [i] = 0; 

  int* array = new int[5];
  array[100] = 0; 

  arrayStack[100] = 0; 
  arrayHeap[100] = 0; 

  for (unsigned int i = 0; i <= arrayStackLen; i++) {
      arrayStack[i] = 0;
  }
  for (unsigned int i = 0; i <= arrayHeapLen; i++) { 
      arrayHeap[i] = 0;
  }

  int* arrayHeap2 = arrayHeap + 1;
  arrayHeap2[4] = 0;

  return 0;
}

void salDemo(int* pInArray, int** ppArray) {
	*ppArray = new int[sizeof(pInArray)];
	for (unsigned int i = 0; i < sizeof(pInArray); i++) {
		(*ppArray)[i] = pInArray[i];
	}
}

void* buggymemcpy(int *dest, const int *src, size_t count) {
   size_t i;
   for (i = 0; i < count + 1; i++) { 
      dest[i] = src[i];
   }
   return dest;
}

int main(int argc, char* argv[]) {

    int arrayStack[5];
    int* arrayHeap = new int[5];
    memset(arrayStack, 0, sizeof(arrayStack));
    memset(arrayHeap, 0, 5 * sizeof(int));
    memcheckFailDemo(arrayStack, 5, arrayHeap, 5);

    int* pArray;
    int* pArray2;
    if (strcmp(argv[1], "alloc") == 0) pArray = new int[5];
    salDemo(pArray, &pArray2);

    buggymemcpy(pArray, pArray2, sizeof(pArray));
    
    return 0;
}

