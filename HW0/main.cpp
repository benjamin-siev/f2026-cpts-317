#include <stdio.h>
#include <stdbool.h>

/*
Assignment description: 

A traffic light color sequence repeats the color pattern RGY (in this order)  for any times including 0 times, where R is for red,
G is for green, and Y is for yellow. 
Write a C-program (or Java if you never did C before) that uses exactly two Boolean variables b1 and b2 that, for any input word w (you type it from keyboard, ended with end-of-line) that is on alphabet {R,G,Y},  returns yes if w is a traffic light color sequence; return no if not.   

1. pls turnin code and screen shot of a sample run.
2. if I require that the sequence shall repeat RGY for at least three times,  how may Boolean variables shall I use (still two?)? pls state your reasoning.
*/

/*
My solution:
Have the 2 bools act like a binary counter, b1 is the rightmost bit and b2 is right before it
False is 0 and true is 1, so an input of RGY should be: Start 00 -> 01 -> 10 -> 11 End

The same logic can be used to check that there are at least 3 RGY sequences, another 2 bools can be used to keep track of the number of times RGY is repeated. In total there would be 4 bools used
*/

int main() {
    // Two bools and a char for reading input
    bool b1 = false, b2 = false;
    char c;

    printf("Enter a traffic light color sequence (R, G, Y): ");
    // Only checking for valid characters and sequence

    // Keep reading keyboard inputs until a newline is entered
    while ((c = getchar()) != '\n') {
        // Check if valid light colors are entered
        if (c != 'R' && c != 'G' && c != 'Y') {
            printf("no\n");
            return 0;
        }

        // Start counting
        if (c == 'R') {
            b1 = false;
            b2 = false;
        } else if (c == 'G') {
            b1 = true;
            b2 = false;
        } else if (c == 'Y') {
            b1 = false;
            b2 = true;
        }
    }

    // Sanity check
    // Check if the final state is valid (b1 = 0, b2 = 1)
    if (b1 == false && b2 == true) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}