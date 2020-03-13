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


    nTotal=nTotal-tree[0][1]+tree[0][0];

    a=tree[0][1];
    for(i=1;i<nM;i++)
    {
        if(a<tree[i][0])
        {
            nTotal=nTotal-tree[i][1]+tree[i][0]-1;
            a=tree[i][1];

        }
        else if(a<tree[i][1])
        {
            nTotal=nTotal-tree[i][1]+a;
            a=tree[i][1];

        }
    }
    printf("%d\n",nTotal);
    return 0;
}
