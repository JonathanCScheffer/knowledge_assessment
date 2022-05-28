#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_calculator.h"

array_struct array_metrics_calculator(){
    array_struct array;
    array_struct array_copy;
    array_metrics_struct metrics;

    print_header();
    read_input(&array);
    array_copy_init(&array_copy);
    metrics_init(&metrics, array.pointer);

    for (int i=0; i<array.size; i++){
        calculate_metrics(&array, &metrics, i);
        get_even_numbers(&array, &array_copy, i);
    }

    calculate_array_average(&metrics, array.size);
    print_footer(metrics);
    return array_copy;
}

void print_header(){
    printf("================================\n");
    printf("=== Array metrics calculator ===\n");
    printf("================================\n");
    printf("Enter the values of the array.\n");
    printf("Press ESC to stop entering values.\n");
}

void read_input(array_struct *array){
    char input_string[6];
    array->pointer = calloc(1, sizeof(int));
    array->size = 0;
    while(1){
        printf("Index {%d}: ", array->size);
        fgets(input_string, 6, stdin);
        if (input_string[0] == 27){
            break;
        }
        else{
            array->pointer[array->size] = atoi(input_string);
            array->size++;
            array->pointer = realloc(array->pointer, sizeof(int));
        }
    }
}

void array_copy_init(array_struct *array_copy){
    array_copy->pointer = calloc(0, sizeof(int));
    array_copy->size = 0;
}

void metrics_init(array_metrics_struct *metrics, int *array_pointer){
    metrics->array_sum = 0;
    metrics->min_value = array_pointer[0];
    metrics->max_value = array_pointer[0];
}

void calculate_metrics(array_struct *array, array_metrics_struct *metrics, int i){
    if (array->pointer[i] > metrics->max_value)
    {
        metrics->max_value = array->pointer[i];
    }

    if (array->pointer[i] < metrics->min_value)
    {
        metrics->min_value = array->pointer[i];
    }
    metrics->array_sum += array->pointer[i];
}

void get_even_numbers(array_struct *array, array_struct *array_copy, int i){
    if ((array->pointer[i] % 2) == 0)
    {
        array_copy->pointer[array_copy->size] = array->pointer[i];
        array_copy->size++;
        array_copy->pointer = realloc(array_copy->pointer, sizeof(int));
    }
}

void calculate_array_average(array_metrics_struct *metrics, int array_size){
    metrics->array_average = (float)(metrics->array_sum) / array_size;
}

void print_footer(array_metrics_struct metrics){
    printf("================================\n");
    printf("================================\n");
    printf("Array average: %.2f\n", metrics.array_average);
    printf("Array minimum value: %d\n", metrics.min_value);
    printf("Array maximum value: %d\n", metrics.max_value);
    printf("********************************\n");
    printf("********************************\n");
    printf("================================\n");
    printf("================================\n");
}