#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>


int main(int argc,char *argv[]){
    if(argv[0] == NULL){
        printf("Missing operand\n");
    }
    else{
        if(!strcmp(argv[0],"-d")){
            int i = 1;
            if(argv[1] == NULL){
                printf("rm: missing operand\n");
            }
            while(argv[i]!=NULL){
                int x = remove(argv[i]);
                if(x){
                    printf("Directory not found\n");
                }
                i+=2;
            }
        }
        else if(!strcmp(argv[0],"-f")){
            int i = 1;
            if(argv[1] == NULL){
                printf("rm: missing operand\n");
            }
            while(argv[i]!=NULL){
                int x = remove(argv[i]);
                if(x){
                    printf("File not found\n");
                }
                i+=2;
            }
        }
        else{
            int i = 1;
            if(argv[1] == NULL){
                printf("rm: missing operand\n");
            }
            while(argv[i]!=NULL){
                int x = remove(argv[i]);
                if(x){
                    printf("File not found\n");
                }
                i+=2;
            }
        }
        
    }
}