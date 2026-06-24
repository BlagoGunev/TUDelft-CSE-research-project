#include <bits/stdc++.h>
using namespace std;

#define loop(i,n) for(int i = 0;i < int(n);i++)
#define rloop(i,n) for(int i = int(n);i >= 0;i--)
#define range(i,a,b) for(int i = int(a);i <= int(b);i++)
#define INF	1e9
#define SZ(c) int(c.size())
#define ALL(c) c.begin(), c.end()
#define RALL(c) c.rbegin(), c.rend()
#define PI acos(-1)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

typedef vector<int> vi;
typedef vector<pair<int,int> > vii;
typedef long long ll;
typedef pair<int, int> pii;

const int N = 1e5 + 5;
map<vi , int > m;
map<int , vi > mv;
int idx = 0;
int v[N];
int n , k , x;

int main()
{

#ifndef ONLINE_JUDGE
	//freopen("in.in", "r", stdin);
	//freopen("out.in", "w", stdout);
	//ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#endif

    scanf("%d%d%d",&n,&k,&x);
    loop(i,n)
        scanf("%d",&v[i]);


    loop(i,k){
        sort(v , v+n);
        vi a(v , v+n);
        if(m.find(a) != m.end()){
            int s = m[a];
            int nw = s;
            while(i < k){
                while(nw < idx && i < k)
                    nw++ , i++;
                if(nw == idx)nw = s;
            }
            cout << mv[nw][n-1] << ' ' << mv[nw][0] << endl;
            return 0;
        }
        m[a] = idx++;
        mv[idx-1] = a;
        for(int i = 0 ; i < n ; i += 2)
            v[i] ^= x;
    }

    int mn , mx;
    mn = mx = v[0];
    loop(i,n){
        mn = min(mn , v[i]);
        mx = max(mx , v[i]);
    }

    cout << mx << ' ' << mn << endl;


    return 0;
}