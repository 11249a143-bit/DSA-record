/*
Aim:
To implement Prim’s algorithm to find the Minimum Spanning Tree (MST)
of a weighted graph using a greedy approach.
*/

#include <stdio.h>

#define V 5   // Number of vertices

// Function to find the vertex with minimum key value
int findMinVertex(int key[], int visited[])
{
    int min = 999999;
    int minIndex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to display MST and total cost
void displayMST(int parent[], int graph[V][V])
{
    printf("\nPrim's Minimum Spanning Tree:\n");
    printf("Edge \tWeight\n");

    int totalCost = 0;

    for (int i = 1; i < V; i++)
    {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("Total Cost = %d\n", totalCost);
}

// Prim's Algorithm implementation
void applyPrim(int graph[V][V])
{
    int parent[V];   // Stores MST
    int key[V];      // Minimum weight values
    int visited[V];  // Tracks included vertices

    // Initialize arrays
    for (int i = 0; i < V; i++)
    {
        key[i] = 999999;
        visited[i] = 0;
    }

    key[0] = 0;     // Start from vertex 0
    parent[0] = -1; // Root node

    for (int count = 0; count < V - 1; count++)
    {
        int u = findMinVertex(key, visited);
        visited[u] = 1;

        // Update adjacent vertices
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    displayMST(parent, graph);
}

int main()
{
    // Adjacency matrix representation of graph
    int graph[V][V] = {
        {0, 2, 3, 0, 0},
        {2, 0, 5, 3, 0},
        {3, 5, 0, 0, 4},
        {0, 3, 0, 0, 2},
        {0, 0, 4, 2, 0}
    };

    applyPrim(graph);

    return 0;
}
