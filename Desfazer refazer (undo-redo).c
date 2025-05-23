//Use duas pilhas 
//para simular o comportamento de desfazer e refazer operações 
//(ex: edição de texto)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM 100
#define TAM_STRING 100



char pilhaUndo[TAM][TAM_STRING];
char pilhaRedo[TAM][TAM_STRING];
int topoUndo = -1;
int topoRedo = -1;

void fazerAcao(char acao[]) {
    if (topoUndo < TAM - 1) {
        topoUndo++;
        strcpy(pilhaUndo[topoUndo], acao);
        topoRedo = -1;
    }
}

void desfazer() {
    if (topoUndo >= 0) {
        topoRedo++;
        strcpy(pilhaRedo[topoRedo], pilhaUndo[topoUndo]);
        printf("\n\nDesfez: %s\n", pilhaUndo[topoUndo]);
        topoUndo--;
    } else {
        printf("Nada para desfazer\n");
    }
}

void refazer() {
    if (topoRedo >= 0) {
        topoUndo++;
        strcpy(pilhaUndo[topoUndo], pilhaRedo[topoRedo]);
        printf("Refez: %s\n", pilhaRedo[topoRedo]);
        topoRedo--;
    } else {
        printf("Nada para refazer\n");
    }
}

void mostrarPilhas() {
    printf("\n\nPilha Undo:\n");
    for (int i = 0; i <= topoUndo; i++) {
        printf("%s\n", pilhaUndo[i]);
    }
    printf("\n\nPilha Redo:\n");
    for (int i = 0; i <= topoRedo; i++) {
        printf("%s\n", pilhaRedo[i]);
    }
}

int main() {
    int opcao;
    char acao[TAM_STRING];

    do {
        printf("\n\n1 - Fazer Acao\n");
        printf("2 - Desfazer\n");
        printf("3 - Refazer\n");
        printf("4 - Mostrar Pilhas\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            printf("\n\nDigite a acao: ");
            fgets(acao, TAM_STRING, stdin);
            acao[strcspn(acao, "\n")] = 0;
            fazerAcao(acao);
        } else if (opcao == 2) {
            desfazer();
        } else if (opcao == 3) {
            refazer();
        } else if (opcao == 4) {
            mostrarPilhas();
        }
    } while (opcao != 5);

    return 0;
}
