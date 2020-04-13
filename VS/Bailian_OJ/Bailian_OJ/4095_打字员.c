#include <stdio.h>
void func(char *str){
    int flag=0;
    int sum=0;
    int i;
    for(i=0;;i++){
        if(str[i]=='\0')
            break;
        if(str[i]<='Z'){
            if(flag==0){
                sum+=2;
                flag=1;
            }
            else
            {
                sum++;
            }
            
        }
        else
        {
            if(flag==1){
                sum+=2;
                flag=0;
            }
            else{
                sum++;
            }
        }
        
    }
    printf("%d\n",sum);
}
int main(){
    int n,i;
    char s[200];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",s);
        func(s);
    }
    return 0;
}