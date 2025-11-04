#include<stdio.h>
void main()
{
   int path[5][5], i, j, min, a[5][5], p, st = 1, ed = 5, stp, edp, t[5], index;
   printf("Enter cost matrix:\n");
   for(i = 1; i <= 5; i++)
      for(j = 1; j <= 5; j++)
         scanf("%d", &a[i][j]);
   printf("Enter no of paths:\n");
   scanf("%d", &p);
   printf("Enter possible paths:\n");
   for(i = 1; i <= p; i++)
      for(j = 1; j <= 5; j++)
         scanf("%d", &path[i][j]);
   for(i = 1; i <= p; i++)
   {
      t[i] = 0;
      stp = st;
      for(j = 1; j <= 5; j++)
      {
            edp = path[i][j];
            t[i] = t[i] + a[stp][edp];
            if(edp == ed)
               break;
            else
               stp = edp;
      }
   }
   min = t[st];
   index = st;
   for(i = 1; i <= p; i++)
   {
      if(min > t[i])
      {
         min = t[i];
         index = i;
      }
   }
   printf("Minimum cost: %d", min);
   printf("\nMinimum cost path: ");
   for(i = 1; i <= 5; i++)
   {
      printf("->%d", path[index][i]);
      if(path[index][i] == ed)
      break;
   }
}
/*output:
Enter cost matrix:
0 2 2 0 0
2 0 3 0 3
2 3 0 3 0
0 0 3 0 2
0 3 0 2 0
Enter no of paths:
4
Enter possible paths:
1 2 5 0 0
1 3 2 5 0
1 3 4 5 0
1 2 3 4 5
Minimum cost: 5
Minimum cost path: ->1->2->5
Process returned 5 (0x5)   execution time : 38.361 s
Press any key to continue.
*/
