#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;   
}Queue;

int push(Queue **q, int newElement);
int pop(Queue **q, int *element);
void print(Queue *q);
void freeQueue(Queue **q);

int main()
{
    Queue *queue = NULL;
    int element = 0;

    push(&queue, 23);
    push(&queue, 21);
    push(&queue, 125);
    push(&queue,-42);
    push(&queue, 71);

    print(queue);

    pop(&queue, &element);
    pop(&queue, &element);
    pop(&queue, &element);

    print(queue);

    freeQueue(&queue);
    return 0;
}

int push(Queue **q, int newElement)
{
    Queue *current = *q;

    Queue *ptr = malloc(sizeof(Queue));
    if(ptr == NULL)
    {
        return -1;
    }
    ptr->data = newElement;
    ptr->next = NULL;

    if(current == NULL)
    {
        *q = ptr;
        return 0;
    }
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = ptr;
    return 0;
}

int pop(Queue **q, int *element)
{
    Queue *current = *q;

    *element = current->data;
    *q = (*q)->next;
    free(current);
    return current->data;
}

void print(Queue *q)
{
    Queue *current = q;

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void freeQueue(Queue **q)
{
    Queue *current = *q;
    Queue *prev;

    while (current != NULL)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
    *q = NULL;
}