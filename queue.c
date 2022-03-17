#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

int queue_size(queue_t* queue) {
	if (queue == NULL){
		return 0;
	}

	queue_t* iterador = queue;
	int size = 0;

	do {
		size += 1;
		iterador = iterador->next;
	} while (iterador != queue);

	return size;
}

void queue_print(queue_t* queue)
{
	if (queue == NULL) {
		printf("\nA fila esta vazia\n");
		return;
	}

	queue_t* iterador = queue;

	printf("\nFila: ");

	do {

		printf("%d<%d>%d ", iterador->prev->valor, iterador->valor, iterador->next->valor);

		iterador = iterador->next;

	} while (iterador != queue);
}

int queue_append(queue_t** queue, int valor)
{
	if (*queue == NULL){
		queue_t* aux = malloc(sizeof(queue_t));

		aux->next = aux;
		aux->prev = aux;
		aux->valor = valor;

		*queue = aux;

		return 0;
	}

	queue_t* aux = malloc(sizeof(queue_t));

	aux->next = *queue;
	aux->prev = (*queue)->prev;
	aux->valor = valor;

	(*queue)->prev->next = aux;
	(*queue)->prev = aux;

	return 0;
}

int queue_remove(queue_t** queue)
{
	if (*queue == NULL) {
		return 0;
	}

	if (queue_size(*queue) == 1) {
		queue_t* out = *queue;
		free(out);

		*queue = NULL;

		return 0;
	}

	queue_t* out = *queue;

	out->prev->next = out->next;
	out->next->prev = out->prev;

	*queue = (*queue)->next;

	free(out);

	return 0;
}

