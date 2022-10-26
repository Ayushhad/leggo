#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main(int argc,char *argv[]){
    
    chdir(argv[0]);
    DIR *dir = opendir(argv[0]);
    struct dirent *x;
    if(argv[1]==NULL){
        while((x=readdir(dir))!=NULL){
            char *y;
            strcpy(y,x->d_name);
            if(!strcmp(y,".") && !strcmp(y,"..")){
                printf("%s\t",y);
            }
        }
        printf("\n");
    }
    else if(!strcmp(argv[1],"-a")){
        while((x=readdir(dir))!=NULL){
            printf("%s\t",x->d_name);
        }
        printf("\n");
    }
    else if(!strcmp(argv[1],"-i")){
        while((x=readdir(dir))!=NULL){
            char *y;
            strcpy(y,x->d_name);
            if(!strcmp(y,".") && !strcmp(y,"..")){
                printf("%lld %s\t",x->d_ino,y);
            }
        }
        printf("\n");
    }
    else if(!strcmp(argv[1],"-l")){
        while((x=readdir(dir))!=NULL){
            char *y;
            strcpy(y,x->d_name);
            if(!strcmp(y,".") && !strcmp(y,"..")){
                printf("%s\n",y);
            }
        }
    }
    else{
        printf("Invalid command\n");
    }
}
