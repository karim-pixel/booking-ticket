#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

void login() {
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "username";
    char pass[10] = "password";

    do {
        printf("\n\t\t\t\t\t\t ********************************************");
        printf("\n\t\t\t\t\t\t **************** LOGIN FIRST **************");
        printf("\n\t\t\t\t\t\t ********************************************");
        printf(" \n\n ENTER USERNAME:-");
        scanf("%s", uname);
        printf(" \n\n ENTER PASSWORD:-");

        while (i < 10) {
            pword[i] = getch();
            c = pword[i];

            if (c == 13)
                break;
            else
                printf("*");

            i++;
        }

        pword[i] = '\0';

        if (strcmp(uname, "username") == 0 && strcmp(pword, "password") == 0) {
            printf("\n\t\t\t\t\t\t\t  ******** LOGIN IS SUCCESSFUL ********");
            printf("\n\n\t\t\t\t\t\t\t     WELCOME TO OUR BOOKING SYSTEM");
            printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
            getch();
            break;
        } else {
            printf("\n LOGIN IS UNSUCCESSFUL \n Try again!!!\n");
            a++;
            getch();
        }
    } while (a <= 2);

    if (a > 2) {
        printf("\n Sorry, you have entered the wrong username and password three times!!!");

        getch();
        exit(0);
    }

    system("cls");
}

void filmdetails() {
    printf("1              | Inception         | 2h28min  \n 2              | Pulp Fiction      | 2h34min \n 3              | The Shawshank Redemption | 2h22min \n 4              | The Dark Knight   | 2h32min \n 5              | Forrest Gump      | 2h22min  " ); 
  

  
}

void buy_ticket() {
    char filmname;
    printf("Which film you want to book for ?");
    scanf(" %c", &filmname); 
    printf("Congratulations! You have booked for %c\n", filmname);
}

void old_record() {
   
    printf("Inception \n Pulp Fiction \n The Shawshank Redemption\n The Dark Knight \n Forrest Gump ");
}

int main() {
    login();
    int ch;

    do {
        printf("\n\t\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
        printf("\n");
        printf(" t\t\t t\t\t\t\t Movie Ticket booking ");
        printf("\n\t\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

        printf("\n\nEnter >1< For Movie Details");
        printf("\nEnter >2< To Buy Ticket ");
        printf("\nEnter >3< To View All Transactions");
        printf("\nEnter >0< To Exit ");

        printf("\nEnter your Choice ::");
        scanf("%d", &ch);
        system("cls");

        switch (ch) {
            case 1:
                filmdetails();
                break;
            case 2:
                buy_ticket();
                break;
            case 3:
                old_record();
                break;
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Wrong choice!\n");
                break;
        }
    } while (ch != 0);

    return 0;
}
