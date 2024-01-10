#include <stdio.h>
#include <stdlib.h>

struct element {
    int value;
    struct element *next;
};

void insert_second_element(struct element *list, struct element *new)
{
    if (list == NULL)
        return;
    if (list->next == NULL) {
        list->next = new;
        return;
    }
    struct element *tmp = list->next;
    list->next = new;
    new->next = tmp;
}

void it_print(struct element *list)
{
    while (list != NULL) {
        printf("%d\n", list->value);
        list = list->next;
    }
}


int main()
{
    struct element* e1 = malloc(sizeof(struct element));
    struct element* e2 = malloc(sizeof(struct element));
    struct element* e3 = malloc(sizeof(struct element));
    struct element* e4 = malloc(sizeof(struct element));
    struct element* e5 = malloc(sizeof(struct element));

    e1->value = 1;
    e2->value = 2;
    e3->value = 3;
    e4->value = 4;

    e1->next = e2;
    e2->next = e3;
    e3->next = e4;
    e4->next = NULL;

    it_print(e1);
    insert_second_element(e1, e5);
    it_print(e1);
}