
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char at(char * array, int index)
{
    if(index < 0)
    {
        index = index * (-1);
        for(int i = 0; i < strlen(array); ++i)
        {
            
            return array[strlen(array) - index];
            
        }
    }
    else
    {
        for(int i = 0; i < strlen(array); ++i)
        {   
                if(i == index)
                return array[i];
        }
            
        
    }
    return 0;
    
    

}

int charCodeAt(char * array, int index)
{
    for(int i = 0; i < strlen(array); ++i)
    {
        if(i == index)
        {
            return (int)array[i];
        }
    }
    return 0;

}
char * concat(char * array1, char * array2, char symbol)
{
    int size1 = strlen(array1);
    int size2 = strlen(array2);
    int sum_size = size1 + size2 + 1;
    int index = 0;
    int count = 0;
    char * tmp = (char*)calloc((strlen(array1) + strlen(array2)) + 2, sizeof(char));
    for(int i = 0; i < size1; ++i)
    {
        tmp[index] = array1[i];
        ++index;
    }
    
    tmp[index] = symbol;
    ++index;
    
    for(int i = index; i < sum_size; ++i)
    {
        tmp[i] = array2[count];
        count++;
        
        ++index;
    }
    return tmp;
}
int endsWith (char * array, char * text)
{
   int array_length = strlen(array);
   int text_length = strlen(text);
   if(text_length > array_length)
   {
        return 0;
   }

    int array_index = array_length - text_length;
    text_length = 0;
    while(array[array_index] != '\0')
    {
        if(array[array_index] != text[text_length])
        {
            return 0;   
        }
        ++array_index;
        ++text_length;
        
    }
    return 1;

}
void swap(char * a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

int isspace(int c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}
char * repet(char * array, int count)
{
    char * tmp = (char*)calloc((strlen(array) * count) + 3, sizeof(char));
    for(int i = 0; i < count; ++i)
    {
        strcat(tmp, array);
        tmp[strlen(tmp)] = ',';
    }

    return tmp;
    

}

void toUpperCase(char* array)
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        if (array[i] >= 'a' && array[i] <= 'z')
        {
            array[i] = array[i] - 'a' + 'A';
        }
    }
}
void toLowerCase(char* array)
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        if (array[i] >= 'A' && array[i] <= 'Z')
        {
            array[i] = array[i] + 32;
        }
    }
}

char * substring_in_two_argument(char * array, int start, int end)
{
    int count = 0;
    char* tmp = (char*)calloc(end - start, sizeof(char));//1, 5
    for(int i = start; i < end; ++i )
    {
        tmp[count] = array[i];
        count++;
    }
    return tmp;
}
char * substring_in_one_argument(char * array, int start)
{
    int count = 0;
    char* tmp = (char*)calloc(strlen(array) - start, sizeof(char) + 1);


    for(int i = start; i < strlen(array); ++i )
    {
        tmp[count] = array[i];
        count++;
    }
    return tmp;

}

int startsWith(char * array, char * text)
{
    int size_array = strlen(array);
    int size_text = strlen(text);

    if(size_array < size_text)
    {
        return 0;
    }
    for (int i = 0; i < size_text; ++i)
    {
        if (array[i] != text[i]) {
            return 0;
        }
    }
    return 1;
}
int startsWit_in_two_argument(char* array, char* text, int position) {
    int size_array = strlen(array);
    int size_text = strlen(text);

    if(size_array < size_text)
    {
        return 0;
    }


    if (position + size_text > size_array) {
        return 0;
    }

    for (int i = 0; i < size_text; i++)
    {
        if (array[i + position] != text[i])
        {
            return 0;
        }
    }

    return 1;
}

char* slice_in_one_argument(char * array, int start)
{
     int count = 0;
    char* tmp = (char*)calloc(strlen(array) - start, sizeof(char) + 1);
    for (int i = start; i < strlen(array); i++)
    {
        tmp[count] = array[i];
        ++count;
    }
    return tmp;
}

int includes(char* array, char* text)
{
    if (strstr(array, text) != NULL)
    {
        return 1;
    }
    
    return 0;
}
int indexOf( char* array,  char* text)
{
    char* ptr = strstr(array, text);
    if (ptr == NULL) {
        return -1; 
    }
    return ptr - array;  
}

int lastIndexOf( char* array,  char* string)
{
    const char* ptr = strstr(array, string);
    const char* lastPtr = NULL;

    while (ptr != NULL) 
    {
        lastPtr = ptr;
        ptr = strstr(ptr + 1, string);
    }

    if (lastPtr == NULL)
    {
        return -1;  
    }

        return lastPtr - array;  
}
char* padEnd(char* array, char* array2, int size)
{
    int size1 = strlen(array);
    if (size <= size1)
    {
        return array;
    }
    char* tmp = (char*)calloc(size, sizeof(char));

    strcat(tmp, array);

    for (int i = 0; i < size - size1; i++)
    {
        strcat(tmp, array2);
    }
  

   return tmp;
}
char* padStart(char* array, char* array2, int size)
{
    int size1 = strlen(array);
    int size2 = strlen(array2);
    if (size <= size1)
    {
        return array;
    }
    char* tmp = (char*)calloc(size + 1, sizeof(char));
   
    for (int i = 0; i < size - size1; i++)
    {
        strcat(tmp, array2);
    }

    strcat(tmp, array);
   
    return tmp;

}
char* replace(char* array, char* text1, char* text2)
{
    int size1 = strlen(text1);
    int size2 = strlen(text2);

    char* tmp = (char*)calloc(size1 + size2, sizeof(char));
    strcpy(tmp, array);
    int index = indexOf(array, text1);
    for (int i = 0; i < size2; ++i)
    {
        tmp[index++] = text2[i];
    }
   
    return tmp;
   
}

char* trim(char* array)
{
    int length = 0;
    int start = 0;
    int end = 0;

    while (array[start] == ' ' || array[start] == '\t' || array[start] == '\n')
    {
        start++;
    }

    for (int i = start; array[i] != '\0'; i++)
    {
        if (array[i] != ' ' && array[i] != '\t' && array[i] != '\n')
        {
            end = i;
        }
    }

    length = end - start + 1;

    char* result = (char*)malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++) {
        result[i] = array[start + i];
    }

    result[length] = '\0'; 

    return result;
}
char* trimStart( char* array)
{
    int length = strlen(array);
    const char* start = array;

    while (isspace(*start))
        start++;

    int size = length - (start - array);

    char* tmp = (char*)malloc((size + 1) * sizeof(char));
    strncpy(tmp, start, size);
    tmp[size] = '\0';

    return tmp;
}
char* trimEnd( char* array)
{
    int length = strlen(array);
    const char* end = array + length - 1;

    while (end >= array && isspace(*end))
        end--;

    int size = end - array + 1;

    char* tmp = (char*)malloc((size + 1) * sizeof(char));
    strncpy(tmp, array, size);
    tmp[size] = '\0';

    return tmp;
}

char* replaceAll(char* array, char* text1, char* text2)
{
    int size1 = strlen(text1);
    int size2 = strlen(text2);

    char* tmp = (char*)calloc(size1 + size2, sizeof(char));
    strcpy(tmp, array);
    for (int i = 0; i < size1 + size2; i++)
    {
        int index = indexOf(tmp, text1);
        for (int i = 0; i < size2; ++i)
        {
            tmp[index++] = text2[i];
        }
    }
    return tmp;
}

int main()
{

}
