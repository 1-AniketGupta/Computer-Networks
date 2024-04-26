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
int GoBackN(int frames){
    int ack,sent=0;
    while(1){
        while(1){
            printf("Frames %d has been transmitted\n",++sent);
            if(sent==frames)
                break;

        }
        printf("Enter the last acknowledgement received\n");
        scanf("%d",&ack);
        if(ack>=frames)
           {
               printf("All frames transmitted\n");
               break;
           }
        else
            sent=ack;

    }
    return 0;
}
int main()
{
    int frames;
    printf("Enter the no. of frames to be sent\n");
    scanf("%d",&frames);
    StopAndWait(frames);
    GoBackN(frames);
    return 0;
}
