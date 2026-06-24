#include<iostream>

#include<cstdio>

#include<cstdlib>

#include<cstring>

#include<cmath>

#include<algorithm>

#define maxn 100010

#define each(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

using namespace std;

typedef long long LL;

int n,m;

char str[maxn];

int work()

{

    m=min(m,n-m+1);

    int ans=0,l,r;

    for(l=1;l<=n&&str[l]==str[n-l+1];++l);

    if(l>n)

        return 0;

    for(r=n/2;str[r]==str[n-r+1];--r);

    ans=min(abs(l-m),abs(r-m))+r-l;

    for(int i=m;i<=n;++i)

        if(str[i]!=str[n-i+1])

        {

            ans+=min(abs(str[i]-str[n-i+1]),26-abs(str[i]-str[n-i+1]));

            str[i]=str[n-i+1];

        }

    return ans;

}

int main()

{

    scanf("%d %d %s",&n,&m,str+1);

    printf("%d\n",work());

    return 0;

}