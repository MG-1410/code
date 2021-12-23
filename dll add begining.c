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
struct node* add_at_pos(struct node *head,int data,int pos)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->i=data;
    temp->prev=NULL;
    temp->next=NULL;
    struct node *ptr=head;
    while(pos != 2)
    {
        ptr=ptr->next;
        pos--;
    }
    temp->next=ptr->next;
    temp->prev=ptr;
    ptr->next=temp;

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
    add_at_pos(head,10,3);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->next;
    }
}
