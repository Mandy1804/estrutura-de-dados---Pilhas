//Dada um pilha de inteiros, 
//remova todos os números pares 
//mantendo a ordem dos ímpares

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
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    push(9);
    push(10);

    printf("Pilha completa:\n");
    for (int i = 0; i <= topo; i++) {
        printf("%d\n", pilha[i]);
    }

    while (topo >= 0) {
        int valor = pop();
        if (valor % 2 != 0) {
            pushAux(valor);
        }
    }

    while (topoAux >= 0) {
        push(popAux());
    }

    printf("\nPilha sem pares:\n");
    for (int i = 0; i <= topo; i++) {
        printf("%d\n", pilha[i]);
    }

    return 0;
}
