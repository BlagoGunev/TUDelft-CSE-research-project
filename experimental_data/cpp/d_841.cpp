#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define maxn 300030
#define maxm 2000030
using namespace std;
inline void read(int &x) {
    char ch;
    bool flag = false;
    for (ch = getchar(); !isdigit(ch); ch = getchar())if (ch == '-') flag = true;
    for (x = 0; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
    x = flag ? -x : x;
}
inline void write(int x) {
    static const int maxlen = 100;
    static char s[maxlen];
    if (x < 0) {   putchar('-'); x = -x;}
    if (!x) { putchar('0'); return; }
    int len = 0; for (; x; x /= 10) s[len++] = x % 10 + '0';
    for (int i = len - 1; i >= 0; --i) putchar(s[i]);
}

int n,m;
int st[maxm];
int pre[maxm],now[maxn],son[maxm],tot;
bool use[maxm];
bool vis[maxn];
int du[maxn];
int pre_p[maxn];
int aim[maxn];
bool vis2[maxn];

void build(int a,int b){
pre[++tot]=now[a];
now[a]=tot;
son[tot]=b;
st[tot]=a;
}

void change(int x){
du[ st[x] ]=1-du[ st[x] ];
du[ son[x] ]=1-du[ son[x] ];
}

bool op_1=0;

void dfs(int x){
vis[x]=1;
for (int p=now[x];p;p=pre[p])
    if ( !vis[ son[p] ] )
        {
            if (aim[son[p]]!=-1)
                dfs(son[p]);
            if ( aim[son[p]]!=-1)
            if ( (du[son[p]]%2 )!=aim[son[p]])
                {
                    change(p);
                    use[p/2]=1^use[p/2];
                }
        }
}


bool check(int x){
vis2[x]=1;
for (int p=now[x];p;p=pre[p])
    if ( !vis2[ son[p] ] )
        {
            if (aim[son[p]]!=-1)
                {
                    bool tmp=check(son[p]);
                    if (tmp)
                        {
                            change(p);
                            use[p/2]=1^use[p/2];
                            return  1;
                        }
                }
            else
                {
                    change(p);
                    use[p/2]=1^use[p/2];
                    return  1;
                }
        }
return 0;
}

int main(){
    read(n); read(m);
    for (int i=1;i<=n;i++)
        read(aim[i]);
    tot=1;
    for (int i=1;i<=m;i++)
        {
            int a,b;
            read(a); read(b);
            build(a,b);
            build(b,a);
            du[a]=1-du[a];    du[b]=1-du[b];
        }
    for (int i=1;i<=n;i++)
        if (!vis[i])
        if (aim[i]!=-1)
        {
            dfs(i);
            if ( ( du[i]%2 ) !=aim[i])
            {
                if ( !check(i) )
                {
                    puts("-1");
                    return 0;
                }
            }
        }
    int cnt=0;
    for (int i=2;i<=tot;i+=2)
        if (use[i/2]==0)
            cnt++;
    printf("%d\n",cnt);
    for (int i=2;i<=tot;i+=2)
        if (use[ i/2 ]==0)
        {
            int x=st[i];
            int y=son[i];
            printf("%d\n",i/2);
            //printf("%d %d\n",x,y);
        }
    return 0;
}