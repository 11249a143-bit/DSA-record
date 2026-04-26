*/Aim:
To implement a simple greedy approximation algorithm for the Vertex Cover problem that selects a set of vertices covering all edges with near-optimal efficiency.*/
//program//
#include <stdio.h>

#define V 5   // total number of vertices in the graph

/* 
   Greedy function to compute an approximate Vertex Cover.
   This follows a basic 2-approximation technique.
*/
void vertexCoverApprox(int adj[V][V])
{
    int cover[V];   // stores whether a vertex is included in cover (1 = yes, 0 = no)

    // initially, no vertex is selected
    for (int i = 0; i < V; i++)
    {
        cover[i] = 0;
    }

    // check every pair (i, j) to find edges
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            // if there is an edge and both vertices are not yet picked
            if (adj[i][j] == 1 && cover[i] == 0 && cover[j] == 0)
            {
                // include both endpoints in the vertex cover
                cover[i] = 1;
                cover[j] = 1;

                /* 
                   once marked, all edges connected to these vertices
                   are effectively considered covered, so no need to remove them manually
                */
            }
        }
    }

    // display the resulting vertex cover
    printf("Approximate Vertex Cover: ");
    int total = 0;

    for (int i = 0; i < V; i++)
    {
        if (cover[i] == 1)
        {
            printf("%d ", i);  // print selected vertex
            total++;
        }
    }

    printf("\nTotal vertices in the cover: %d\n", total);
}

int main()
{
    // adjacency matrix representation of the graph
    int adjMatrix[V][V] = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };

    printf("Running Vertex Cover Approximation...\n");

    // call the function
    vertexCoverApprox(adjMatrix);

    return 0;
}
