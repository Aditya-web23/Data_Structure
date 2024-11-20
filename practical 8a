#include<stdio.h>
# define MAXSIZE 10
int queue[MAXSIZE];
int rear=-1, front=0;
void insert(){
int n;
if(rear==MAXSIZE-1)
printf("queue overflow");
else{
printf("enter the number");
scanf("%d",&n);
rear++;
queue[rear]=n;
}
}
void delete1()
{
int n;
if(front>rear)
printf("queue is empty");
else{
n=queue[front];
front++;
printf("element deleted");
}
}
void display()
{
if(front>rear)
printf("queue is empty");
else
{
printf("queue elements");
for(int i=front; i<=rear; i++){
printf("\n %d",queue[i]);}1
}
}
int main(){
int choice;
do{
printf("\n ------queue------");
printf("\n1.insert \n2.delete \n3.display\n4.exit");
printf("-------------------------------------");1
case 1:
insert();
break;
case 2:
delete1();
break;
case 3:
display();
break;
case 4 :
printf("Exiting");
break;
default:
printf("invalid choice");
}
while(choice!=4);
return 0;
}
