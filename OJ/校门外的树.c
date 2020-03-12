#include <stdio.h>
#include <stdlib.h>
#define MAX_M 100

int main()
{
    int nTotal,nCount=0;
    int tree[MAX_M][2];
    int nM;
    int i,j,tmp,a;
    scanf("%d",&nTotal);
    scanf("%d",&nM);
    for(i=0;i<nM;i++)
    {
        scanf("%d",&tree[i][0]);
        scanf("%d",&tree[i][1]);
    }
    for(i=0;i<nM;i++)
    {
        for(j=0;j<nM-i-1;j++)
        {
            if(tree[j][0]>tree[j+1][0])
            {
                tmp=tree[j][0];
                tree[j][0]=tree[j+1][0];
                tree[j+1][0]=tmp;
                tmp=tree[j][1];
                tree[j][1]=tree[j+1][1];
                tree[j+1][1]=tmp;
            }
        }
    }
    a=tree[0][0];
    for(i=0;i<nM;i++)
    {
        if(a<tree[i][1])
        {
            nTotal=nTotal-max(a,tree[i][0]);
        }    

    }
    printf("%d",nTotal);
}