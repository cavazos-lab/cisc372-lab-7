#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int * createArray(int n) {
  return malloc(n * sizeof(int));
}

int * initArray(int n) {
  int * res = createArray(n);

  int i;
  for (i = 0; i < n; i++)
    res[i] = i;

  return res;
}

void vectAdd(int n, int * a, int * b, int * c) {
  int i;
  for (i = 0; i < n; i++) 
    c[i] = a[i] + b[i];
}

int main(int argc, char ** argv) {
  assert(argc == 2);

  int n = atoi(argv[1]);
  assert(n>0 && n<=16384 && n%512==0);
  int N = n*n;

  printf ("Initializing two arrays of size %d \n", n*n);
  int * a = initArray(N);
  int * b = initArray(N);
  printf ("Creating an empty array of size %d\n", n*n);
  int * c = createArray(N);

  printf ("Adding the elements of two arrays\n", n*n);
  vectAdd(N, a, b, c);

  printf( "c[0] = %ld\n",0,c[0] );
  printf( "c[%d] = %ld\n",N-1, c[N-1] );
  return 0;
}

