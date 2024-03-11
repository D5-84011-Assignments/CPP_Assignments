#include <stdio.h>

struct Date
{
    int day;
    int month;
    int year;
};

void initDate(struct Date *ptrDate)
{
    ptrDate->day;
    ptrDate->month;
    ptrDate->year;
}

void printDateOnConsole(struct Date *ptrDate)
{
    printf("Date: %d/%d/%d\n", ptrDate->day, ptrDate->month, ptrDate->year);
}

void acceptDateFromConsole(struct Date *ptrDate)
{
    printf("Enter day:");
    scanf("%d", &ptrDate->day);

    printf("Enter month:");
    scanf("%d", &ptrDate->month);

    printf("Enter year:");
    scanf("%d", &ptrDate->year);
}

int main()
{
    struct Date date;
    int choice;

    initDate(&date);

    do
    {
        printf("\nMenu:\n");
        printf("1. Initialize date\n");
        printf("2. Accept date\n");
        printf("3. Print date\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        initDate(&date);
        switch (choice)
        {
        case 1:
            printf("Date initialized.\n");
            break;
        case 2:
            acceptDateFromConsole(&date);
            break;
        case 3:
            printDateOnConsole(&date);
            break;
        case 4:
            printf("Program exit.\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
