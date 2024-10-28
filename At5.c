#include <stdio.h>
#include <pthread.h>

// Variável global para armazenar o resultado dos fatoriais
unsigned long long int soma_fatoriais = 0;

// Mutex para garantir acesso seguro à variável compartilhada
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Função para calcular o fatorial de um número
void *fatorial(void *arg) {
    int num = *((int*) arg);
    unsigned long long int resultado = 1;

    // Calculando o fatorial
    for (int i = 1; i <= num; i++) {
        resultado *= i;
    }

    // Bloquear o mutex antes de acessar a variável compartilhada
    pthread_mutex_lock(&mutex);

    // Atualizar a variável compartilhada
    soma_fatoriais += resultado;

    // Desbloquear o mutex após a atualização estar completa
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2, thread3;
    int num1, num2, num3;

    // Lendo os três números inteiros
    scanf("%d", &num1);
    scanf("%d", &num2);
    scanf("%d", &num3);

    // Criando as threads
    pthread_create(&thread1, NULL, fatorial, &num1);
    pthread_create(&thread2, NULL, fatorial, &num2);
    pthread_create(&thread3, NULL, fatorial, &num3);

    // Esperando pelas threads terminarem
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    // Imprimindo a soma dos fatoriais
    printf("%llu\n", soma_fatoriais);

    return 0;
}
