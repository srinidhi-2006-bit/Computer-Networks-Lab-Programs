//BIT-stuffing:
#include <stdio.h>
#include <string.h>
#define MAX 200
#define FLAG "01111110"

void bitStuffing(char data[], char stuffed[])
{
    int count = 0, j = 0;
    for (int i = 0; i < strlen(data); i++)
    {
        stuffed[j++] = data[i];
        if (data[i] == '1')
        {
            count++;
            if (count == 5)
            {
                stuffed[j++] = '0'; 
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    stuffed[j] = '\0';
}
void bitDeStuffing(char stuffed[], char original[])
{
    int count = 0, j = 0;
    for (int i = 0; i < strlen(stuffed); i++)
    {
        original[j++] = stuffed[i];
        if (stuffed[i] == '1')
        {
            count++;
            if (count == 5)
            {
                i++;
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    original[j] = '\0';
}
int main()
{
    char data[MAX], stuffed[MAX], frame[MAX], destuffed[MAX];
    printf("Enter binary data bits: ");
    scanf("%s", data);
    bitStuffing(data, stuffed);
    strcpy(frame, FLAG);
    strcat(frame, stuffed);
    strcat(frame, FLAG);
    printf("\nTransmitted Frame with Bit Stuffing:\n%s\n", frame);
    char extracted[MAX];
    strncpy(extracted, frame + 8, strlen(frame) - 16);
    extracted[strlen(frame) - 16] = '\0';
    bitDeStuffing(extracted, destuffed);
    printf("\nReceived Data after De-stuffing:\n%s\n", destuffed);
    return 0;
}
/*output:
Enter binary data bits: 1111

Transmitted Frame with Bit Stuffing:
01111110111101111110

Received Data after De-stuffing:
1111

Process returned 0 (0x0)   execution time : 4.157 s


*/
