#include <stdio.h>
#include <pthread.h>

#define SIZE 10

// Vetor global
int vetor[SIZE];

// Mutex para garantir acesso seguro ao vetor
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Função executada pela thread
void *multiply() {
    int number;
    scanf("%d",&number);

    // Bloquear o mutex antes de acessar o vetor
    pthread_mutex_lock(&mutex);

    // Multiplicar o número em todas as posições do vetor
    for (int i = 0; i < SIZE; i++) {
        vetor[i] *= number;
    }

    // Desbloquear o mutex após a operação estar completa
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    

    // Lendo o vetor
    
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &vetor[i]);
    }
    // Criando as threads
    pthread_create(&thread1, NULL, multiply, NULL);
    pthread_create(&thread2, NULL, multiply, NULL);

    // Esperando pelas threads terminarem
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Imprimindo o vetor resultante
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
