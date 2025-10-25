#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CITIES 30


void addCity();
void renameCity();
void removeCity();
void displayCities();
void cityMenu();
void distanceMenu();
void reportMenu();



int main()
{
    int choice;
    while (1)
    {
        printf("\n========== LOGISTICS MANAGEMENT SYSTEM ==========\n");
        printf("1. City Management\n");
        printf("2. Distance Management\n");
        printf("3. New Delivery\n");
        printf("4. Reports\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            cityMenu();
            break;
        case 2:
            distanceMenu();
            break;
        case 3:
            deliveryMenu();
            break;
        case 4:
            reportMenu();
            break;
        case 0:
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;



    return 0;
}

void cityMenu()
{
    int choice;
    while (1)
    {
        printf("\n---- City Management ----\n");
        printf("1. Add City\n);");
        printf("2. Rename City\n");
        printf("3. Remove City\n");
        printf("4. Display Cities\n");
        printf("0. Back\n");
        printf("Choice: ");
        scanf("%d", &choice);
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addCity();
            break;
        case 2:
            renameCity();
            break;
        case 3:
            removeCity();
            break;
        case 4:
            displayCities();
            break;
        case 0:
            return;
        default:
            printf("Invalid!\n");
        }
    }
}
