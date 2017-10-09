#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACKMAX 255 // Reference point, used in isfull

typedef struct intstack // Stack structure for use in the sort
{
    int stack[STACKMAX]; // The Array to be the stack itself
    int top; // Defines place inside the array that is the top of the stack, should not be incremented without testing
} intstack;

void initialize (intstack **); //This should be run on any newly initialised array of stacks to ensure top is initialized and set to -1
int peek(intstack*); // Used to check the top element of a stack
bool isfull(intstack*); // Used to check if a stack is full
bool isempty(intstack*); // Used to check if a stack is empty
int pull(intstack*); // Used to take the top element off a stack
void push(intstack*, int); // Used to place a value on the top of a stack
void printstack(intstack*); // Used to print an entire stack from 0 on the left to top on the right
int main(int argc, char ** argv)
{
    intstack* sofs[STACKMAX];
    initialize(sofs);
    int i;
    for(i=0;i<13;i++){
        push(sofs[1],i);
    }
    printstack(sofs[1]);
}

void initialize (intstack* stacks[]) // Takes the array of stacks and iterates over it allocating memory setting top to -1
{ 
    int i;
    for(i=0;i<STACKMAX;i++){
        stacks[i] = malloc(sizeof(intstack));
        stacks[i] -> top = -1;
    }
}

int peek(intstack* s) // Returns the top element of an array without removing it
{
    return s -> stack[s ->top];
}

bool isfull(intstack* s) // Returns true if the top of the stack is at its maximum value
{
    if(s -> top == STACKMAX){
        return true;
    }
    else{
        return false;
    }
}

bool isempty(intstack* s) // Returns true if the top of the stack is at its minimum value
{
    if(s -> top == -1){
        return true;
    }
    else{
        return false;
    }
}

int pull(intstack* s) // Removes and returns the top value of a stack while incredmenting down where the top of the stack is
{
    int r;
    if(!isempty(s)){ // Will error check, but should error check before, returns -1 on error.
        r = s -> stack[s ->top];
        s -> top = s -> top - 1;
        return r;
    }
    else{
        printf("Error: Pull called on empty stack");
        return -1;
    }
}

void push(intstack* s, int a) // Places a new value on top of a stack while incrementing up where the top of the stack is
{
    if(!isfull(s)){
        s -> top = s -> top + 1;
        s -> stack[s -> top] = a;
        return;
    }
    else{
        printf("Error: Push called on full stack");
        return;
    }
}

void printstack(intstack* s) //Itterates over the array printing its values until reaching the top
{
    int i;
    for(i=0;i <= s -> top;i++){
        printf("%6d", s -> stack[i]);
    }
    printf("\n");
    return;
}