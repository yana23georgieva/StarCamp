#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

typedef struct node 
{
    int data;
    struct node* next;
} node_t;

void push(node_t** list, int data);
int randint(int min, int max);
void mergeSort(node_t** list, int(*cmp)(int, int));
void frontBackSplit(node_t* list, node_t** front, node_t** back);
node_t* sortedMerge(node_t* listA, node_t* listB, int(*cmp)(int, int));
int cmp(int a, int b);
void print_list(node_t* list);
void listFree(node_t** list);

int main()
{
    node_t* head = NULL;
    srand(time(NULL));

    for (size_t i = 0; i < N; i++)
    {
        push(&head, randint(0, 100));
    }

    print_list(head);
    mergeSort(&head, cmp);
    print_list(head);
    listFree(&head);
    
    return 0;
}

int cmp(int a, int b)
{
    int sum1 = 0, sum2 = 0;
    while(a != 0 && b != 0)
    {
        if(a != 0)
        {
            sum1 += (a%10);
            a /= 10;
        }
        if(b != 0)
        {
            sum2 += (b%10);
            b /= 10;
        }
    }

    return sum1 - sum2;
}

void push(node_t** list, int data)
{
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}

void mergeSort(node_t** list, int(*cmp)(int, int))
{
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    node_t *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}

node_t* sortedMerge(node_t* listA, node_t* listB, int(*cmp)(int, int))
{
    node_t* sorted = NULL;
    if (listA == NULL){
        return listB;
    }
    if (listB == NULL){
        return listA;
    }
    if (cmp(listA->data, listB->data) > 0){
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    } else {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}


void frontBackSplit(node_t* list, node_t** front, node_t** back)
{
    node_t* slow = list;
    node_t* fast = list->next;
    while (fast != NULL){
        fast = fast->next;
        if (fast  != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

void print_list(node_t* list)
{
    node_t* current = list;
    while (current){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void listFree(node_t** list)
{
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}