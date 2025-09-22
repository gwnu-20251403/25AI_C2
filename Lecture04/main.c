#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main() {
	srand((unsigned int)time(NULL));

	int arrA[SIZE];
	int arrB[SIZE];

	arrA[0] = -1;

	for (int i = 0; i < SIZE; i++)
	{
		int is_duplicate = 0;
		int rand_value = rand() % SIZE;
		for (int j = 0; j <= i; j++)
		{
			if (rand_value == arrA[j]) is_duplicate++;
		}
		if (is_duplicate) 
		{
			i--;
		}
		else 
		{
			arrA[i] = rand_value;
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		int index = -1;
		for (int j = 0; j < SIZE; j++)
		{
			if (arrA[j] == i) {
				index = j;
				break;
			}
		}
		arrB[i] = index;
	}

	for (int i = 0; i < SIZE; i++)
	{
		printf("%4d [a: %4d  b: %4d]\n", i, arrA[i], arrB[i]);
	}

	return 0;
}