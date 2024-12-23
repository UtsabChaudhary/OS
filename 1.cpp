#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_THREADS 2
int shared_counter = 0;

pthread_mutex_t mutex;
void* increment_counter(void* arg) {
for (int i = 0; i < 10; ++i) {
pthread_mutex_lock(&mutex);
int temp = shared_counter;
printf("Thread %d: Joining the Critical section\n", *(int*)arg);
shared_counter = temp + 1;
printf("Thread %d: Going to leave Critical section\n", *(int*)arg);
pthread_mutex_unlock(&mutex);
sleep(1);
}
return NULL;
}
int main() {
pthread_t threads[NUM_THREADS];
int thread_ids[NUM_THREADS] = {0, 1};
pthread_mutex_init(&mutex, NULL);
for (int i = 0; i < NUM_THREADS; ++i) {
pthread_create(&threads[i], NULL, increment_counter, &thread_ids[i]);
}
for (int i = 0; i < NUM_THREADS; ++i) {
pthread_join(threads[i], NULL);
}
pthread_mutex_destroy(&mutex);
return 0;
}
