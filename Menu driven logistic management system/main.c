#include <stdio.h>
#include <stdlib.h>

int citymanagement(char *citynames,int x);



int citymanagement(char *citynames,int x)
{
    int y=0;
    int citycount;
    printf("Type \"done\" when complete entering.");
    do
    {fgets(**citynames[y][50],50,stdin);
    getchar();
    y++;

    }
    while(strcmp(*citynames[y][50],done)!=0);
    citycount=y-1;
    return citycount;


}

int main()
{
    //int *citycount;
    int x=30;
    int choice;
    char *citynames[30][50];

    printf("Logistic Management System\n");
    printf("--------------------------\n\n\n");
    printf("-Menu-");

    printf("1).City Management.\n");
    printf("2).Distance Management.\n");
    printf("3).Delivery Request Handling.\n");
    printf("4).Cost,Time and Fuel Calculations.\n");
    //printf("5)..\n");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        void citymanagement(char *citynames,int x);

    case 2:



    }


    return 0;
}
