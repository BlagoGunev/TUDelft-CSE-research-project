#include <bits/stdc++.h>
#define LL long long
#define Pr pair<int,int>
#define VI vector<int>
#define fread() freopen("in.in","r",stdin)
#define fwrite() freopen("out.out","w",stdout)

using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;
const double eps = 1e-8;

Pr pr[200200];
int num[200200];
int cnt[200200];
int tp,n;

int Search(int x)
{
    int l = 0;
    int r = tp;
    while(l <= r)
    {
        int mid = (l+r)>>1;
        if(num[mid] == x) return cnt[mid];
        else if(num[mid] > x) r = mid-1;
        else l = mid+1;
    }
    return 0;
}

int main()
{
    //fread();
    //fwrite();

    int m;
    int id,a,b,aa,bb;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i)
        scanf("%d",&num[i]);

    sort(num,num+n);

    tp = 0;
    cnt[0] = 1;
    for(int i = 1; i < n; ++i)
        if(num[i] == num[tp]) cnt[tp]++;
        else
        {
            num[++tp] = num[i];
            cnt[tp] = 1;
        }


    id = -1;
    scanf("%d",&m);

    for(int i = 1; i <= m; ++i) scanf("%d",&pr[i].first);
    for(int i = 1; i <= m; ++i) scanf("%d",&pr[i].second);

    for(int i = 1; i <= m; ++i)
    {
        aa = Search(pr[i].first);
        bb = Search(pr[i].second);
        //printf("%d %d %d %d\n",pr[i].first,pr[i].second,aa,bb);
        if(id == -1 || aa > a || (aa == a && bb > b))
        {
            a = aa;
            b = bb;
            id = i;
        }
    }
    printf("%d\n",id);
    return 0;
}