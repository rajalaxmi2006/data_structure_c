#include <stdio.h>
#include <string.h>

int main()
{
    char c_name[100], v_number[15], choice[10];
    long long mobile;
    float petrol_price = 108.90 , disel_price = 102.10;
    int quantity;

    printf("===Lakhsya Petrol Pump===\n");
    printf("=========================\n");
    printf("Enter your name : ");
    scanf(" %99[^\n]",c_name);
    printf("Enter your vehicle number : ");
    scanf(" %14[^\n]",v_number);
    printf("Enter your mobile number :");
    scanf(" %lld",&mobile);

    printf("Fuels Available : \n");
    printf("\tPetrol : %.2f\n", petrol_price);
    printf("\tDisel : %.2f\n", disel_price);

    printf("Enter your choice [petrol/disel] : ");
    scanf(" %9[^\n]" , choice);

    printf("Enter the quantity :");
    scanf("%d" , &quantity);

    float fuel_price;
    if (strcmp(choice, "petrol") == 0)
        fuel_price = petrol_price;
    else 
        fuel_price= disel_price;

    float subtotal = quantity * fuel_price;
    float gst = subtotal * 0.18;
    float total = subtotal + gst;

    printf("===Fuel Bill===\n");
    printf("===============\n");
    printf("Your name : %s\n",c_name);
    printf("Your vehicle number : %s\n", v_number);
    printf("Your mobile number : %lld\n",mobile);
    printf("Price of selected fule type : Rs.%.2f\n", fuel_price);
    printf("Quantity : %dltrs\n", quantity);
    printf("================\n");
    printf("Subtotal : Rs.%.2f\n", subtotal);
    printf("GST[18%] : Rs.%.2f\n", gst);
    printf("Total : Rs.%.2f\n",total);

}