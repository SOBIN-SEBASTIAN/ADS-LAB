#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
    struct node *prev;
}*head=NULL,*temp,*temp2;
void insert_beg(int n)
{
    struct node * newnode=malloc(sizeof(struct node));
    newnode->data=n;
    if(head==NULL)
    {
        newnode->next=NULL;
        head = newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    printf("\n one item is inserted to the List \n");
}
//Insert in last position>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void insert_end(int n)
{
   struct node * newnode=malloc(sizeof(struct node));
    newnode->data=n;
    if(head==NULL)
    {
        newnode->next=NULL;
        head = newnode;
        printf("\n one item is inserted to the List \n");
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=NULL;
        printf("\n one item is inserted to the List \n");
    }
}
insert_spec(int n)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=n;
    if(head==NULL)
    {
        newnode->next=NULL;
        newnode->prev=NULL;
        head = newnode;
        printf("\n one item is inserted to the List \n");
    }
    else
    {
        int key;
        printf("Enter value of node after which you want insert new node:\n");
        scanf("%d",&key);
        temp=head;
        while(temp->data!=key)
        {
            if(temp->next==NULL)
            {
                printf("\n Given key is not found in list.\n");
            }
            else
            {
                 temp=temp->next;
            }
         }
         temp2=temp->next;
         temp->next=newnode;
         newnode->prev=temp;
         newnode->next=temp2;
         temp2->prev=newnode;
    }
}
void delete()
{
    if(head==NULL)
    {
        printf("\n the List is empty,deletion  is not possiable \n");
    }
    else
    {
        temp=head;
        if(temp->next==temp->prev)
        {
            head=NULL;
        }
        else
        {
            head=temp->next;
            temp2=temp->next;
            temp2->prev=NULL;
        }
    printf("\n One item is Deleted from the List \n");
    }
}
void delete_end()
{
    if(head==NULL)
    {
            printf("\n the List is empty,deletion  is not possiable \n");
    }
    else
    {
        temp=head;
        if(temp->prev==temp->next)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            while(temp -> next != NULL)
                  {
                      temp=temp->next;
                  }
        temp2=temp->prev;
        temp2->next=NULL;
        free(temp);
        }
    }
printf("\n One item is Deleted from the List \n");
}
void deleteSpec(int delValue)
{
   if(head == NULL)
      printf("List is Empty!!! Deletion not possible!!!");
   else
   {
      temp=head;
      while(temp->data!=delValue)
      {
         if(temp->next==NULL)
         {
            printf("\nGiven node is not found in the list!!!");
         }
         else
         {
            temp=temp->next;
         }
      }
      if(temp==head)
      {
         head=NULL;
         free(temp);
      }
      else
      {
         temp->prev->next=temp->next;
         free(temp);
      }
      printf("\nOne item is deleted");
   }
}
//function for displaying list elements>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void display()
{
    if(head==NULL)
    {
        printf("\nThe list is Empty \n");
    }
    else
    {
       temp=head;
       while(temp->next!=NULL)
       {
           printf("%d \n",temp->data);
           temp=temp->next;
       }
       printf("%d",temp->data);
    }
}
void main()
{
    int ch,n;
    do{
        printf("Operation in Doubly Linked list\n");
        printf("\n Select the operation : \n 1.Insertion at Beginning \n 2.Insertion at end \n 3.Insertion in between a node \n 4.Delete at front \n 5.Delete at end \n 6.delete from specific mode\n 7.display");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("\n Enter the value to insert : \n");
            scanf("%d",&n);
            insert_beg(n);
            break;
        case 2:
            printf("\n Enter the value to insert : \n");
            scanf("%d",&n);
            insert_end(n);
            break;
        case 3:
            printf("\n Enter the value to insert : \n");
            scanf("%d",&n);
            insert_spec(n);
            break;
        case 4:
            delete();
            break;
        case 5:
            delete_end();
            break;
        case 6:
            printf("Enter the Node value to be deleted: ");
            scanf("%d",&n);
            deleteSpec(n);
        case 7:
            display();
            break;
        }
        printf("\nDo You Want to Continue....\n 1.Yes \n 2.No");
        scanf("%d",&ch);
    }while(ch<7);
}
