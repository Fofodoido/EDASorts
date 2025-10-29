#include <stdio.h>
#include <stdlib.h>

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

void intercala(int *v, int e, int m, int d){
    int i = e, j=m+1, k=0;
    int *w=malloc((d-e+1)*sizeof(int));
    while (i<=m && j<=d){
        if (v[i]<v[j]) w[k++]=v[i++];
        else w[k++]=v[j++];
    }
    while (i<=m) w[k++]=v[i++];
    while (j<=d) w[k++]=v[j++];
    for (i = e, k =0; i<=d; i++, k++) v[i]=w[k];
    free(w);
}

void mergesort(int *v, int e, int d){
    if(e<d){
        int m =(e+d)/2;
        mergesort(v,e,m);
        mergesort(v,m+1,d);
        intercala(v,e,m,d);
    }
}

int main() {
    // 1. Um vetor totalmente DESORDENADO
    int meu_vetor[] = {38, 27, 43, 3, 9, 82, 10, -5};
    
    // 2. Calcula o tamanho dinamicamente
    int n = sizeof(meu_vetor) / sizeof(meu_vetor[0]);

    printf("Vetor original (desordenado):\n");
    imprimir_vetor(meu_vetor, n);

    // 3. Chama o MERGESORT
    // O Mergesort ordena o vetor "in-place" (no próprio local)
    // Passamos o início (0) e o fim (n-1)
    printf("\nChamando mergesort(v, 0, %d)...\n\n", n - 1);
    mergesort(meu_vetor, 0, n - 1);

    // 4. Imprime o resultado
    printf("Vetor final (ordenado):\n");
    imprimir_vetor(meu_vetor, n);

    return 0;
}