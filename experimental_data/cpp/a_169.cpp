#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a,b,data[2010];
bool cmp(const int &a,const int &b)
{   
    return a>b;
}
int main()
{   

    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++)
        scanf("%d",&data[i]);
    sort(data+1,data+n+1,cmp);
    printf("%d\n",data[a]-data[a+1]);
    return 0;
}