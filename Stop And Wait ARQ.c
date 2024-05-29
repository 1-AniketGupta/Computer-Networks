#include <stdio.h>
#include <stdlib.h>

int StopAndWait(int frames)
{
    int framesToSend=1,ack;
    while(framesToSend<=frames){
        printf("Sending frame %d\n",framesToSend);
        printf("Enter acknowledgement for frame %d\n ('1' if received)",framesToSend);
        scanf("%d",&ack);
        if(ack){
            printf("Receiver Received frame %d\n",framesToSend);
            framesToSend++;
        }
    }
    return 0;

}

int main()
{
    int frames;
    printf("Enter the no. of frames to be sent\n");
    scanf("%d",&frames);
    StopAndWait(frames);
    
    return 0;
}
