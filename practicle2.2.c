#include<stdio.h>

int main() {
    int n, i, m,b ;
    int a[100];

    printf("Enter the number of elements you want in the array: ");
    scanf("%d", &m);

    printf("Enter the elements in the array: ");
    for(i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    printf("(1 to delete the first element)(2 for index wise deletion )(3 for delete last element 5) ");
    scanf("%d", &n);

    switch (n) {
        case 1:
            for (i = 0; i < m-1; i++) {
                a[i] = a[i+1];
            }
            m--; 
            break;

        case 2 :
            printf("enter the element index number you want to delete ");
            scanf("%d",&b);
            for (i = b; i < m-1; i++) {
                a[i] = a[i+1];
            }
            m--;
            break;
        case 3 :
            m=m-1;
            break;


        default:
            printf("Invalid option\n");
            return 1;
    }

    printf("Updated array: ");
    for (i = 0; i < m; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}