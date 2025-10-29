#include <stdio.h>

int bb(int *v, int e, int d, int x){
    if (e<d-1)    {
        int m=(e+d)/2;
        if (v[m]>=x) return bb(v,e,m,x);
        else return bb(v,m,d,x);
    }
    return d;
}

int busca(int *v, int n, int x){
    return bb(v,-1,n,x);
}


int main() {
    // A busca binária exige que o array esteja ORDENADO
    int meu_vetor[] = {2, 5, 7, 8, 11, 12, 15, 20};
    int n = 8; // Tamanho do vetor

    printf("Vetor: [");
    for (int i = 0; i < n; i++) {
        printf("%d%s", meu_vetor[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n\n");

    // --- Teste 1: Elemento que existe ---
    int x1 = 7;
    int indice1 = busca(meu_vetor, n, x1);
    
    printf("Buscando por %d...\n", x1);
    // A função retorna o "ponto de inserção" (lower_bound)
    // Precisamos verificar se o elemento nesse índice é realmente o que buscamos
    if (indice1 < n && meu_vetor[indice1] == x1) {
        printf("Resultado: Elemento %d encontrado no índice %d.\n", x1, indice1);
    } else {
        printf("Resultado: Elemento %d não encontrado.\n", x1);
    }

    printf("---\n");

    // --- Teste 2: Elemento que NÃO existe (entre valores) ---
    int x2 = 9;
    int indice2 = busca(meu_vetor, n, x2);

    printf("Buscando por %d...\n", x2);
    if (indice2 < n && meu_vetor[indice2] == x2) {
        printf("Resultado: Elemento %d encontrado no índice %d.\n", x2, indice2);
    } else {
        // A sua implementação retorna o índice onde o 9 *deveria ser inserido*
        // para manter a ordem (no caso, índice 4, lugar do 11)
        printf("Resultado: Elemento %d não encontrado. Posição de inserção: %d.\n", x2, indice2);
    }

    printf("---\n");
    
    // --- Teste 3: Elemento que NÃO existe (maior que todos) ---
    int x3 = 25;
    int indice3 = busca(meu_vetor, n, x3);

    printf("Buscando por %d...\n", x3);
    if (indice3 < n && meu_vetor[indice3] == x3) {
        printf("Resultado: Elemento %d encontrado no índice %d.\n", x3, indice3);
    } else {
        // Retorna o tamanho do array (índice 'n'), 
        // indicando que deve ser inserido no final.
        printf("Resultado: Elemento %d não encontrado. Posição de inserção: %d.\n", x3, indice3);
    }

    return 0;
}