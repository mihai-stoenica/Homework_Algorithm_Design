#ifndef LOBSTERS_H_INCLUDED
#define LOBSTERS_H_INCLUDED

//the lobster structure has 3 components: a size,a value and an id
typedef struct {
    int size;
    int value;
    int id;
}lobster;


//the matrix is declared as a struct containing the number of rows, the number of colums and a pointer that points to the begining of the matrix(stored linearly)
typedef struct {
    int no_rows;
    int no_colums;
    int *matrix;
}a_matrix;



//headers for the used functions

void set_matrix_value(a_matrix matrix, int row_index, int column_index, int element_value);
int get_matrix_value(a_matrix matrix, int row_index, int column_index);
void print_matrix(a_matrix matrix);
a_matrix generate_value_matrix(int no_of_lobsters,int net_capacity,lobster *lobsters);
int get_max_value(int val1, int val2);
void print_lobsters_result(int no_of_lobsters,int net_capacity,lobster *lobsters);

#endif // LOBSTERS_H_INCLUDED
