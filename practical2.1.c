#include<stdio.h>
int main (){

int n ,i,m;
int pos ,num ;
int a[100];
printf("enter the element you want in the array ");
scanf("%d",&n);
printf("enter the elements in the array ");
for (i=0;i<n;i++){

    scanf("%d",&a[i]);

}
printf("enter the element index number where you wne to insert the alement");
scanf("%d",&pos);
printf("enter the new inserting elements");
scanf("%d",&num);
for(i=n;i>=pos;i--){
if (i==pos){
    a[i]=num;
}
else{
    m=i-1;
    a[i]=a[m];
}

}
printf("new array is :");
for (i=0;i<=n;i++){
    printf("%d ",a[i]);


}
return 0;


}