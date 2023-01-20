#include<stdio.h>
#include<stdlib.h>
 struct node
 {
     int data;
     struct node*next;
 }*head=NULL,*temp;
 //Insert at Beginning.....................................
 void in_begn(int value)
 {
     struct node*newnode=malloc(sizeof(struct node));
     newnode->data=value;
     if(head==NULL)
     {
         head=newnode;
         newnode->next=NULL;
     }
     else
     {
         newnode->next=head;
         head=newnode;
     }
  printf("\n /////////// One item is Inserted /////////// \n ");
 }

 //Insert at end .............................................
 void in_end( int value)
 {
     struct node* newnode=malloc(sizeof(struct node));
     newnode->data=value;
     newnode->next=NULL;
     if(head==NULL)
     {
         head=newnode;
     }
     else
     {
         temp=head;
         while(temp->next!=NULL)
         {
            temp=temp->next;
         }
         temp->next=newnode;
     }
     printf("\n /////////// One item is Inserted /////////// \n ");
 }
//insert between node//////////////////////////////////////////////////////////////////
void in_node(int value)
{
    struct node *newnode=malloc(sizeof(struct node));
    newnode->data=value;
    printf("\n Enter the key after which you want to insert:\n");
    int key;
    scanf("%d",&key);
    if(head==NULL)
     {
         newnode->next=NULL;
         head=newnode;
        printf("\n /////////// One item is Inserted /////////// \n ");
     }
    else
     {
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
         newnode->next=temp->next;
     temp->next=newnode;
     }
}
//Function for deleting first node////////////////////////////////////////////
void del()
{
    if (head==NULL)
    {
        printf("\n Linked list is empty......\n");
    }
    else
    {
        struct node*temp;
        temp=head;
        if(temp->next==NULL)
        {
            head=NULL;
            printf("\n /////////// One item is Deleted. /////////// \n ");
        }
        else
        {
            head=temp->next;
            free(temp);
            printf("\n /////////// One item is Deleted. /////////// \n ");
        }
    }
}
//function for deleting at end
void del_end()
{
    if(head==NULL)
    {
        printf("\n Linked list is empty......\n");
    }
   else
   {
       struct node*temp1;
       struct node*temp2;
       temp1=head;
       if(temp1->next==NULL)
       {
           head=NULL;
           printf("\n /////////// One item is Deleted. /////////// \n ");
       }
       else
       {
        while(temp1->next!=NULL)
         {
            temp2=temp1;
            temp1=temp1->next;
         }
        temp2->next=NULL;
       }
   }
}

void del_in(int key)
{
    if(head==NULL)
    {
        printf("\n Linked list is empty......\n");
    }
   else
   {
       struct node*temp1;
       struct node*temp2;
       temp1=head;
       if(temp1->next==NULL)
       {
           head=NULL;
           printf("\n /////////// One item is Deleted. /////////// \n ");
       }
       else
       {
        while(temp1->data!=key)
         {
            temp2=temp1;
            temp1=temp1->next;
         }
        temp2->next=temp1->next ;
        printf("\n /////////// One item is Deleted. /////////// \n ");
        free(temp1);
       }
   }
}
//Function for Display in Linked list elements////////////////////////////////
void display()
{
    if(head==NULL)
    {
        printf("\n Linked list is empty \n");
    }
    else
    {
        temp=head;
        while(temp->next !=NULL)
        {
            printf("\n  %d",temp->data);
            temp = temp -> next;
        }
        printf("\n %d \n",temp -> data);
    }
}
void main()
{
    int ch,n;
    do{
        printf("\n \\\\\\\\\\\\\\\ Linked list //////////// \n");
        printf("\n Select the operation : \n 1.Insertion at Beginning \n 2.Insertion at end \n 3.Insertion in between a node \n 4.Delete at front \n 5.Delete From End \n 6.delete a specific node \n 7.display");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\n Enter value to insert : \n");
            scanf("%d",&n);
            in_begn(n);
            break;
        case 2:
            printf("\n Enter value to insert : \n");
            scanf("%d",&n);
            in_end(n);
            break;
        case 3:
            printf("\n Enter value to insert : \n");
            scanf("%d",&n);
            in_node(n);
            break;
        case 4:
            del();
            break;
        case 5:
            del_end();
            break;
        case 6:
            printf("\n Enter value to be deleted : \n");
            scanf("%d",&n);
            del_in(n);

        case 7:
            display();
            break;
        }
        printf("Do you want to continue?? \n press 1 for yes \n press 2 for no ");
        scanf("%d",&ch);
    }while(ch==1);

}
