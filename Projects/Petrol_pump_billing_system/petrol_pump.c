#include <stdio.h>

int main()
{
    float petrol_price = 108.90, disel_price = 102.28;

    int choice;
    printf("===Lakhsya Petrol Pump===");
    printf("===================");
    printf("Fule available here : \n");
    printf("1. Petrol \n");
    printf("1. Disel\n");
    printf("Choose your fuel type :\n")
    scanf("%d", &choice);

    printf("\n Selected fuel price : %.2f\n", choice ==1 ? petrol_price : disel_price);
    int quantity;
    printf("Enter quantity : ");
    scanf("%d", &quantity);
    printf("The selected quantity : %d\n", quantity);

    float amount = quantity * (choice ==1 ? petrol_price : disel_price);
    float gst = amount * 0.18;
    float final = amount + gst;

    printf("\n\n===Lakhsya Petrol Pump===\n");
    printf("=====================");
    printf("Invoice number : 12132\n");
    printf("Fule type ; %s\n", choice == 1 ? "Petrol" : "Disel");
    printf("Rate/Liter : %.2f\n", choice == 1 ? petrol_price : disel_price);
    printf("Quantity : %d ltrs\n", quantity);
    printf("Subtotal : %.2f\n", amount);
    printf("GST(18%) : %.2f\n" , gst);
    printf("=====================");
    printf("Total Bill : %.2f\n ", final);

    
}