#include <stdio.h>
int data[10];
int received[10];

// p1 = D3 D5 D7
// p2 = D3 D6 D7
// p4 = D5 D6 D7

// D7 D6 D5 P4 D3 P2 P1

void generateParity()
{
    data[1] = data[3] ^ data[5] ^ data[7];
    data[2] = data[3] ^ data[6] ^ data[7];
    data[4] = data[5] ^ data[6] ^ data[7];
}

void printData(int arr[8])
{
    for (int i = 7; i >= 1;i--)
        printf("%d", arr[i]);
}

void checkParity()
{
    int a = received[3] ^ received[5] ^ received[7] ^ received[1];
    int b = received[3] ^ received[6] ^ received[7] ^ received[2];
    int c = received[5] ^ received[6] ^ received[7] ^ received[4];
    // printf("%d %d %d \n", c, b, a);
    if(a == 0 && b == 0 && c == 0)
    {
        printf("No error detected\n");
        return;
    }
    else
    {
        int bit = (c << 2) | (b << 1) | a;
        printf("Error detected at bit %d\n", bit);
        printf("Correct data \n");
        received[bit] = received[bit] == 0 ? 1 : 0;
        printData(received);
    }
}

int main()
{
    printf("Sender side \n");
    printf("Enter 4 bit data: ");
    scanf("%d%d%d%d", &data[7], &data[6], &data[5], &data[3]);
    generateParity();
    // printf("%d %d %d\n", data[4], data[2], data[1]);
    printf("7 bit hamming code \n");
    printData(data);
    printf("\n\nReceiver side\n");
    printf("Enter received data: ");
    for (int i = 7; i >= 1;i--)
        scanf("%d", &received[i]);
    checkParity();
    return 0;
}
