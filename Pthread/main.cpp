/*
 * main.cpp
 *
 *  Created on: Jul 16, 2015
 *      Author: momchil
 */

#include <stdio.h>
#include <pthread.h>

typedef enum eMyThreads
{
	THR_1,
	THR_2,
	THR_3,
	THR_4,
	THR_5,
	THR_COUNT
}tMyThreads;

void *print_method(void *arg)
{
	int self_id = *((int*)arg);

	printf("Hello world from thread #%d \n", self_id);

	pthread_exit(NULL);
}


int main(int argc, char **argv)
{
	pthread_t my_threads[THR_COUNT];

	for(int thread_iter = 0; thread_iter < THR_COUNT; thread_iter++)
	{
		int res_create = pthread_create(&my_threads[thread_iter], NULL, print_method, &thread_iter);
		if (res_create)
		{
			printf("Error creating thread (pthread_create): %d \n", res_create);
		}
	}

	return 0;
}


