//Dada um pilha de inteiros
//use apenas operações de pilha para ordená -la 
//em ordem crescente (pode usar pilha auxiliar)
#include <stdio.h>

#define TAM 100

int pilha[TAM];
int topo = -1;

int pilhaAux[TAM];
int topoAux = -1;

void push(int valor) {
    topo++;
    pilha[topo] = valor;
}

int pop() {
    int valor = pilha[topo];
    topo--;
    return valor;
}

void pushAux(int valor) {
    topoAux++;
    pilhaAux[topoAux] = valor;
}

int popAux() {
    int valor = pilhaAux[topoAux];
    topoAux--;
    return valor;
}

int main() {
    push(4);
    push(1);
    push(3);
    push(2);
    push(5);

    printf("Pilha original:\n");
    for (int i = 0; i <= topo; i++) {
        printf("%d\n", pilha[i]);
    }

    while (topo >= 0) {
        int temp = pop();
        while (topoAux >= 0 && pilhaAux[topoAux] > temp) {
            push(popAux());
        }
        pushAux(temp);
    }

    while (topoAux >= 0) {
        push(popAux());
    }

    printf("\nPilha ordenada (ordem crescente):\n");
    for (int i = 0; i <= topo; i++) {
        printf("%d\n", pilha[i]);
    }

    return 0;
}
