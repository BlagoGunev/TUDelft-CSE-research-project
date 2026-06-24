#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

int a[sz],d[sz],ans[sz],r[sz],l[sz];

int main()
{
    int n,i,j,k,f=1;
    cin >> n >> k;
    for(i=1; i<n; i++) r[i]=i+1;
    for(i=2; i<=n; i++) l[i]=i-1;
    for(i=1; i<=n; i++) scanf("%d", &a[i]), d[a[i]]=i;
    for(i=n; i; i--) {
        if(d[i]) {
            int now=d[i];
            ans[now]=f;
            for(j=0; j<k; j++) {
                if(r[now]) {
                    now=r[now];
                    ans[now]=f;
                    d[a[now]]=0;
                }
                else break;
            }
            int onr=r[now];

            now=d[i];
            for(j=0; j<k; j++) {
                if(l[now]) {
                    now=l[now];
                    ans[now]=f;
                    d[a[now]]=0;
                }
                else break;
            }
            int onl=l[now];

            r[onl]=onr;
            l[onr]=onl;
            if(f==1) f=2;
            else f=1;
            d[i]=0;
        }
    }

    for(i=1; i<=n; i++) printf("%d", ans[i]);
}