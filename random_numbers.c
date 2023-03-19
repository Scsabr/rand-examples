#include <stdlib.h>
#include <stdio.h>

/* 
 * This program generates a random number between 0 and argv[1].
 * The randomiser is seeded with argv[2]
 * Usage: ./randomBetween max_value seed 
 */

int main(int argc, char** argv)
{
    // usage message
    if(argc==1)
    {
        printf("Usage: randomBetween maxValue seedValue\n");
        return 0;
    }else if(argc!=3)
    {
	printf("Bad arg count\n");
	return 1;
    }
    
    // set up variables to hold args
    int max, seed;
    // attempt to convert to ints
    max = atoi(argv[1]);
    seed = atoi(argv[2]);
    // check that these are within accepted range
    if(max < 1 || seed < 0)
    {
	printf("Bad argument values.\n");
	return 1;
    }

    // seed the convertor with the provided argument
    srand((unsigned) seed);

    // generate a random number between 0 and our maximum
    // we do this by runnind rand() to produce a value 0 -> MAXINT
    // and then finding the modulo when divided by our maximum
    // I have added 1 as the maximum should be inclusive in this case
    int random_number = rand() % (max+1);

    printf("Random number: %d\n", random_number);

    return 0;
}
