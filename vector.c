#include <stdio.h>
#include <limits.h>
#define INFINITY INT_MAX
#define MAX_NODES 10
void initialize(int graph[MAX_NODES][MAX_NODES], int distance[MAX_NODES][MAX_NODES], int numNodes)
{
    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            if (i == j)
            {
                distance[i][j] = 0;
            }
            else if (graph[i][j] != 0)
            {
                distance[i][j] = graph[i][j];
            }
            else
            {
                distance[i][j] = INFINITY;
            }
        }
    }
}
void distanceVectorRouting(int graph[MAX_NODES][MAX_NODES], int numNodes)
{
    int distance[MAX_NODES][MAX_NODES];
    initialize(graph, distance, numNodes);
    for (int k = 0; k < numNodes; ++k)
    {
        for (int i = 0; i < numNodes; ++i)
        {
            for (int j = 0; j < numNodes; ++j)
            {
                if (distance[i][k] != INFINITY && distance[k][j] != INFINITY && distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    printf("Final Distance Matrix:\n");
    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            if (distance[i][j] == INFINITY)
            {
                printf("INF\t");
            }
            else
            {
                printf("%d\t", distance[i][j]);
            }
        }
        printf("\n");
    }
}
int main()
{
    int numNodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    int graph[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = 0; j < numNodes; ++j)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    distanceVectorRouting(graph, numNodes);
    return 0;
}

/*output:
Enter the number of nodes: 5
Enter the adjacency matrix:
0 2 2 0 0
2 0 3 0 3
2 3 0 4 0
0 0 4 0 3
0 3 0 3 0

Final Distance Matrix:
0	2	2	6	5
2	0	3	6	3
2	3	0	4	6
6	6	4	0	3
5	3	6	3	0
*/

