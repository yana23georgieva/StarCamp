#include <stdio.h>
#include <stdlib.h>

int N;

typedef struct node
{
    int data;
    struct node *next;   
}Node;

void push(Node** list, int data);
Node* insertAfter(Node** list, int skip, int newEl);
void print(Node* list);
void listFree(Node** list);

int main()
{
    Node *list = list;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        push(&list, num);
    }
    
    print(list);

    insertAfter(&list, 3, 5);
    print(list);

    listFree(&list);
    return 0;
}

void push(Node** list, int data)
{
    Node* n = malloc(sizeof(Node));
    n->data = data;
    n->next = *list;
    *list = n;
}

Node* insertAfter(Node** list, int skip, int newEl)
{
    Node* current = *list;

    for(int i = 0; i < skip - 1; i++)
    {
        current = current->next;
    }
    
    Node* n = malloc(sizeof(Node));
    n->data = newEl;
    n->next = current->next;
    current ->next = n;
    N++;
    return n;
}

void print(Node* list)
{
    Node* current = list;
    for(int i = 0; i < N; i++)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void listFree(Node** list)
{
    Node *current = *list, *prev;
    for(int i = 0; i < N; i++)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}