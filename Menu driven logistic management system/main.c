#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_CITIES 30
#define MAX_DELIVERIES 50
#define FUEL_PRICE 310.0

void addCity();
void renameCity();
void removeCity();
void displayCities();
void cityMenu();
void distanceMenu();
void reportMenu();
void editDistance();
void displayDistanceTable();
void newDelivery();
double findDistance(int src, int dest);
void calculateCost(Delivery *d);
void showDeliverySummary(Delivery d);
void showReports();

typedef struct
{
    char name[20];
    int capacity;
    double ratePerKm;
    double speed;
    double efficiency;
} Vehicle;


typedef struct
{
    int src, dest, vehicleType;
    double weight, distance, cost, fuelUsed, totalCost, profit, charge, time;
} Delivery;


char cities[MAX_CITIES][50];
int distanceMatrix[MAX_CITIES][MAX_CITIES];
int cityCount = 0;
Delivery deliveries[MAX_DELIVERIES];
int deliveryCount = 0;


Vehicle vehicles[3] =
{
    {"Van", 1000, 30, 60, 12},
    {"Truck", 5000, 40, 50, 6},
    {"Lorry", 10000, 80, 45, 4}
};

Delivery deliveries[MAX_DELIVERIES];
int deliveryCount = 0;


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
    if (index < 0 || index >= cityCount)
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
    if (index < 0 || index >=cityCount)
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

void distanceMenu()
{
    int choice;
    while (1)
    {
        printf("\n---- Distance Management ----\n");
        printf("1. Edit Distance:\n ");
        printf("2. Display Distance Table:\n");
        printf("0. Back:\n");
        printf("Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            editDistance();
            break;
        case 2:
            displayDistanceTable();
            break;
        case 0:
            return;
        default:
            printf("Invalid!\n");
        }
    }
}


void displayCities()
{
    printf("\nCities:\n");
    for (int i = 0; i < cityCount; i++)
    {
        printf("%d. %s\n", i+1, cities[i]);
    }
}



void editDistance()
{
    if (cityCount < 2)
    {
        printf("At least 2 cities needed.\n");
        return;
    }
    displayCities();
    int a, b, d;
    printf("Enter source city index: ");
    scanf("%d", &a);
    printf("Enter destination city index: ");
    scanf("%d", &b);
    if (a == b)
    {
        printf("Cannot set distance from city to itself.\n");
        return;
    }
    printf("Enter distance (km): ");
    scanf("%d", &d);
    distanceMatrix[a-1][b-1] = distanceMatrix[b-1][a-1] = d;
    printf("Distance updated.\n");
}

void displayDistanceTable()
{
    printf("\nDistance Table (km):\n\t");
    for (int i = 0; i < cityCount; i++)
        printf("%s\t\t", cities[i]);
    printf("\n");
    for (int i = 0; i < cityCount; i++)
    {
        printf("%s\t", cities[i]);
        for (int j = 0; j < cityCount; j++)
        {
            printf("%d\t\t", distanceMatrix[i][j]);
        }
        printf("\n");
    }
}


void deliveryMenu()
{
    int choice;
    while (1)
    {
        printf("\n---- Delivery Menu ----\n");
        printf("1. New Delivery Request\n ");
        printf("0. Back\n");
        printf("Choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            newDelivery();
            break;
        case 0:
            return;
        default:
            printf("Invalid!\n");
        }
    }
}

void newDelivery()
{
    if (deliveryCount >= MAX_DELIVERIES)
    {
        printf("Delivery record full.\n");
        return;
    }

    displayCities();
    int src, dest, type;
    double weight;
    printf("Enter source city index: ");
    scanf("%d", &src);
    printf("Enter destination city index: ");
    scanf("%d", &dest);
    if (src == dest)
    {
        printf("Source and destination cannot be same.\n");
        return;
    }
    printf("Enter weight (kg): ");
    scanf("%lf", &weight);

    printf("Select vehicle:\n ");
    printf("1=Van:\n");
    printf("2=Truck:\n");
    printf("3=Lorry:\n");
    scanf("%d", &type);
    if (type < 1 || type > 3)
    {
        printf("Invalid vehicle.\n");
        return;
    }
    Vehicle v = vehicles[type - 1];
    if (weight > v.capacity)
    {
        printf("Exceeds vehicle capacity (%d kg).\n", v.capacity);
        return;
    }

    Delivery d;
    d.src = src;
    d.dest = dest;
    d.vehicleType = type - 1;
    d.weight = weight;
    d.distance = findDistance(src, dest);
    calculateCost(&d);

    deliveries[deliveryCount++] = d;
    showDeliverySummary(d);
}

double findDistance(int src, int dest)
{
    return distanceMatrix[src-1][dest-1];
}

void calculateCost(Delivery *d)
{
    Vehicle v = vehicles[d->vehicleType];
    double D = d->distance;
    double W = d->weight;
    double R = v.ratePerKm;
    double S = v.speed;
    double E = v.efficiency;

    d->cost = D * R * (1 + (W / 10000.0));
    d->time = D / S;
    d->fuelUsed = D / E;
    double fuelCost = d->fuelUsed * FUEL_PRICE;
    double totalCost = d->cost + fuelCost;
    double profit = d->cost * 0.25;
    d->totalCost = totalCost;
    d->profit = profit;
    d->charge = totalCost + profit;
}


void showDeliverySummary(Delivery d)
{
    Vehicle v = vehicles[d.vehicleType];
    printf("\n=====================================================\n");
    printf("DELIVERY COST ESTIMATION\n");
    printf("\n-----------------------------------------------------\n");
    printf("From: %s\n",cities[d.src]);
    printf("To: %s\n",cities[d.dest]);
    printf("Distance: %.2f km\n", d.distance);
    printf("Vehicle: %s\n", v.name);
    printf("Weight: %.2f kg\n", d.weight);
    printf("-----------------------------------------------------\n");
    printf("Base Cost: %.2f LKR\n", d.cost);
    printf("Fuel Used: %.2f L\n", d.fuelUsed);
    printf("Total Operational Cost: %.2f LKR\n", d.totalCost);
    printf("Profit: %.2f LKR\n", d.profit);
    printf("Customer Charge: %.2f LKR\n",d.charge);
    printf("Estimated Time: %.2f hours\n",d.time);
    printf("=====================================================\n");
}



