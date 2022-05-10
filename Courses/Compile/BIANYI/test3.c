#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char ch;
    fp = fopen("E:/test2","r");
    if(fp==NULL){
        printf("Can't get the file.");
        return 1;
    }
    char parselist[10000] = {0};
    int parselistpos = 0;
    while(1){
        ch = getc(fp);
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
            else if(parselistpos!=0&&isalnum(parselist[parselistpos-1])==0&&isalnum(ch)!=0){
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
                else{
                    printf("Unknown\n");
                }
            }
            else if(parselistpos!=0&&isdigit(parselist[parselistpos-1])!=0&&isalnum(ch)==0){
                int i=0;
                for(i=0;i<parselistpos-1;i++){
                    if(isdigit(parselist[i])==0){
                        break;
                    }
                }
                if(i==parselistpos-1){
                    printf("Int(");
                    printf("%s",&parselist);
                    printf(")\n");
                    memset(parselist, 0, 10000);
                    parselistpos = 0;                
                }
                parselist[parselistpos] = ch;
                parselistpos++;
            }
            else if(parselistpos!=0&&isalnum(parselist[parselistpos-1])!=0&&isalnum(ch)==0){
                if(strcmp(parselist,"BEGIN")==0){
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
                else{
                    printf("Ident(");
                    printf("%s",&parselist);
                    printf(")\n");
                }
            }
            else if(strlen(parselist)!=0){
                printf("Unknown\n");
            }            
            memset(parselist, 0, 10000);
            parselistpos = 0;            
        }
        else if(parselistpos!=0&&isalnum(parselist[parselistpos-1])==0&&isalpha(ch)!=0){

        }
        else if(parselistpos!=0&&isalnum(parselist[parselistpos-1])==0&&isalnum(ch)!=0){
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
            else{
                printf("Unknown\n");
            }
            memset(parselist, 0, 10000);
            parselistpos = 0;
            parselist[parselistpos] = ch;
            parselistpos++;
        }
        else if(parselistpos!=0&&isdigit(parselist[parselistpos-1])!=0&&isalnum(ch)==0){
            int i=0;
            for(i=0;i<parselistpos-1;i++){
                if(isdigit(parselist[i])==0){
                    break;
                }
            }
            if(i==parselistpos-1){
                printf("Int(");
                printf("%s",&parselist);
                printf(")\n");
                memset(parselist, 0, 10000);
                parselistpos = 0;                
            }
            parselist[parselistpos] = ch;
            parselistpos++;
        }
        else if(parselistpos!=0&&isalnum(parselist[parselistpos-1])!=0&&isalnum(ch)==0){
            if(strcmp(parselist,"BEGIN")==0){
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
            else{
                printf("Ident(");
                printf("%s",&parselist);
                printf(")\n");
            }
            memset(parselist, 0, 10000);
            parselistpos = 0;
            parselist[parselistpos] = ch;
            parselistpos++;
        }
        else{
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