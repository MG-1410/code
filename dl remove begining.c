#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    struct node *prev;
    struct node *next;
};

struct node* add_at_end(struct node *ptr , int data)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->i=data;
    temp->prev=ptr;
    temp->next=NULL;
    ptr->next=temp;
    return temp;
}
struct node* rem_at_pos(struct node **head,int pos)
{
    struct node *ptr,*ptr2;
    ptr= *head;
    ptr2= *head;
    while(pos != 1)
    {
        ptr2=ptr;
        ptr=ptr->next;
        pos--;
    }
    ptr2->next=ptr->next;
    free(ptr);

};


int main()
{
    struct node *head= (struct node *)malloc(sizeof(struct node));
    head->i=14;
    head->prev=NULL;
    head->next=NULL;
    struct node  *ptr=head;
    ptr=add_at_end(ptr,28);
    ptr=add_at_end(ptr,42);
    ptr=add_at_end(ptr,90);
    rem_at_pos(&head,3);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->next;
    }
}
