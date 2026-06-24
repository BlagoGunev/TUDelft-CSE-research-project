#include <bits/stdc++.h>
#include <cmath>

#define ll long long
using namespace std;
int t;
int all[4];
int main()
{
    scanf("%d",&t);
    getchar();
    for(int time=0;time<t;time++)
    {
        memset(all,0,sizeof(all));
        while(1)
        {
            char ch=getchar();
            if(ch!='L'&&ch!='R'&&ch!='U'&&ch!='D')break;
            if(ch=='L')all[0]++;
            if(ch=='R')all[1]++;
            if(ch=='U')all[2]++;
            if(ch=='D')all[3]++;
        }
        ll x=min(all[0],all[1]);
        ll y=min(all[2],all[3]);
        if(x==0&&y>0)y=1;
        if(y==0&&x>0)x=1;
        printf("%lld\n",2*x+2*y);
        for(int time1=0;time1<x;time1++)
        {
            printf("L");
        }
        for(int time1=0;time1<y;time1++)
        {
            printf("U");
        }
        for(int time1=0;time1<x;time1++)
        {
            printf("R");
        }
        for(int time1=0;time1<y;time1++)
        {
            printf("D");
        }
        printf("\n");
    }
    return 0;
}