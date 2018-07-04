#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

//
// Created by GuiHuan on 2018/7/3.
//

#ifndef LAB_HEADER_H
#define LAB_HEADER_H


/*爬虫参数*/
#define MAX_URL_LEN 1024
#define MAX_FILE_NAME_LEN 64
#define MAX_REQUEST_LEN 1024
#define BUFF_MAX_SIZE 512
#define PAGE_MAX_SIZE 4096*128

void parseURL(char * url,char* host,char* path);
void getPage(char* host,char* path,char* file);



/*BloomFilter参数*/



/*PageRank参数*/


#endif //LAB_HEADER_H
