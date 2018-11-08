#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
      int info;
      char name[20];
      struct node *next;
}*start;

void InsertBeg();
void display();
void DeletionBeg();
void count();
void InsertEnd();
void DeletionEnd();
void InsertMid();
void DeletionMid();
void rev();
void sort();

void main(){
  int ch;
  clrscr();
  printf("\nA Program By Chanpreet Singh");
  while(1){
	printf("\n\t\t\tMAIN MENU\n");
	printf("\t\t\t---------\n");
	printf("\t\t1 Insertion At Beginning\n");
	printf("\t\t2 Insert At End\n");
	printf("\t\t3 Insert At A User Defined Position\n");
	printf("\t\t4 Display\n");
	printf("\t\t5 Deletion From Beginning\n") ;
	printf("\t\t6 Deletion From End\n");
	printf("\t\t7 Deletion From A User Defined Position\n");
	printf("\t\t8 Reverse the Linked List\n");
	printf("\t\t9 Count \n");
	printf("\t\t10 Sort such that even roll nos. come first and then the odd roll nos.\n");
	printf("\t\t11 Exit");
	printf("\n\t\tEnter your choice:");
	scanf("%d",&ch);
	switch(ch){
	case 1: InsertBeg();
		break;
	case 2: InsertEnd();
		break;
	case 3: InsertMid();
		break;
	case 4: display();
		break;
	case 5: DeletionBeg();
		break;
	case 6: DeletionEnd();
		break;
	case 7: DeletionMid();
		break;
	case 8: rev();
		break;
	case 9: count();
		break;
	case 10: sort();
		break;
	case 11: printf("Exiting!!");
		getch();
		exit(1);
	default: printf("Wrong Choice!!");

		}
	}
}

void InsertBeg(){
int info1;
struct node *new_node;
new_node=(struct node *)malloc(sizeof(struct node));
printf("\nEnter name of new student:");
scanf("%s",&new_node->name);
printf("\nEnter Roll No. of new student:");
scanf("%d",&new_node->info);
if(start==NULL)
  start=new_node;
else{
       new_node->next=start;
       start=new_node;

      }
printf("\nInsertion Successful\n");
getch();
clrscr();
}

void display(){
struct node *node1;
if(start==NULL)
  {
   printf("\nList is already empty");
   getch();
   clrscr();
   return;
  }
node1=start;
printf("\nThe linked list is:\n");
while(node1!=NULL)
       {
	   printf("Roll No:%d\t\tName:%s\n",node1->info,node1->name);
	   node1=node1->next;
	}

getch();
clrscr();
}

void DeletionBeg(){
struct node *del;
if(start==NULL){
   printf("\nList is already empty");
   return;
  }
del=start;
start=start->next;
printf("Record deleted is:\tRoll No:%d\t\tName:%s\n",del->info,del->name);
free(del);
getch();
clrscr();
}

void count(){
int ctr=0;
struct node *x;
x=start;
while(x!=NULL)
     {
	x=x->next;
	ctr++;
     }
printf("The number of Records are:%d",ctr);
getch();
clrscr();
}

void InsertEnd(){
int info1;
struct node *node1;
struct node *node2=(struct node *)malloc(sizeof(struct node));
printf("\nEnter name of new student:");
scanf("%s",&node2->name);
printf("\nEnter Roll No of new student:");
scanf("%d",&node2->info);
node2->next=NULL;
if(start==NULL)
   start=node2;
else{
      node1=start;
      while(node1->next!=NULL) {
	    node1=node1->next;
			    }
      node1->next=node2;
	}
printf("\nInsertion Successful\n");
getch();
clrscr();
}

void DeletionEnd(){
struct node *p,*q;
if(start==NULL)
  {
   printf("Underflow\n");
    getch();
    clrscr();
    return;
   }

p=start;
q=p->next;
while(q->next!=NULL)
   {
   q=q->next;
   p=p->next;
   }
printf("The record deleted is:\t\tRoll No:%d\t\tName:%s\n",q->info,q->name);
free(q);
p->next=NULL;
getch();
clrscr();
}

void InsertMid(){
struct node *new_node=(struct node *)malloc(sizeof(struct node));
struct node *q,*p;
int loc,i;
p=start;
q=p->next;
printf("\nEnter the position where you want to enter the node:");
scanf("%d",&loc);
printf("\nEnter name of new student:");
scanf("%s",&new_node->name);
printf("Enter the Roll no of the new node:");
scanf("%d",&new_node->info);
for(i=1;i<loc-1;i++)
   {
   p=p->next;
   q=q->next;
   }
p->next=new_node;
new_node->next=q;
printf("\nInsertion Successful\n");
getch();
clrscr();
}

void DeletionMid(){
struct node *q,*p;
int loc,i;
p=start;
q=p->next;
printf("\nEnter the position of the node to be deleted:");
scanf("%d",&loc);
for(i=1;i<loc-1;i++)
   {
   p=p->next;
   q=q->next;
   }
p->next=q->next;
printf("The Record deleted is:\t\tRoll no:%d\t\tName:%s\n",q->info,q->name);
free(q);
getch();
clrscr();
}

void rev(){
struct node *prev,*current,*next;
current=start;
prev=next=NULL;
while(current!=NULL){
	next=current->next;
	current->next=prev;
	prev=current;
	current=next;
	}
start=prev;
printf("\nLinked List Reversed\n");
getch();
clrscr();
}

void sort(){
struct node *i,*j;
int temp;
char *temp1=(char *)malloc(100);
if (start==NULL){
	printf("Linked list already empty!!");
	getch();
	clrscr();
	return;
	}
i=start;
while(i!=NULL){
	j=i->next;
	while(j!=NULL){
	     if(((i->info)%2!=0) && ((j->info)%2==0)){
	       temp=i->info;
	       i->info=j->info;
	       j->info=temp;

	       strcpy(temp1,i->name);
	       strcpy(i->name,j->name);
	       strcpy(j->name,temp1);
	       }
	     else j=j->next;
	   }
	i=i->next;
	}
printf("The sorted list is:\n");
display();
}