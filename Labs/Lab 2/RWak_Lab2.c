/*
Name: Rita Wak
Student ID: 240164
Date: 20/03/26
Algorithm: 
1. Display message about guessing number between 1 and 20.
2. Generate random number using rand().
3. Loop for 5 attempts:
   - Get user guess.
   - Compare guess with random number.
   - If equal → print success message and terminate.
   - Else → print hint (low/high).
4. If all attempts fail → print sorry message with the correct number.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int getGuess();
void printSuccess();
void printHint(int guess, int number);
void printSorry(int number);

int main() {
    srand(time(0)); // Seed random number
    int number = rand() % 20 + 1; // Random number between 1 and 20
    int guess;
    int attempts;

    printf("I am thinking of a number between 1 and 20.\n");

    for (attempts = 1; attempts <= 5; attempts++) {
        guess = getGuess();

        if (guess == number) {
            printSuccess();
            return 0; // terminate program immediately
        } else {
            printHint(guess, number);
        }
    }

    printSorry(number);
    return 0;
}

// Function definitions
int getGuess() {
    int g;
    printf("Can you guess what it is? ");
    scanf("%d", &g);
    return g;
}

void printSuccess() {
    printf("Congratulations! You did it.\n");
}

void printHint(int guess, int number) {
    if (guess < number)
        printf("Your guess is low. Try again:\n");
    else
        printf("Your guess is high. Try again:\n");
}

void printSorry(int number) {
    printf("Sorry. The number was %d. You should have gotten it by now. Better luck next time.\n", number);
}

