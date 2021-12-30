
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
/*================================================================================================*/
void *Random_threads(void *param) {       /* create random number */
		int Ran_number ;
		Ran_number = rand()%10 +1;
		return (void *)Ran_number ;
}
/*================================================================================================*/
int main(void) {
	srand(time(0));
	int i;
	int sum=0 ;
	int MAX_THREAD = 5;
	int arr[5];
/*================================================================================================*/
    pthread_t tid[MAX_THREAD];                 /* create threads */
	for(i = 0; i < MAX_THREAD; i++) {
	 pthread_create(&tid[i], NULL,&Random_threads, (void*)i);
	}
	for(i = 0; i < MAX_THREAD; i++) {               /* wait for all threads end */
		pthread_join(tid[i], (void**)&arr[i]);

	}
/*================================================================================================*/
	for(i = 0; i < MAX_THREAD; i++) {                  /* print sum of random numbers and random numbers */
	 sum+=arr[i];
	printf("  Random number %d result = %d \n ", i ,arr[i]);

	}
	printf ("\n sum : %i " , sum);
	return 0;
}



