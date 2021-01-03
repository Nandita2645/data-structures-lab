#include<stdio.h>
#include<stdlib.h>
struct node{
	 int info;
	 struct node *llink;
	 struct node *rlink;
	 };
typedef struct node *NODE;
NODE getnode(){
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	if(x==NULL){
		printf("mem full\n");
		exit(0);
		}
	return x;
	}
void freenode(NODE x){
	free(x);
}
NODE dinsert_front(int item,NODE head){
NODE temp,cur;
temp=getnode();
temp->info=item;
cur=head->rlink;
head->rlink=temp;
temp->llink=head;
temp->rlink=cur;
cur->llink=temp;
return head;
}
NODE dinsert_rear(int item,NODE head){
NODE temp,cur;
temp=getnode();
temp->info=item;
cur=head->llink;
head->llink=temp;
temp->rlink=head;
temp->llink=cur;
cur->rlink=temp;
return head;
}
NODE ddelete_front(NODE head){
NODE cur,next;
if(head->rlink==head){
printf("dq empty\n");
return head;
}
cur=head->rlink;
next=cur->rlink;
head->rlink=next;
next->llink=head;
printf("the node deleted is %d",cur->info);
freenode(cur);
return head;
}
NODE ddelete_rear(NODE head){
NODE cur,prev;
if(head->rlink==head){
printf("dq empty\n");
return head;
}
cur=head->llink;
prev=cur->llink;
head->llink=prev;
prev->rlink=head;
printf("the node deleted is %d",cur->info);
freenode(cur);
return head;
}
NODE delete_all_key(int item,NODE head){
NODE prev,cur,next;
int count;
   if(head->rlink==head)  {
     printf("LE");
     return head;
     }
count=0;
cur=head->rlink;
while(cur!=head){
  if(item!=cur->info)
  cur=cur->rlink;
  else
 {
  count++;
  prev=cur->llink;
  next=cur->rlink;
  prev->rlink=next;
  next->llink=prev;
  freenode(cur);
  cur=next;
 }
}
if(count==0)
  printf("key not found");
  else
printf("key found at %d positions and are deleted", count);
return head;
}
void display(NODE head){
NODE temp;
if(head->rlink==head){
printf("dq empty");
return;
}
printf("contents of dq=");
temp=head->rlink;
while(temp!=head){
printf("%d ",temp->info);
temp=temp->rlink;
}
printf("\n");
}
NODE delete_except_one(int item,NODE head){
NODE prev,cur,next;
int count;
  if(head->rlink==head)  {
     printf("LE");
     return head;
     }
count=0;
cur=head->rlink;
while(cur!=head){
  if(item!=cur->info)
  cur=cur->rlink;
  else {
  count++;
    if(count==1){
    cur=cur->rlink;}
  else   {
  prev=cur->llink;
  next=cur->rlink;
  prev->rlink=next;
  next->llink=prev;
  freenode(cur);
  cur=next;
}
 }
}
if(count==0)
  printf("key not found");
  else
 printf("key found at %d positions and are deleted.", count);
return head;
}
NODE insert_leftpos(int item,NODE head){
NODE temp,cur,prev;
if(head->rlink==head){
printf("list empty");
return head;
}
cur=head->rlink;
while(cur!=head){
if(item==cur->info)break;
cur=cur->rlink;
}
 prev=cur->llink;
 printf("enter towards left of %d=",item);
 temp=getnode();
 scanf("%d",&temp->info);
 prev->rlink=temp;
 temp->llink=prev;
 cur->llink=temp;
 temp->rlink=cur;
 return head;
}
NODE insert_rightpos(int item,NODE head){
 NODE temp,cur,next;
if(head->rlink==head){
printf("list empty");
return head;
}
cur=head->rlink;
while(cur!=head){
if(item==cur->info)break;
cur=cur->rlink;
}
 next=cur->rlink;
 printf("enter towards right of %d=",item);
 temp=getnode();
 scanf("%d",&temp->info);
 next->llink=temp;
 cur->rlink=temp;
 temp->llink=cur;
 temp->rlink=next;
 return head;
}
int main(){
NODE head,last;
int item, choice;
head=getnode();
head->rlink=head;
head->llink=head;
for(;;){
printf("\n1:insert_front 2:insert_rear 3:delete_front 4:delete_rear 5:display 6:delete_duplicates 7:delete_all_except_one 8:insert_left 9:insert_right 10:exit\n");
printf("enter the choice=");
scanf("%d",&choice);
switch(choice){
case 1: printf("enter the item at front end=");
	scanf("%d",&item);
             last=dinsert_front(item,head);
	break;
case 2: printf("enter the item at rear end=");
	scanf("%d",&item);
	last=dinsert_rear(item,head);
	break;
case 3:last=ddelete_front(head);
	break;
case 4: last=ddelete_rear(head);
	break;
case 5: display(head);
	break;
 case 6: printf("Enter the item whose duplicates are to be deleted: ");
               scanf("%d",&item);
                head=delete_all_key(item,head);
                break;
 case 7: printf("Enter the item to be deleted: ");
                scanf("%d",&item);
                head=delete_except_one(item,head);
                break;
  case 8: printf("enter the key item=");
                scanf("%d",&item);
                head=insert_leftpos(item,head);
                break;
     case 9: printf("Enter key item=");
               scanf("%d",&item);
               head=insert_rightpos(item,head);
               break;
		default:exit(0);
		}
             }
}
