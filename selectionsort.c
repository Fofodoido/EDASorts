#include <stdio.h>
#include <locale.h>



void troca(int *v, int *t){
    int temp = *v;
    *v=*t;
    *t=temp;
}

void selecao(int *v, int n){
    for(int j=0; j<n; j++){
        int min = j;
        for (int i = j+1; i < n; i++)
            if (v[i]<v[min]) min = i;
        troca(&v[j],&v[min]);
    }
}
void imprimir_vetor_detalhado(int *v, int n, int j_atual, int min_encontrado) {
    printf("  Vetor atual: [");
    for (int i = 0; i < n; i++) {
        if (i < j_atual) {
            // Parte já ordenada
            printf(" %d", v[i]);
        } else if (i == j_atual && i == min_encontrado) {
            // O elemento na posição 'j' JÁ ERA o mínimo.
            // (Vamos destacá-lo de forma especial)
            printf(" |%d|", v[i]);
        } else if (i == j_atual) {
            // Posição 'j' que será trocada
            printf(" [%d]", v[i]);
        } else if (i == min_encontrado) {
            // Mínimo encontrado na parte não ordenada
            printf(" <%d>", v[i]);
        } else {
            // Resto da parte não ordenada
            printf(" %d", v[i]);
        }
        
        if (i < n - 1) printf(",");
    }
    // A barra | separa a parte ordenada da não ordenada
    printf(" ]\n"); 
}

void selecao_detalhada(int *v, int n){
    printf("\n--- Iniciando Selection Sort ---\n");
    printf("Legenda: [n] = Posição 'j' (início da área não ordenada)\n");
    printf("         <n> = Mínimo encontrado na área não ordenada\n");
    printf("         |n| = Posição 'j' que já contém o mínimo\n");
    printf("          n  = Parte já ordenada\n\n");

    // j: Marca o início da parte "não ordenada"
    // Vamos até n-1, pois se os n-1 primeiros estão certos, o último também está.
    for(int j = 0; j < n - 1; j++){
        printf("--- Passo %d (j=%d) ---\n", j + 1, j);
        printf("  Procurando o menor elemento a partir do índice %d...\n", j);

        // 1. Encontrar o índice do menor elemento (min)
        int min = j; // Assume que v[j] é o menor
        for (int i = j + 1; i < n; i++) {
            if (v[i] < v[min]) {
                min = i; // Encontrou um novo mínimo! Atualiza o índice.
            }
        }
        
        // Imprime o estado ANTES da troca
        if (min == j) {
            printf("  - O menor elemento (%d) já está na posição correta (índice %d).\n", v[min], min);
        } else {
            printf("  - Menor elemento encontrado: %d (no índice %d).\n", v[min], min);
            printf("  - Trocando v[j] (que é %d) com v[min] (que é %d).\n", v[j], v[min]);
        }
        
        imprimir_vetor_detalhado(v, n, j, min);

        // 2. Efetuar a troca
        troca(&v[j], &v[min]);

        // Imprime o estado DEPOIS da troca (se houve troca)
        if (min != j) {
            printf("  Resultado pós-troca: ");
            imprimir_vetor_detalhado(v, n, j, j); // Após a troca, o min está em j
        }
        printf("\n");
    }
    printf("--- Ordenação Concluída ---\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int meu_vetor[] = {64, 25, 12, 22, 11};
    int n = sizeof(meu_vetor) / sizeof(meu_vetor[0]);

    printf("Vetor Original:\n");
    printf("  [ 64, 25, 12, 22, 11 ]\n");

    // Chama a função de seleção detalhada
    selecao_detalhada(meu_vetor, n);

    printf("\nVetor Final Ordenado:\n  [");
    for(int i=0; i<n; i++){
        printf(" %d", meu_vetor[i]);
        if(i < n-1) printf(",");
    }
    printf(" ]\n");

    return 0;
}