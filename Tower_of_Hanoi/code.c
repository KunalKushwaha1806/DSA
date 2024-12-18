/*
The Towers of Hanoi is a classic problem in recursion. The problem consists of three rods (or pegs) and a number of disks of different sizes. The goal is to move all the disks from the source rod to the destination rod, using the auxiliary rod as an intermediate, with the following constraints:

Only one disk can be moved at a time.
A disk can only be moved to the top of another rod if it is smaller than the disk already on the rod.
The recursive approach for solving the Towers of Hanoi problem is as follows:

Move n-1 disks from the source rod to the auxiliary rod using the destination rod.
Move the nth disk (the largest disk) directly from the source rod to the destination rod.
Move the n-1 disks from the auxiliary rod to the destination rod using the source rod.
*/
#include <stdio.h>

// Function to perform the move
void moveDisk(int n, char fromRod, char toRod) {
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
}

// Function to solve the Towers of Hanoi problem using recursion
void towersOfHanoi(int n, char fromRod, char toRod, char auxRod) {
    if (n == 1) {
        moveDisk(1, fromRod, toRod);  // Base case: Only one disk to move
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary rod
    towersOfHanoi(n - 1, fromRod, auxRod, toRod);

    // Step 2: Move the nth disk from source to destination
    moveDisk(n, fromRod, toRod);

    // Step 3: Move the n-1 disks from auxiliary rod to destination
    towersOfHanoi(n - 1, auxRod, toRod, fromRod);
}

int main() {
    int n;
    
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // The three rods are labeled 'A' (source), 'C' (destination), and 'B' (auxiliary)
    printf("The steps to solve the Towers of Hanoi problem are:\n");
    towersOfHanoi(n, 'A', 'C', 'B');  // A is the source, C is the destination, B is the auxiliary rod

    return 0;
}
