/*  Problem: Write a program to create a customer’s bill for a company.
    Algorithm: 
              1. Define constants for unit prices and tax rate.
              2. Prompt user for quantity of each product.
              3. Read quantities into integer variables.
              4. Calculate total price for each product = quantity × unit price.
              5. Compute subtotal = sum of all product totals.
              6. Compute tax = subtotal × tax rate.
              7. Compute grand total = subtotal + tax.
              8. Display formatted bill with QTY, DESCRIPTION, UNIT PRICE, TOTAL PRICE.
              9. Display subtotal, tax, and total.

    Developed by: Rita Wak
    Date: 3/02/2026

*/

#include <stdio.h>

#define TV_PRICE 400.00 
#define MONITOR_PRICE 220.00 
#define FLASHDRIVE_PRICE 35.20
#define HARDDRIVE_PRICE 150.00 
#define PRINTER_PRICE 300.00 
#define TAX_RATE 0.0835 // 8.35%

 int main() {
    int qtyTV, qtyMonitor, qtyFlash, qtyHard, qtyPrinter;
    double totalTV, totalMonitor, totalFlash, totalHard, totalPrinter;
    double subtotal, tax, total;

    // Input
    printf("How many TVs were sold? "); 
    scanf("%d", &qtyTV);

    printf("How many Monitors were sold? "); 
    scanf("%d", &qtyMonitor); 

    printf("How many Flash Drives were sold? ");
    scanf("%d", &qtyFlash);

    printf("How many Hard Drives were sold? "); 
    scanf("%d", &qtyHard);

     printf("How many Deskjet Printers were sold? ");
     scanf("%d", &qtyPrinter);

     // Calculations
     totalTV = qtyTV * TV_PRICE; 
     totalMonitor = qtyMonitor * MONITOR_PRICE; 
     totalFlash = qtyFlash * FLASHDRIVE_PRICE; 
     totalHard = qtyHard * HARDDRIVE_PRICE; 
     totalPrinter = qtyPrinter * PRINTER_PRICE;

     subtotal = totalTV + totalMonitor + totalFlash + totalHard + totalPrinter; 
     tax = subtotal * TAX_RATE;
      total = subtotal + tax;

       // Output
       printf("\n---------------------------------------------\n");
       printf("QTY DESCRIPTION UNIT PRICE TOTAL PRICE\n"); 
       printf("%-5d TV %8.2f %10.2f\n", qtyTV, TV_PRICE, totalTV); 
       printf("%-5d Monitor %8.2f %10.2f\n", qtyMonitor, MONITOR_PRICE, totalMonitor); 
       printf("%-5d Flash Drive %8.2f %10.2f\n", qtyFlash, FLASHDRIVE_PRICE, totalFlash); 
       printf("%-5d Hard Drive %8.2f %10.2f\n", qtyHard, HARDDRIVE_PRICE, totalHard); 
       printf("%-5d Deskjet Printer %8.2f %10.2f\n", qtyPrinter, PRINTER_PRICE, totalPrinter);

       printf("---------------------------------------------\n");
       printf("Subtotal: %30.2f\n", subtotal); 
       printf("Tax: %30.2f\n", tax); 
       printf("Total: %30.2f\n", total);

       return 0; 
    }

