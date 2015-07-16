/*
 * bug3.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: momchil
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define NUM_THREADS     8


void *PrintHello_bug(void *threadid)
{
	long taskid;

	sleep(1);

	taskid = *(long *)threadid;
	printf("Hello from thread %ld\n", taskid);
	pthread_exit(NULL);
}

void bug3(void)
{
	pthread_t threads[NUM_THREADS];
	int rc;
	long t;

	for(t=0;t<NUM_THREADS;t++)
	{
		printf("Creating thread %ld\n", t);

		// PASSING THE SAME ADDRESS TO ALL THREADS !!!
		rc = pthread_create(&threads[t], NULL, PrintHello_bug, (void *) &t);

		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

	pthread_exit(NULL);
}
