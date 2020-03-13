#include <stdio.h>
int main(){
    int i,max[1000],a[100000];
    int s[1000],d[1000],j,k=1,m=1;
    while(EOF!=scanf("%d %d",&s[m],&d[m])){
        max[m]=1;
        if(s[m]<=d[m]){
        for(j=s[m];j<=d[m];j++){
            a[1]=j;
            for(i=1;;i++){
                if(a[i]==1) break;
                if(a[i]%2==0)
                    a[i+1]=a[i]/2;
                else
                    a[i+1]=a[i]*3+1;
            }
            if(i>max[m])
            max[m]=i;
        }
        }
        else
        {
            for(j=d[m];j<=s[m];j++){
            a[1]=j;
            for(i=1;;i++){
                if(a[i]==1) break;
                if(a[i]%2==0)
                    a[i+1]=a[i]/2;
                else
                    a[i+1]=a[i]*3+1;
            }
            if(i>max[m])
            max[m]=i;
        }
        }
        printf("%d %d %d\n",s[m],d[m],max[m]);
        m++;
    }
    return 0;
}

