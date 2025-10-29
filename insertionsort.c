#include <stdio.h>

void insercao(int *v, int n){
    for (int i = 1; i < n; i++){
        int x=v[i];
        int j=i-1;
        while (j>=0 && v[j]>x){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=x;
    }
}
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

int main() {
    int meu_vetor[] = {12, 11, 13, 5, 6, 7, -2};
    int n = sizeof(meu_vetor) / sizeof(meu_vetor[0]);

    printf("Vetor original: ");
    imprimir_vetor(meu_vetor, n);

    // Chama a sua função de ordenação
    insercao(meu_vetor, n);

    printf("Vetor ordenado: ");
    imprimir_vetor(meu_vetor, n);

    return 0;
}