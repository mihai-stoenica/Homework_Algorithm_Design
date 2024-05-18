#include <stdio.h>
#include <stdlib.h>
#include "datagenerator.h"
#include "lobsters.h"

int main()
{
    int net_capacity = generate_net_capacity(); //randomly generated net capacity
    int no_of_lobsters = generate_no_of_lobsters(); //randomly generated number of lobsters

    lobster *lobsters = malloc(no_of_lobsters * sizeof(lobster)); //dynamically memory allocation for the pointer of lobsters



    generate_lobsters(lobsters,no_of_lobsters); //randomly generated values for all lobsterers

    printf("Net capacity: %d\nTotal number of lobsters: %d\n\n",net_capacity,no_of_lobsters); //printing net capacity and number of lobsters

    for(int i=0;i<no_of_lobsters;i++)
      printf("Id: %d Size: %d Value %d\n",lobsters[i].id,lobsters[i].size,lobsters[i].value); //printting each lobster's id,size and value


    a_matrix matrix = generate_value_matrix(no_of_lobsters,net_capacity,lobsters); //calculating the matrix of values
    //print_matrix(matrix);//printing the matrix                                     //for each i (from 0 to no of lobsters) and j (from 0 to net capacity) the corresponding cell from the matrix will have the highest total value using the first i lobsters not exceding the size j

    printf("\n");

    printf("The maximum value: %d",get_matrix_value(matrix,no_of_lobsters,net_capacity)); //the maximum value possible(using all the lobsters and the entire capacity) will be found in the last cell of the matrix ( matrix[no_of_lobsters][net_capacity] )

    printf("\n");
    print_lobsters_result(no_of_lobsters,net_capacity,lobsters); // printing all the lobsters that are used


    return 0;
}
