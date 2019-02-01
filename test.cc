#include <stdio.h>
int n = 1e9;
int main()
{
  int *a = new int [10]; // new is O(1)
  int size = 10;
  for (int i = 0; i < n; i ++)
  {
    if (i == size)
    {
        int newsize = 3*size/2;
        int *b = new int [newsize];  // new is O(1)
        for (int j = 0; j < size; j ++) b[j] = a[j];
        delete [] a;  // delete is O(1)
        a = b;
        size = newsize;
    }
    a[i] = i*i;
    printf("%d\n", i);
  }
  printf("OVER\n");
}
