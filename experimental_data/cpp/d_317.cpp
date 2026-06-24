#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[35] = {0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12 };
int n,now,total;
bool mark[32000];
main()
{
        scanf("%d",&n);
        now=1;
        total=1;
        for(int i=2;i*i<=n;i++)
        {
                if(mark[i]) continue;
                int nub=0;
                for(long long j=i;j<=n;j*=i)
                {
                        nub++;
                        if(j*j<=n)
                        {
                                mark[j]=1;
                        }
                }
                now^=a[nub];
                total+=nub;
                //printf("%d %d %d\n",i,nub,total);
                //system("pause");
        }
        total = n-total;
        if(total&1)
        {
                now^=1;
        }
        if(now==0)
        {
                printf("Petya\n");
        }
        else
        {
                printf("Vasya\n");
        }
        //system("pause");

}