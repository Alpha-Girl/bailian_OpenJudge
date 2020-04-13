#include <stdio.h>
int main(){
    int i;
    double sum,t;
    sum=0;
    for(i=0;i<12;i++){
        scanf("%lf",&t);
        sum=t+sum;
    }
    sum=sum/12.0;
    printf("$%.2lf\n",sum);
}