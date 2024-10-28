#include <stdio.h>
#include <pthread.h>

void *positivo(void *args_p){
    int arg = *(int *) args_p;
    if(arg>0){
    printf("%d is positive.\n",arg);    
    }
    
    pthread_exit(NULL);
}
void *par(void *args_p){
    int arg = *(int *) args_p;
    int rest = arg % 2;
	if (rest == 0){
    printf("%d is even.\n",arg);
    }
    
    pthread_exit(NULL);
}



int main(void) {
    int arg;
    scanf("%d", &arg);
    pthread_t pt1,pt2;
    pthread_create(&pt1,NULL,positivo,(void *) &arg);
    pthread_create(&pt2,NULL,par,(void *) &arg);
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);
    

    return 0;
}