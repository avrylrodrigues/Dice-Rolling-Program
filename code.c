//including header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //declaring variables with specified datatypes
    int faces, throws, i, random;
    
    //declaring arrays and initializing each element in it
    int occurrences[25] = {0};
    float percentages[25] = {0.0};
    
    //starting point for random number generation
    srand(time(NULL));
    
    //user input for number of faces
    printf("Enter number of faces: ");
    int face_result = scanf("%d", &faces);
    
    //if input for number of faces is invalid
    while (faces <= 0 || faces >= 26)
    {
        while (getchar() != '\n');
        printf("Invalid input. Enter a number between 1 and 25.\n");
        printf("Enter number of faces: ");
        face_result = scanf("%d", &faces);
    }
    
    //user input for number of throws
    printf("Enter number of throws: ");
    int throw_result = scanf("%d", &throws);
    //if input for number of throws is invalid
    while (throws <= 0 || throws >= 500)
    {
        while (getchar() != '\n');
        printf("Invalid input. Enter a number between 1 and 500.\n");
        printf("Enter number of throws: ");
        throw_result = scanf("%d", &throws);
    }
    
    //counts occurrences
    for (i = 0; i < throws; ++i)
    {
        random = rand() % faces + 1;
        occurrences[random] ++;
    }

    //calculates percentages
    for (i = 1; i <= faces; ++i)
    {
        percentages[i] = (float) occurrences[i] / throws * 100;
    }

    //output
    printf("\n********************************************");
    printf("\n Number \t Occurrences \t Percentage \n");
    printf("********************************************");
    for (i = 1; i <= faces; ++i)
    {
        printf(" \n %d \t\t %d \t\t %.1f%% \n", i, occurrences[i], percentages[i]);
    }
    printf("********************************************");
    return 0;
}
