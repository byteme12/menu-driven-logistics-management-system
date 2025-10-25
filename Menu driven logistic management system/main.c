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

void addCity()
{
    if (cityCount >= MAX_CITIES)
    {
        printf("City limit reached.\n");
        return;
    }
    printf("Enter city name: ");
    scanf("%s", cities[cityCount]);
    cityCount++;
    printf("City added successfully.\n");
}

void renameCity()
{
    displayCities();
    int index;
    printf("Enter city index to rename: ");
    scanf("%d", &index);
    if (index < 0  ||index >= cityCount)
    {
        printf("Invalid index.\n");
        return;
    }
    printf("Enter new name: ");
    scanf("%s", cities[index-1]);
    printf("City renamed.\n");
}

void removeCity()
{
    displayCities();
    int index;
    printf("Enter city index to remove: ");
    scanf("%d", &index);
    if (index < 0 || index >= cityCount)
    {
        printf("Invalid index.\n");
        return;
    }
    for (int i = index; i < cityCount - 1; i++)
    {
        strcpy(cities[i], cities[i + 1]);
        for (int j = 0; j < cityCount; j++)
        {
            distanceMatrix[i][j] = distanceMatrix[i+1][j];
            distanceMatrix[j][i] = distanceMatrix[j][i+1];
        }
    }
    cityCount--;
    printf("City removed.\n");
}

void displayCities()
{
    printf("\nCities:\n");
    for (int i = 0; i < cityCount; i++)
    {
        printf("%d. %s\n", i+1, cities[i]);
    }
}
