#include <stdio.h>
#include <stdlib.h>
int main()
{
    int bucket_capacity, process_rate;
    int bucket = 0;
    int packets_arrived = 0;
    printf("Enter the bucket capacity: ");
    scanf("%d", &bucket_capacity);
    printf("Enter the processing rate: ");
    scanf("%d", &process_rate);
    while (1)
    {
        int input;
        printf("Enter the number of packets arriving (0 to quit): ");
        scanf("%d", &input);
        if (input == 0)
        {
            printf("Exiting program.\n");
            break;
        }
        packets_arrived = input;
        bucket += packets_arrived;
        if (bucket > bucket_capacity)
        {
            printf("Bucket overflow! Dropping packets: %d\n", bucket - bucket_capacity);
            bucket = bucket_capacity;
        }
        if (bucket > 0)
        {
            int packets_processed = (bucket < process_rate) ? bucket : process_rate;
            printf("Processing %d packets...\n", packets_processed);
            bucket -= packets_processed;
        }
        printf("Bucket status: %d/%d\n\n", bucket, bucket_capacity);
    }
    return 0;
}


/*Output:

Enter the bucket capacity: 10
Enter the processing rate: 2
Enter the number of packets arriving (0 to quit): 4
Processing 2 packets...
Bucket status: 2/10

Enter the number of packets arriving (0 to quit): 6
Processing 2 packets...
Bucket status: 6/10

Enter the number of packets arriving (0 to quit): 5
Bucket overflow! Dropping packets: 1
Processing 2 packets...
Bucket status: 8/10

Enter the number of packets arriving (0 to quit): 0
Exiting program.*/

