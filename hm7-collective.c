#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <mpi.h>

#define MASTER  0
#define TAG     0
#define MSGSIZE 100
#define MAX 25

int main(int argc, char* argv[])
{
//http://mpitutorial.com/tutorials/mpi-broadcast-and-collective-communication/
    int my_rank, source, num_nodes;
    char my_host[MAX];    
    int array[100];   
    int number = 0;
    double time = 0.0;     

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_nodes);   
       
    if (my_rank == MASTER) {
        number = 99;        
        printf("Before MPI_Bcast, process %d value is %d\n", my_rank, number);
    }else{
        printf("Before MPI_Bcast, process %d value is %d\n", my_rank, number);    
    }

    time -= MPI_Wtime(); 
    MPI_Bcast(&number, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
    time += MPI_Wtime(); 


    printf("After MPI_Bcast, process %d value is %d\n", my_rank, number);



    MPI_Finalize();
    if (my_rank == MASTER){
         printf("Avg MPI_Bcast time = %lf\n", time);
    }

    return 0;
}
