//Airplane Seat Reservation System

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct customer
{
    char fName[50];
    char lName[50];
    int passNum;
    long long int phnNum;
    int seatNum;
}seats[15];

int seatCount()
{
    int seatcount=0;
    for(int i = 0; i<15; i++)
    {
        if(seats[i].passNum == 0)
        {
            seatcount++;
        }
    }
    return seatcount;
}

void reservation()
{
    int index;
    for(int i = 0; i<15; i++)
    {
        if(seats[i].passNum == 0)
        {
            index = i;
            break;
        }
    }
    printf("==================================================================================\n");
    printf("Enter first name :");
    scanf("%s",seats[index].fName);
    printf("Enter last name :");
    scanf("%s",seats[index].lName);
    int pNum;
    L2 :printf("Enter passport number:");
    scanf("%d",&pNum);
    for(int i = 0;i<15;i++)
    {
        if(pNum == seats[i].passNum)
        {
            printf("This passport already has a seat booked. Try another passport number.");
            goto L2;
        }
    }
    seats[index].passNum = pNum;
    printf("Enter contact number (10 digits):");
    scanf("%lld",&seats[index].phnNum);
    printf("==================================================================================\n");
    printf("\t\t\tRESERVATION SUCCESSFUL!\n");
    printf("\t\t\tYour seat number is %d.\n",seats[index].seatNum);
    printf("\t\t\tBon voyage!!!\n");
    printf("==================================================================================\n");
}

void cancellation()
{
    int cancelNum;
    L3 : printf("Enter the passport number to cancel your booking :");
    scanf("%d",&cancelNum);
    printf("==================================================================================\n");
    printf("Your passport number is %d.\n",cancelNum);
    int index = -1;
    for(int i = 0; i < 15; i++)
    {
        if(cancelNum == seats[i].passNum)
        {
            index =  i;
            break;
        }
    }
    if(index == -1)
    {
        printf("Invalid passport number to cancel.\n");
        goto L3;
    }
    else
    {
        seats[index].passNum = 0;
        printf("Your seat has been cancelled!\n");
        printf("Thank you, see you next time.\n");
    }
    printf("==================================================================================\n");
}

void displayPass()
{
    for(int i = 0; i <15; i++)
    {
        if(seats[i].passNum != 0)
        {
            printf("The Seat no. %d is occupied by...\n",seats[i].seatNum);
            printf("==================================================================================\n");
            printf("Name of the passenger:\t\t%s %s\n",seats[i].fName,seats[i].lName);
            printf("Passport No.:\t\t%d\n",seats[i].passNum);
            printf("Contact No.:\t\t%lld\n",seats[i].phnNum);
            printf("==================================================================================\n");
        }
    }
}

void exportRecord()
{
    FILE* fp = fopen("ASR Services.txt","w");
    if(fp==NULL)
    {
        printf("The file was not created.");
    }
    else
    {
        printf("The file creation was successful.");
    }
    
    for(int i = 0; i <15; i++)
    {
        if(seats[i].passNum != 0)
        {
            fprintf(fp,"The Seat no. %d is occupied by...\n",seats[i].seatNum);
            fprintf(fp,"==================================================================================\n");
            fprintf(fp,"Name of the passenger:\t\t%s %s\n",seats[i].fName,seats[i].lName);
            fprintf(fp,"Passport No.:\t\t%d\n",seats[i].passNum);
            fprintf(fp,"Contact No.:\t\t%lld\n",seats[i].phnNum);
            fprintf(fp,"==================================================================================\n");
        }
    }
    fclose(fp);
    printf("The Passenger records were exported successfully.");
}

int main()
{
    int option;
    for(int i = 0; i < 15; i++ )
    {
        seats[i].passNum = 0;
        seats[i].seatNum = i+1;
    }
    printf("==================================================================================\n");
    L1 : printf("\t\t\t\t\tMain Menu:\t\t\t\t\n");
    printf("\t\t\t1. Reservation\n\t\t\t2. Cancellation\n\t\t\t3. Display Boarding Pass\n\t\t\t4. Export Data to a text file (.txt)\n\t\t\t5. Exit\n");
    printf("==================================================================================\n");
    printf("Enter your choice (1 to 5):");
    scanf("%d",&option);
    switch(option)
    {
        case 1:
            
            printf("No. of seats available is %d.\n ",seatCount());
            if(seatCount()>0)
            {
                reservation();
            }
            else
            {
                printf("All the seats are filled!\n");
            }
            goto L1;
        case 2:
            cancellation();
            goto L1;
        case 3:
            displayPass();
            goto L1;
        case 4:
            exportRecord();
            goto L1;
        case 5:
            printf("Thank you for using ASR services.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
            goto L1;
    }
}
