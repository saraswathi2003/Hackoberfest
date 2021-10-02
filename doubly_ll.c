#include<stdio.h>
#include<stdlib.h>
struct node {
    int info;
    struct node*prev;
    struct node*next;

}; 
struct node* head=NULL;
void traverse(){
    struct node* ptr=head;
    if(ptr==NULL){
        printf("The linkedlist is Empty\n");
    }
    while(ptr!=NULL){
        printf("%d\n",ptr->info);
        ptr=ptr->next;
    }
    
}
void insertAtFront(){
    int data;
    printf("enter the data\n");
    scanf("%d",&data);
    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=data;
    ptr->next=head;
    ptr->prev=NULL; 
    head=ptr;
}
void insertAtPosition(){
    struct node*ptr;
    int data,index;
    printf("Enter the data which u wanna insert at your index\n");
    scanf("%d",&data);
    printf("enter the index\n");
    scanf("%d",&index);
    ptr=(struct node*)malloc(sizeof(struct node));
    int i=0;
    struct node *p=head;
    while(i!=index-1){
        p=p->next;
        i++;
        }
    ptr->info=data;    
    ptr->next=p->next;
    p->next->prev=ptr;
    ptr->prev=p;
    p->next=ptr;  
}
void insertAtEnd(){
    struct node*ptr;
    int data;
    ptr=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data whichu u wanna insert at your node\n");
    scanf("%d",&data);
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->info=data;
    ptr->next=p->next;
    ptr->prev=p;
    p->next=ptr;


}
void deleteatbegining( ){
    struct node *ptr=head;
    head=head->next;
    head->prev=NULL;
    free(ptr);
}
void deleteatindex(){
    int index;
    printf("enter the index\n");
    scanf("%d",&index);
    struct node*ptr=head;
    struct node*q=head->next;
    int i=0;
    if(index==0){
        printf("Delete at index is not posible\n");
    }
    while(i!=index-1){
        ptr=ptr->next;
        q=q->next;
        i++;
    }
    ptr->next=q->next;
    if(q->next!=NULL){
    q->next->prev=ptr;
    }
    free(q);
}

int main(){
    
     int choice;
    while (1) {
  
        printf("\n\t1  To see list\n");
        printf("\t2  For insertion at starting\n");
        printf("\t3  For insertion at position\n");
        printf("\t4  For insertion at End\n");
        printf("\t5  For delete at Begining\n");
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
            insertAtPosition();
            break;
        case 4:
            insertAtEnd();
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