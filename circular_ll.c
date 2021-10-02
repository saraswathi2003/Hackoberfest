#include <stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
};
struct node*head=NULL;
void traverse( ){
    struct node*ptr=head;
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    ptr=head->next;
    do{
        printf("%d\n",ptr->info);
        ptr=ptr->next;
    }while(ptr!=head->next);
    }
    //do{
      //  printf("%d\n",ptr->next->info);
        //ptr=ptr->next;
    //}while(ptr!=head);
void insertAtFront( ){
    int data;
    printf("enter the data\n");
    scanf("%d",&data);
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=data;
    if(head==NULL){
        ptr->next=ptr;
        head=ptr;
        return;
    }
    ptr->next=head->next;
    head->next=ptr;

}
void insertAtEnd( ){
     int data;
    printf("enter the data\n");
    scanf("%d",&data);
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=data;
    ptr->next=head->next;
    head->next=ptr;
    head=ptr;

}
void insertAtPosition(){
    int data,index;
    printf("enter the data\n");
    scanf("%d",&data);
    printf("enter the index\n");
    scanf("%d",&index);
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    struct node*p=head;
    int i=0;
    while(i!=index){
        p=p->next;
        i++;
    }
    ptr->info=data;
    ptr->next=p->next;
    p->next=ptr;

}
void deleteatbegining(){
    struct node*ptr=head->next;
    head->next=ptr->next;
    free(ptr);
}
void deleteatindex( ){
    int index;
    printf("enter the index\n");
    scanf("%d",&index);
    struct node*p=head;
    struct node*q=head->next;
    int i=0;
    while(i!=index){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    free(q);

}

int main()
{
     int choice;
    while (1) {
  
        printf("\n\t1  To see list\n");
        printf("\t2  For insertion at starting\n");
        printf("\t3  For insertion atend\n");
        printf("\t4  For insertion at any position\n");
        printf("\t5  For delete at begining\n");
        printf("\t6  For delete atindex\n");
        printf("\t7  exit\n");  
        printf("\tEnter your choice: ");
        scanf("%d",&choice);
        switch (choice) {
        case 1:
            traverse();
            break;
        case 2:
            insertAtFront();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteatbegining();
            break;
        case 6:
            deleteatindex();
            break;    
        case 7:
            exit(1);
        default:
            printf("invalid choice\n");
         }
    }        
    return 0;

  
}
