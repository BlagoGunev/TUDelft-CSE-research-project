#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

char s[200010],s2[200010];

int big(int l,int r)
{
    int mid=(l+r)>>1;
    for (int i=1;i<=r-mid;i++)
    {
        if (s[l+i-1]>s[mid+i]) return 1;
        if (s[l+i-1]<s[mid+i]) return 0;
    }
    return 0;
}

void solve(int l,int r)
{
    if ((r-l+1)%2!=0)  return;
    int mid=(l+r)>>1;
    solve(l,mid);solve(mid+1,r);
    if (big(l,r))
    {
        for (int i=1;i<=r-mid;i++) swap(s[l+i-1],s[mid+i]);
    }
}
    
int main()
{
    #ifdef waltz
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    scanf("%s",s+1);int n=strlen(s+1);
    solve(1,n);
    for (int i=1;i<=n;i++) s2[i]=s[i];
    scanf("%s",s+1);
    solve(1,n);
    bool ok=1;
    for (int i=1;i<=n;i++) if (s[i]!=s2[i]) {ok=0;break;}
    if (ok) printf("YES\n"); else printf("NO\n");
    return 0;
}