#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

int main(int argc,char *argv[]){
    if(argv[0] == NULL){
        printf("Missing operand\n");
    }
    else if(!strcmp(argv[0],"-E")){
        if(argv[1] == NULL){
            printf("Missing File Name\n");
        }
        else{
            FILE *fp;
            fp = fopen(argv[1],"r");
            if(fp == NULL){
                printf("No %s File Found\n",argv[1]);
            }
            else{
                char str[1000];
                while(fgets(str,1000,fp)!=NULL){
                    for(int i=0;i<strlen(str)-1;i++){
                        printf("%c",str[i]);
                    }
                    printf("$\n");
                }
                fclose(fp);
            }
        }
    }
    else if(!strcmp(argv[0],"-n")){
        if(argv[1] == NULL){
            printf("Missing File Name\n");
        }
        else{
            FILE *fp;
            fp = fopen(argv[1],"r");
            if(fp == NULL){
                printf("No %s File Found\n",argv[1]);
            }
            else{
                int i =1;
                char str[1000];
                while(fgets(str,1000,fp)!=NULL){
                    printf("%d) ",i);
                    for(int j=0;j<strlen(str)-1;j++){
                        printf("%c",str[j]);
                    }
                    i++;
                }
                fclose(fp);
            }
        }
    }
    else{
        FILE *fp;
        fp = fopen(argv[1],"r");
        if(fp == NULL){
            printf("No %s File Found\n",argv[1]);
        }
        else{
            char c = fgetc(fp);
            while(c!= EOF){
                printf("%c",c);
                c = fgetc(fp);
            }
            printf("\n");
            fclose(fp);
        }
    }
}
