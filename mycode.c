#include<stdio.h>
#include<stdlib.h>

void login() {
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "username";
    char pass[10] = "password";
    FILE *fp;
    
    fp = fopen("BookedSeat.txt", "w");
    fclose(fp);

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

struct book {
    char code[20];
    char name[20];
    char date[20];
    char time[20];
    int cost;
};

struct book b[100];
int seat = 100;

void movie_details();
void buy_ticket();
void old_record();

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
                movie_details();
                break;
            case 2:
                buy_ticket();
                break;
            case 3:
                old_record();
                break;
            case 0:
                exit(0);
                break;
            default:
                printf("Wrong choice!");
                break;
        }
    } while (ch != 0);

    return 0;
}

void movie_details() {
    char ch;
    FILE *fp;

    fp = fopen("data.txt", "r");
    
    if (fp == NULL) {
        printf("file does not found !");
        exit(1);
    } else {
        system("cls");
        
        while ((ch = fgetc(fp)) != EOF)
            printf("%c", ch);
    }

    fclose(fp);
}

void buy_ticket() {
    // your buy_ticket function code
}

void old_record() {
    char ch;
    FILE *fp;

    fp = fopen("oldTransaction.txt", "r");
    
    if (fp == NULL) {
        printf("file does not found !");
        exit(1);
    } else {
        system("cls");
        
        while ((ch = fgetc(fp)) != EOF)
            printf("%c", ch);
    }

    fclose(fp);
}

