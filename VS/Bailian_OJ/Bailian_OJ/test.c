#include <stdio.h>
#include <time.h>
#define MAX 100
clock_t start,stop;
double duration;
int main (){
    start=clock();
    int i;
    long long res=1;
    for(i=1;i<=MAX;i++){
        res=res*i;
    }
    
}