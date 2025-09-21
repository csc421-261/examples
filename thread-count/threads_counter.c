/*
 * threads_counter.c
 * authors: chatGPT and bjr
 * last-update:
 *	21 sep 2025: created
 *
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define N 5    // number of threads
#define K 5 // increments per thread

#define NO_COLOR "\033[0m"

char * colors[5] = {
	"\033[31m", // red
	"\033[32m", // green
	"\033[33m", // yellow
	"\033[34m", // blue
	"\033[35m"	// magenta
} ;

typedef struct {
	int * count ;
	int index ;
	char * color ;
} thread_data_t ;


void * counter_thread(void * arg) {
	thread_data_t * data = (thread_data_t *) arg ;
	int temp ;
	for (int i = 0; i < K; i++) {
		temp = *(data->count) ;
		temp += 1 ;
		
#ifdef ADD_SLEEP
		sleep(1) ;
#endif

		*(data->count) = temp ;
		printf("%sThread %d incremented count to %d%s\n", 
			data->color, data->index, *data->count, NO_COLOR);
	}
	printf("%sThread %d done%s\n", data->color, data->index, NO_COLOR);
	return NULL;
}

int main(void) {
	int count = 0;
	pthread_t threads[N];
	thread_data_t * thread_data_p ; 

	for (int i = 0; i < N; i++) {
		thread_data_p = (thread_data_t *) malloc(sizeof(thread_data_t)) ;
		thread_data_p->count = &count ;
		thread_data_p->index = i ;
		thread_data_p->color = colors[i% N] ;
		if (pthread_create(&threads[i], NULL, counter_thread, thread_data_p) != 0) {
			perror("pthread_create");
			exit(1);
		}
	}

	for (int i = 0; i < N; i++) {
		pthread_join(threads[i], NULL) ;
	}

	printf("Final count = %d\n", count) ;
	return 0;
}

