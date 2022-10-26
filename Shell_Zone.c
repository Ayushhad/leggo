#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
char *dir;

void* call_ls(void *a){
    system(strcat(dir,"/ls"));
    pthread_exit(NULL);
}

void* call_rm(void *a){
    system(strcat(dir,"/rm"));
    pthread_exit(NULL);
}

void* call_mkdir(void *a){
    system(strcat(dir,"/mkdir"));
    pthread_exit(NULL);
}

void* call_date(void *a){
    system(strcat(dir,"/date"));
    pthread_exit(NULL);
}

void* call_cat(void *a){
    system(strcat(dir,"/cat"));
    pthread_exit(NULL);
}

int main(){
    printf("Shell Zone\n");
    dir = (char *) malloc(500);
    getcwd(dir,sizeof(dir));
    printf("%s $ ",dir);  
    while (1)
    {
        char inst[500];

        fgets(inst,500,stdin);
        inst[strlen(inst)-1] ='\0';

        char *cmnd = strtok(inst," ");
        char *ex = strtok(NULL," ");
        //INTERNAL COMMANDS//
        if(!strcmp(cmnd,"cd")){
            printf(ex);
            if(ex == NULL || !strcmp(ex,"~"))  chdir(getenv("HOME"));
            else if(!strcmp(ex,"..")){
                printf("dflkj");
                chdir("..");
            }
            else printf("%s Command not Found\n",ex);
        }

        else if(!strcmp(cmnd,"pwd")){
            if(ex == NULL || !strcmp(ex,"-P"))  printf("%s\n",dir);
            else if(!strcmp(ex,"-L")){
                //NEED TO PRINT ACTUAL PATH
            }
            else printf("%s Command not Found\n",ex);

        }

        else if(!strcmp(cmnd,"echo")){
            if(!strcmp(ex,"-n")){
                strcat(cmnd," ");
                char * part = strtok(NULL," ");
                char * data =(char *)malloc(500);
                while(part){
                    strcat(data,part); strcat(data," ");
                    part = strtok(NULL," ");
                }
                printf("%s",data);
            }
            else if(!strcmp(ex,"--help")){
                FILE *hlp = fopen(strcat(dir,"/echo_help"),"r");
                char c =  fgetc(hlp);
                while(c!= EOF){
                    printf("%c",c);
                    c = fgetc(hlp);
                }
                printf("\n");
                fclose(hlp);
            }
            else if(ex == NULL)  printf("No Command Entered\n");
            else printf("%s Command not Found\n",ex);
        }

        //EXTERNAL COMMANDS//

        else{
            if(inst[strlen(inst)-3]=='&'&& inst[strlen(inst)-2] =='t'){
                if(!strcmp(cmnd,"ls")){
                    pthread_t ptid;
                    pthread_create(&ptid, NULL, &call_ls, ex);
                    pthread_join(ptid,NULL);
                }
                else if(!strcmp(cmnd,"rm")){
                    pthread_t ptid;
                    pthread_create(&ptid, NULL, &call_rm, ex);
                    pthread_join(ptid,NULL);
                }
                else if(!strcmp(cmnd,"cat")){
                    pthread_t ptid;
                    pthread_create(&ptid, NULL, &call_cat, ex);
                    pthread_join(ptid,NULL);
                }
                else if(!strcmp(cmnd,"mkdir")){
                    pthread_t ptid;
                    pthread_create(&ptid, NULL, &call_mkdir, ex);
                    pthread_join(ptid,NULL);
                }
                else if(!strcmp(cmnd,"date")){
                    pthread_t ptid;
                    pthread_create(&ptid, NULL, &call_date, ex);
                    pthread_join(ptid,NULL);
                }
            }
            else{
                int pid;
                pid = fork();  
                if(pid<0) printf("Fork Failed\n");
                else if(!pid){ 
                    if(!strcmp(cmnd,"date")){
                        char *arg[] = {ex,NULL};
                        char * ad = strcat(dir,"/date") ;
                        execv(ad,arg);
                    }
                    else if(!strcmp(cmnd,"ls")){
                        char *newcom[] = {dir,ex};
                        char * ad = strcat(dir,"/ls");
                        execv(ad,newcom);
                    }
                    else if(!strcmp(cmnd,"rm")){
                        char *arg[] = {ex,NULL};
                        char * ad = strcat(dir,"/rm");
                        execv(ad,arg);
                    }
                    else if(!strcmp(cmnd,"mkdir")){
                        char *arg[] = {ex,NULL};
                        char * ad =strcat(dir,"/mkdir"); 
                        execv(ad,arg);
                    }
                    else if(!strcmp(cmnd,"cat")){
                        char *arg[] = {ex,NULL};
                        char * ad = strcat(dir,"/cat"); 
                        execv(ad,arg);
                    }
                }
                else{
                    wait(NULL);
                }
            } 
        }   
    }   
}
