#include<bits/stdc++.h>

#define endl '\n'

#define forn(i, n) for (int i = 0; i < int(n); i++)

#define fi first

#define se second

#define pb push_back

#define vi vector<int>

#define vll vector<long long>

#define vec vector

#define sz(x) (int)(x).size()

#define rall(x) (x).rbegin(),(x).rend()

#define all(x) (x).begin(),(x).end()

#define pw(x) (1LL<<(x))

#define pii pair<int, int>

#define pll pair<long, long>

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

ll INF = 1e17 + 7;

int num = -1;

const ll mod = 998244353;

int pp = 998244351;

int n, k;

int val;

int glob;

//priority_queue<array<int, 2>> pq;

//ll bin_power(ll a, int p)

//{

//    if(p == 0 || a == 1)

//        return 1ll;

//    ll sup = a;

//    ll ans = 1ll;

//    while(p > 0){

//        if(p % 2 == 1){

//            ans *= sup;

//            ans %= mod;

//        }

//        p = p/2;

//        sup = sup * sup;

//        sup %= mod;

//    }

//    return ans;

//}





void dfs(vi& t, vec<vi>& v, vi& vis, int cur, vi& up, int deep, vi& d)

{

    vis[cur] = 1;

    d[cur] = deep;

    for(auto it : v[cur]){

        if(!vis[it]){

            up[it] = cur;

            dfs(t, v, vis, it, up, deep+1, d);

        }

    }

}



int func(vec<vi>& v, vi& vis, int cur, int deep, int mark)

{

    vis[cur] = mark;

    int ww = 0;

//    int qq = 0;

    if(deep >= val){

        vis[cur] = 1;

        return 1;

    }

    for(auto it : v[cur]){

        if(vis[it] != 1 && vis[it] != mark){

            ww += func(v, vis, it, deep+1, mark);

            if(ww > 0){

                vis[cur] = 1;

                return 1;

            }

        }

    }

    return ww;



}











int main(){

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    //freopen("clocktree.in", "r", stdin);

    //freopen("clocktree.out", "w", stdout);

    int tt;

    int mark;

    cin >> tt;

    int l;

    int ost;

    int qq;

    bool flag;

    int mid;

    bool fl;

    int a, b;

    int r;

    while(tt--){

        cin >> n;

        vi t(n+1);

        vi up(n+1);

        vi d(n+1);

        vi vv;

        vec<vi> v(n+1);

        forn(i, n-1)

        {

            cin >> a >> b;

            v[a].pb(b);

            v[b].pb(a);

        }

        cin >> k;

        forn(i, k)

        {

            cin >> a;

            t[a] = 1;

            vv.push_back(a);

        }



        vi vis(n + 1);

        vis[0] = 1;

        up[a] = 0;

        dfs(t, v, vis, a, up, 0, d);

        l = 0; r = n;

        while(l < r){

            mid = (l+r+1)/2;

            priority_queue<array<int, 3>> q;

            ost = mid%k;

            qq = mid/k;

            for(int i=0; i<ost; i++){

                q.push({d[vv[i]], 1+qq, vv[i]});

            }



            for(int i = ost; i<k; i++){

                q.push({d[vv[i]], qq, vv[i]});

            }



            for(int i=1; i<=n; i++){

                vis[i] = t[i];

            }

            vis[0] = 1;

                flag = true;

                mark = -1;

                while(!q.empty())

                {

                    auto it = q.top();

                    q.pop();

                    if(it[1] <= 0){

                        continue;

                    }

                    fl = false;

                    val = it[1];

//                    glob = 0;

                    for(auto w : v[it[2]]){

                        if(w == up[it[2]] || vis[w] == 1){

                            continue;

                        }

                        mark--;

                        a = func(v, vis, w, 1, mark);

                        if(a){

                            fl = true;

                            break;

                        }

                    }

                    if(fl){

                        continue;

                    }

                    if(vis[up[it[2]]] == 1){

                        flag = false;

                        break;

                    }

                    vis[up[it[2]]] = 1;

                    if(it[1] <= 1){

                        continue;

                    }

                    q.push({it[0]-1, it[1]-1, up[it[2]]});

                }



                if(flag){

                    l = mid;

                }

                else{

                    r = mid - 1;

                }



        }



        cout << l << endl;







    }



















    return 0;

}