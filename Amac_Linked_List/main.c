#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

int AddItemAfterThis(struct node * np,int value)
{
    struct node *after;
    after = np->next;
    np->next = malloc(sizeof(struct node));
    if(np->next == NULL)
    {
        np->next = after;
        printf("Memory Error");
        exit(1);
        return 1;
    }

    np->next->value = value;
    np->next->next = after;

    return 0;
}

int RemoveItemAfterThis(struct node * np)
{
    struct node *toFree;
    toFree = np->next;
    np->next=np->next->next;
    free(toFree);
    return 0;
}

struct node *FindItemByValue(struct node * np,int value)
{
    struct node *current;
    current = np;

    while(current->value != value && current->next !=NULL)
    {
        current = current->next;
    }

    if(current->value == value)
    {
        return current;
    }

    //no item with that value detected.
    return NULL;
};

int RemoveItemByValue(struct node * np,int value)
{
    struct node *current;
    struct node *old;
    current = np;

    while(current->value != value && current->next !=NULL)
    {
        old = current;
        current = current->next;
    }

    if(current->value == value)
    {
        old->next = old->next->next;
        free(current);
        return 0;
    }

    return 1;
}

void Print_List(struct node * np)
{
    struct node *current;
    current = np;
    while(current->next != NULL)
    {
        printf("\n%d",current->value);
        current = current->next;
    }
    printf("\n%d",current->value);

    return;
}

int main()
{

    struct node *hp;

    hp = malloc(sizeof(struct node));

    hp ->next = NULL;
    hp ->value = 22;

    hp ->next = malloc(sizeof(struct node));
    hp ->next->value = 55;
    hp ->next->next = NULL;

    hp ->next->next = malloc(sizeof(struct node));
    hp ->next->next->value = 99;
    hp ->next->next->next = NULL;

    AddItemAfterThis(hp->next,44);
    AddItemAfterThis(hp->next,67);
    AddItemAfterThis(hp->next,45);
    AddItemAfterThis(hp->next,23);
    AddItemAfterThis(hp->next,11);
    Print_List(hp);

    printf("\n-----");

    RemoveItemByValue(hp,45);

    Print_List(hp);

    //Print_List( FindItemByValue(hp,11));

    //RemoveItemAfterThis(hp->next);

    //Print_List(hp);

    return 0;
}

