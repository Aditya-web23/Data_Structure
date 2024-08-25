#include<stdio.h>
#include<stdlib.h>

struct node
{

    int data;
    struct node*next;

} ;
int main()
{
    struct node *s, *p,*q ;
    int n ;
  printf("enter the no.of elements u want: ");
  scanf("%d",&n);
    p = (struct node*)malloc(sizeof(struct node));
    printf("enter the first node:");
    scanf("%d",&p->data);
    s = p ;
  
    int count = 1 ;
        do
        {
         q = (struct node*)malloc(sizeof(struct node));
          printf("enter value for next node:");
          scanf("%d",&q->data);

          p->next = q ;
           p = q;
          count++;
          
        }while(count<n);
         
        p->next = NULL ;
      printf("the linked list:\n");
        while(s!=NULL){
            printf("%d\n",s->data);
            s = s->next ;
        }
return 0;
}