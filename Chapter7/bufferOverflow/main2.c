#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "other.h" // contains secret function definitions

/* Prints out the You Win! message */
void endGame(void) {
    printf("You win!\n");
    exit(0);
}

/* Main function of the game */
int main() {
    int guess, secret, len, x = 3;
    char buf[12]; // buffer (12 bytes long)
    
    printf("Enter secrent number:\n");
    scanf("%12s", buf); // Read guess from user input (fixed potential overflow)
    guess = atoi(buf); // Convert to an integer
    
    secret = getSecretCode(); // Call the getSecretCode function

    // Check to see if guess is correct
    if (guess == secret) {
        printf("You got it right!\n");
    }
    else {
        printf("You are so wrong!\n");
        return 1; // If incorrect, exit
    }

    printf("Enter the secret string to win:\n");
    scanf("%s", buf); // Get the secret string from user input

    guess = calculateValue(buf, strlen(buf)); // Call calculateValue function
    
    // Check to see if guess is correct
    if (guess != secret) {
        printf("You lose!\n");
        return 2; // If guess is wrong, exit
    }

    /* If both the secret string and number are correct call endGame() */
    endGame();

    return 0;
}

