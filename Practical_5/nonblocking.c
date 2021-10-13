
#include <mpi.h>
#include <stdio.h>

int main()
{
    int first = 1, second = 2, third = 3, fourth = 4;

    MPI_Init(NULL, NULL);
    MPI_Request reqs[8];
    MPI_Status stats[8];
    // int tags[2] = {1, 2};
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0)
        MPI_Send(&first, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    if (rank == 1)
    {
        MPI_Irecv(&first, 1, MPI_INT, 0, 33, MPI_COMM_WORLD, &reqs[0]);
        printf("process rank-  %d , data received %d \n", rank, first);
        MPI_Isend(&second, 1, MPI_INT, 2, 33, MPI_COMM_WORLD, &reqs[1]);
    }

    if (rank == 2)
    {
        MPI_Irecv(&second, 1, MPI_INT, 1, 33, MPI_COMM_WORLD, &reqs[2]);
        printf("process rank-  %d , data received %d \n", rank, first);
        MPI_Isend(&third, 1, MPI_INT, 3, 33, MPI_COMM_WORLD, &reqs[3]);
    }

    if (rank == 3)
    {
        MPI_Irecv(&second, 1, MPI_INT, 2, 33, MPI_COMM_WORLD, &reqs[4]);
        printf("process rank-  %d , data received %d \n", rank, first);
        MPI_Isend(&third, 1, MPI_INT, 0, 33, MPI_COMM_WORLD, &reqs[5]);
    }

    if (rank == 0)
    {
        MPI_Irecv(&second, 1, MPI_INT, 2, 33, MPI_COMM_WORLD, &reqs[4]);
        printf("process rank-  %d , data received %d \n", rank, fourth);
        MPI_Isend(&third, 1, MPI_INT, 1, 33, MPI_COMM_WORLD, &reqs[1]);
    }
    MPI_Finalize();
}