

#include<stdio.h>
#include<stdlib.h>

void login()
{
    int a=0,i=0;
    char uname [10],c=' ';
    char pword[10],code[10];
    char user[10]="username";
    char pass[10]="password";
    FILE *fp;
fp = fopen("BookedSeat.txt","w");
 fclose(fp);
    do
{
    printf("\n\t\t\t\t\t\t       ********************************************");
    printf("\n\t\t\t\t\t\t       **************** LOGIN FIRST ***************");
    printf("\n\t\t\t\t\t\t       ********************************************");
    printf(" \n\n        ENTER USERNAME:-");
    scanf("%s", &uname);
    printf(" \n\n        ENTER PASSWORD:-");
    while(i<10)
    {
        pword [i]=getch() ;
        c=pword [i];
        if (c==13) break;
        else printf ("*");
        i++;
    }
    pword[i]='\0';
    //char code=pword;
    i=0;
    //scanf ("%s",&pword);
    if (strcmp (uname, "username") ==0 && strcmp (pword, "password") ==0)
    {

        printf ("\n\t\t\t\t\t\t\t  ******** LOGIN IS SUCCESSFUL ********");
        printf ("\n\n\t\t\t\t\t\t\t     WELCOME TO OUR BOOKING SYSTEM");
        printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tPress any key to continue...");
        getch ();//holds the screen break;
        break;
        }
        else
        {
   printf ("\n   LOGIN IS UNSUCCESSFUL \n Try again!!!\n");
   a++;

  getch(); //holds the screen

        }
}
   while (a<=2);
   if (a>2)
        {
       printf ("\n Sorry you have entered the wrong username and password for three times!!!");

        getch ();
        exit (0);
        }
        system ("cls");

}

 struct book
 {
   char code [20];
   char name [20];
   char date [20];
   char time [20];
   int cost;

 };
struct book b[100];
int seat = 100 ;

void movie_details ();//for movie details
void buy_ticket (); // to buy ticket
void old_record(); //for view old records of users, booked tickets
void main ()
{
   login ();
   int ch;
  do{
  printf("\n\t\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
  printf("\n");
  printf (" t\t\t t\t\t\t\t             Movie Ticket booking  ");
  printf("\n\t\t\t\t\t\t++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

  printf ("\n\nEnter >1< For Movie Details");
  printf ("\nEnter >2< To Buy Ticket ");
  printf ("\nEnter >3< To View All Transactions");
  printf ("\nEnter >0< To Exit ");

  printf ("\nEnter your Choice ::");
  scanf ("%d", &ch);
      system ("cls");

  switch (ch)
  {
          case 1 :
          movie_details();
    break;
    case 2:
        buy_ticket ();
    break;

    case 3:
        old_record ();
    break;

    case 0:
    exit (0);
    break;

    default:
    printf ("Wrong choice!");
    break;
    }
  }while (ch!=0);

}


void movie_details ()
{

    char ch;
   FILE *fp;

   fp = fopen ("data.txt", "r");
   if (fp == NULL)
   {
       printf ("file does not found !");
       exit (1);

   }
   else
   {
       system("cls");
       while(( ch = fgetc (fp) ) !=EOF )
        printf ("%c", ch);

   }

   fclose (fp);

}

//for ticket booking
 void buy_ticket ()
{int count=0;
//struct book b;
   FILE *fp;

FILE *ufp;

  int total_seat,mobile,total_amount;
  char name [20];


  char ch; //used.in display all movies
  char movie_code[20]; // for searching

  //display all movies by default for movie code
  fp - fopen ("data.txt" , "r");
  if (fp == NULL)
  {
      printf ("file does not found !");
      exit (1);

  }
  else
  {
      system ("cls");
      while ( ( ch = fgetc(fp) ) != EOF )
      printf ("%c", ch);

  }
  fclose (fp);

          //display ends
          printf ("\n To Buy ticket Choice Movie (Enter the number of Movie) \n");
          printf ("\n Enter movie code :");
          scanf ("%s" ,movie_code);
          //system("clear")
       fp = fopen ("data.txt", "r");
       if (fp == NULL)
       {
           printf ("file does not found !");
           exit (1);

       }
      else
      {
          while (getc (fp) != EOF)
       {
       fscanf (fp, "8s is is as &d", b[count] . code, b [count] . name, b [count] . date, b [count] .time, &b [count]);

      if(strcmp(b[count].code,movie_code)== 0)
      {
      //printf("%s / %s / %3 / 85 / %d\n", b.code, b.name, b.date, b.time, b.cost) ;
      printf ("\n Record Found\n");
      printf ("\n\t\tCode ::%s", b[count]. code);
      printf ("\n\t\tMovie name ::%s", b[count].name);
      printf("\n\t\tDate ::%s", b[count].date);
      printf ("In\t\tTime ::%s", b[count].time) ;
      printf ("\n\t\tPrice of ticket::%dTK", b[count].cost);

      break;
    }
     count++;

       }

    }
    printf("\n* Fill Details *");
    printf("\n Your name :");
    scanf("%s",name);
    printf("\n * Mobile number *");
    scanf("%d",&mobile);
    printf ("\n Total number of tickets :");
    scanf ("%d",&total_seat);
    if (total_seat>=10)
  {
    printf ("You can't book these amount of tickets \n");
    printf ("Please book between 10 tickets\n");
    printf ("\nPlease re-enter total number of tickets : ");
    scanf ("%d", &total_seat);
}
   int i,j;
   int seat [10];
        printf ("\n\t\t\t\t                                       SCREEN\n\n\n");
     for (i=1;i<=100;i++)
     {

     printf ("%d\t", i);

     printf ("*\t",i);
     if (1%10==0)
     printf ("\n\n");
     }

     printf ("\n Booked seats\n");
     fp = fopen ("BookedSeat.txt", "r");
   if (fp == NULL)
{
     printf ("file does not found !");
     exit (1);

}
 else
 {
    while ( (ch = fgetc(fp) ) != EOF )
     printf ("%c", ch);

 }
   fclose(fp);
     printf ("\n These seats are booked for %s Movie", b [count] .name);
     printf ("\n Please choose others seats");
     for (i=1;i<=total_seat;i++) {
     printf ("\n Choose seat number :");
  scanf ("%d", &j);

   if (j>100||j<1)
    {
         printf ("&d seat is unavailable in this theater\n", j) ;
         printf ("Please re-enter seat number: ");
         scanf ("%d", &j);
    }
      ufp=fopen ("Bookedssat .txt", "a");
   if (ufp == NULL)
   {
      printf ("File not Found");
   }
   else
   {
    fprintf (ufp, "ed In",j);
    printf ("\n Record insert Successful to the Booked seat file");
    seat [i-1]=j;
   }
    printf ("\n");
  fclose (ufp);
  fclose (fp);

  }



     total_amount = b[count].cost * total_seat;

     printf ("\n\n");
     printf ("\t\t\t\t\t\t\t -----------------------THEATER BOOKING TICKET---------------------\n");
     printf ("\t\t\t\t\t\t\t=======================================================================\n");
     printf ("\n\n\n\n \t\t\t\tName : %s                   It\t\t\t\tItMovie name : %s \n" , name, b [count].name);
     printf ("\t\t\t\tMobile Number : %d        \t\t\t\t\tDate      : %s\n", mobile, b[count].date);
     printf("\t\t\t\t\t\t\t\t\t                             Time              : %s",b[count].time);
     printf ("\n\t\t\t\t\t                            Total seats : %d", total_seat);
     printf ("\n\t\t\t\t\t                            Cost per ticket: %dTK" ,b[count].cost);
     printf ("\n\t\t\t\t\t                            Total Amount : %dTK",total_amount);
     printf ("\n\t\t\t\t\t                             Seat Number : ");
     for(i=1;i<=total_seat;i++)
 {
    printf ("%d  ",seat[i-1]);
 }
  printf ("\n");


 printf("\n\t\t\t\t\t\t\t                 Payment                       \n");
 printf("\n\t\t\t\t\t\t\t  **************** BKASH ********************\n");
 printf ("\n Merchant Number: 01869738641\n");
 printf ("\n Your number: %d\n", mobile);
 printf("\n Total Amount : %dTK\n", total_amount);
 printf("\n\n\t\t\t\t\t\t\t\t ********** Booking Confirmed **********  \n");
 printf("\n\n\t\t\t\t\t\t\t\t ********** ENJOY YOUR MOVIE **********  \n");


   ufp=fopen ("oldTransaction.txt", "a");
   if (ufp == NULL)
   {
    printf ("File not Found");
   }
   else
    {
    fprintf (ufp, "% %d %d %d %s %d %s %s \n" , name, mobile, total_seat, total_amount, b [count] . name, b[count].time);
    printf ("\n Record insert Successful to the old record file");
    }
    printf ("\n");
  fclose (ufp);
  fclose (fp);

}

//for view all user transactions
void old_record ()
{
    char ch;
    FILE *fp;

    //system ("clear");

     fp = fopen ("oldTransaction.txt", "r");
     if (fp == NULL)
{
     printf("file does not found !");
     exit (1);

   }
   else
   {
       system ("cls") ;
       while ((ch = fgetc (fp) ) != EOF )
        printf("%c", ch);

   }
     fclose (fp) ;


   }







#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 5
#define MAX_USERS 10
#define MAX_ROWS 10
#define MAX_COLS 10
#define TICKET_PRICE 10

// Define movie structure
struct Movie {
    char title[50];
    int duration;
    int availableSeats[MAX_ROWS][MAX_COLS];
};

// Define user structure
struct User {
    char username[20];
    char password[20];
    int bookedSeats[MAX_ROWS][MAX_COLS];
    float wallet;
};

// Function prototypes
void displayMovies(struct Movie movies[], int numMovies);
void displaySeats(int seats[MAX_ROWS][MAX_COLS]);
int bookSeats(struct Movie *movie, struct User *user);
void cancelBooking(struct Movie *movie, struct User *user);
void displayBookings(struct User *user);
int loginUser(struct User users[], int numUsers, struct User *currentUser);
void registerUser(struct User users[], int *numUsers);

int main() {
    // Initialize movies
    struct Movie movies[MAX_MOVIES] = {
        {"Inception", 150, {0}},
        {"The Dark Knight", 180, {0}},
        {"Nos Otages", 115, {0}},
        {"Jurassic Park", 120, {0}},
        {"The Shawshank Redemption", 142, {0}}
    };

    // Initialize users
    struct User users[MAX_USERS];
    int numUsers = 0;
    struct User currentUser;

    int choice;

    do {
        printf("\n========= Movie Ticket Booking System =========\n");
        printf("1. Display Movies\n");
        printf("2. Book Tickets\n");
        printf("3. Cancel Booking\n");
        printf("4. View Bookings\n");
        printf("5. Login\n");
        printf("6. Register\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMovies(movies, MAX_MOVIES);
                break;
            case 2:
                if (loginUser(users, numUsers, &currentUser)) {
                    bookSeats(&movies[0], &currentUser);
                }
                break;
            case 3:
                if (loginUser(users, numUsers, &currentUser)) {
                    cancelBooking(&movies[0], &currentUser);
                }
                break;
            case 4:
                if (loginUser(users, numUsers, &currentUser)) {
                    displayBookings(&currentUser);
                }
                break;
            case 5:
                loginUser(users, numUsers, &currentUser);
                break;
            case 6:
                registerUser(users, &numUsers);
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}

// Function to display movies
void displayMovies(struct Movie movies[], int numMovies) {
    printf("\n========= Available Movies =========\n");
    for (int i = 0; i < numMovies; ++i) {
        printf("%d. %s (%d minutes)\n", i + 1, movies[i].title, movies[i].duration);
    }
}

// Function to display available seats
void displaySeats(int seats[MAX_ROWS][MAX_COLS]) {
    printf("\n========= Available Seats =========\n");
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            printf("%c ", seats[i][j] ? 'X' : 'O');
        }
        printf("\n");
    }
}

// Function to book seats
int bookSeats(struct Movie *movie, struct User *user) {
    // Implementation similar to the previous example
    // ...
}

// Function to cancel booking
void cancelBooking(struct Movie *movie, struct User *user) {
    // Implementation similar to the previous example
    // ...
}

// Function to display user bookings
void displayBookings(struct User *user) {
    // Implementation similar to the previous example
    // ...
}
void displayBookings(struct User *user) {
    printf("\n========= Your Bookings =========\n");
    displaySeats(user->bookedSeats);

    printf("\n========= Wallet Balance =========\n");
    printf("Current Wallet Balance: $%.2f\n", user->wallet);
}
// Function to login user
int loginUser(struct User users[], int numUsers, struct User *currentUser) {
    char username[20];
    char password[20];

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; ++i) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            *currentUser = users[i];
            printf("Login successful!\n");
            return 1;
        }
    }

    printf("Invalid username or password. Please try again.\n");
    return 0;
}

// Function to register a new user
void registerUser(struct User users[], int *numUsers) {
    if (*numUsers < MAX_USERS) {
        printf("Enter a new username: ");
        scanf("%s", users[*numUsers].username);
        printf("Enter a password: ");
        scanf("%s", users[*numUsers].password);

        memset(users[*numUsers].bookedSeats, 0, sizeof(users[*numUsers].bookedSeats));
        users[*numUsers].wallet = 0.0; // Initialize wallet balance

        printf("Registration successful!\n");
        (*numUsers)++;
    } else {
        printf("Maximum number of users reached. Cannot register new user.\n");
    }
}
