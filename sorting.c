#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define FSize 4 // Define the packet size as 4 bytes
typedef struct packet
{
    int SeqNum;
    char Data[FSize + 1]; // Data buffer with the size of FSize + 1 for null terminator
} packet;
struct packet *readdata, *transdata; // Declare pointers for storing packet data
int divide(char *msg)
{
    int msglen, NoOfPacket, i, j; // Declare variables for message length, number of packets, and loop counters
    msglen = strlen(msg); // Calculate the length of the message
    NoOfPacket = msglen / FSize; // Calculate the number of packets needed
    if ((msglen % FSize) != 0)
    NoOfPacket++; // Adjust number of packets if the message length is not divisible by packet size
    readdata = (struct packet *)malloc(sizeof(packet) * NoOfPacket);
    // Allocate memory to store the packets
    for (i = 0; i < NoOfPacket; i++)
    {
        // Loop through each packet
        readdata[i].SeqNum = i + 1; // Assign sequence number to the packet
        for (j = 0; (j < FSize) && (*msg != '\0'); j++, msg++) // Copy data from the message to the packet
            readdata[i].Data[j] = *msg;
        readdata[i].Data[j] = '\0'; // Add null terminator to the end of the data
    }
    printf("\nThe Message has been divided as follows\n");
    printf("\nPacket No. Data\n\n");
    for (i = 0; i < NoOfPacket; i++) // Print the divided packets
        printf(" %2d %s\n", readdata[i].SeqNum, readdata[i].Data);
    return NoOfPacket; // Return the number of packets
}

void shuffle(int NoOfPacket)
{
    int *Status; // Declare an array to keep track of packet status
    int i, trans; // Declare loop counters and a variable to store random index
    srand(time(0)); // Seed the random number generator
    Status = (int *)calloc(NoOfPacket, sizeof(int)); // Allocate memory for packet status array
    transdata = (struct packet *)malloc(sizeof(packet) * NoOfPacket); // Allocate memory for shuffled packets
    for (i = 0; i < NoOfPacket;)
    {
        // Loop until all packets are shuffled
        trans = rand() % NoOfPacket; // Generate a random index
        if (Status[trans] != 1)
        {
            // Check if the packet at the random index is not already selected
            transdata[i].SeqNum = readdata[trans].SeqNum; // Copy sequence number
            strcpy(transdata[i].Data, readdata[trans].Data); // Copy data
            i++; // Move to the next packet
            Status[trans] = 1; // Mark the packet as selected
        }
    }
    free(Status); // Free memory allocated for packet status array
}

void sortframes(int NoOfPacket)
{
    packet temp; // Declare a temporary packet for swapping
    int i, j; // Declare loop counters
    for (i = 0; i < NoOfPacket; i++) // Loop through each packet
        for (j = 0; j < NoOfPacket - i - 1; j++) // Loop through each pair of adjacent packets
            if (transdata[j].SeqNum > transdata[j + 1].SeqNum)
            {
                // Check if packets are out of order
                temp = transdata[j]; // Swap packets
                transdata[j] = transdata[j + 1];
                transdata[j + 1] = temp;
            }
}

void receive(int NoOfPacket)
{
    int i; // Declare loop counter
    printf("\nPackets received in the following order\n");
    for (i = 0; i < NoOfPacket; i++) // Print the sequence numbers of received packets
        printf("%4d", transdata[i].SeqNum);
    sortframes(NoOfPacket); // Sort the received packets
    printf("\n\nPackets in order after sorting..\n");
    for (i = 0; i < NoOfPacket; i++) // Print the sequence numbers of sorted packets
        printf("%4d", transdata[i].SeqNum);
    printf("\n\nMessage received is :\n");
    for (i = 0; i < NoOfPacket; i++) // Print the data of sorted packets
        printf("%s", transdata[i].Data);
}
int main()
{
    char msg[100]; // Declare an array to store the message
    int NoOfPacket; // Declare a variable to store the number of packets
    printf("\nEnter The message to be Transmitted :\n");
    scanf(" %[^\n]", msg); // Read the message from the user
    NoOfPacket = divide(msg); // Divide the message into packets
    shuffle(NoOfPacket); // Shuffle the packets
    receive(NoOfPacket); // Receive the shuffled packets
    free(readdata); // Free memory allocated for read data
    free(transdata); // Free memory allocated for trans data
    return 0; // Return 0 to indicate successful completion
}

/*output:

Enter The message to be Transmitted :Good Morning

The Message has been divided as follows

Packet No. Data

  1 Good
  2  Mor
  3 ning

Packets received in the following order
   3   2   1

Packets in order after sorting..
   1   2   3

Message received is :
Good Morning
*/
