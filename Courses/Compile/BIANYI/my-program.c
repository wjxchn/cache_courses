#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char *argv[]){
    FILE *fp = NULL;
    char ch;
    fp = fopen("E:/test","r");
    if(fp==NULL){
        printf("Can't get the file.");
        return 1;
    }
    ch = getc(fp);
    char parselist[10000] = {0};
    int parselistpos = 0;
    while(1){
        if(ch==' '||ch=='\n'||ch=='\r'||ch==EOF){
            if(strcmp(parselist,":")==0){
                printf("Colon\n");
            }
            else if(strcmp(parselist,"+")==0){
                printf("Plus\n");
            }     
            else if(strcmp(parselist,"*")==0){
                printf("Star\n");
            }
            else if(strcmp(parselist,",")==0){
                printf("Comma\n");
            }
            else if(strcmp(parselist,"(")==0){
                printf("LParenthesis\n");
            }
            else if(strcmp(parselist,")")==0){
                printf("RParenthesis\n");
            }
            else if(strcmp(parselist,":=")==0){
                printf("Assign\n");
            }
            else if(strcmp(parselist,"BEGIN")==0){
                printf("Begin\n");
            }
            else if(strcmp(parselist,"END")==0){
                printf("End\n");
            }
            else if(strcmp(parselist,"FOR")==0){
                printf("For\n");
            }
            else if(strcmp(parselist,"IF")==0){
                printf("If\n");
            }
            else if(strcmp(parselist,"THEN")==0){
                printf("Then\n");
            }
            else if(strcmp(parselist,"ELSE")==0){
                printf("Else\n");
            }
            else if(strlen(parselist)!=0){
                //printf("%d\n",strlen(parselist));
                int i=0;
                for(i=0;i<strlen(parselist);i++){
                    if(parselist[i]<'0'||parselist[i]>'9'){
                        break;
                    }
                }
                if(i==strlen(parselist)){
                    //printf(strcat(strcat("Int(",parselist),")\n"));
                    printf("Int(");
                    printf(parselist);
                    printf(")\n");
                }
                else{
                    if(i!=0){
                        int k = i;
                        for(;i<strlen(parselist);i++){
                            if(!isalpha(parselist[i])){
                                break;
                            }
                        }
                        if(i==strlen(parselist)){
                            //printf("Int()\n");
                            //printf("Ident()\n");
                            printf("Int(");
                            for(int j=0;j<k;j++){
                                printf("%c",parselist[j]);
                            }
                            printf(")\n");
                            printf("Ident(");
                            for(int j=k;j<strlen(parselist);j++){
                                printf("%c",parselist[j]);
                            }
                            printf(")\n");                            
                        }
                        else{
                            for(;i<strlen(parselist);i++){
                                if(!isalnum(parselist[i])){
                                    break;
                                }
                            }
                            if(i==strlen(parselist)){
                                //printf("Ident()\n");
                                printf("Ident(");
                                printf(parselist);
                                printf(")\n");
                            }
                            else{
                                printf("Unknown\n");
                                //break;
                            }
                        }                       
                    }
                    else{
                        for(;i<strlen(parselist);i++){
                            if(!isalnum(parselist[i])){
                                break;
                            }
                        }
                        if(i==strlen(parselist)){
                            //printf("Ident()\n");
                            printf("Ident(");
                            printf(parselist);
                            printf(")\n");                            
                        }
                        else{
                            printf("Unknown\n");
                            //break;
                        }
                    }
                }
            }
            memset(parselist, 0, 10000);
            parselistpos = 0;
            if(ch==EOF){
                break;
            }
        }
        else{
            parselist[parselistpos] = ch;
            parselistpos++;            
        }
        ch = getc(fp);
    }
    fclose(fp);
    return 0;
}