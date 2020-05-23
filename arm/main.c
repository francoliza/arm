#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct nodo_list{
	uint32_t value;
	struct nodo_list* next;
	struct nodo_list* prev;
}nodo;

typedef struct list{
	struct nodo_list* first;
	struct nodo_list* last;
}list;

void listPrint(list* l1){
	printf("[");
	nodo* tmp = l1->first;
	while(tmp){
		printf("%d",tmp->value);
		tmp = tmp->next;
		if(tmp){
			printf(",");
		}
	}
	printf("]\n");
}

list* newList(){
	list* tmp = malloc(sizeof(list));
	tmp->first = NULL;
	tmp->last = NULL;
	return tmp;
}

list* addFirst(list* l1, uint32_t value){
	nodo* tmp = l1->first;

	tmp = malloc(sizeof(nodo));
	tmp->value = value;
	
	if(l1->first == NULL){
		tmp->next = NULL;
		tmp->prev = NULL;
		l1->first = tmp;
	}else{
		nodo* primero = l1->first;
		tmp->next = primero;
		primero->prev = tmp;
		l1->first = tmp;
	}
}

int main(){

	list* lista = newList();

	addFirst(lista, 32);
	addFirst(lista, 22);
	addFirst(lista, 123);

	listPrint(lista);

	return 0;
}