void troca(int *v, int *t);
int particiona (int *v, int e, int d);
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void imprimir_vetor(int *v, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", v[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void troca(int *v, int *t){
    int temp = *v;
    *v=*t;
    *t=temp;
}

int particiona (int *v, int e, int d){
    int pivo = v[d];
    int i = (e - 1); 
    for (int j = e; j <= d - 1; j++){
       if (v[j] <= pivo){
         i++;
         troca(&v[i], &v[j]); 
       }
    }
    troca(&v[i + 1], &v[d]);
    return (i + 1); 
}

void mediana_de_tres(int *v, int e, int d){
    int m = (e+d)/2;
    if ((v[e] >= v[m] && v[e] <= v[d]) || (v[e] <= v[m] && v[e] >= v[d])) {
       troca(&v[e], &v[d]);
    } 
    else if ((v[m] >= v[e] && v[m] <= v[d]) || (v[m] <= v[e] && v[m] >= v[d])) {
       troca(&v[m], &v[d]);
    }
}
int quickselect(int *v, int e, int d, int k) {
    // Caso base: Se a partição tem 1 elemento, é ele.
    if (e == d) {
        return v[e];
    }
    
    // Otimiza a escolha do pivô
    mediana_de_tres(v, e, d); 
    
    // Particiona usando a sua função original
    int j = particiona(v, e, d);

    // Verifica onde o pivô 'j' caiu
    if (k == j) {
        // Encontramos!
        return v[j]; 
    }
    else if (k < j) { 
        // O elemento está na partição da esquerda
        return quickselect(v, e, j - 1, k); 
    }
    else { // (k > j)
        // O elemento está na partição da direita
        return quickselect(v, j + 1, d, k);
    }
}

void quicksort(int *v, int e, int d){
    if (e<d){
        int j = particiona(v,e,d);
        quicksort(v,e,j-1);
        quicksort(v,j+1,d);
    }
}

//Na main, escreva quicksort(v,0,n-1)

int main() {
    setlocale(LC_ALL, "Portuguese");
    int meu_vetor[] = {10, 7, 8, 9, 1, 5, -3};
    int n = sizeof(meu_vetor) / sizeof(meu_vetor[0]);

    printf("Vetor original:\n");
    imprimir_vetor(meu_vetor, n);

    // Conforme solicitado:
    quicksort(meu_vetor, 0, n - 1);

    printf("\nVetor ordenado (com Quicksort):\n");
    imprimir_vetor(meu_vetor, n);

    printf("\n--- Testando o Quickselect ---\n");
    // O vetor ordenado é: {-3, 1, 5, 7, 8, 9, 10}

    // O Quickselect modifica o vetor, então criamos uma cópia
    int vetor_copia[] = {10, 7, 8, 9, 1, 5, -3};
    int n_copia = n;

    // k=0 -> 1º menor elemento (Mínimo)
    int k0 = 0;
    int el_k0 = quickselect(vetor_copia, 0, n_copia - 1, k0);
    printf("Procurando o %dº menor elemento (k=%d): %d\n", k0 + 1, k0, el_k0);

    // k=2 -> 3º menor elemento
    // Precisamos de uma nova cópia, pois a anterior foi modificada
    int vetor_copia2[] = {10, 7, 8, 9, 1, 5, -3};
    int k2 = 2;
    int el_k2 = quickselect(vetor_copia2, 0, n_copia - 1, k2);
    printf("Procurando o %dº menor elemento (k=%d): %d\n", k2 + 1, k2, el_k2);

    // k=n-1 -> Último menor elemento (Máximo)
    int vetor_copia3[] = {10, 7, 8, 9, 1, 5, -3};
    int k_max = n_copia - 1;
    int el_k_max = quickselect(vetor_copia3, 0, n_copia - 1, k_max);
    printf("Procurando o %dº menor elemento (k=%d): %d\n", k_max + 1, k_max, el_k_max);

    return 0;
}