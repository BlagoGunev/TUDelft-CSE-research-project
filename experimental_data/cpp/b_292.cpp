#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define maxn 100005

using namespace std;
typedef int arr[maxn];

arr f;
int n,m;

bool bus()
{
    for (int i=1;i<=n;i++)
        if (f[i]>2) return false;
    int d=0;
    for (int i=1;i<=n;i++)
        if (f[i]==1) ++d;
    if (d!=2) return false;
    d=0;
    for (int i=1;i<=n;i++)
        if (f[i]==2) ++d;
    if (d!=n-2) return false;
    cout<<"bus topology";
    return true;
}

bool ring()
{
    int d=0;
    for (int i=1;i<=n;i++)
        if (f[i]==2) ++d;
    if (d!=n) return false;
    cout<<"ring topology";
    return true;
}

bool star()
{
    int d=0;
    for (int i=1;i<=n;i++)
        if (f[i]==1) ++d;
    if (d!=n-1) return false;
    for (int i=1;i<=n;i++)
        if (f[i]!=1 && f[i]!=n-1) return false;
    cout<<"star topology";
    return true;
}

void tinh()
{
    if (bus()) return;
    if (ring()) return;
    if (star()) return;
    cout<<"unknown topology";
}

int main()
{
    //freopen("inp.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        ++f[u];
        ++f[v];
    }
    tinh();
}