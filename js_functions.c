#include <stdio.h>
#include <stdlib.h>



int * concat(int * array1, int * array2, int size1, int size2)
{
	int size3 = size1 + size2;
	int * array3 = (int*)calloc(size3, sizeof(int));
	for(int i = 0; i < size1; ++i)
	{
		array3[i] = array1[i];

	}
	int count = 0;
	for(int i = size1; i < size3; ++i)
	{
		array3[i] = array2[count];
		count++;
	}
	return array3;
}
int test(int num)
{
	if(num > 45)
	{
		return 0;
	}

	return 1;
	

}

int every(int * arr, int size, int(*ptr_function)(int))
{
	
	for(int i = 0; i < size; ++i)
	{		
		if(ptr_function(arr[i]) == 0)
		{
			return 0;
		}
		
	}

	return 1;

}

int* filter(int * arr, int size, int(*ptr_function)(int), int * new_size)
{
	//int * tmp = (int*)calloc(size, sizeof(int));
	int count = 0;
	for(int i = 0; i < size; ++i)
	{
		if(ptr_function(arr[i]) == 1)
		{
			(*new_size)++;
		}	
	}
	int * tmp = (int*)calloc((*new_size), sizeof(int)); 
	for(int i = 0; i < size; ++i)
	{
		if(ptr_function(arr[i]) == 1)
		{
			tmp[count] = arr[i];	
			++count;
		}

	}
	
	return tmp;


}
void callback(int value)
{
	printf("%i", value);

}


void forEach(int* arr, int size, void(*callback)(int))
{
	for(int i = 0; i < size; ++i)
	{	
		callback(arr[i]);
	}

}

int index_of(int * array, int size, int value)
{
	for(int i = 0; i < size; ++i)
	{
		if(array[i] == value)
		{
			return i;
		}
	}
	return -1;

}
int last_index_of(int * array, int size, int index)
{
	for(int i = size - 1; i >= 0; --i)
	{
		if(array[i] == index)
		{
			return i;
		}
	}
	return -1;
	
}

void  map(int * array, int size, void(*ptr_function)(int))
{
	 forEach(array, size, ptr_function);
}
void swap(int * a, int * b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;

}

void reverse(int * array, int size)
{
	for(int i = 0; i < size / 2; ++i)
	{
		swap(&array[i], &array[size - i - 1]);
	}

}

int* slice_in_2(int * array, int start, int end)
{
	int count = 0;
	int * tmp = (int*)calloc((end - start), sizeof(int));
	for(int i = start; i < end; ++i)
	{
		tmp[count] = array[i];
		count++;
	}

	return tmp;
}

int * slice_in_1(int * array, int size, int start)
{
	int count = 0;
	int * tmp = (int*)calloc(size - start, sizeof(int));
	for(int i = start; i < size; ++i)
	{
		tmp[count] = array[i];
		count++;
	}
	return tmp;
}
int * slice(int * array, int size)
{
	int count = 0;
	int * tmp = (int*)calloc(size, sizeof(int));
	for(int i = 0; i < size; ++i)
	{	
		tmp[i] = array[i];
		count++;
	}
	return tmp;
}

int some(int * array, int size, int(*ptr_function)(int))
{
	for(int i = 0; i < size; ++i)
	{
		if(ptr_function(array[i]) == 0)
		{
			return 1;	
		}

	}
	return 0;

}

void sort(int * array, int size)
{
	int * new_arr = calloc(size, sizeof(int));
	int index = 0;
	int sym = 0;
	for(int i = 0; i < size; ++i)
	{
		int copy = array[i];

		do
		{
			sym = copy % 10;
			copy /= 10;
	
		}
		while(copy != 0);

		new_arr[index++] = sym;

	}
	for (int i = 0; i < size - 1; i++)
	{
        for (int j = i + 1; j < size; j++)
		{
            if (new_arr[j] <= new_arr[i])	
			{	
				swap(&array[j], &array[i]);
				swap(&new_arr[j],&new_arr[j]); 
			

			}

		}
	}
	
}
int * with(int * array, int size, int index, int value)
{
	int* tmp = (int*)calloc(size, sizeof(int));
	for(int i = 0; i < size; ++i)
	{
		tmp[i] = array[i];
	}
	tmp[index] = value;
	return tmp;

}


int includes(int * array, int size, int symbol)
{
	for(int i = 0; i < size; ++i)
	{
		if(array[i] == symbol)
		return 1;
	}
	return 0;
}

int findLastIndex(int * array, int size, int(*function_ptr)(int), int symbol)
{
	for(int i = size - 1; i >= 0; --i)
	{
		if(function_ptr(array[i]) == 0)
		{
			return i;
		}

	} 
	return 0;

}

int findIndex(int * array, int size, int(*function_ptr)(int), int symbol)
{
	for(int i = 0; i < size; ++i)
	{
		if(function_ptr(array[i]) == 0)
		{
			return i;
	
		}

	}
	return -1;
}
int find(int * array, int size, int(*function_ptr)(int), int symbol)
{
	for(int i = 0; i < size; ++i)
	{
		if(function_ptr(array[i]) == 0)
		{
			return array[i];

		}
	}
	return -1;
}

int * fill(int* array, int size, int change_value, int start, int end)
{
	for(int i = start; i <= end; ++i)
	{
		array[i] = change_value;
	}
	return array;
}




int main()
{
	const int size1 = 5;
	int array1[size1] = {11, 67, 78, 6, 32};


}
