#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

int main() {
	srand((unsigned int)time(NULL));

	int arrA[SIZE];
	int arrB[SIZE];
	int i;

	for (i = 0; i < SIZE; i++)
	{
		arrA[i] = -1;
		arrB[i] = -1;
	}
	
	for (i = 0; i < SIZE; i++)
	{
		int is_duplicate = 0;
		int rand_value = rand() % SIZE;
		for (int j = 0; j <= i; j++)
		{
			if (rand_value == arrA[j]) {
				is_duplicate++; 
				break;
			}
		}
		if (is_duplicate)
		{
			i--;
			continue;
		}
		arrA[i] = rand_value;
	}

	for (i = 0; i < SIZE; i++)
	{
		arrB[arrA[i]] = i;
	}

	for (i = 0; i < SIZE; i++)
	{
		printf("index: %4d [a: %4d  b: %4d]\n", i, arrA[i], arrB[i]);
	}

	return 0;
}