#include<stdio.h>
#include<stdlib.h>
int q[10],f=-1,r=-1,i,size;
int ch;
void insert(){
 if((r==size-1 &&  f==0) ||(f)-(r)==1){
  printf("\nqueue is full");
 }
 else{
  if(r==size-1){
   r=-1;
  }
  if(f==-1){
   f=0; 
  }
  r++;
  printf("\nEnter a value :");
  scanf("%d",&q[r]);
 }
}
void delete(){
 if(f==-1){
  printf("\n\nQueue is empty");
 }
 else{
  if(f==r){
   q[f]=0;
   f=r=-1;
  }
  else if(f==size-1 && q[0]>0){
   q[f]=f=0;
  } 
  else{  
   q[f]=0;  
   f++; 
  }   
 }
}
void main(){
 printf("Enter queue size :");
 scanf("%d",&size);
 system("clear");
 do{
  printf("\n\n1.Insert\n2.Deletes\n3.Display\n5.exit");
  printf("\n\nEnter your choice :");
  scanf("%d",&ch);
 
  if(ch==1){
   insert();
  }
  if(ch==2){
   delete();
  }
  if(ch==3){
   for(i=size-1; i>=0; i--){
    printf("\n|%d|",q[i]);
    if(i==r)
     printf("<-rear");
    if(i==f)
     printf("<-front");   
   }
  }
 }while(ch!=5);
}
