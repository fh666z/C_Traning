/*
 * hello_arg1.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: momchil
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>

#define NUM_THREADS			8

char *messages1[NUM_THREADS];


void *PrintHello1(void *threadid)
{
   int *id_ptr, taskid;

   sleep(1);

   id_ptr = (int *) threadid;
   taskid = *id_ptr;
   printf("Thread %d: %s\n", taskid, messages1[taskid]);
   pthread_exit(NULL);
}


void hello_arg1(void)
{
	pthread_t threads[NUM_THREADS];
	int *taskids[NUM_THREADS];
	int rc, t;

	messages1[0] = "English: Hello World!";
	messages1[1] = "French: Bonjour, le monde!";
	messages1[2] = "Spanish: Hola al mundo";
	messages1[3] = "Klingon: Nuq neH!";
	messages1[4] = "German: Guten Tag, Welt!";
	messages1[5] = "Russian: Zdravstvuyte, mir!";
	messages1[6] = "Japan: Sekai e konnichiwa!";
	messages1[7] = "Latin: Orbis, te saluto!";

	for(t=0;t<NUM_THREADS;t++)
	{
		taskids[t] = (int *) malloc(sizeof(int));
		*taskids[t] = t;

		printf("Creating thread %d\n", t);
		rc = pthread_create(&threads[t], NULL, PrintHello1, (void *) taskids[t]);

		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d\n", rc);
			exit(-1);
		}
	}

	pthread_exit(NULL);
}


