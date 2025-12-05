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
int find_min_index(double* ptr_array, int size);
double* merge_arrays(double* a, int size_a, double* b, int size_b, double* c, int size_c, int* result_size);

int main()
{
    setlocale(LC_ALL, "RUS");
    system("chcp 65001");
    srand(time(NULL));

    int size_a = rand() % 41 + 10;
    int size_b = rand() % 41 + 10;
    int size_c = rand() % 41 + 10;

    double* array_a = (double*)malloc(size_a * sizeof(double));
    double* array_b = (double*)malloc(size_b * sizeof(double));
    double* array_c = (double*)malloc(size_c * sizeof(double));

    if (array_a == NULL || array_b == NULL || array_c == NULL) 
    {
        puts("error");
        return -1;
    }

    full_elements(array_a, size_a);
    full_elements(array_b, size_b);
    full_elements(array_c, size_c);
    put_elements(array_a, size_a);
    put_elements(array_b, size_b);
    put_elements(array_c, size_c);

    int min_index_a = find_min_index(array_a, size_a);
    array_a = delete_k(array_a, &size_a, min_index_a);

    int min_index_b = find_min_index(array_b, size_b);
    array_b = delete_k(array_b, &size_b, min_index_b);

    int min_index_c = find_min_index(array_c, size_c);
    array_c = delete_k(array_c, &size_c, min_index_c);

    printf("Массив A после удаления минимума:\n");
    put_elements(array_a, size_a);

    printf("Массив B после удаления минимума:\n");
    put_elements(array_b, size_b);

    printf("Массив C после удаления минимума:\n");
    put_elements(array_c, size_c);

    int size_d;
    double* array_d = merge_arrays(array_a, size_a, array_b, size_b, array_c, size_c, &size_d);

    if (array_d == NULL) 
    {
        puts("error");
        return -1;
    }

    printf("Объединенный массив D:\n");
    put_elements(array_d, size_d);

    free(array_a);
    free(array_b);
    free(array_c);
    free(array_d);

    return 0;
}

int find_min_index(double* ptr_array, int size) 
{
    int min_index = 0;
    for (int i = 1; i < size; i++)
    {
        if (ptr_array[i] < ptr_array[min_index]) 
        {
            min_index = i;
        }
    }
    return min_index;
}

double* merge_arrays(double* a, int size_a, double* b, int size_b, double* c, int size_c, int* result_size) 
{
    *result_size = size_a + size_b + size_c;
    double* result = (double*)malloc(*result_size * sizeof(double));
    if (result == NULL) 
    {
        return NULL;
    }

    int index = 0;
    for (int i = 0; i < size_a; i++) 
    {
        result[index++] = a[i];
    }
    for (int i = 0; i < size_b; i++) 
    {
        result[index++] = b[i];
    }
    for (int i = 0; i < size_c; i++) 
    {
        result[index++] = c[i];
    }

    return result;
}

double* insert(double* ptr_arr, int* size, int index, double num) {
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

double* delete_k(double* ptr_arr, int* size, int k) {
    for (int i = k; i < ((*size) - 1); i++) {
        ptr_arr[i] = ptr_arr[i + 1];
    }
    double* temp = (double*)realloc(ptr_arr, (*size - 1) * sizeof(double));
    if (temp == NULL) {
        puts("error");
        return NULL;
    }
    ptr_arr = temp;
    (*size)--;
    return ptr_arr;
}

double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)rand() / RAND_MAX * 2 - 1;
    }
    return ptr_array;
}

double* calc_elements(double* ptr_array, int size) {
    double* temp_array;
    temp_array = (double*)malloc(size * sizeof(double));
    if (temp_array == NULL) {
        puts("error");
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        temp_array[i] = ptr_array[i];
    }
    for (int i = 0; i < size; i++) {
        temp_array[i] = (int)temp_array[i];
    }
    return temp_array;
}

int put_elements(double* ptr_array, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%.2lf \t", ptr_array[i]);
    }
    printf("\n");
    return 0;
}