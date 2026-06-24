#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 200050, OFFSET = 10;
typedef int DATA;

int a[MAXN], b[MAXN], c[MAXN], cnt[MAXN];

int main()
{
    int n, m, p, M;
    scanf("%d%d%d", &n, &m, &p);
    M=m;
    for(int i=0; i<n; i++)
        scanf("%d", a+i);
    for(int i=0; i<m; i++)
        scanf("%d", b+i);
    sort(b, b+m);
    c[0]=1;
    int l=0;
    for(int i=1; i<m; i++){
        if(b[i]==b[l])c[l]++;
        else b[++l]=b[i], c[l]=1;
    }
    m=l+1;
    for(int i=0; i<n; i++)
    {
        int t=lower_bound(b, b+m, a[i])-b;
        if(t>=m || b[t]!=a[i])a[i]=-1;
        else a[i]=t;
    }
    /*
    for(int i=0; i<n; i++)
        printf("%3d", a[i]);
    puts("");
    for(int i=0; i<m; i++)
        printf("%3d", b[i]);
    puts("");
    for(int i=0; i<m; i++)
        printf("%3d", c[i]);
    puts("");
    */
    vector<int> ans;
    for(int i=0; i<p && i<n; i++){
        int l=i, r=i, s=0, tot=0;
        while(r<n && tot<M){
            if(~a[r]){
                cnt[a[r]]++;
                if(cnt[a[r]]==c[a[r]])s++;
            }
            tot++;
            r+=p;
        }
        while(tot==M){
            if(s==m)ans.push_back(l);
            if(r<n){
                if(~a[r]){
                    cnt[a[r]]++;
                    if(cnt[a[r]]==c[a[r]])s++;
                }
                tot++;
                r+=p;
            } else break;
            if(~a[l]){
                if((cnt[a[l]]--)==c[a[l]])s--;
            }
            tot--;
            l+=p;
        }
        while(l<n){
            if(~a[l])cnt[a[l]]--;
            l+=p;
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for(int i=0; i<ans.size(); i++)
        printf("%d ", ans[i]+1);
    puts("");
}