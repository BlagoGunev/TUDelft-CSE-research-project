#include<iostream>
using namespace std;
bool v[11];
int main()
{
    int i,k,t,s;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&s);
        for(k=1;k<10;k++)
        v[k]=0;
        for(k=9;k>0;k--)
        {
            if(s>=k)
            {
                s=s-k;
                v[k]=1;
            }
        }
        for(k=1;k<10;k++)
        if(v[k]==1)printf("%d",k);
        printf("\n");
    }
    return 0;
}