/*
 * CSC 17B  Example 1 Threading Program
 * Purpose:  Create a simple function call
 * that is threaded
 */

// System Libraries
#include <pthread.h> //Threading
#include <stdio.h>   //Printf library
#include <cstdlib>   //Exit Library

// Function Prototypes
void *PrintHello(void *);

// Execution Begins Here
int main(int argc, char *argv[]) {
  const int NUM_THREADS = 5;
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;
  for (t = 0; t < NUM_THREADS; t++) {
    printf("In main: creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  /* Last thing that main() should do */
  pthread_exit(NULL);
  return 0;
}

void *PrintHello(void *threadid)
{
  intptr_t tid;
  tid = (intptr_t)threadid;
  printf("Hello World! It's Mark, thread #%ld!\n", tid);
  pthread_exit(NULL);
}