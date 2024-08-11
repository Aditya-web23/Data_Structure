#include <stdio.h>

int main() {
    int n;
    int a[100];
    int i;
    int b;
    int found = 0;
    int p;
    int newnum;

    printf("sixe of array: ");
    scanf("%d", &n);

    printf("Enter the elements in the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter 0 to replace element by index or 1 to replace by element value: ");
    scanf("%d", &b);

    if (b == 0) {
        printf("Enter the index you want to replace: ");
        scanf("%d", &p);

        if (p < n) {
            printf("You want to replace element %d at index %d\n", a[p], p);
            printf("Enter the new element: ");
            scanf("%d", &newnum);
            a[p] = newnum;

            printf("New array: ");
            for(i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        } else {
            printf("Wrong input. Index out of range.\n");
        }
    } else if (b == 1) {
        printf("Enter the element you want to replace in the array: ");
        scanf("%d", &p);

        for(i = 0; i < n; i++) {
            if (a[i] == p) {
                printf("Entered element found at index %d\n", i);
                printf("Enter the new element to replace: ");
                scanf("%d", &newnum);
                a[i] = newnum;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            printf("Element does not exist in the array.\n");
        } else {
            printf("New array: ");
            for(i = 0; i < n; i++) {
                printf("%d ", a[i]);
            }
            printf("\n");
        }
    } else {
        printf("Wrong input.\n");
    }

    return 0;
}
