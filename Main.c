#include "header.h"

int main()
{
    char url[MAX_URL_LEN] = "http://www.runoob.com/http/http-intro.html";
    //char url[MAX_URL_LEN] = "https://www.runoob.com/http/http-intro.html";
    char host[MAX_URL_LEN] = {0};
    char path[MAX_URL_LEN] = {0};
    char file[MAX_FILE_NAME_LEN]  = "file";

    //parse url to get host and page path
    parseURL(url, host, path);
    //puts(host);
    //puts(path);
    //connect and sv the page into a file
    getPage(host, path, file);

}
