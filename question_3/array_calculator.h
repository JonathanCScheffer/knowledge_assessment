struct array{
    int *pointer;
    int size;
};

struct array_metrics{
    int min_value, max_value, array_sum;
    float array_average;
};

typedef struct array array_struct;
typedef struct array_metrics array_metrics_struct;

array_struct array_metrics_calculator();
void print_header();
void read_input(array_struct *array);
void array_copy_init(array_struct *array_copy);
void metrics_init(array_metrics_struct *metrics, int* array_pointer);
void calculate_metrics(array_struct *array, array_metrics_struct *metrics, int i);
void get_even_numbers(array_struct *array, array_struct *array_copy, int i);
void calculate_array_average(array_metrics_struct *metrics, int array_size);
void print_footer(array_metrics_struct metrics);
