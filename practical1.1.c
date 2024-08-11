#include<stdio.h>


int main (){

int num ;
int i=0;
int a[10];
int found = 0 ;

printf("enter the element in the array ");

for (i=0;i<10;i++){
scanf("%d/n",&a[i] );}
printf("enter the element you find in the array ");
scanf("%d",&num);
for (i=0;i<10;i++){
if(a[i]== num ){
    printf("the number is found at index at %d",i);
    found=1;}
}
if (found==0){
    printf("The number is not present in the array ");
}

}
