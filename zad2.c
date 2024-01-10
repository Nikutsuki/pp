#include <stdio.h>
#include <stdlib.h>

struct element {
    int value;
    struct element *next;
};

// count elements 

void count_elements_it(struct element *list)
{
    int count = 0;
    while (list != NULL) {
        count++;
        list = list->next;
    }
    printf("Number of elements: %d\n", count);
}

void count_elements_rec(struct element *list, int count_old)
{
    int count = count_old;
    if (list == NULL) {
        printf("Number of elements: %d\n", count);
        return;
    }
    count++;
    count_elements_rec(list->next, count);
}

int main()
{
    struct element* e1 = malloc(sizeof(struct element));
    struct element* e2 = malloc(sizeof(struct element));
    struct element* e3 = malloc(sizeof(struct element));
    struct element* e4 = malloc(sizeof(struct element));

    e1->value = 1;
    e2->value = 2;
    e3->value = 3;
    e4->value = 4;

    e1->next = e2;
    e2->next = e3;
    e3->next = e4;
    e4->next = NULL;

    count_elements_rec(e1, 0);
}