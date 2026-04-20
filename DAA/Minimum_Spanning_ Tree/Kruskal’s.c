/*
Aim:
To implement Kruskal’s algorithm to find the Minimum Spanning Tree (MST)
of a weighted graph using a greedy approach.
*/

#include <stdio.h>

#define V 5   // Number of vertices
#define E 6   // Number of edges

int parent[V];  // Disjoint set array

// Function to find the representative (leader) of a set
int findRoot(int vertex)
{
    while (parent[vertex] != vertex)
    {
        vertex = parent[vertex];
    }
    return vertex;
}

// Function to unite two sets
void unionSets(int u, int v)
{
    int rootU = findRoot(u);
    int rootV = findRoot(v);
    parent[rootU] = rootV;
}

// Function to sort edges based on weight (Bubble Sort)
void sortByWeight(int edgeList[E][3])
{
    for (int i = 0; i < E - 1; i++)
    {
        for (int j = 0; j < E - i - 1; j++)
        {
            if (edgeList[j][2] > edgeList[j + 1][2])
            {
                // Swap entire edge (u, v, w)
                for (int k = 0; k < 3; k++)
                {
                    int temp = edgeList[j][k];
                    edgeList[j][k] = edgeList[j + 1][k];
                    edgeList[j + 1][k] = temp;
                }
            }
        }
    }
}

// Kruskal's algorithm implementation
void applyKruskal(int edgeList[E][3])
{
    sortByWeight(edgeList);

    // Initialize disjoint sets
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }

    int edgeCount = 0;
    int totalCost = 0;

    printf("Edges selected for MST:\n");

    for (int i = 0; i < E && edgeCount < V - 1; i++)
    {
        int u = edgeList[i][0];
        int v = edgeList[i][1];
        int weight = edgeList[i][2];

        // Check if adding this edge forms a cycle
        if (findRoot(u) != findRoot(v))
        {
            printf("%d -- %d  (Weight: %d)\n", u, v, weight);
            unionSets(u, v);
            totalCost += weight;
            edgeCount++;
        }
    }

    printf("Total cost of MST: %d\n", totalCost);
}

int main()
{
    // Edge format: {source, destination, weight}
    int edges[E][3] = {
        {0, 1, 2}, {0, 2, 3}, {1, 2, 5},
        {1, 3, 3}, {2, 4, 4}, {3, 4, 2}
    };

    applyKruskal(edges);

    return 0;
}
