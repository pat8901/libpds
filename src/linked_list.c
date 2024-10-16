#include <linked_list.h>
#include <stdlib.h>
#include <stdio.h>

void slist_print(SingleLinkedList *list)
{
    int count = 0;
    printf("***********************\n");
    if (list->head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        SingleLinkedNode *curr = list->head;
        while (curr != NULL)
        {
            printf("%d: {id: %d}\n", count, curr->id);
            curr = curr->next;
            count++;
        }
    }
}

SingleLinkedList *slist_create()
{
    SingleLinkedList *ptr = (SingleLinkedList *)malloc(sizeof(SingleLinkedList));
    ptr->head = NULL;
    ptr->tail = NULL;

    return ptr;
}

int slist_prepend(SingleLinkedList *list, int id)
{
    SingleLinkedNode *temp = list->head;
    if (temp == NULL)
    {
        SingleLinkedNode *node = malloc(sizeof(SingleLinkedNode));
        node->id = id;
        node->next = NULL;
        list->head = node;
        list->tail = node;
    }
    else
    {
        SingleLinkedNode *node = malloc(sizeof(SingleLinkedNode));
        node->id = id;
        node->next = temp;
        list->head = node;
    }
    return 0;
}

int slist_append(SingleLinkedList *list, int id)
{
    printf("if: %d\n", id);
    SingleLinkedNode *curr = list->head;
    /* No nodes in list */
    if (curr == NULL)
    {
        printf("No nodes in list\n");
        SingleLinkedNode *node = malloc(sizeof(SingleLinkedNode));
        node->id = id;
        node->next = NULL;

        list->head = node;
        list->tail = node;
    }
    /* One or more nodes in list */
    else
    {
        printf("One node in list\n");
        SingleLinkedNode *node = malloc(sizeof(SingleLinkedNode));
        node->id = id;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
    }
    return 0;
}

int slist_remove_head(SingleLinkedList *list)
{
    SingleLinkedNode *temp = list->head;
    if (temp == NULL)
    {
        printf("List is empty!\n");
    }
    else if (list->head == list->tail)
    {
        printf("Found a single node!\n");
        free(temp);
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        printf("Found more than one node!\n");
        list->head = list->head->next;
        temp->next = NULL;
        free(temp);
    }
    return 0;
}

int slist_remove_tail(SingleLinkedList *list)
{
    SingleLinkedNode *temp = list->tail;
    if (list->tail == NULL)
    {
        printf("List is empty\n");
    }
    else if (list->head == list->tail)
    {
        list->head = NULL;
        list->tail = NULL;
        free(temp);
    }
    else
    {
        SingleLinkedNode *prev = list->head;
        SingleLinkedNode *next_prev = prev->next;
        while (next_prev->next != NULL)
        {
            prev = next_prev;
            next_prev = next_prev->next;
        }
        list->tail = prev;
        prev->next = NULL;
        free(temp);
    }
    return 0;
}

void slist_get_id(SingleLinkedList *list, int id)
{
    SingleLinkedNode *temp = list->head;

    if (temp == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        int count = 0;
        while (temp != NULL)
        {
            if (temp->id == id)
            {
                printf("Found %d at index %d\n", id, count);
                return;
            }
            temp = temp->next;
            count++;
        }
    }
    printf("Id not found!\n");
}

void slist_get_index(SingleLinkedList *list, int index)
{
    SingleLinkedNode *temp = list->head;

    if (temp == NULL)
    {
        printf("List is empty!\n");
    }
    else
    {
        int count = 0;
        while (temp != NULL)
        {
            if (count == index)
            {
                printf("Found %d at index %d\n", temp->id, count);
                return;
            }
            temp = temp->next;
            count++;
        }
    }
    printf("Index not found!\n");
}

void slist_remove_list(SingleLinkedList *list)
{
}
