/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr != NULL && len > 0)
	{
		int i, j = 0;
		for (i = 0; i < len - 1; i++)
			if (Arr[i] > Arr[i + 1])
				return NULL;
		for (i = 0; i < len; i++)
			if (num>Arr[i])
				j = i + 1;
		int *arr = (int *)malloc((len + 1)*sizeof(int));
		for (i = 0; i <j; i++)
			arr[i] = Arr[i];
		arr[j] = num;
		j++;
		for (i = j; i < len + 1; i++)
			arr[i] = Arr[i - 1];
		Arr = arr;
	}
	else
		return NULL;
}
