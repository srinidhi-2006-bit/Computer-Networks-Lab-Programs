#include <stdio.h>
void adj(int k, int n, int a[10][10]);
int main()
{
    int a[10][10], n, root;
    int i, j;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("Enter connection of %d --> %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter root node: ");
    scanf("%d", &root);
    adj(root, n, a);
    return 0;
}
void adj(int k, int n, int a[10][10])
{
    int j;
    printf("Adjacent nodes of root node %d:\n", k);
    for (j = 1; j <= n; j++)
    {
        if (a[k][j] == 1 || a[j][k] == 1)
        { 
            printf("%d\t", j);
        }
    }
    printf("\n");
}

/*output:
Enter number of nodes: 5
Enter adjacency matrix:
Enter connection of 1 --> 1: 0
Enter connection of 1 --> 2: 1
Enter connection of 1 --> 3: 1
Enter connection of 1 --> 4: 0
Enter connection of 1 --> 5: 0
Enter connection of 2 --> 1: 1
Enter connection of 2 --> 2: 0
Enter connection of 2 --> 3: 1
Enter connection of 2 --> 4: 0
Enter connection of 2 --> 5: 1
Enter connection of 3 --> 1: 1
Enter connection of 3 --> 2: 1
Enter connection of 3 --> 3: 0
Enter connection of 3 --> 4: 1
Enter connection of 3 --> 5: 0
Enter connection of 4 --> 1: 0
Enter connection of 4 --> 2: 0
Enter connection of 4 --> 3: 1
Enter connection of 4 --> 4: 0
Enter connection of 4 --> 5: 1
Enter connection of 5 --> 1: 0
Enter connection of 5 --> 2: 1
Enter connection of 5 --> 3: 0
Enter connection of 5 --> 4: 1
Enter connection of 5 --> 5: 0
Enter root node: 3
Adjacent nodes of root node 3:
1       2       4
*/