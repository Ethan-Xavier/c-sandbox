#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    int numOfItem = 0;
    int maxItemLetters = 20;

    float subtotal = 0.0f;

    printf("--- CASHIER ---\n");

    printf("Enter the number of items you want to buy: ");
    scanf("%d", &numOfItem);
    getchar();

    char **itemList = malloc(numOfItem*sizeof(char *));

    if(itemList == NULL){
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    for(int i = 0; i < numOfItem; i++){
        itemList[i] = (char *)malloc(maxItemLetters*sizeof(char));

        if(itemList[i] == NULL){
            printf("Memory Allocation Failed for String %d!\n", i);
            return 1;
        }
    }

    for(int i = 0; i < numOfItem; i++){
        printf("Enter the name of item #%d: ", i+1);
        fgets(itemList[i], maxItemLetters, stdin);

        int len = strlen(itemList[i]);

        if(len > 0 && itemList[i][len - 1] == '\n'){
            itemList[i][len - 1] = '\0';
        }
    }

    printf("------------------------------------------\n");

    float *priceList = malloc(numOfItem*sizeof(float));

    if(priceList == NULL){
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    for(int i = 0; i < numOfItem; i++){
        printf("Enter the price of item #%d: $", i+1);
        scanf("%f", &priceList[i]);
        getchar();
    }

    printf("------------------------------------------\n");

    int *qtyList = malloc(numOfItem*sizeof(int));

    if(qtyList == NULL){
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    for(int i = 0; i < numOfItem; i++){
        printf("Enter the quantity of item #%d: #", i+1);
        scanf("%d", &qtyList[i]);
        getchar();
    }
    
    printf("------------------------------------------\n");

    printf("\n--- RECEIPT ---\n");

    for(int i = 0; i < numOfItem; i++){
        printf("%d. %-11s x%d  @ $%-5.2f = $%.2f\n", i+1, itemList[i], qtyList[i], priceList[i], ((qtyList[i])*(priceList[i])));

        subtotal+=(qtyList[i])*(priceList[i]);
    }

    printf("\nSubtotal: $%.2f\n", subtotal);
    printf("Tax (%%5): $%.2f\n", subtotal*0.05);
    printf("Total Bill: $%.2f\n", subtotal+(subtotal*0.05));

    printf("------------------------------------------\n");

    //Clean up crew:

    for(int i = 0; i < numOfItem ; i++){
        free(itemList[i]);
        itemList[i] = NULL;
    }

    free(itemList);
    free(priceList);
    free(qtyList);

    priceList = NULL;
    itemList = NULL;
    qtyList = NULL;

    return 0;
}
