// Airplane Seat Reservation System
// Done by 20PW06 and 20PW14
#include<stdio.h>
#include<stdlib.h>
#include<string.h>      
#include<windows.h>   // To use system("cls");

struct customer         // The structure of a customer.
{
    char fName[50];
    char lName[50];
    int passNum;
    unsigned long long int phnNum;
    int seatNum;
}seats[15];

void login()    // User login framework.
{
    int attempts=0,i=0;
    char username[5];
    char password[9];
    char c = ' ';
    char user[5]="root";
    char pass[9]="password";
    do
    {
        printf("\n  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  User Login  \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb  ");
        printf(" \n\n                       Enter userid: ");
        scanf("%s",username);
        printf(" \n\n                       Enter password: ");
        while(i < 8)
        {
            password[i] = getch();
            c = password[i];
            if(c == 13)
            {
                break;
            }
            else if(c == 8)
            {
                if(i>0)
                {
                    printf("\b \b");
                    i--;
                }
            }
            else
            {
                printf("*");
                i++;
            }
        }
        password[i]='\0';
        i=0;
        getch();
        if(strcmp(username,user)==0 && strcmp(password,pass)==0)
        {
            printf("\n\n\n\t\t\t\tLogin Sucessful.\n");
            printf("\n\n\n\t\t\t\tPress any key to continue...");
            getch();
            break;
        }
        else
        {
            printf("\n\t\t\t\tLogin Unsucessful\n\n");
            attempts++;
            getch();
        }
    }while(attempts<3);
    if (attempts>2)
    {
        printf("\nSorry, you have entered the wrong username and password too many times.");
        getch();
        exit(0);
    }
    system("cls");
}
int seatCount()      // To count the total no. of seats left.
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
int seatCountE()    // To count the total no. of seats left in the Economy class.
{
    int seatcount=0;
    for(int i = 6; i<15; i++)
    {
        if(seats[i].passNum == 0)
        {
            seatcount++;
        }
    }
    return seatcount;
}
int seatCountB()    //To count the total no. of seats left in the Business class.
{
    int seatcount=0;
    for(int i = 0; i < 6; i++)
    {
        if(seats[i].passNum == 0)
        {
            seatcount++;
        }
    }
    return seatcount;
}

void reservationB() //To reserve seats in Business class.
{
    int index;
    for(int i = 0; i < 6; i++)
    {
        if(seats[i].passNum == 0)
        {
            index = i;
            break;
        }
    }
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
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
            printf("This passport already has a seat booked. Try another passport number.\n");
            goto L2;
        }
    }
    seats[index].passNum = pNum;
    long long int phNum;
    L4 : printf("Enter contact number (10 digits):");
    scanf("%lld",&phNum);
    if(phNum>999999999 && phNum<10000000000)
    {
        seats[index].phnNum = phNum;
    }
    else
    {
        printf("Invalid number.\n");
        goto L4;
    }
    system("cls");
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\tRESERVATION SUCCESSFUL!\n");
    printf("\t\t\tTotal to be paid : Rs. 50000/- . \n");
    printf("\t\t\tYour seat number is %d.\n",seats[index].seatNum);
    printf("\t\t\tBon voyage!!!\n");
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
}

void reservationE() // To reserve seats in Economy class.
{
    int index;
    for(int i = 6; i< 15; i++)
    {
        if(seats[i].passNum == 0)
        {
            index = i;
            break;
        }
    }
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("Enter first name :");
    scanf("%s",seats[index].fName);
    printf("Enter last name :");
    scanf("%s",seats[index].lName);
    int pNum;
    L3 :printf("Enter passport number:");
    scanf("%d",&pNum);
    for(int i = 0;i<15;i++)
    {
        if(pNum == seats[i].passNum)
        {
            printf("This passport already has a seat booked. Try another passport number.");
            goto L3;
        }
    }
    seats[index].passNum = pNum;
    long long int phNum;
    L5 : printf("Enter contact number (10 digits):");
    scanf("%lld",&phNum);
    if(phNum>999999999 && phNum<10000000000)
    {
        seats[index].phnNum = phNum;
    }
    else
    {
        printf("Invalid number.\n");
        goto L5;
    }
    system("cls");
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("\t\t\tRESERVATION SUCCESSFUL!\n");
    printf("\t\t\tTotal to be paid : Rs. 5000/- . \n");
    printf("\t\t\tYour seat number is %d.\n",seats[index].seatNum);
    printf("\t\t\tBon voyage!!!\n");
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
}

void cancellation() // To cancel reserved seats.
{
    int cancelNum;
    printf("Enter the passport number to cancel your booking :");
    scanf("%d",&cancelNum);
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("Your passport number is %d.\n",cancelNum);
    int index = -1;
    for(int i = 0; i < 15; i++)
    {
        if(cancelNum == seats[i].passNum)
        {
            index = i;
            break;
        }
    }
    system("cls");
    if(index == -1)
    {
        printf("Invalid passport number to cancel.\n");
    }
    else
    {
        seats[index].passNum = 0;
        printf("Your seat has been cancelled and you fee paid has been refunded.\n");
        printf("Thank you, see you next time.\n");
    }
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
}

void displayPass()  // To display all the Passenger records.
{
    for(int i = 0; i <15; i++)
    {
        if(seats[i].passNum != 0)
        {
            if(i>0 && i<6)
                printf("The Seat no. %d [Business class] is occupied by...\n",seats[i].seatNum);
            else
                printf("The Seat no. %d [Economy class] is occupied by...\n",seats[i].seatNum);
            printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
            printf("Name of the passenger:\t\t%s %s\n",seats[i].fName,seats[i].lName);
            printf("Passport No.:\t\t%d\n",seats[i].passNum);
            printf("Contact No.:\t\t%lld\n",seats[i].phnNum);
            printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
        }
    }
}

void exportRecord() // To export the Passenger records to a .txt file.
{
    FILE* fp = fopen("ASR Services.txt","w");
    if(fp==NULL)
    {
        printf("The file was not created.");

    }
    else
    {
        printf("The file creation was successful.");
        for(int i = 0; i <15; i++)
        {
            if(seats[i].passNum != 0)
            {
                if(i>0 && i<6)
                    fprintf(fp,"The Seat no. %d [Business class] is occupied by...\n",seats[i].seatNum);
                else
                    fprintf(fp,"The Seat no. %d [Economy class] is occupied by...\n",seats[i].seatNum);
                    fprintf(fp,"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
                    fprintf(fp,"Name of the passenger:\t\t%s %s\n",seats[i].fName,seats[i].lName);
                    fprintf(fp,"Passport No.:\t\t%d\n",seats[i].passNum);
                    fprintf(fp,"Contact No.:\t\t%lld\n",seats[i].phnNum);
                    fprintf(fp,"\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
            }
        }
        fclose(fp);
        printf("The Passenger records were exported successfully.");
    }
}
void seatStructure()    // Shows a graphical representation of the availability and structure of seats.
{
    char xdb[15];
    for(int i = 0; i < 15; i++)
    {
        if(seats[i].passNum !=0)
        {
            xdb[i] = '\xdb';
        }
        else
        {
            xdb[i] = '0';
        }
        
    }
    printf("\n\xdb = Occupied Seats.\t 0 = Unoccupied Seats.\n\n");
    printf("[%c]\t[%c]\t[%c]\n[%c]\t[%c]\t[%c]\n[%c]\t[%c]\t[%c]\n[%c]\t[%c]\t[%c]\n[%c]\t[%c]\t[%c]\n",xdb[0],xdb[1],xdb[2],xdb[3],xdb[4],xdb[5],xdb[6],xdb[7],xdb[8],xdb[9],xdb[10],xdb[11],xdb[12],xdb[13],xdb[14]);
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
}
int main()  // Main function.
{
    int option,suiteOp;
    login();
    for(int i = 0; i < 15; i++ )
    {
        seats[i].passNum = 0;
        seats[i].seatNum = i+1;
    }
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    L1 : printf("\t\t\tMain Menu:\t\t\t\t\n");
    printf("\t\t\t1. Reservation\n\t\t\t2. Cancellation\n\t\t\t3. Display Boarding Pass\n\t\t\t4. Export Data to a text file (.txt)\n\t\t\t5. Display Seat Structure.\n\t\t\t6. Exit\n");
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n");
    printf("Enter your choice (1 to 6):");
    scanf("%d",&option);
    system("cls");
    switch(option)
    {
        case 1:
            printf("No. of seats available in total is %d.\n ",seatCount());
            printf("No. of seats available in Business class is %d.\n ",seatCountB());
            printf("No. of seats available in Economy class is %d.\n ",seatCountE());
            L6: printf("Enter 0 for Economy and 1 for Business class seats :");
            scanf("%d",&suiteOp);
            if(suiteOp == 1)
            {
                if(seatCountB()>0)    
                    reservationB();
                else
                {
                    printf("All the Business class seats are filled.\n");
                }
                
            }
            else if(suiteOp == 0)
            {
                if(seatCountE()>0)    
                    reservationE();
                else
                {
                    printf("All the Economy class seats are filled.\n");
                }
                
            }
            else
            {
                printf("Enter a valid suite.\n");
                goto L6;
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
            seatStructure();
            goto L1;
        case 6:
            system("cls");
            printf("Thank you for using ASR services.\n");
            getch();
            return 0;
        default:
            printf("Invalid choice.\n");
            goto L1;
    }
}
