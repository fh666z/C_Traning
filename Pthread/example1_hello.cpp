/*
 * pthread_hello.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: momchil
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


#define THREAD_COUNT		999


void *print_method(void *arg)
{
	int self_id = *((int*)arg);

	printf("Hello world from thread #%d \n", self_id);

	pthread_exit(NULL);
}


void example1_hello(void)
{
	pthread_t my_threads[THREAD_COUNT];
	int my_thread_ids[THREAD_COUNT];

	for(int thread_iter = 0; thread_iter < THREAD_COUNT; thread_iter++)
	{
		my_thread_ids[thread_iter] = thread_iter;
		int res_create = pthread_create(&my_threads[thread_iter], NULL, print_method, &my_thread_ids[thread_iter]);
		if (res_create)
		{
			printf("Error creating thread (pthread_create): %d \n", res_create);
			exit(-1);
		}
	}

	pthread_exit(NULL);
}


