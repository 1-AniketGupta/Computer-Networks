#include <stdio.h>
//#include <unistd.h>

// Print Window
void pw(int w[], int ws){
  printf("Window Contains : ");
  for(int i=0;i<ws;i++)
    printf("%d ",w[i]);
  printf("\n");
}

int main(){
  int tf; // Total Frames
  printf("Enter total frames to send : ");
  scanf("%d", &tf);

  int ws; // Window Size
  printf("Enter the window size : ");
  scanf("%d", &ws);

  int w[ws]; // Window
  int n=1;
  for(int i=0;i<ws;i++){
    printf("Sending frame %d\n",n);
    w[i]=n;
    n++;
  }
  pw(w,ws);

  while(n-ws<=tf){
    int r;
    printf("Enter acknowledgment for frame %d (ACK:1, NACK:0) : ",w[0]);
    scanf("%d", &r);
    if(r==1){
      printf("\n");
      for(int i=0;i<ws-1;i++)
        w[i]=w[i+1];
      if(n<=tf){
        printf("Sending frame %d\n",n);
        w[ws-1]=n;
        n++;
      }
      else{
        w[ws-1]=0;
        n++;
      }
      pw(w,ws);
    }
    else{
      printf("\nWaiting for %d seconds\n", 1);
      sleep(1);
      for(int i=0;i<ws;i++) printf("Sending frame %d\n",w[i]);
      pw(w,ws);
    }
  }
  return 0;
}
