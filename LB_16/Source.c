#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define STEP 0.1

double* full_elements(double* ptr_array, int size);
double* calc_elements(double* ptr_array, int size);
int put_elements(double* ptr_array, int size);
double* delete_k(double* ptr_arr, int* size, int k);
double* insert(double* ptr_arr, int* size, int index, double num);

int main()
{
    setlocale(LC_ALL, "RUS");
    system("chcp 65001");
    srand(time(NULL));

    double* ptr_array, * ptr_array_changed;
    int size;

    puts("¬ведите кол-во элементов массива: ");
    scanf("%d", &size);

    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL)
    {
        puts("error");
        return -1;
    }

    ptr_array_changed = (double*)malloc(size * sizeof(double));
    if (ptr_array_changed == NULL)
    {
        puts("error");
        return -1;
    }

    full_elements(ptr_array, size);
    ptr_array_changed = calc_elements(ptr_array, size);

    put_elements(ptr_array, size);
    put_elements(ptr_array_changed, size);

    ptr_array = delete_k(ptr_array, &size, 4);
    if (ptr_array == NULL)
    {
        puts("error");
        return -1;
    }
    put_elements(ptr_array, size);

    ptr_array = insert(ptr_array, &size, 2, 9.0);
    if (ptr_array == NULL)
    {
        puts("error");
        return -1;
    }
    put_elements(ptr_array, size);

    free(ptr_array);
    free(ptr_array_changed);

    return 0;
}

double* insert(double* ptr_arr, int* size, int index, double num)
{
    double* ptr_arr_n = (double*)realloc(ptr_arr, ((*size) + 1) * sizeof(double));

    if (ptr_arr_n == NULL)
        return NULL;

    ptr_arr = ptr_arr_n;

    for (int i = *size; i > index; i--)
        ptr_arr[i] = ptr_arr[i - 1];

    ptr_arr[index] = num;
    (*size)++;

    return ptr_arr;
}

double* delete_k(double* ptr_arr, int* size, int k)
{
    for (int i = k; i < ((*size) - 1); i++)
    {
        ptr_arr[i] = ptr_arr[i + 1];
    }

    double* temp = (double*)realloc(ptr_arr, (*size - 1) * sizeof(double));
    if (temp == NULL)
    {
        puts("error");
        return NULL;
    }

    ptr_arr = temp;
    (*size)--;

    return ptr_arr;
}

double* full_elements(double* ptr_array, int size)
{
    for (int i = 0; i < size; i++)
    {
        ptr_array[i] = (double)rand() / RAND_MAX * 2 - 1;
    }

    return ptr_array;
}

double* calc_elements(double* ptr_array, int size)
{
    double* temp_array;
    temp_array = (double*)malloc(size * sizeof(double));

    if (temp_array == NULL)
    {
        puts("error");
        return NULL;
    }

    for (int i = 0; i < size; i++)
    {
        temp_array[i] = ptr_array[i];
    }

    for (int i = 0; i < size; i++)
    {
        temp_array[i] = (int)temp_array[i];
    }

    return temp_array;
}

int put_elements(double* ptr_array, int size)
{
    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("%.2lf \t", ptr_array[i]);
    }

    printf("\n");

    return 0;
}