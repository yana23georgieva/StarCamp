#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

void push(node_t** head, int value){
    node_t* temp = malloc(sizeof(node_t));
    temp->data = value;
    temp->next = *head;
    *head = temp;
}

void printElements(node_t* head){
    node_t* current = head;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

int sumElements(node_t* head)
{
    int sum = 0;
    node_t* current = head;

    while (current != NULL)
    {
        sum += current->data;
        current = current->next;
    }

    return sum;
}


int maxElement(node_t* head)
{
    int max = INT_MIN;
    node_t* current = head;

    while (current != NULL)
    {
        if(current->data > max)
        {
            max = current->data;
        }
        current = current->next;
    }

    return max;
}

int main(){
    node_t* head = NULL;
    push(&head, 20);
    push(&head, 40);
    push(&head, 100);
    push(&head, 200);
    printElements(head);
    printf("Sum %d\n", sumElements(head));
    printf("Max %d\n", maxElement(head));
    return 0;
}