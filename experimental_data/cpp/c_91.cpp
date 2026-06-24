#include <algorithm>

#include <iostream>

#include <cstring>

#include <vector>

#include <cstdio>

#include <string>

#include <cmath>

#include <queue>

#include <set>

#include <map>

using namespace std;

typedef long long ll;

typedef double db;

typedef pair<int,int> pii;

typedef vector<int> vi;

#define de(x) cout << #x << "=" << x << endl

#define rep(i,a,b) for(int i=a;i<(b);++i)

#define all(x) (x).begin(),(x).end()

#define sz(x) (int)(x).size()

#define mp make_pair

#define pb push_back

#define fi first

#define se second

#define setIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)

const int N = 101010 , P = 1e9 + 9;

int fa[N] , n , m;

int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}

int M(int a,int b){if(a!=b)return fa[b]=a,1;else return 0;}



int main(){

    scanf("%d%d",&n,&m);

    rep(i,1,n+1) fa[i] = i;

    int ans = 1;

    rep(i,0,m){

        int u , v;

        scanf("%d%d",&u,&v);

        if(!M(F(u),F(v))) (ans+=ans)%=P;

        printf("%d\n",(ans-1+P)%P);

    }

    return 0;

}