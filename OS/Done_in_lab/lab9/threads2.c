#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define NUM_THREADS 5
int sum = 0;

void *PrintHello(void *val) {
	int *n = (int*)val;
	sum += *n;
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t threads[NUM_THREADS];
	int data[NUM_THREADS], errcode, i;

	for (int t = 0;t<NUM_THREADS;t++) {
		data[t] = atoi(argv[t+1]);
		
		if (pthread_create(&threads[t], NULL, PrintHello, (void*)&data[t])) {
			printf("Error in pthread_create\n");
			exit(1);
		}
		//pthread_join(threads[t], NULL); create and join here itself
	}
	for (int t = 0;t<NUM_THREADS;t++) 
		pthread_join(threads[t], NULL); // first create then join
	
	printf("Sum is : %d\n", sum);

	pthread_exit(NULL);
	return 0;
}
