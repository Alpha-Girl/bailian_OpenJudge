#include <stdio.h>
#include <string.h>
#define MAX_LEN 100010
int main(){
    char str1[MAX_LEN], str2[MAX_LEN], c;
    int i = 0, j = 0, len1, len2;
    while(1){
        c = getchar();
        if(c != ' '){
            str1[i] = c;
            i++;
        }
        else
            break;
    }
    str1[i] = '\0';
    i = 0;
    while(1){
        c = getchar();
        if(c != ' ' && c != '\n'){
            str2[i] = c;
            i++;
        }
        else
            break;
    }
    str2[i] = '\0';
    i = 0;
    len1 = strlen(str1);
    len2 = strlen(str2);
    for( ; j < len2; j++){
        if(str1[i] == str2[j])
            i++;
        if(i == len1)
            break;
    }
    if(i == len1)
        printf("Yes\n");
    else
        printf("No\n");
}
