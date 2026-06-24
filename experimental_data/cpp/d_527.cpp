#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
struct node {
    int l,r;
}a[200100];
bool cmd1(node a,node b)
{
    if (a.r==b.r) return a.l<b.l;
    return a.r<b.r;
}
int main()
{
    int i,n,x,w,ans1=0,ll;
    scanf("%d", &n);
    for (i=0;i<n;i++) {
        scanf("%d%d", &x, &w);
        a[i].l=x-w;a[i].r=x+w;
    }
    sort(a,a+n,cmd1);
    ll=-2100000000;
    for (i=0;i<n;i++)
    if (a[i].l>=ll) {
        ans1++;ll=a[i].r;
    }
    printf("%d\n", ans1);
    return 0;
}