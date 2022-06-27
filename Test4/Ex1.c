#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define ITEMS_COUNT 2

typedef struct
{
    uint16_t number;
    char description[251];
    double weight;
    double price;
}Item;

typedef struct node
{
    Item items;
    struct node *next;   
}List;

int randint(int min, int max);
double randReal(double min, double max);
char* randomDescription(char *description);
void push(List **list, Item item);
void print(List *list);
double totalItemsWeight(List *list);
List* minPriceItem(List *list);

int main()
{
    srand(time(NULL));
    List *list = NULL;
    for (int i = 0; i < ITEMS_COUNT; i++)
    {
        Item currentItem;
        currentItem.number = randint(0, INT16_MAX);
        randomDescription(currentItem.description);
        currentItem.weight = randReal(0.1, 100.0);
        currentItem.price = randReal(1.0, 1500.0);
        push(&list, currentItem);
    }

    double total = totalItemsWeight(list);
    printf("Total weight: %lf\n", total);
    List* item = minPriceItem(list);
    printf("Item with min price: %lf, number: %d\n", 
    item->items.price, item->items.number);

    print(list);
    
    return 0;
}

List* minPriceItem(List *list)
{
    List *current = list;
    double minPrice = INT16_MAX;
    List *item = malloc(sizeof(List));
    while (current != NULL)
    {
        if((minPrice - current->items.price) > 0.001)
        {
            minPrice = current->items.price;
            item->items = current->items;
            item->next = current->next;
        }
        
        current = current->next;
    } 
    return item;
}

double totalItemsWeight(List *list)
{
    List *current = list;
    double total = -1;
    while (current != NULL)
    {
        total += current->items.weight;
        current = current->next;
    } 
    return total;
}

void print(List *list)
{
    List *current = list;
    while (current != NULL)
    {
        printf("Number: %d, ", current->items.number);
        printf("Description: %s, ", current->items.description);
        printf("Weight: %lf, ", current->items.weight);
        printf("Price: %lf\n", current->items.price);
        current = current->next;
    }    
}

void push(List **list, Item item)
{
    List* newEl = malloc(sizeof(List));
    newEl->items = item;
    newEl->next = *list;
    *list = newEl;
}

char* randomDescription(char *description)
{
    unsigned index = 0;
    int n = randint(1, 10);
    int words = randint(5, 10);

    description[index++] = randint('A', 'Z');

    for (int i = 0; i < words; i++)
    {
        for (int j = 0; j < n; j++)
        {
            description[index++] = randint('a', 'z');
        }
        description[index++] = ' ';
    }

    description[index] = '\0';
    return description;
}

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}