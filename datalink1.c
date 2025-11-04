//3. Develop a simple data link layer that performs the flow control using the sliding window protocol and loss recovery using the Go-Back-N mechanism.
//Flow control using the sliding window protocol
#include<stdio.h>
int main()
{
    int w,i,f,frames[50];
    printf("Enter window size: ");
    scanf("%d",&w);
    printf("\nEnter number of frames to transmit: ");
    scanf("%d",&f);
    printf("\nEnter %d frames: ",f);
    for(i=1;i<=f;i++)
        scanf("%d",&frames[i]);
    printf("\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)\n\n");
    printf("After sending %d frames at each stage sender waits for acknowledgement sent by the receiver\n\n",w);
    for(i=1;i<=f;i++)
    {
        if(i%w==0)
        {
            printf("%d\n",frames[i]);
            printf("Acknowledgement of above frames sent is received by sender\n\n");
        }
        else
        printf("%d ",frames[i]);
    }
    if(f%w!=0)
    printf("\nAcknowledgement of above frames sent is received by sender\n");
    return 0;
}


/*output:
Enter window size: 3

Enter number of frames to transmit: 8

Enter 8 frames: 8 9 6 5 2 3 1 4

With sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)

After sending 3 frames at each stage sender waits for acknowledgement sent by the receiver

8 9 6
Acknowledgement of above frames sent is received by sender

5 2 3
Acknowledgement of above frames sent is received by sender

1 4
Acknowledgement of above frames sent is received by sender

Process returned 0 (0x0)   execution time : 37.900 s
Press any key to continue.

*/
