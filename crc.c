#include <stdio.h>
int main(void)
{
    int data[50], div[16], rem[16];
    int datalen, divlen, i, j, k;
    int ch;
    printf("Enter the data: ");
    i = 0;
    while ((ch = fgetc(stdin)) != '\n')
    {
        if (ch == '1')
            data[i] = 1;
        else
            data[i] = 0;
        i++;
    }
    datalen = i; 
    printf("\nEnter the divisor: ");
    i = 0;
    while ((ch = fgetc(stdin)) != '\n')
    {
        if (ch == '1')
            div[i] = 1;
        else
            div[i] = 0;
        i++;
    }
    divlen = i; 
    for (i = datalen; i < datalen + divlen - 1; i++)
        data[i] = 0;
    datalen = datalen + divlen - 1;
    for (i = 0; i < divlen; i++)
        rem[i] = data[i];
    k = divlen - 1;
    while (k < datalen)
    {
        if (rem[0] == 1)
        {
            for (i = 0; i < divlen; i++)
                rem[i] = rem[i] ^ div[i];
        }
        else
        {
            if (k == datalen - 1)
            break;
            for (i = 0; i < divlen - 1; i++)
            {
                rem[i] = rem[i + 1];
                printf("%d", rem[i]); 
            }
            rem[i] = data[++k];
            printf("%d\n", rem[i]); 
        }
    }
    j = 1;
    for (i = datalen - divlen + 1; i < datalen; i++)
        data[i] = rem[j++];
    printf("\nThe data to be sent is\n");
    for (i = 0; i < datalen; i++)
        printf("%d", data[i]);
    return 0;
}
/*output:
CRC-12
Enter the data: 11010111

Enter the divisor: 1100000001111
0010111011110
0101110111100
1011101111000
1111011101110
0110111000010
1101110000100
0011100010110

The data to be sent is
11010111011100010110

CRC-16
Enter the data: 11010111

Enter the divisor: 11000000000000101
10101110000000000
01011100000000000
10111000000000000
01110000000000000
11100000000000000
11000000000000000
10000000000000000

The data to be sent is
110101110000000000000000
CRC-CCITT
Enter the data: 11010111

Enter the divisor: 10001000000100001
10101110000000000
01011100000000000
10111000000000000
01110000000000000
11100000000000000
11000000000000000
10000000000000000

The data to be sent is
110101110000000000000000

*/