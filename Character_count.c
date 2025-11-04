//Character count framing method:
#include <stdio.h>
#include <string.h>
#define MAX 100
void characterCountFraming(char data[], int frameSize[], int numFrames)
{
    char framedData[MAX];
    int index = 0; 
    int pos = 0;   
    for (int i = 0; i < numFrames; i++)
    {
        int count = frameSize[i] + 1; 
        framedData[pos++] = count;
        for (int j = 0; j < frameSize[i]; j++)
        {
            framedData[pos++] = data[index++];
        }
    }
    printf("\nTransmitted Framed Data (Character Count Framing):\n");
    for (int i = 0; i < pos; i++)
    {
        printf("%d ", framedData[i]);
    }
    printf("\n\nReceiver Side (Extracted Frames):\n");
    int i = 0;
    while (i < pos)
    {
        int count = framedData[i];
        printf("Frame of %d characters: ", count - 1);
        for (int j = 1; j < count; j++)
        {
            printf("%d ", framedData[i + j]);
        }
        printf("\n");
        i += count;
    }
}
int main()
{
    char data[MAX];
    int frameSize[MAX], numFrames;
    printf("Enter total number of frames: ");
    scanf("%d", &numFrames);
    int totalData = 0;
    for (int i = 0; i < numFrames; i++)
    {
        printf("Enter size of frame %d: ", i + 1);
        scanf("%d", &frameSize[i]);
        totalData += frameSize[i];
    }
    printf("Enter %d data bytes (as integers):\n", totalData);
    for (int i = 0; i < totalData; i++)
    {
        scanf("%d", (int *)&data[i]);
    }
    characterCountFraming(data, frameSize, numFrames);
    return 0;
}

/*output:
Enter total number of frames: 3
Enter size of frame 1: 3
Enter size of frame 2: 4
Enter size of frame 3: 5
Enter 12 data bytes (as integers):
1 2 3 4 5 6 7 8 9 10 11 12

Transmitted Framed Data (Character Count Framing):
4 1 2 3 5 4 5 6 7 6 8 9 10 11 12

Receiver Side (Extracted Frames):
Frame of 3 characters: 1 2 3
Frame of 4 characters: 4 5 6 7
Frame of 5 characters: 8 9 10 11 12

Process returned 0 (0x0)   execution time : 74.934 s
Press any key to continue.

*/
