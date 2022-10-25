#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <string.h>
#include <sys/stat.h>
#include <assert.h>

int main(int argc,char *argv[]){
    time_t x = time(NULL);
    struct tm * now;
    
    if(!strcmp(argv[0],"-u")){
        now = gmtime(&x);
        printf("%s\n",asctime(now));
    }

    else if(!strcmp(argv[0],"-I")){
        now = localtime(&x);
        printf("%d-%d-%d \n",now ->tm_year+1900, now ->tm_mon+1, now ->tm_mday);
    }

    else if(argv[0] == NULL){
        now = localtime(&x);
        printf("%s\n",asctime(now));
    }
    else{
        printf("%s Command not Found\n",argv[0]);
    }

}