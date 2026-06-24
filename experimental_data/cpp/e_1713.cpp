#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using db = double;

#define endl '\n'

#define str string

#define PII pair<ll, ll>

#define fir first

#define sec second

#define priq priority_queue

#define SPO(n) fixed << setprecision(n)

#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))

#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))

#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'

const int N=1010;

int f[N][N];

struct DSU{

    vector<int> f,siz;

    DSU(int n) : f(n+1){

        iota(f.begin(),f.end(),0);

    }

    bool check(int x,int y){

        return find(x) == find(y);

    }

    int find(int x){

        while(x!=f[x]) x=f[x]=f[f[x]];

        return x;

    }

    bool merge(int x,int y){

        x=find(x); y=find(y);

        if(x == y) return false;

        f[y]=x;

        return true;

    }

};

void Solve(){

    int n;

    cin>>n;

    DSU dsu(n*2);

    rep(i,1,n){

        rep(j,1,n)

            cin>>f[i][j];

    }

    rep(i,1,n){

        rep(j,i+1,n){

            if(f[i][j]>f[j][i]){

                if(dsu.check(i,j)||dsu.check(i+n,j+n)) continue;

                dsu.merge(i,j+n);

                dsu.merge(i+n,j);

                swap(f[i][j],f[j][i]);

            }else if(f[i][j]<f[j][i]){

                if(dsu.check(i,j+n)||dsu.check(i+n,j)){

                    swap(f[i][j],f[j][i]);

                    continue;

                }

                dsu.merge(i,j);

                dsu.merge(i+n,j+n);

            }

        }

    }

    rep(i,1,n){

        rep(j,1,n) 

            cout<<f[i][j]<<' ';

        cout<<endl;

    }

    return;

}

int main(){

    std::ios::sync_with_stdio(false);

    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin>>t;

    while(t--)

    Solve();

    return 0;

}