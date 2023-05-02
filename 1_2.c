/*
Ответы на вопросы:
1. Сортировка расчёской оказалась самой эффективной
2. Сортировка производилась за разное время (сортировка расчёской самая быстрая)
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

clock_t start, end;
double timeUsage;


void PrintArray(int n, char* array[])
{
    printf("[ ");
    for (int i = 0; i < n - 1; i++)
        printf("%s, ", array[i]);
    printf("%s ]\n", array[n-1]);
    return;
}

void Swap(char** str1, char** str2)
{
    char* temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

int SelectionSort(int n, char* array[])
{
	start = clock();
	
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
        Swap(&array[h], &array[iterationMin]);
        PrintArray(n, array);
        iterations++;
    }
    
    end = clock();
    timeUsage = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Selection sort performed %d iterations within %f seconds with result:\n", iterations, timeUsage);
    PrintArray(n, array);
    printf("%d comparisons had been made\n", comparisons);
    return comparisons;
}

int BubbleSort(int n, char* array[])
{
	start = clock();
	
    int comparisons = 0, iterations = 0;
    for (int h = 0; h < n - 1; h++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if ( strcmp( array[i], array[i+1] ) > 0 )
                Swap(&array[i], &array[i+1]);
            comparisons++;
        }
        PrintArray(n, array);
        iterations++;
    }
    
    end = clock();
    timeUsage = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    
    printf("Bubble sort performed %d iterations within %f seconds with result:\n", iterations, timeUsage);
    PrintArray(n, array);
    printf("%d comparisons had been made\n", comparisons);
    return comparisons;
}

int CombSort(int n, char* array[], const float C)
{
    start = clock();
	
    int comparisons = 0, iterations = 0;
    int gap = n, j;
    while (gap > 1)
    {
        gap = (1 < gap/C) ? gap/C : 1;
        for (int i = 0; i < n - gap; i++)
        {
            j = i + gap;
            if ( strcmp( array[i], array[j] ) > 0 )
                Swap(&array[i], &array[j]);
            comparisons++;
        }
        PrintArray(n, array);
        iterations++;
    }
    
    end = clock();
    timeUsage = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    
    printf("Comb sort performed %d iterations within %f seconds with result:\n", iterations, timeUsage);
    PrintArray(n, array);
    printf("%d comparisons had been made\n", comparisons);
    return comparisons;
}


int main(int argc, char* argv[])
{
    int A = atoi(argv[1]);
    const int N = 2;
    const float C = 1.25; // Comb sort multiplier

    if (A == 1)
    {
        SelectionSort(argc - N, &argv[N]);
    }
    else if (A == 2)
    {
        BubbleSort(argc - N, &argv[N]);
    }
    else if (A == 3)
    {
        CombSort(argc - N, &argv[N], C);
    }
    else if (A == 4)
    {
        char *array2[argc-N], *array3[argc-N];
        memcpy(&array2, &argv[N], (argc-N)*sizeof(char*));
        memcpy(&array3, &argv[N], (argc-N)*sizeof(char*));
        
        SelectionSort(argc - N, &argv[N]);
        printf("\n");
        BubbleSort(argc - N, &array2[0]);
        printf("\n");
        CombSort(argc - N, &array3[0], C);
    }
    
    return 0;
}