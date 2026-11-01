#include <stdio.h>
#include <string.h>

typedef struct{
    char name[30];
    int qty;
    float price;
}ITEM;

int main(){

    int numOfItems = 0;
    float subtotal = 0.0f;

    printf("--- CASHIER ---\n");
    printf("Enter the number of items you want to buy: ");
    scanf("%d", &numOfItems);
    getchar();

    ITEM store[numOfItems];

    printf("------------------------------------------\n");

    for(int i = 0; i < numOfItems; i++){

        printf("Enter the name of item #%d: ", i+1);
        fgets(store[i].name ,sizeof(store[i].name) ,stdin);
        store[i].name[strlen(store[i].name) - 1] = '\0';

        printf("Enter the price: $");
        scanf("%f", &store[i].price);

        printf("Enter the quantity: ");
        scanf("%d", &store[i].qty);
        getchar();

        printf("------------------------------------------\n");
    }

    printf("\n--- RECEIPT ---\n");

    for(int i = 0; i < numOfItems; i++){

        printf("%d. %-11s x%-2d  @ $%-5.2f = $%.2f\n", i+1, store[i].name, store[i].qty, store[i].price, ((store[i].qty)*(store[i].price)));
        
           subtotal+=(store[i].qty)*(store[i].price);
    }

    printf("\nSubtotal: $%.2f\n", subtotal);
    printf("Tax (%%5): $%.2f\n", subtotal*0.05);
    printf("Total Bill: $%.2f\n", subtotal+(subtotal*0.05));

    return 0;
}
