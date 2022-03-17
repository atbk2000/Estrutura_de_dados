
#ifndef __QUEUE__
#define __QUEUE__

#ifndef NULL
#define NULL ((void *) 0)
#endif

//------------------------------------------------------------------------------
// estrutura de uma fila duplamente encadeada de números inteiros
typedef struct queue_t
{
	struct queue_t* prev;  // aponta para o elemento anterior na fila
	struct queue_t* next;  // aponta para o elemento seguinte na fila
	int valor;
} queue_t;

//------------------------------------------------------------------------------
// Retorna o tamanho da fila
int queue_size(queue_t* queue);

//------------------------------------------------------------------------------
// Escreve os elementos da fila
void queue_print(queue_t* queue);

//------------------------------------------------------------------------------
// Insere elemento no fim da fila
int queue_append(queue_t** queue, int valor);

//------------------------------------------------------------------------------
// Remove o primeiro elemento da fila
int queue_remove(queue_t** queue);

#endif
