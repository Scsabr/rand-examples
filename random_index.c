#include <stdlib.h>
#include <stdio.h>

/* 
 * This program demonstrates selection a random item from a 2D array.
 * The randomiser is seeded with argv[1]
 * Usage: ./randomItem seed 
 */

int main(int argc, char** argv)
{
    // usage message
    if(argc==1)
    {
        printf("Usage: randomItem seedValue\n");
        return 0;
    }else if(argc!=2)
    {
	printf("Bad arg count\n");
	return 1;
    }
    
    // collect and convert seed
    int seed = atoi(argv[1]);
    // check that seed is acceptable
    if(seed < 0)
    {
	printf("Bad seed value.\n");
	return 1;
    }

    // seed the convertor with the provided argument
    srand((unsigned) seed);

    // create a 2D array and fill it
    int my_array[100][100];
    for(int row=0; row<100; row++)
    {
        for(int col=0; col<100; col++)
        {
             // randomising the contents of the array
             my_array[row][col] = rand() % 10000;
        }
    }

    // select random indexes
    int random_row = rand() % 100;
    int random_col = rand() % 100;

    int random_value = my_array[random_row][random_col];

    printf("my_array[%d][%d] = %d\n", random_row, random_col, random_value);

    return 0;
}
