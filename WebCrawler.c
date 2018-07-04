#include "header.h"


//
// Created by GuiHuan on 2018/7/3.
//


void parseURL(char* url, char* host, char* path)
{
    //char tmp[MAX_URL_LEN] = {0};
    char* ptmp = NULL;
    strcpy(host, url);
    if((ptmp = strstr(url, "http://")) != NULL)//https format
    {
        ptmp = ptmp + 7;
        strcpy(host, ptmp);
    } else if(ptmp = NULL, (ptmp = strstr(url, "https://")) != NULL)//http format
    {
        ptmp = ptmp + 8;
        strcpy(host, ptmp);
    }
    ptmp = NULL;
    if((ptmp = strpbrk(host, "/")) != NULL)
    {
        strcpy(path, ptmp);
        ptmp[0] = '\0';
    }

}



void getPage(char* host, char* path, char* file)
{
    struct hostent *phost;
    if(0 == (phost = gethostbyname(host)))
    {
        printf("host err\n");
        exit(1);
    }

    struct sockaddr_in pin;
    int port = 80;
    bzero(&pin, sizeof(pin));
    pin.sin_family = AF_INET;
    pin.sin_port = htons(port);
    pin.sin_addr.s_addr = ((struct in_addr*)(phost->h_addr)) -> s_addr;

    int isock;
    if((isock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("socket err\n");
        exit(1);
    }


    char requestHeader[MAX_REUQEST_LEN] = "GET ";
    strcat(requestHeader, path);
    strcat(requestHeader," HTTP/1.0\r\nHost: ");
    strcat(requestHeader, host);
    strcat(requestHeader, "\r\nAccept: */*\r\n");
    strcat(requestHeader, "User-Agent: Mozilla/4.0(compatible)\r\n");
    strcat(requestHeader, "Connection: Keep-Alive\r\n");
    strcat(requestHeader, "\r\n");

    if(connect(isock, (struct sockaddr*) &pin, sizeof(pin)) == -1)
    {
        printf("connect err\n");
        exit(1);
    }

    if(send(isock, requestHeader,strlen(requestHeader), 0) == -1)
    {
        printf("send err\n");
        exit(1);
    }

    //struct timeval timeout={1,0};
    //setsockopt(isock,SOL_SOCKET,SO_RCVTIMEO,(char *)&timeout,sizeof(struct timeval));
    char buffer[BUFF_MAX_SIZE];
    char page[PAGE_MAX_SIZE];
    int len;


    printf("Start fetch\n");
    int fd = open("file", O_RDWR|O_CREAT, 0666);
    int flag = 0;
    char tmpch;


    //while(recv(isock,&tmpch,sizeof(char))>0)
    //{
    //    if(tmpch == '\r')
    //    {
    //       如何读到一个http请求头的末尾？
    //        http://www.runoob.com/http/http-messages.html
    //    }
    //}
    while((len = recv(isock, buffer, BUFF_MAX_SIZE - 1, 0)) > 0)
    {
        buffer[len]='\0';

        write(fd, buffer, strlen(buffer) + 1);

    }


    close(isock);
    close(fd);
}


