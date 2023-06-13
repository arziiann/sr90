#include <stdio.h>
#include <stdlib.h>

struct Vector
{
	int * m_vector;
	int m_size;
	int m_copacity;
};

typedef struct Vector Vector;
void init(Vector * vector)
{
	vector->m_vector = NULL;
	vector->m_size = 0;
	vector->m_copacity = 0;

}

void reserv(Vector * vector, int size)
{
	if(vector->m_vector == NULL)
	{
		int * tmp = (int*)calloc(sizeof(int), size);
	}
	else
	{
		int * tmp1 = (int*)calloc(sizeof(int), size);
		for(int i = 0; i < size; ++i)
		{
			tmp1[i] = vector->m_vector[i];
		} 
		free(vector->m_vector);
		vector->m_vector = tmp1;
		tmp1 = NULL;
	}	

}


void push_back(Vector * vector, int sym)
{
	reserv(vector, 1);
	vector -> m_vector[vector -> m_size] = sym;
	vector -> m_size ++;
}

void insert(Vector * vector,int pos, int elem)
{	
	reserv(vector,1);
	
	for(int i = vector->m_size; i >= pos; --i)
	{
		vector->m_vector[i] = vector->m_vector[i - 1];
	}
	vector->m_vector[pos] = elem;
	vector->m_size++;	
}

int capacity(Vector * vector)
{
	return vector->m_copacity;

}
int empty(Vector * vector)
{
	if(vector->m_size == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int at(int pos, Vector * vector)
{
	return vector -> m_vector[pos];
}

int size(Vector * vector)
{
	return vector -> m_size;
}	



int main()
{
	

}
