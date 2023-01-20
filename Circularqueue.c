#include<stdio.h>
#include<stdlib.h>
 struct node
 {
     int data;
     struct node*next;
 }*front=NULL,*rear=NULL,*temp;
 void enqueue()
 {
     int value;
     printf("Enter the value to be inserted :- ");
     scanf("%d",&value);
     struct node*newnode=malloc(sizeof(struct node));
     newnode->data=value;
     if(front==NULL && rear==NULL)
     {
        front=rear=newnode;
        rear->next=front;
     }
     else
    {
        rear->next=newnode;
        rear=newnode;
        newnode->next=front;
    }
    printf("\n One item is inserted \n");
 }

 void dequeue()
 {
    if(front==NULL && rear==NULL)
     {
         printf("Queue is empty!!! \n");
     }
     else{
        front=front->next;
        rear->next=front;
        printf("One Item is deleted form queue\n");
     }
 }
 void display()
 {
    if(front==NULL && rear==NULL)
     {
         printf("Queue is empty!!! \n");
     }
     else
     {
         temp=front;
         while(temp!=rear)
         {
             printf("\n %d",temp->data);
             temp=temp->next;
         }
          printf("\n %d",temp->data);

     }
 }
 void main()
 {
     int ch;
     do{
        printf("Circular Queue Operations \n 1.Enqueue \n 2.Dequeue \n 3.Display \n Choose your Operation :-\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
        }
        printf("\n>>> Do you Want To Continue......\n  1.yes \n  2.no");
        scanf("%d",&ch);
     }while(ch==1);
 }
