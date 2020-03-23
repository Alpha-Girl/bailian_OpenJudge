#include <stdio.h>
#include <string.h>
#define MAX_LEN 120
void DelSpace(char *str){
    int i = 0,j = 0;
    for(;str[i] != '\0'; i++){
        if(str[i] == ' '){
            i++;
        }
        else{
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}
int main(){
    char str1[MAX_LEN], str2[MAX_LEN];
    gets(str1);
    gets(str2);
    DelSpace(str1);
    DelSpace(str2);
    if(strlen(str1) == 0 && strlen(str2) == 0)
        printf("YES\n");
    else if(stricmp(str1,str2))
        printf("YES\n");
    else
        printf("NO\n");
}
