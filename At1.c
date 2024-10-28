#include <stdio.h>
#include <pthread.h>

void *pt(){
    printf("Hello from thread\n");
    pthread_exit(NULL);
}



int main(void) {
    int arg = 1;
    pthread_t pt1,pt2,pt3;
    pthread_create(&pt1,NULL,pt,NULL);
    pthread_create(&pt2,NULL,pt,NULL);
    pthread_create(&pt3,NULL,pt,NULL);
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);
    pthread_join(pt3,NULL);
    printf("Hello from the main thread\n");

    return 0;
}