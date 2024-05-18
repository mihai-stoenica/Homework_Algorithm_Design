#include <stdlib.h>
#include <stdio.h>
#include "lobsters.h"

void set_matrix_value(a_matrix matrix, int row_index, int column_index, int element_value) //set a value for the ,atrix element situated at [row_index][column_index]
{
    int position;

    position = row_index * matrix.no_colums + column_index; //offset from the start of the matrix pointer to the element we want to overwrite

    *(matrix.matrix + position) = element_value; //matrix.matrix points to the begining of the "matrix" and, by addind the offset, we can set the value from the element at the position [row_index][column_index]
}

int get_matrix_value(a_matrix matrix, int row_index, int column_index) //function to return the value of element at the position [row_index][column_index]
{
    int position;

    position = row_index * matrix.no_colums + column_index; //offset from the start of the matrix pointer to the element we want to return

    return *(matrix.matrix + position); //matrix.matrix points to the begining of the "matrix" and, by adding the offset, we can return the value from the element at the position [row_index][column_index]
}

void print_matrix(a_matrix matrix) //function for printing the matrix
{
    int iterator_rows;
    int iterator_columns;

    printf("\n === Matrix === \n");
    for(iterator_rows = 0; iterator_rows < matrix.no_rows; iterator_rows++)
    {
        for(iterator_columns = 0; iterator_columns < matrix.no_colums; iterator_columns++)
        {
            printf("%d ",matrix.matrix[iterator_rows * matrix.no_colums + iterator_columns]); //"iterator_rows * matrix.no_colums + iterator_columns" is the number of elements from the begining of the matrix till the actual element
        }
        printf("\n");
    }
}

int get_max_value(int val1, int val2) //returns the highest value between 2 parameters
{
    return (val1 >= val2) ? val1 : val2;
}


a_matrix generate_value_matrix(int no_of_lobsters,int net_capacity,lobster *lobsters) //function to generate the matrix with the property: for each i (from 0 to no of lobsters) and j (from 0 to net capacity) the corresponding cell from the matrix will have the highest total value using only the first i lobsters not exceding the size j
{
    a_matrix matrix;
    matrix.no_rows = no_of_lobsters+1; //the matrix number of rows must be no_of_lobsters+1 because it has start from 0 and reach no_of_lobsters
    matrix.no_colums = net_capacity+1; //the matrix number of colums must be net_capacity+1 because it has start from 0 and reach net_capacity
    matrix.matrix = calloc((matrix.no_rows) * (matrix.no_colums), sizeof(int)); //dynamically allocation for the matrix

    int iterator_rows,iterator_columns;

    for(iterator_rows = 0; iterator_rows < matrix.no_rows; iterator_rows++)
        for(iterator_columns = 0; iterator_columns < matrix.no_colums; iterator_columns++) //we go through the whole matrix
        {
            if(iterator_rows == 0 || iterator_columns == 0) //for either 0 lobsters or 0 capacity the maximum value will be 0
                set_matrix_value(matrix,iterator_rows,iterator_columns,0);
            else
            {
                if(iterator_columns < lobsters[iterator_rows-1].size) set_matrix_value(matrix,iterator_rows,iterator_columns,get_matrix_value(matrix,iterator_rows-1,iterator_columns)); //in the case when the size of a lobster we want to use is higher than the capacity available at that point, the column index may exceed the matrix boundaries and the program won't work properly, so we choose directly not to use the certain lobster
                else
                    set_matrix_value(matrix,iterator_rows,iterator_columns,
                                     get_max_value(
                                             get_matrix_value(
                                                     matrix,iterator_rows-1,iterator_columns),lobsters[iterator_rows-1].value+
                                                                                              get_matrix_value(matrix,iterator_rows-1,iterator_columns-lobsters[iterator_rows-1].size))); //the value for a every cell is chosen between 2 variants(we choose the highest): we either use the i'th lobster or not. in case of not using it, the value will be the same with the one from above(matrix[i-1][j]). in case of using it we add up its value(lobster[i].value) with the max value obtained using (i-1) lobsters and (j - lobster[i].size) (the remaining available size in case of using the lobster)
            }
        }


    return matrix; //reutrning the matrix
}

void print_lobsters_result(int no_of_lobsters,int net_capacity,lobster *lobsters) // function to print the lobsters that were used
{
    a_matrix matrix = generate_value_matrix(no_of_lobsters,net_capacity,lobsters);

    int iterator_rows = no_of_lobsters; //the iterators are initialized with the last indexes from the matrix because we need to go through the matrix backwards
    int iterator_colums = net_capacity;

    while(iterator_rows > 0 && iterator_colums > 0)
    {
        if(get_matrix_value(matrix,iterator_rows-1,iterator_colums) == get_matrix_value(matrix,iterator_rows,iterator_colums)) //in case of equality between the current value and the element above it (the current lobster wasn't used), we simply go upwards
        {
            iterator_rows--;
        }
        else       //in case of inequality(it means the current lobster was used), we go upwards 1 position and substract the size of current lobster from colum iterator
        {
            printf("Id: %d Size: %d Value: %d\n",lobsters[iterator_rows-1].id,lobsters[iterator_rows-1].size,lobsters[iterator_rows-1].value);
            iterator_rows--;
            iterator_colums -= lobsters[iterator_rows].size;
        }
    }

}

