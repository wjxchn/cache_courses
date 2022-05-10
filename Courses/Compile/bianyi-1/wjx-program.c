#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    FILE *fp = NULL;
    char ch;
    fp = fopen(argv[1],"r");
    if(fp==NULL){
        printf("Can't get the file.");
        return 1;
    }
    char parselist[10000] = {0};
    int parselistpos = 0;
    while(1){
        ch = getc(fp);
        if(strcmp(parselist,":")==0&&ch!='='){
            printf("Colon\n");
            memset(parselist, 0, 10000);
            parselistpos = 0;
        }
        else if(strcmp(parselist,"+")==0){
            printf("Plus\n");
            memset(parselist, 0, 10000);
            parselistpos = 0;
        }     
        else if(strcmp(parselist,"*")==0){
            printf("Star\n");
            memset(parselist, 0, 10000);
            parselistpos = 0;
        }
        else if(strcmp(parselist,",")==0){
            printf("Comma\n");
            memset(parselist, 0, 10000);
            parselistpos = 0;
        }
        else if(strcmp(parselist,"(")==0){
            printf("LParenthesis\n");
            memset(parselist, 0, 10000);
            parselistpos = 0;
        }
        else if(strcmp(parselist,")")==0){
            printf("RParenthesis\n");
            memset(parselist, 0, 10000);
            parselistpos = 0;
        }
        else if(strcmp(parselist,":=")==0){
            printf("Assign\n");
            memset(parselist, 0, 10000);
            parselistpos = 0;
        }
        else{
            int i=0;
            for(i=0;i<parselistpos;i++){
                if(isdigit(parselist[i])==0){
                    break;
                }
            }
            if(parselistpos!=0&&i==parselistpos&&isdigit(ch)==0){
                printf("Int(");
                printf("%d",atoi(parselist));
                printf(")\n");
                memset(parselist, 0, 10000);
                parselistpos = 0;                
            }
            else if(ch==' '||ch=='\n'||ch=='\r'||ch==EOF||ch=='('||ch==')'||ch=='+'||ch=='*'||ch==':'||ch==','){
                if(strcmp(parselist,"BEGIN")==0){
                    printf("Begin\n");
                    memset(parselist, 0, 10000);
                    parselistpos = 0;
                }
                else if(strcmp(parselist,"END")==0){
                    printf("End\n");
                    memset(parselist, 0, 10000);
                    parselistpos = 0;
                }
                else if(strcmp(parselist,"FOR")==0){
                    printf("For\n");
                    memset(parselist, 0, 10000);
                    parselistpos = 0;
                }
                else if(strcmp(parselist,"IF")==0){
                    printf("If\n");
                    memset(parselist, 0, 10000);
                    parselistpos = 0;
                }
                else if(strcmp(parselist,"THEN")==0){
                    printf("Then\n");
                    memset(parselist, 0, 10000);
                    parselistpos = 0;
                }
                else if(strcmp(parselist,"ELSE")==0){
                    printf("Else\n");
                    memset(parselist, 0, 10000);
                    parselistpos = 0;
                }
                else{
                    for(i=0;i<parselistpos;i++){
                        if(isalnum(parselist[i])==0){
                            break;
                        }
                    }
                    if(parselistpos!=0&&i==parselistpos&&isalnum(ch)==0){
                        printf("Ident(");
                        printf("%s",parselist);
                        printf(")\n");
                        memset(parselist, 0, 10000);
                        parselistpos = 0;                 
                    }
                    else if(parselistpos!=0){
                        printf("Unknown\n");
                        break;
                    }
                }
            }
        }
        if(ch!=' '&&ch!='\n'&&ch!='\r'&&ch!=EOF){
            parselist[parselistpos] = ch;
            parselistpos++; 
        }       
        if(ch==EOF){
            break;
        }
    }
    fclose(fp);
    return 0;
}