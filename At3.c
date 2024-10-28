#include <stdio.h>
#include <math.h>
#include <pthread.h>

// Variáveis globais para armazenar os resultados das funções f1 e f2
double f1_result;
double f2_result;

// Função para calcular f1 = sin(3x)
void *calculate_f1(void *arg) {
    double x = *((double*) arg);
    f1_result = sin(3 * x);
    pthread_exit(NULL);
}

// Função para calcular f2 = cos(x)^0.5
double *calculate_f2(void *arg) {
    double x = *((double*) arg);
    f2_result = sqrt(cos(x));
    pthread_exit(NULL);
}

int main() {
    double x;
    
    scanf("%lf", &x);

    pthread_t thread_f1, thread_f2;

    // Iniciar threads para calcular f1 e f2 simultaneamente
    pthread_create(&thread_f1, NULL, calculate_f1, &x);
    pthread_create(&thread_f2, NULL, calculate_f2, &x);

    // Esperar pelas threads terminarem
    pthread_join(thread_f1, NULL);
    pthread_join(thread_f2, NULL);

    // Calcular o valor final y
    double y = f1_result + f2_result;

    // Imprimir o resultado na tela
    printf("y = %.2f\n", y);

    return 0;
}
