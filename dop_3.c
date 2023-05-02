/*
Все алгоритмы выполняются за различное время
*/

/*

User must pass one number and at least one string. A number denotes the algorithm to be used as follows:

1 - use Selection sort
2 - use Bubble sort
3 - use Comb sort
4 - use Selection, Bubble and Comb sort continuously

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


const int WORDS = 9, LEN = 1;

clock_t start, end;
double timeUsage;


void PrintArray(int n, char array[WORDS][LEN+1])
{
    printf("[ ");
    for (int i = 0; i < n - 1; i++)
        printf("%s, ", array[i]);
    printf("%s ]\n", array[n-1]);
    return;
}

void Swap(char* str1[LEN+1], char* str2[LEN+1])
{
    char temp[LEN];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

int SelectionSort(int n, char array[WORDS][LEN+1])
{
    start = clock();
	
    printf("Started Selection sort of array\n");
    PrintArray(WORDS, array);

    int comparisons = 0, iterations = 0;
    int iterationMin;
    for (int h = 0; h < n - 1; h++)
    {
        iterationMin = h;
        for (int i = h+1; i < n; i++)
        {
            if ( strcmp( array[i], array[iterationMin] ) < 0 )
                iterationMin = i;
            comparisons++;
        }
        Swap((char**)&array[h], (char**)&array[iterationMin]);
        // PrintArray(WORDS, array);
        iterations++;
    }
    
    end = clock();
    timeUsage = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    
    printf("Selection sort performed %d iterations within %f seconds with result:\n", iterations, timeUsage);
    PrintArray(n, array);
    printf("%d comparisons had been made\n", comparisons);
    return comparisons;
}

int BubbleSort(int n, char array[WORDS][LEN+1])
{
    start = clock();
	
    printf("Started Bubble sort of array\n");
    PrintArray(WORDS, array);
    int comparisons = 0, iterations = 0;
    for (int h = 0; h < n - 1; h++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if ( strcmp( array[i], array[i+1] ) > 0 )
                Swap((char**)&array[i], (char**)&array[i+1]);
            comparisons++;
        }
        // PrintArray(WORDS, array);
        iterations++;
    }
    
    end = clock();
    timeUsage = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    
    printf("Bubble sort performed %d iterations within %f seconds with result:\n", iterations, timeUsage);
    PrintArray(n, array);
    printf("%d comparisons had been made\n", comparisons);
    return comparisons;
}

int CombSort(int n, char array[WORDS][LEN+1], const float C)
{
    start = clock();
	
    printf("Started Comb sort of array\n");
    PrintArray(WORDS, array);

    int comparisons = 0, iterations = 0;
    int gap = n, j;
    while (gap > 1)
    {
        gap = (1 < gap/C) ? gap/C : 1;
        for (int i = 0; i < n - gap; i++)
        {
            j = i + gap;
            if ( strcmp( array[i], array[j] ) > 0 )
                Swap((char**)&array[i], (char**)&array[j]);
            comparisons++;
        }
        // PrintArray(WORDS, array);
        iterations++;
    }
    
    end = clock();
    timeUsage = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    
    printf("Comb sort performed %d iterations within %f seconds with result:\n", iterations, timeUsage);
    PrintArray(n, array);
    printf("%d comparisons had been made\n", comparisons);
    return comparisons;
}

void RandomWord(char* word, const int LOWER, const int UPPER)
{
    char l;
    for (int i = 0; i < LEN; i++)
    {
        l =  ( rand() % (UPPER - LOWER + 1) ) + LOWER;
        word[i] = l;
    }
    word[LEN] = '\0';
    return;
}

void GenerateArray(char array[WORDS][LEN+1])
{
    char word[LEN];
    for (int i = 0; i < WORDS; i++)
    {
        RandomWord(word, 97, 122);
        for (int k = 0; k < LEN; k++)
            array[i][k] = word[k];
        array[i][LEN] = '\0';
    }
    printf("Created array ");
    PrintArray(WORDS, array);
    return;
}


int main(int argc, char* argv[])
{
    /* Provide rand() with a seed */
    int i, stime;
    long ltime;
    ltime = time(NULL);
    stime = (unsigned) ltime/2;
    srand(stime);

    char array1[WORDS][LEN+1];
    GenerateArray(array1);

    int A = atoi(argv[1]);
    const int N = 2;
    const float C = 1.25; // Comb sort multiplier

    if (A == 1)
    {
        printf("\n");
        SelectionSort(WORDS, array1);
    }
    else if (A == 2) 
    {
        printf("\n");
        BubbleSort(WORDS, array1);
    }
    else if (A == 3)
    {
        printf("\n");
        CombSort(WORDS, array1, C);
    }
    else if (A == 4)
    {
        char array2[WORDS][LEN], array3[WORDS][LEN];
        GenerateArray(array2);
        GenerateArray(array3);
        printf("\n");
        
        SelectionSort(WORDS, array1);
        printf("\n");
        BubbleSort(WORDS, array2);
        printf("\n");
        CombSort(WORDS, array3, C);
    }
    
    return 0;
}