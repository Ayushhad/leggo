#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include <pthread.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc,char *argv[]){
    if(argv[0]==NULL){
        printf("No directory name provided\n");
    }
    else{
        if(!strcmp(argv[0],"-v")){
            if(argv[1] == NULL){
                printf("No directory name provided\n");
            }
            else{
                int i =1;
                while(argv[i]!=NULL){
                    int x = mkdir(argv[1],0777);
                    if(x == -1){
                        printf("mkdir : Cannot create directory\n");
                        if(errno == 17){
                            printf("Directory %s already exists\n",argv[1]);
                        }
                    }
                    else{
                        printf("mkdir: %s Directory created\n",argv[1]);
                    }
                    i+=2;
                }
            }
        }
        else if(!strcmp(argv[0],"-P")){
            char *x;
            getcwd(x,500);
            strcat(x,"/");
            strcat(x,argv[1]);
            printf("%s\n",x);
            remakee(x);
        }
        else{
            int i =1;
            while(argv[i]!=NULL){
                int x = mkdir(argv[1],0777);
                if(x == -1){
                    if(errno == 17){
                        printf("Directory %s already exists\n",argv[1]);
                    }
                }
                i+=2;
            }
        }
    }
}
