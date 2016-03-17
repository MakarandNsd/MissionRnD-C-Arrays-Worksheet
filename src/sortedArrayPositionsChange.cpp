/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
void * swap(int *, int *);
void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (len>0 && Arr != NULL)
	{
		int i, j = 0;
		int p[2];
		for (i = 0; (i<len && j != 2); i++)
		{
			if (Arr[i]>Arr[i + 1])
			{
				p[0] = i;
				j++;
			}
			if (Arr[len - i - 1] < Arr[len - i - 2])
			{
				p[1] = len - i - 1;
				j++;
			}

		}
		if (j == 2)
			swap(&Arr[p[0]], &Arr[p[1]]);
		else
			return NULL;
		for (i = 0; i<len - 1; i++)
			if (Arr[i]>Arr[i + 1])
				return NULL;
	}
	return NULL;
}
void * swap(int *a, int *b)
{
	*a = (*a) + (*b);
	*b = (*a) - (*b);
	*a = (*a) - (*b);
	return NULL;
}
