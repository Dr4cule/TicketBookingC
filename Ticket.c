// Ticket program in c

// for standard input output, used in every program 
#include <stdio.h>
// for tolower and toupper functions
#include <ctype.h>
// idk why i included this, had the random function ig
#include <stdlib.h>
// for current time, time(0)
#include <time.h>
// for strcmp function
#include <string.h>

// to make list of movies
typedef struct {
    char name[20];
    int price;
}
Movie;

int main() {
    system("cls");
    printf("\033[1;37m");
    int choice;
    // for random numbers
    srand(time(0));
    int n = 10;
    int x[n][n];
    int c = 1;
    // to store seats
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = c;
            c++;
        }
    }
    // makes 9th row reserved
    for (int i = 0; i < n; i++) {
        x[9][i] = 0;
    }
    printf("\t\t\t\t\t\t      Welcome to ticket booking system!\n\n");
    char ans;
    // input for program to continue or not
    printf("Do you want to book a ticket? (y/n): ");
    scanf("%c", & ans);
    // makes Y or N to y or n
    if (tolower(ans) == 'y') {
        // highly confidential data! 
        char rlusn[] = "OnePiece";
        char rlpass[] = "Shanks24";
        char usn[20];
        char pass[20];
        printf("\n\t\t\t Login\n\n");
        printf("Username :- ");
        scanf("%s", & usn);
        printf("Password :- ");
        scanf("%s", & pass);
        if (strcmp(usn, rlusn) == 0 && strcmp(rlpass, pass) == 0) {
            printf("\n");
            // array of structure to store movie and its price
            Movie movies[] = {{"Pushpa-2",400}, {"Interstellar",300}, {"RRR",500}, {"The Matrix",600}, {"One Piece",700}, {"IT",800}, {"The Dark Knight",900}};
            printf("=== Movies available ===\n");
            // to print from array of struct
            for (int i = 0; i < sizeof(movies) / sizeof(movies[0]); i++) {
                printf("%d) %s - %d\n", i + 1, movies[i].name, movies[i].price);
            }
            printf("\n");
            printf("Enter the number of the movie you want to book: ");
            scanf("%d", & choice);
            printf("\n\n");
            printf("\t\t The available seats for %s are: \n\n", movies[choice - 1].name);
            // reserving random seats for a little feel of real-ism
            int l = (rand() % 20) + 20;
            int rans[l];
            for (int i = 0; i < l; i++) {
                int num = rand() % 90;
                rans[i] = num;
            }
            for (int i = 0; i < n; i++) {
                // making the randomly generated seats reserved
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < l; k++) {
                        if (x[i][j] == rans[k]) {
                            x[i][j] = 0;
                        }
                    }
                }
            }
            // to print seats
            printf("\t\t\033[1;37m============================================ Screen =============================================\033[0m\n\n");
            for (int i = 0; i < n; i++) {
                printf("\t\t");
                for (int j = 0; j < n; j++) {
                    // to get spaces right
                    if (i == 0) {
                        if (x[i][j] == 0) {
                            printf("\033[1;31m(%d,%d)R    \033[0m", i, j + 1);
                        } else {
                            printf("\033[1;32m(%d,%d)E    \033[0m", i, j + 1);
                        }
                    } else {
                        if (x[i][j] == 0) {
                            printf("\033[1;31m(%d,%d)R    \033[0m", i, j + 1);
                        } else {
                            printf("\033[1;32m(%d,%d)E    \033[0m", i, j + 1);
                        }
                    }
                }
                if (i == 8) {
                    printf("\n\n\t\t\033[1;37m==========================================>\033[0m \033[1;33mvip row\033[0m \033[1;37m<============================================\033[0m\n");
                }
                if (i == 8) {
                    printf("\n");
                } else {
                    printf("\n\n");
                }
            }
            printf("\t\t\033[1;37m=================================================================================================\033[0m\033[1;37m\n");
            // take in seats to be reserved
            int y;
            printf("\nEnter the number of seats you want to reserve: ");
            scanf("%d", &y);
            if(y > 10){
                printf("\nYou can only reserve 10 seats at a time.\nTry again\n");
                return 0;
            }
            printf("\nThe total price for tickets will be %d", y * movies[choice - 1].price);
            int kl = y + 10;
            int rsv[kl];
            printf("\n\nEnter the seat numbers you want to reserve with spaces in between(Example for (2,3) input 23): ");
            for (int i = 0; i < y; i++) {
                scanf("%d", &rsv[i]);
            }
            int ccc = 90;
            for(int i = y; i < kl; i++){
                rsv[i] = ccc;
                ccc++;
            }
            // checks if the input array of seat numbers is valid (neet to fix)
            for (int i = 0; i < y; i++) {
                if (rsv[i] > 90) {
                    if(rsv[i] > 90 && rsv[i] < 100){
                        printf("\n\nThe seat in the vip row is already reserved.\n");
                        return 0;
                    } else{
                        printf("\n\n%d is a Invalid seat number. Please enter a valid seat number next time.\n", rsv[i]);
                    }
                    return 0;
                }
            }
            // checks if the seat is already registered or not (need to fix)
            // for (int i = 0; i < y; i++) {
            //     int z = rsv[i] / 10;                       // why is this not working 
            //     int y = rsv[i] % 10;                       // does not work because input 11, checks for value at 00, how would it work duh
            //     z -= 1;                                      // 75 checks for 64
            //     y -= 1;
            //     if (x[z][y] == 0) {
            //         printf("Seat (%d,%d) is already reserved!\n", z, y);
            //         return 0;
            //     }
            // }
            // THIS WORKS!!!!!
            int m = 0;
            // checks if the given seat number is present in the 2d array or not and if yes increases m count
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    for(int k = 0; k < y; k++){
                        if(x[i][j] == rsv[k]){
                            m++;
                        }
                    }
                }
            }
            // printf("\n");
            // for(int i = 0; i < sizeof(avail)/sizeof(avail[0]); i++){
            //     printf("%d ", avail[i]);
            // }
            // printf("\n");
            // if m count != number of input values
            if(m != y){
                printf("\nYou chose an already registered seat, please try again.\n");
                return 0;
            }
            int tobepayed = y * movies[choice - 1].price;
            int payed;
            printf("Pay the fee for the reservation to be finalized\n");
            printf("Total amount to pay: %d\n", tobepayed);
            // loop till condition satisflies
            while (1) {
                printf("Paying: ");
                scanf("%d", & payed);
                if (payed == tobepayed) {
                    printf("\n\tPayment successful!\n\n");
                    break;
                } else {
                    printf("Invalid payment amount, try again.\n");
                }
            }
            // seat reserver 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < y; k++) {
                        if (x[i][j] == rsv[k]) {
                            x[i][j] = 0;
                        }
                    }
                }
            }
            //system("cls");
            printf("\t\t\033[1;37m============================================ Screen =============================================\033[0m\n\n");
            for (int i = 0; i < n; i++) {
                printf("\t\t");
                for (int j = 0; j < n; j++) {
                    // to get spaces right
                    if (i == 0) {
                        if (x[i][j] == 0) {
                            printf("\033[1;31m(%d,%d)R    \033[0m", i, j + 1);
                        } else {
                            printf("\033[1;32m(%d,%d)E    \033[0m", i, j + 1);
                        }
                    } else {
                        if (x[i][j] == 0) {
                            printf("\033[1;31m(%d,%d)R    \033[0m", i, j + 1);
                        } else {
                            printf("\033[1;32m(%d,%d)E    \033[0m", i, j + 1);
                        }
                    }
                }
                if (i == 8) {
                    printf("\n\n\t\t\033[1;37m==========================================>\033[0m \033[1;33mvip row\033[0m \033[1;37m<============================================\033[0m\n");
                }
                if (i == 8) {
                    printf("\n");
                } else {
                    printf("\n\n");
                }
            }
            printf("\t\t\033[1;37m=================================================================================================\033[0m\033[1;37m\n");
        }  else {
        printf("Invalid credentials, try again!");
    }
        printf("\n\t\t\t\t Thank you");
    } else if (tolower(ans) == 'n') {
            printf("\t\t\t Thank you, see you later!");
        }
    printf("\033[0m");
    return 0;
}
