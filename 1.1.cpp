#include <stdio.h>
#include <pthread.h>

// Function executed by the thread
void* threadFunction(void* arg) {
    printf("Hello from the thread! Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t thread;

    // Create the thread
    int result = pthread_create(&thread, NULL, threadFunction, NULL);
    if (result != 0) {
        perror("Failed to create thread");
        return 1;
    }

    // Wait for the thread to finish execution
    pthread_join(thread, NULL);

    printf("Main thread completed.\n");

    return 0;
}

