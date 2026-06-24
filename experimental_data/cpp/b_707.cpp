#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define INFLL 1000000000000000000
#define range(a, b, c) (a>=b && a<c)
#define mod(a) (a<0 ? -a : a)
#define stlfor(a, b) for(auto a=b.begin(); a!=b.end(); a++)
#define rstlfor(a, b) for(auto a=b.rbegin(); a!=b.rend(); a++)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

void readStrn(char a[], int n)
{
    for(register long i=0; i<n; i++)
        a[i]=getchar();
    getchar();
}

void readStr(char a[], int &n)
{
    n=0;
    for(register char c=getchar(); c>='0' && c<='9'; c=getchar())
        a[n++]=c;
}

long long readLI()
{
    register char c;
    for(c=getchar(); !(c>='0' && c<='9'); c=getchar());
    register long long a=c-'0';
    for(c=getchar(); c>='0' && c<='9'; c=getchar())
        a=(a<<3)+(a<<1)+c-'0';
    return a;
}

int main()
{
    int n = readLI();
    int m = readLI();
    int k = readLI();
    int ans = INF + INF;
    vector<bool> N(n, false);
    vector<pair<pair<int, int>, int>> M;
    for(int i=0; i<m; i++)
    {
        int a = readLI() - 1;
        int b = readLI() - 1;
        int l = readLI();
        M.pb(mp(mp(a, b), l));
    }
    for(int i=0; i<k; i++)
        N[readLI() - 1] = true;
    for(auto &it : M)
        if(N[it.ff.ff] != N[it.ff.ss])
            ans = min(ans, it.ss);
    if(ans == INF + INF)
        puts("-1");
    else
        cout << ans << endl;
    return 0;
}