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

struct node* rem_at_pos(struct node **head,int pos)
{
    struct node *current=*head;
    struct node *previous=*head;
    while( pos != 1 )
    {
        previous=current;
        current=current->link;
        pos--;
    }
    previous->link=current->link;
    free(current);
    current=NULL;

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
    rem_at_pos(&head,2);

    ptr=head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->i);
        ptr=ptr->link;
    }
}
