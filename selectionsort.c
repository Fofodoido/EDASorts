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
            // Parte j� ordenada
            printf(" %d", v[i]);
        } else if (i == j_atual && i == min_encontrado) {
            // O elemento na posi��o 'j' J� ERA o m�nimo.
            // (Vamos destac�-lo de forma especial)
            printf(" |%d|", v[i]);
        } else if (i == j_atual) {
            // Posi��o 'j' que ser� trocada
            printf(" [%d]", v[i]);
        } else if (i == min_encontrado) {
            // M�nimo encontrado na parte n�o ordenada
            printf(" <%d>", v[i]);
        } else {
            // Resto da parte n�o ordenada
            printf(" %d", v[i]);
        }
        
        if (i < n - 1) printf(",");
    }
    // A barra | separa a parte ordenada da n�o ordenada
    printf(" ]\n"); 
}

void selecao_detalhada(int *v, int n){
    printf("\n--- Iniciando Selection Sort ---\n");
    printf("Legenda: [n] = Posi��o 'j' (in�cio da �rea n�o ordenada)\n");
    printf("         <n> = M�nimo encontrado na �rea n�o ordenada\n");
    printf("         |n| = Posi��o 'j' que j� cont�m o m�nimo\n");
    printf("          n  = Parte j� ordenada\n\n");

    // j: Marca o in�cio da parte "n�o ordenada"
    // Vamos at� n-1, pois se os n-1 primeiros est�o certos, o �ltimo tamb�m est�.
    for(int j = 0; j < n - 1; j++){
        printf("--- Passo %d (j=%d) ---\n", j + 1, j);
        printf("  Procurando o menor elemento a partir do �ndice %d...\n", j);

        // 1. Encontrar o �ndice do menor elemento (min)
        int min = j; // Assume que v[j] � o menor
        for (int i = j + 1; i < n; i++) {
            if (v[i] < v[min]) {
                min = i; // Encontrou um novo m�nimo! Atualiza o �ndice.
            }
        }
        
        // Imprime o estado ANTES da troca
        if (min == j) {
            printf("  - O menor elemento (%d) j� est� na posi��o correta (�ndice %d).\n", v[min], min);
        } else {
            printf("  - Menor elemento encontrado: %d (no �ndice %d).\n", v[min], min);
            printf("  - Trocando v[j] (que � %d) com v[min] (que � %d).\n", v[j], v[min]);
        }
        
        imprimir_vetor_detalhado(v, n, j, min);

        // 2. Efetuar a troca
        troca(&v[j], &v[min]);

        // Imprime o estado DEPOIS da troca (se houve troca)
        if (min != j) {
            printf("  Resultado p�s-troca: ");
            imprimir_vetor_detalhado(v, n, j, j); // Ap�s a troca, o min est� em j
        }
        printf("\n");
    }
    printf("--- Ordena��o Conclu�da ---\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int meu_vetor[] = {64, 25, 12, 22, 11};
    int n = sizeof(meu_vetor) / sizeof(meu_vetor[0]);

    printf("Vetor Original:\n");
    printf("  [ 64, 25, 12, 22, 11 ]\n");

    // Chama a fun��o de sele��o detalhada
    selecao_detalhada(meu_vetor, n);

    printf("\nVetor Final Ordenado:\n  [");
    for(int i=0; i<n; i++){
        printf(" %d", meu_vetor[i]);
        if(i < n-1) printf(",");
    }
    printf(" ]\n");

    return 0;
}