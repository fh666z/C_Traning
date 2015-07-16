/*
 * bug5.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: momchil
 */


#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define NUM_THREADS	5

void *PrintHello_bug5(void *threadid)
{
	int i;
	double myresult=0.0;

	printf("thread=%ld: starting...\n", threadid);

	for (i=0; i<1000000; i++)
		myresult += sin(i) * tan(i);

	printf("thread=%ld result=%e. Done.\n",threadid,myresult);

	pthread_exit(NULL);
}


void bug5(void)
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;

	for(t=0;t<NUM_THREADS;t++)
	{
		printf("Main: creating thread %ld\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello_bug5, (void *)t);

		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

	printf("Main: Done.\n");

	pthread_exit(NULL);
}

