#include <stdio.h>  
#include <sys/socket.h> 
#include <unistd.h> 
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define RCVBUFSIZE 256 
int tmp;
void DieWithError(char *errorMessage); 

void HandleTCPClient(int clntSocket)
{
  char echoBuffer[RCVBUFSIZE];  
  int recvMsgSize;  

  for (int i=0; i<50; i++) {
    echoBuffer[i] = '\0';
  }

  if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
    DieWithError("recv() failed");
  
  if (!strcmp(echoBuffer, "anagram")) {
    if (recvMsgSize % 2 == 0) {
      printf("received: %s\n", echoBuffer);
      
      for (int i=0; i < recvMsgSize/2; i++) {
        tmp = echoBuffer[i];
        echoBuffer[i] = echoBuffer[recvMsgSize-1-i]; 
        echoBuffer[recvMsgSize-1-i] = tmp;
      } 
    } else {
      printf("received: %s\n", echoBuffer);
      for (int i=0; i <= recvMsgSize/2; i++) {
        tmp = echoBuffer[i];
        echoBuffer[i] = echoBuffer[recvMsgSize-1-i]; 
        echoBuffer[recvMsgSize-1-i] = tmp;
      } 
    }
  } else if (!strcmp(echoBuffer, "age")) {
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, "25歳です。");  
  } else if (!strcmp(echoBuffer, "time")) {
    char s[256];
    time_t timer;
    struct tm *timeptr;

    timer = time(NULL);
    timeptr = localtime(&timer);
    strftime(s, 256, "%Y年%m月%d日%H時%M分", timeptr);
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, s);  
  } else if (!strcmp(echoBuffer, "萩原先生は")) {
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, "優しい");  
  } else if (!strcmp(echoBuffer, "好きな言語は")) {
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, "python");  
  } else if (!strcmp(echoBuffer, "今の時刻は")) {
    char s[256];
    time_t timer;
    struct tm *timeptr;

    timer = time(NULL);
    timeptr = localtime(&timer);
    strftime(s, 256, "%Y年%m月%d日%H時%M分", timeptr);
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, s);  
  } else if (!strcmp(echoBuffer, "住所は")) {
    for (int i=0; i<BUFSIZ; i++) {
      echoBuffer[i] = '\0';
    }
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, "新小岩");  
  } else if (!strcmp(echoBuffer, "c言語は")) {
    for (int i=0; i<BUFSIZ; i++) {
      echoBuffer[i] = '\0';
    }
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, "嫌い");  
  } else if (!strcmp(echoBuffer, "hello")) {
    printf("received: %s\n", echoBuffer);
    if (rand() % 2 == 0) {
      strcpy(echoBuffer, "world");  
    } else {
      strcpy(echoBuffer, "hello");  
    }
  } else if (!strcmp(echoBuffer, "squit")) {
    close(clntSocket);    
  } else {
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, "I don't know!");
    }

  while (recvMsgSize > 0) 
  {
    send(clntSocket, echoBuffer, 30, 0);
    for (int i=0; i<=256; i++) { 
      echoBuffer[i] = '\0'; 
    }
    if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
      DieWithError("recv() failed");

    if (!strcmp(echoBuffer, "anagram")) {
      if (recvMsgSize % 2 == 0) {
        printf("received: %s\n", echoBuffer);
        
        for (int i=0; i < recvMsgSize/2; i++) {
          tmp = echoBuffer[i];
          echoBuffer[i] = echoBuffer[recvMsgSize-1-i]; 
          echoBuffer[recvMsgSize-1-i] = tmp;
        } 
      } else {
        printf("received: %s\n", echoBuffer);
        for (int i=0; i <= recvMsgSize/2; i++) {
          tmp = echoBuffer[i];
          echoBuffer[i] = echoBuffer[recvMsgSize-1-i]; 
          echoBuffer[recvMsgSize-1-i] = tmp;
        } 
      }
    } else if (!strcmp(echoBuffer, "age")) {
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, "25歳です。");  
    } else if (!strcmp(echoBuffer, "time")) {
      char s[256];
      time_t timer;
      struct tm *timeptr;

      timer = time(NULL);
      timeptr = localtime(&timer);
      strftime(s, 256, "%Y年%m月%d日%H時%M分", timeptr);
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, s);  
    } else if (!strcmp(echoBuffer, "萩原先生は")) {
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, "優しい");  
    } else if (!strcmp(echoBuffer, "好きな言語は")) {
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, "python");  
    } else if (!strcmp(echoBuffer, "今の時刻は")) {
      char s[256];
      time_t timer;
      struct tm *timeptr;

      timer = time(NULL);
      timeptr = localtime(&timer);
      strftime(s, 256, "%Y年%m月%d日%H時%M分", timeptr);
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, s);  
    } else if (!strcmp(echoBuffer, "住所は")) {
      for (int i=0; i<BUFSIZ; i++) {
        echoBuffer[i] = '\0';
      }
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, "新小岩");  
    } else if (!strcmp(echoBuffer, "c言語は")) {
      for (int i=0; i<BUFSIZ; i++) {
        echoBuffer[i] = '\0';
      }
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, "嫌い");  
    } else if (!strcmp(echoBuffer, "hello")) {
      printf("received: %s\n", echoBuffer);
      if (rand() % 2 == 0) {
        strcpy(echoBuffer, "world");  
      } else {
        strcpy(echoBuffer, "hello");  
      }
    } else if (!strcmp(echoBuffer, "squit")) {
      close(clntSocket);    
    } else {
        printf("received: %s\n", echoBuffer);
        strcpy(echoBuffer, "I don't know!");
      }
  }

  close(clntSocket);  
}
