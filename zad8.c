#include <stdio.h>
#include <stdlib.h>

struct element {
    int value;
    struct element *next;
};

struct element* find_previous(struct element *list, struct element *elem)
{
    if (list == NULL)
        return NULL;
    if (list->next == NULL)
        return NULL;
    if (list->next == elem)
        return list;
    return find_previous(list->next, elem);
}

void delete_node(struct element *list, struct element *elem)
{
    if (list == NULL)
        return;
    if (elem == NULL)
        return;
    if (list == elem) {
        list->value = list->next->value;
        list->next = list->next->next;
        return;
    }
    struct element *tmp = find_previous(list, elem);
    if (tmp == NULL)
        return;
    tmp->next = tmp->next->next;
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
    delete_node(e1, e2);
    printf("\n");
    it_print(e1);
}