#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mst(a,b) memset((a),(b),sizeof(a))
#define pi acos(-1)
#define pii pair<int,int>
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 1e5 + 10;
const int MAXM = 1e6 + 10;
const ll mod = 1e9 + 7;

int n;
char s1[MAXN],s2[MAXN];
int mat[30][30];
int num[30];
bool vis[30];

void dfs(int u,int pa) {
    vis[u] = true;
    for(int i=0; i<26; i++) {
        if(i == pa) continue;
        if(mat[u][i] != 1) continue;
        if(!vis[i]) {
            dfs(i,u);
        }
        else {
            mat[u][i] = 0;
            mat[i][u] = 0;
        }
    }
}

int main()
{
#ifdef local
    freopen("data.txt","r",stdin);
//    freopen("data.txt","w",stdout);
#endif
    mst(mat,-1);
    scanf("%d",&n);
    scanf("%s%s",s1,s2);
    for(int i=0; i<n; i++) {
        if(s1[i] != s2[i]) {
            mat[s1[i]-'a'][s2[i]-'a'] = 1;
            mat[s2[i]-'a'][s1[i]-'a'] = 1;
            num[s1[i]-'a'] = 1;
            num[s2[i]-'a'] = 1;
        }
    }
    for(int i=0; i<26; i++)
        if(!vis[i] && num[i])
            dfs(i,0);
    int ans = 0;
    for(int i=0; i<26; i++)
        for(int j=i+1; j<26; j++)
            if(mat[i][j] == 1) ans++;
    printf("%d\n",ans);
    for(int i=0; i<26; i++)
        for(int j=i+1; j<26; j++)
            if(mat[i][j] == 1)
                printf("%c %c\n",'a' + i,'a' + j);
    return 0;
}