#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TAM 10

int resp;


typedef struct {
	int dados[TAM];
	int topo;
} Pilha;


bool isEmpty(Pilha *p) {
	return p->topo == -1;
}


void inicializar(Pilha *p) {
	p->topo = -1;
}


void push(Pilha *p, int data) {
	if(p->topo == TAM-1) {
		printf("Pilha Cheia!\n");
		return;
	}
	p->topo++;
	p->dados[p->topo] = data;
}


void imprimePilha(Pilha *p){
	if(isEmpty(p)) {
		printf("Pilha Vazia\n");
		return;
	}
	printf("Pilha: ");
	int i;
	for(i = 0; i <= p->topo; i++) {
		printf("%d -> ", p->dados[i]);
	}
	printf("Top");
}


void top(Pilha *p) {
	if(isEmpty(p)) {
		printf("Pilha Vazia!\n");
		return;
	}
	printf("%d", p->dados[p->topo]);
}


int pop(Pilha *p) {
	if(isEmpty(p)) {
		printf("\nPilha Vazia!\n");
		return 0;
	}
	int temp = p->dados[p->topo];
	p->topo--;
	return temp;
}


main() {
	
	
	srand(time(NULL));
	int vetor[TAM], i;
	Pilha pilha;
	inicializar(&pilha);
	
	for (i = 0; i < TAM; i++) {
		vetor[i] = rand() % 90 + 10	;	
	}
	
	printf("Valores preenchidos no vetor:\n");
	
	for (i = 0; i < TAM; i++) {
		printf("%d ", vetor[i]);
		push(&pilha, vetor[i]);
	}
	
	printf("\n\nVetor invertido utilizando a pilha:\n");
	
	for (i = 0; i < TAM; i++) {
		vetor[i] = pop(&pilha);	
	}
	
	for (i = 0; i < TAM; i++) {
		printf("%d ", vetor[i]);
	}
}
