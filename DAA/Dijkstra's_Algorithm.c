*/Aim:
To develop and execute Dijkstra’s Algorithm for determining the shortest path from a chosen source vertex to all other vertices in a weighted graph.*/
//program//
  
#include <stdio.h>

#define V 5
#define INF 999999   // represents infinity (a very large value)

/*
   Function to pick the vertex with the smallest distance
   among the vertices that are not yet processed
*/
int getMinVertex(int distance[], int used[])
{
    int minVal = INF;
    int index = -1;

    for (int i = 0; i < V; i++)
    {
        // choose the unvisited vertex with minimum distance
        if (used[i] == 0 && distance[i] < minVal)
        {
            minVal = distance[i];
            index = i;
        }
    }
    return index;
}

void runDijkstra(int adj[V][V])
{
    int distance[V];   // stores shortest distances from source
    int used[V];       // keeps track of processed vertices

    // initialize distances as infinite and mark all as unvisited
    for (int i = 0; i < V; i++)
    {
        distance[i] = INF;
        used[i] = 0;
    }

    distance[0] = 0;   // taking vertex 0 as the source

    // main loop runs V-1 times
    for (int step = 0; step < V - 1; step++)
    {
        int u = getMinVertex(distance, used); // get closest unvisited vertex

        if (u == -1)
            break; // no valid vertex left

        used[u] = 1; // mark it as processed

        // update distances of adjacent vertices
        for (int v = 0; v < V; v++)
        {
            /*
               conditions for relaxation:
               - vertex not yet processed
               - edge exists
               - current vertex has valid distance
               - new path is shorter
            */
            if (used[v] == 0 && adj[u][v] != 0 &&
                distance[u] != INF &&
                distance[v] > distance[u] + adj[u][v])
            {
                distance[v] = distance[u] + adj[u][v]; // update distance
            }
        }
    }

    // print final shortest distances
    printf("\nVertex \t Distance from Source (0)\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d --> %d\n", i, distance[i]);
    }
}

int main()
{
    // weighted adjacency matrix
    int adjMatrix[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    printf("Executing Dijkstra's Algorithm...\n");

    runDijkstra(adjMatrix);

    return 0;
}
