#include "datagenerator.h"
#include <time.h>
#include <stdlib.h>
#include "lobsters.h"

int generate_net_capacity()
{
    srand((unsigned)time(NULL) + clock());
    return (rand()*12) % 20000+1; //generates a random number between 1 and 20000
}

int generate_no_of_lobsters() //generates a random number from 1 to
{
    srand((unsigned)time(NULL) + clock());
    return (rand()*11) % 60000+1; //generates a random number between 1 and 60000
}

void generate_lobsters(lobster *lobsters,int no_of_lobsters)
{
    srand(time(NULL));
    for(int iterator=0;iterator<no_of_lobsters;iterator++)
    {
        lobsters[iterator].id = iterator+1; //lobsters' id's will star from 1
        lobsters[iterator].size = rand()%12332+1; //generates random sizes for each lobster(between 1 and 12332)
        lobsters[iterator].value = rand()%17607+1; //generates random values for each lobster(between 1 and 17607)
        //those 2 random numbers were chosen to avoid getting the same size and value
    }
}


