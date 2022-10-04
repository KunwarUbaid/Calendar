
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

// Structure to store the reminders/ important dates

struct reminder
{
    char name[30];
    int date;
    int month;
    int year;

}a[10];
int remno=0;

// Function to input values in reminder a

void setreminder()
{
    printf("Enter the details of reminder %d\n",remno+1);
    printf("Enter the date:  ");
    scanf("%d",&a[remno].date);
    printf("Enter the month:  ");
    scanf("%d",&a[remno].month);
    printf("Enter the year:  ");
    scanf("%d",&a[remno].year);
    fflush(stdin);
    printf("Enter description/occasion:  ");
    gets(a[remno].name);
    remno++;
}

// Function to sort reminders

void sortreminders()
{
 struct reminder temp;
 for(int i=0;i<remno;i++)
 {
     for(int j=i+1;j<remno;j++)
     {
         if( ( a[j].year < a[i].year )
            || ((a[j].month < a[i].month) && (a[i].year==a[j].year))
            || ((a[j].date>a[i].date) && ((a[j].month < a[i].month) && (a[i].year==a[j].year)))
           )
         {
             temp=a[j];
             a[j]=a[i];
             a[i]=temp;
         }
      }
 }

 }

// Function to display reminders

void displayreminders()
{
    if(remno==0)
        printf("You have not set any reminders.");
    else
    {
    for(int i=0;i<remno;i++)
    {
        printf("Reminder %d is set for %d/%d/%d. \t\tDescription: %s\n", i+1, a[i].date,a[i].month,a[i].year, a[i].name);
    }
    }
}

// Function to check if year is leap

int is_leap(int year)
{
    if(year % 400 == 0)
        return 1;
    else if(year % 100 == 0)
        return 0;
    else if(year % 4 == 0)
        return 1;
    else
        return 0;
}

// Function to find value of day acc to Zeller’s Formula

int ZellerDay(int date, int month, int year )
{
        int m = month;
    m -= 2;
    if(m < 0)
    {
        m += 12;
        --year;
    }
    int D = year % 100, C = year / 100;
    int day = date + ((13*m - 1) / 5) + D + (D/4) + (C/4) - 2*C;

    return day;
}

// Main Code

int main()
{
char choice;
A:
do{
system("cls");
printf("**************************************************************************************************\n");
printf("**************************************************************************************************\n");
printf("\t\t\t\tWELCOME TO THE CALENDAR\n");
printf("**************************************************************************************************\n");
printf("**************************************************************************************************\n");
printf("                             PLEASE ENTER WHAT YOU WANT TO DO                                     \n");
printf("1.Find Out the Day : \n2.Print a month \n3.Set reminder  \n4.Print reminder list \n5.Exit \nEnter the Choice : ");
choice = getche();
int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
switch(choice)
{
case '1':
{
    system("cls");
    int date, month, year;
    printf("Enter the date : ");
    scanf("%d", &date);
    printf("Enter the month : ");
    scanf("%d", &month);
    printf("Enter the year : ");
    scanf("%d", &year);

    if(month==2 && is_leap(year))
    {
        days[1]= 29;
    }
    if(((month < 1) || (month > 12)) || (date < 1) || (date>days[month-1]) || (year < 0))
    {
        printf("\nEntered date is not valid. Press any key ...");
        getch();
        goto A;
    }
    int day= ZellerDay(date,month,year);
    if(month==2)
    {
        if(is_leap(year))
            day++;
        else
            day+=2;

    }

    if(day >= 0)
        day %= 7;
    else
        while(day < 0)
            day += 7;

   // To print day of the week

 switch(day)
    {
        case 0: printf("The day is Sunday") ;
            break;
        case 1: printf("The day is Monday") ;
            break;
        case 2: printf("The day is Tuesday") ;
            break;
        case 3: printf("The day is Wednesday") ;
            break;
        case 4: printf("The day is Thursday") ;
            break;
        case 5: printf("The day is Friday") ;
            break;
        case 6: printf("The day is Saturday") ;
            break;
    }
    printf(" \n\n");
    printf("Press any key ...");
    getch();
    break;

}
case '2':
{
    system("cls");
    int month, year;
    printf("Enter the month : ");
    scanf("%d", &month);
    printf("Enter the year : ");
    scanf("%d", &year);

    if(((month < 1) || (month > 12)) || (year < 0))
    {
        printf("Invalid date entered. Press any key ...");
        getch();
        goto A;
    }
    if(month==2 && is_leap(year))
    {
        days[1]= 29;
    }
    int day;
    day=ZellerDay( 1, month,year);

// To convert Zeller Day index to our everyday use index
//    i.e Monday=0, Tuesday=1.

if(day >= 0)
        day %= 7;
    else
        while(day < 0)
            day += 7;

--day;
    if(day == -1)
        day = 6;
    if(month==2)
    {
        if(is_leap(year))
            day++;
        else
            day+=2;

    }

   // To Print in Calendar Format

printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");
    for(int i=0 ; i < day ; ++i)
        printf("\t");
    for(int i=1 ; i <= days[month-1] ; ++i)
    {
        printf("%d\t", i);
        if((day+i) % 7 == 0)
            printf("\n");
    }
    printf(" \n\n");
    printf("Press any key ...");
    getch();
    break;
}
case '3':
    {
        system("cls");
        if(remno>10)
        {
            printf("You have reached max limit to enter reminders. Press any key ...");
            getch();
            goto A;
        }
        else
        {
            setreminder();
        }
        printf(" \n\n");
        break;
    }
case '4':
    {
        system("cls");
        sortreminders();
        displayreminders();
        printf(" \n\n");
        printf("Press any key ...");
        getch();
        break;
    }
case '5': exit(0);
default:
{
    system("cls");
    printf("Wrong choice entered. Press any key ...");
    getch();
    goto A;
}
}
} while(1);
return 0;
}


