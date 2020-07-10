#include <stdio.h>  /* printf()��fprintf()��ɬ�� */
#include <sys/socket.h> /* recv()��send()��ɬ�� */
#include <unistd.h> /* close()��ɬ�� */
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define RCVBUFSIZE 256 /* �����Хåե��Υ����� */
int tmp;
void DieWithError(char *errorMessage);  /* ���顼�����ؿ� */

void HandleTCPClient(int clntSocket)
{
  char echoBuffer[RCVBUFSIZE];  /* ������ʸ����ΥХåե� */
  int recvMsgSize;  /* ������å������Υ����� */

  for (int i=0; i<BUFSIZ; i++) {
    echoBuffer[i] = '\0';
  }
  /* ���饤����Ȥ���μ�����å����� */
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
  }
  if (!strcmp(echoBuffer, "age")) {
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, "25歳です。");  
  }
  if (!strcmp(echoBuffer, "time")) {
    char s[256];
    time_t timer;
    struct tm *timeptr;

    timer = time(NULL);
    timeptr = localtime(&timer);
    strftime(s, 256, "%Y年%m月%d日%H時%M分", timeptr);
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, s);  
  }
  if (!strcmp(echoBuffer, "萩原先生は")) {
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, "優しい");  
  }
  if (!strcmp(echoBuffer, "好きな言語は")) {
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, "python");  
  }
  if (!strcmp(echoBuffer, "今の時刻は")) {
    char s[256];
    time_t timer;
    struct tm *timeptr;

    timer = time(NULL);
    timeptr = localtime(&timer);
    strftime(s, 256, "%Y年%m月%d日%H時%M分", timeptr);
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, s);  
  }
  if (!strcmp(echoBuffer, "住所は")) {
    for (int i=0; i<BUFSIZ; i++) {
      echoBuffer[i] = '\0';
    }
    printf("received: %s\n", echoBuffer);
    strcpy(echoBuffer, "新小岩");  
  }
  if (!strcmp(echoBuffer, "hello")) {
    printf("received: %s\n", echoBuffer);
    if (rand() % 2 == 0) {
      strcpy(echoBuffer, "world");  
    } else {
      strcpy(echoBuffer, "hello");  
    }
  }


  if (!strcmp(echoBuffer, "squit")) {
    close(clntSocket);    
  }

  /* ��������ʸ�������������ž������λ���Ƥ��ʤ���м���������� */
  while (recvMsgSize > 0) /* ������ž���ν�λ���̣���� */
  {
    /* ��å������򥯥饤����Ȥ˥������Хå����� */
    send(clntSocket, echoBuffer, 30, 0);
    for (int i=0; i<=256; i++) { 
      echoBuffer[i] = '\0'; 
    }
    /* ��������ǡ������ĤäƤ��ʤ�����ǧ���� */
    if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0)) < 0)
      DieWithError("recv() failed");

    if (!strcmp(echoBuffer, "anagram")) { 
      if (recvMsgSize % 2 == 0) { 
        printf("received: %s\n", echoBuffer); 
        for (int i=0; i < recvMsgSize/2; i++) { 
          tmp = echoBuffer[i]; echoBuffer[i] = echoBuffer[recvMsgSize-1-i]; 
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
    }
    if (!strcmp(echoBuffer, "age")) {
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, "25歳です。");  
    }
    if (!strcmp(echoBuffer, "time")) {
      char s[256];
      time_t timer;
      struct tm *timeptr;

      timer = time(NULL);
      timeptr = localtime(&timer);
      strftime(s, 256, "%Y年%m月%d日%H時%M分", timeptr);
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, s);  
    }
    if (!strcmp(echoBuffer, "萩原先生は")) {
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, "優しい");  
    }
    if (!strcmp(echoBuffer, "好きな言語")) {
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, "python,Go");  
    }
    if (!strcmp(echoBuffer, "今の時刻は")) {
      char s[256];
      time_t timer;
      struct tm *timeptr;

      timer = time(NULL);
      timeptr = localtime(&timer);
      strftime(s, 256, "%Y年%m月%d日%H時%M分", timeptr);
      printf("received: %s\n", echoBuffer);
      strcpy(echoBuffer, s);  
    }
    if (!strcmp(echoBuffer, "住所は")) {
      printf("received: %s\n", echoBuffer);
      char s[256] = "しんこいわ";
      strcpy(echoBuffer, s);  
    }

    if (!strcmp(echoBuffer, "hello")) {
      printf("received: %s\n", echoBuffer);
      if (rand() % 2 == 0) {
        strcpy(echoBuffer, "world");  
      } else {
        strcpy(echoBuffer, "hello");  
      }
    }

    if (!strcmp(echoBuffer, "squit")) {
      close(clntSocket);    
    }
  }

  close(clntSocket);  /* ���饤����ȥ����åȤ򥯥��������� */
}
