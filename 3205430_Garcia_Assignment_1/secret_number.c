/*
Program Name: EECS 348 Assignment 1
Description: A C program that sets a secret number between 1 and 10 and 
              allows the user up to 3 attempts to guess it correctly.
Inputs: User guesses entered via standard input (stdin).
Output: Terminal output providing feedback on guesses, status messages, 
         and game result.
Collaborators: None
Other Sources: ChatGPT for help creating error catching in c
Author: Andy Garcia
Creation Date: September 8, 2026
Revision Date: September 8, 2026
Revisions: Added input validation, range checks, and const modifiers.
*/
#include <stdio.h>   // include the standard input output library

int main(void){  // initialize main
    const int secret = 7;  // create constant variable secret as an int equal to 7
    const int min_range = 1;   // create constant variable min_range as an int equal to 1
    const int max_range = 10;  // create constant variable max_range as an int equal to 10
    const int attempts = 3; // create constant variable attempts as an int equal to 3

    int guess;   // create variable guess as an int to be used for user input
    int won = 0;  // create variable won as an int equal to 0
    char inputBuffer[100]; // create character array buffer to store raw user input (concept and code from ChatGPT)

    printf("Guess a number between %d and %d.\n", min_range, max_range);   // prints prompt to the user to get their guess

    for (int i = 1; i <= attempts; i++) {    // initialize for loop to run code below as many times as attempts is equal to
        printf("Attempt %d/%d. Enter your guess: ", i, attempts);    // prints which guess out of total attempts it is and asks user for another guess
        

        /* ChatGPT created the inputbuffer and uses it over the next two blocks of code to test if the users 
           input is readable and then if the input is a valid integer. */
        if (fgets(inputBuffer, sizeof(inputBuffer), stdin) == NULL) { // reads full input line and checks if input read failed
            printf("\nError reading input. Exiting.\n"); // prints error message to the user
            return 1; // returns 1 to exit program with an error status
        }
        // Code authored and originated from ChatGPT 
        if (sscanf(inputBuffer, "%d", &guess) != 1) { // checks if input buffer fails to parse as a valid int
            printf("Invalid input! Please enter a valid number.\n"); // prints error message to the user
            i--; // subtracts 1 from i so bad input does not count as an attempt
            continue; // skips rest of loop and restarts next iteration
        }

        // If statement to verify if guess is within boundary (improved by chatgpt)
        if (guess < min_range || guess > max_range) { // checks if guess is less than min_range or greater than max_range
            printf("Out of bounds! Guess must be between %d and %d.\n", min_range, max_range); // prints message that guess was out of range
            i--; // subtracts 1 from i so out of bounds guess does not count as an attempt
            continue; // skips rest of loop and restarts next iteration
        }

        if (guess == secret) {   // checks if guess is equal to secret
            printf("Correct! You win!\n");   // prints winning message to the user
            won = 1;  // sets variable won equal to 1
            break;   // exits the for loop immediately
        } else if (guess < secret) { // checks if guess is less than secret
            printf("Too low! Try again.\n"); // prints message to user that guess was too low
        } else { // handles case where guess is greater than secret
            printf("Too high! Try again.\n");    // prints message to user that guess was too high
        }
    }

    if (!won) {  // checks if variable won is equal to 0
        printf("You lose! The number was %d.\n", secret);    // prints losing message and reveals secret to the user
    }

    return 0;    // returns 0 to end the program successfully
}