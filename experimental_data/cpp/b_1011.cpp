/*
              *******
When winter comes,You'll hear no lions roar,
no stags grazing the fields,
no roses growing in the meadows,
no snakes in the sand.
The krakens will freeze where they swim.
The flayed men will rot and wither.
No trouts swimming in the river and no falcons flying in the air.
Not even the dragons breath will warm you in your halls.
Only the wolfs howl in the night.
            WINTER IS COMING
*/
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define s(x) scanf("%lld",&x)
#define p(x) printf("%lld\n",x)
#define sc(x) scanf("%s",x)
#define pc(x) printf("%s",x)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define inf 1e18
#define prec(x) fixed<<setprecision(15)<<x
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define mem(x,y) memset(x,y,sizeof(x))
#define PQG priority_queue< int,std::vector<int>,std::greater<int> >
#define PQL priority_queue< int,std::vector<int>,std::less<int> >
#define PQPL priority_queue<pii ,vector< pii >, less< pii > >
#define PQPG priority_queue<pii ,vector< pii >, greater< pii > >
#define PQPGB priority_queue<pii ,vector< pll >, greater< pll > >
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;


int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);      
    #endif
    fast_io;
    int n,m; cin>>n>>m; 
    int a[m]; 
    int cnt[105]; mem(cnt,0);
    for(int i = 0;i<m;i++) {
        cin>>a[i];
        cnt[a[i]]++;
    } 
    int ate[105] = {}; 
    int ans = 1e9+55;
    for(int j = 1;j<=n;j++){
        int temp = 0; int max_so_far = -1;
        for(int i = 0;i<m;i++){ 
            if(!(max_so_far >= (cnt[a[i]]/(ate[a[i]]+1)))){ 
                temp = a[i];
                max_so_far = (cnt[a[i]]/(ate[a[i]]+1)); 
                
                 } 
             } 
            if(max_so_far==-1){ 
                cout<<0<<endl;
                return 0;
            } 
            else{ 
                ate[temp]++; 
            }
        } 
                for(int i = 0;i<m;i++){
                        int freq = ate[a[i]];
                if(freq ==0)
                    continue;
                ans = min(cnt[a[i]]/freq,ans);
               }
               cout<<ans<<endl;



    return 0;
}