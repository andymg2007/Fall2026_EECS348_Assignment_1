#include <stdio.h>   // include the standard input output library

int main(void){  // initialize main
    int secret = 7;  // create variable secret as an int equal to 7
    int guess;   // create variable guess as an int to be used for user input
    int attempts = 3; // create variable attempts as an int equal to 3
    int won = 0;  // create variable won as an int equal to 0

    printf("Guess a number between 1 and 10.\n");   // prints prompt to the user to get their guess

    for (int i = 1; i <= attempts; i++) {    // initialize for loop to run code below as many times as attempts is equal to
        printf("Attempt %d/%d. Enter your guess: ", i, attempts);    // prints which guess out of total attempts it is and asks user for another guess
        scanf("%d", &guess);  

        if (guess == secret) {
            printf("Correct! You win!\n");
            won =1;
            break;
        } else if (guess < secret) {
            printf("Too low! Try again.\n");
        } else {
            printf("Too high! Try again.\n");
        }
    }

    if (!won) {
        printf("You lose! The number was %d.\n", secret);
    }

    return 0;
}