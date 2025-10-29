#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
typedef struct celula{
    int dado;
    struct celula * prox;
}celula;

//Declaração de funções antes da execução do programa.
celula *cria_lista();
void remove_lista(celula *le, int x);
void insere_inicio(celula *le, int x);
void insere_depois(celula *le, int y, int x);
int remove_inicio(celula *le);
int remove_ultimo(celula *le, int x);
celula *busca(celula *le, int x);
celula *busca_pos(celula *le, int i);
int lista_vazia(celula *le);
void destroi_lista(celula *le);
void imprime_lista(celula *le);


celula *cria_lista(){
    celula *le = malloc(sizeof(celula));
    le ->prox = NULL;
    return le;
}

void insere_inicio(celula *le, int x){
    celula *novo = malloc(sizeof(celula));
    novo -> dado =x;
    novo ->prox = le ->prox;
    le -> prox = novo;
}

celula *busca(celula *le, int x){
    le = le->prox;
    while (le != NULL && le -> dado != x){
       le = le ->prox;
    }
    return le;
}

int lista_vazia(celula *le){
    return le ->prox == NULL;
}


celula *busca_pos(celula *le, int i){
    if(le!=NULL){
       le = le -> prox;
       int j=0;
       while(le != NULL && j != i){
         le = le -> prox;
         j++;
       }
    }
    return le;
}



void insere_depois(celula *le, int y, int x){
    while (le -> prox !=NULL && le -> prox -> dado != y){
       le = le -> prox;
    }
    if (le -> prox == NULL){
       insere_inicio(le, x);
    }else{
       insere_inicio(le -> prox, x);
    }
}

int remove_inicio(celula *le){
    celula *lixo = le->prox;
    if (lixo == NULL) {
       return 0; 
    }
    le ->prox = lixo->prox;
    int dado = lixo ->dado;
    free(lixo);
    return dado;
}

void remove_lista(celula *le, int x){
    while (le -> prox != NULL && le -> prox -> dado != x){
       le = le->prox;
    }
    if (le ->prox != NULL){
       remove_inicio(le);
    } 
}

int remove_ultimo(celula *le, int x){
    while (le -> prox != NULL && le -> prox -> dado != x){
       le = le->prox;
    }
    if (le ->prox != NULL){

       return remove_inicio(le); 
    }
    return 0; 
}


void destroi_lista(celula *le){
    celula *atual = le->prox; 
    celula *lixo;
        while (atual != NULL) {
       lixo = atual;               atual = atual->prox; 
       free(lixo);    
    }
    free(le);
}

void imprime_lista(celula *le) {
    // Pula o nó cabeça
    celula *atual = le->prox; 
        printf("Lista: [ ");
    if (atual == NULL) {
       printf("(vazia) ");
    }
    while (atual != NULL) {
       printf("%d -> ", atual->dado);
       atual = atual->prox;
    }
    printf("NULL ]\n");
}


// --- MAIN PARA TESTAR SUAS FUNÇÕES ---
int main() {
    setlocale(LC_ALL, "Portuguese");
    printf("--- Criando lista ---\n");
    celula *minha_lista = cria_lista();
    imprime_lista(minha_lista);
        if (lista_vazia(minha_lista)) {
       printf("Teste 'lista_vazia': OK\n");
    } else {
       printf("Teste 'lista_vazia': FALHOU\n");
    }

    printf("\n--- Testando insere_inicio ---\n");
    insere_inicio(minha_lista, 10);
    insere_inicio(minha_lista, 20);
    insere_inicio(minha_lista, 30);
    // A lista deve ser: 30 -> 20 -> 10
    imprime_lista(minha_lista);

    printf("\n--- Testando insere_depois ---\n");
    // Inserir 25 depois do 20
    printf("Inserindo 25 depois de 20...\n");
    insere_depois(minha_lista, 20, 25);
    // A lista deve ser: 30 -> 20 -> 25 -> 10
    imprime_lista(minha_lista);
    
    // Tentar inserir 99 depois do 5 (que não existe)
    printf("Inserindo 99 depois de 5 (não existe)...\n");
    insere_depois(minha_lista, 5, 99);
    // Deve inserir no fim: 30 -> 20 -> 25 -> 10 -> 99
    imprime_lista(minha_lista);

    printf("\n--- Testando busca ---\n");
    celula *no_encontrado = busca(minha_lista, 25);
    if (no_encontrado != NULL) {
       printf("Busca por 25: Encontrado (dado = %d)\n", no_encontrado->dado);
    } else {
       printf("Busca por 25: Não encontrado\n");
    }

    printf("\n--- Testando busca_pos ---\n");
    // Posição 0 é o 30, Posição 2 é o 25
    celula *no_pos = busca_pos(minha_lista, 2);
    if (no_pos != NULL) {
       printf("Busca por pos 2: Encontrado (dado = %d)\n", no_pos->dado);
    } else {
       printf("Busca por pos 2: Não encontrado\n");
    }

    printf("\n--- Testando remove e remove_ultimo ---\n");
    // Lista atual: 30 -> 20 -> 25 -> 10 -> 99
    printf("Removendo 20 (void remove_lista)...\n"); // (Também corrigi o printf para ficar claro)
    remove_lista(minha_lista, 20); // <--- CORRIGIDO
    // Lista: 30 -> 25 -> 10 -> 99
    imprime_lista(minha_lista);
    
    printf("Removendo 99 (int remove_ultimo)...\n");
    int dado_removido = remove_ultimo(minha_lista, 99);
    printf("Dado removido: %d\n", dado_removido);
    // Lista: 30 -> 25 -> 10
    imprime_lista(minha_lista);

    printf("\n--- Testando remove_inicio ---\n");
    // Cuidado: remove_inicio(minha_lista) remove o *primeiro* item (30)
    printf("Removendo o primeiro item (30)...\n");
    remove_inicio(minha_lista);
    // Lista: 25 -> 10
    imprime_lista(minha_lista);

    printf("\n--- Destruindo lista ---\n");
    destroi_lista(minha_lista);
    printf("Lista destruída.\n");
    // Se tentássemos imprimir agora, o programa quebraria (correto)
    // imprime_lista(minha_lista); // <-- ISSO CAUSARIA UM CRASH

    return 0;
}