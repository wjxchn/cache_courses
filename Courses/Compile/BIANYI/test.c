#include <stdio.h>
#include <memory.h>
int main(){
    FILE *fp = NULL;
    char ch;
    fp = fopen("inputfile","r");
    if(fp==NULL){
        printf("Can't get the file.");
        return 1;
    }
    ch = getc(fp);
    char parselist[10000] = {0};
    int parselistpos = 0;
    while(1){
        if(ch==' '||ch=='\n'||ch=='\r'||ch==EOF){
            parselist[parselistpos]='\n';
            if(parselist==":"){
                printf("Colon\n");
            }
            else if(parselist=="+"){
                printf("Plus\n");
            }     
            else if(parselist=="*"){
                printf("Star\n");
            }
            else if(parselist==","){
                printf("Comma\n");
            }
            else if(parselist=="("){
                printf("LParenthesis\n");
            }
            else if(parselist==")"){
                printf("RParenthesis\n");
            }
            else if(parselist==":="){
                printf("Assign\n");
            }
            else if(parselist=="BEGIN"){
                printf("Begin\n");
            }
            else if(parselist=="END"){
                printf("End\n");
            }
            else if(parselist=="FOR"){
                printf("For\n");
            }
            else if(parselist=="IF"){
                printf("If\n");
            }
            else if(parselist=="THEN"){
                printf("Then\n");
            }
            else if(parselist=="ELSE"){
                printf("Else\n");
            }
            else{

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