//Loss recovery using the Go-Back-N
#include<stdio.h>
int main()
{
    int w, i, f, frames[50];
    printf("Enter window size: ");
    scanf("%d", &w);
    printf("\nEnter number of frames to transmit: ");
    scanf("%d", &f);
    printf("\nEnter %d frames: ", f);
    for (i = 1; i <= f; i++)
         scanf("%d", &frames[i]);
    printf("\nWith sliding window protocol and Go-Back-N loss recovery, the frames will be sent in the following manner (assuming no corruption of frames)\n\n");
    int base = 1;
    int nextSeqNum = 1;
    while (base <= f)
    {
        for (i = base; i < base + w && i <= f; ++i)
        {
            printf("%d ", frames[i]);
        }
        int ack;
        printf("\nEnter the last acknowledged frame number: ");
        scanf("%d", &ack);
        if (ack < nextSeqNum)
        {
            continue;
        }
        base = ack + 1;
        nextSeqNum = base;
        printf("Acknowledgment received. Resending frames from %d to %d\n", base, base + w - 1);
    }
    printf("\nAcknowledgement of all frames sent is received by sender\n");
    return 0;
}


/*output;
Enter window size: 3

Enter number of frames to transmit: 8

Enter 8 frames: 8 9 6 5 2 3 1 4

With sliding window protocol and Go-Back-N loss recovery, the frames will be sent in the following manner (assuming no corruption of frames)

8 9 6
Enter the last acknowledged frame number: 2
Acknowledgment received. Resending frames from 3 to 5
6 5 2
Enter the last acknowledged frame number:
*/
