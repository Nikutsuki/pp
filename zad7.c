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

void swap_nodes(struct element *list, struct element *first, struct element *second)
{
    if (list == NULL)
        return;
    if (first == NULL)
        return;
    if (second == NULL)
        return;
    if (first == second)
        return;
    if (first->next == second) {
        find_previous(list, first)->next = second;
        first->next = second->next;
        second->next = first;
        return;
    }
    if (second->next == first) {
        find_previous(list, second)->next = first;
        second->next = first->next;
        first->next = second;
        return;
    }
    struct element *tmp_first_next = first->next;
    struct element *tmp_second_next = second->next;
    struct element *tmp_first_prev = find_previous(list, first);
    struct element *tmp_second_prev = find_previous(list, second);
    tmp_first_prev->next = second;
    tmp_second_prev->next = first;
    first->next = tmp_second_next;
    second->next = tmp_first_next;
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
    swap_nodes(e1, e4, e3);
    printf("\n");
    it_print(e1);
}