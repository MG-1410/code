#include <stdio.h>
#include <stdlib.h>

struct node
{
    int i;
    struct node *link;
};

struct node* add_at_end(struct node *ptr , int data)
{
    struct node *temp= (struct node *)malloc(sizeof(struct node));
    temp->i=data;
    temp->link=NULL;
    ptr->link=temp;
    return temp;
}

struct node* rem_at_beg(struct node *head)
{
    struct node *ptr=head;
    ptr=ptr->link;
    free(head);
    head=ptr;
    return  head;
};
int main()
{
    struct node *head= (struct node *)malloc(sizeof(struct node));
    head->i=14;
    head->link=NULL;
    struct node  *ptr=head;
    ptr=add_at_end(ptr,28);
    ptr=add_at_end(ptr,42);
    ptr=add_at_end(ptr,90);
    head=rem_at_beg(head);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->link;
    }
}
