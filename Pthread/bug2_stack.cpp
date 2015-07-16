/*
 * bug2_stack.cpp
 *
 *	A "hello world" Pthreads program that dumps core.
 *
 *  Created on: Jul 16, 2015
 *      Author: momchil
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define NTHREADS			8
#define ARRAY_SIZE      	500000
#define MEGEXTRA        	1000000


void *Hello_stack(void *threadid)
{
	double A[ARRAY_SIZE];
	int i;
	long tid;

	tid = (long)threadid;
	sleep(3);

	for (i=0; i<ARRAY_SIZE; i++)
	{
		A[i] = i * 1.0;
	}

	printf("%ld: Hello World!   %f\n", tid, A[ARRAY_SIZE-1]);
	pthread_exit(NULL);
}


void stack_example(void)
{
	pthread_t threads[NTHREADS];
	size_t stacksize;
	pthread_attr_t attr;

	int rc;
	long t;

	pthread_attr_init(&attr);
	stacksize = ARRAY_SIZE*sizeof(double) + MEGEXTRA;
	pthread_attr_setstacksize (&attr, stacksize);
	pthread_attr_getstacksize (&attr, &stacksize);

	printf("Thread stack size = %li bytes (hint, hint)\n",stacksize);

	for(t = 0; t < NTHREADS; t++)
	{
		rc = pthread_create(&threads[t], NULL, Hello_stack, (void *)t);
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

	printf("Created %ld threads.\n", t);
	pthread_exit(NULL);
}


