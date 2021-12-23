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
struct node* add_at_beg(struct node *head,int data)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->i=data;
    temp->prev=NULL;
    temp->next=head;
    head=temp;
    return head;
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
    head=add_at_beg(head,10);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->next;
    }
}
