#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int lower, upper, x, guess, count = 0, flag = 0;
    int total_chances;

    // Taking Inputs
    printf("Enter Lower bound: ");
    scanf("%d", &lower);

    // Taking Inputs
    printf("Enter Upper bound: ");
    scanf("%d", &upper);

    // Seed the random number generator
    srand(time(0));

    // Generating random number between the lower and upper
    x = (rand() % (upper - lower + 1)) + lower;
    total_chances
        = (int)ceil(log(upper - lower + 1) / log(2));

    printf("\n\tYou've only %d chances to guess the "
           "integer!\n\n",
           total_chances);

    // for calculation of minimum number of guesses depends
    // upon range
    while (count < total_chances) {
        count++;

        // Taking guessing number as input
        printf("Guess a number: ");
        scanf("%d", &guess);

        // Condition testing
        if (x == guess) {
            printf(
                "Congratulations you did it in %d try!\n",
                count);
            // Once guessed, loop will break
            flag = 1;
            break;
        }
        else if (x > guess) {
            printf("You guessed too small!\n");
        }
        else if (x < guess) {
            printf("You guessed too high!\n");
        }
    }

    // If Guessing is more than required guesses, shows this
    // output.
    if (!flag) {
        printf("\nThe number is %d\n", x);
        printf("\tBetter Luck Next time!\n");
    }

    return 0;
}
