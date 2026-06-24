#include <bits/stdc++.h>

using namespace std;

 

typedef long long ll;

typedef double db;

#define pairll pair<ll,ll>

#define lpairll pair<ll,pairll>

 

#define pb push_back

#define mp make_pair

#define fr first

#define sc second

#define repp(i,a,b) for(ll i = (a); i <= (b); i++)

#define repm(i, a, b) for (ll i = (a); i >= (b); i--)

#define repz(i, a, b) for (ll i = (a); i < (b); i++)

 

const ll N = 5e5 + 5, M = 3e3+5, MOD = 998244353;



ll tc = 1, n, m=0, k, ar[N], pos[N];

ll di[] = {0,0,-1,1}, dj[]={-1,1,0,0};

string s, ye = "Yes", no = "No", s1, s2;

vector<pairll> ed[N];

vector<ll> ad[N];



void fastt(){ 

  ios_base::sync_with_stdio(0);

  cin.tie(NULL);

  cout.tie(NULL); 

}



ll dep[N], deg[N];

pairll pr[N];



void ser(ll idx, ll par){

  for (auto i : ed[idx]){

    if (i.fr == par) continue;

    dep[i.fr] = dep[idx]+1;

    pr[i.fr] = mp(idx,i.sc);

    ser(i.fr,idx); 

  } 

}



void input(){

  cin >> n >> m;

  repp (i,1,n){

    cin >> ar[i];

    pos[ar[i]] = i;

  } 

  repp(i,1,m){

    ll a, b;

    cin >> a >> b;

    ed[a].pb(mp(b,i));

    ed[b].pb(mp(a,i));

  }

}



void get(ll idx){

  vector<ll> lef, rig;

  //idea -> go from pos to idx

  ll from = pos[idx], to = idx;

  //cout << endl;

  //cout << from << " " << to << endl;

  //cout << dep[from] << " " << dep[to] << endl;

  while(dep[from] > dep[to]){

    lef.pb(pr[from].sc);

    from = pr[from].fr;

  }

  while(dep[to] > dep[from]){

    rig.pb(pr[to].sc);

    to = pr[to].fr;

  }

  //cout << from << " " << to << endl;

  while(from != to){

    lef.pb(pr[from].sc);

    from = pr[from].fr;

    rig.pb(pr[to].sc);

    to = pr[to].fr;

    //cout << from << " " << to << endl;

  }

  //cout << "hm" << endl;

  repm(i,(int)rig.size()-1,0) lef.pb(rig[i]);

  repz(i,0,(int)lef.size()-1){

    deg[lef[i+1]]++;

    ad[lef[i]].pb(lef[i+1]);

  }

  //cout << "fin" << endl;

}



void solve(){

  //assign depth to the numbers

  memset(dep,-1,sizeof(dep));

  repp(i,1,n){

    if (dep[i] == -1){

      dep[i] = 0;

      ser(i,-1);

    }

  }

  

  // repp(i,1,n){

  //   cout << dep[i] << " " << pr[i].fr << " " << pr[i].sc << endl;

  // }

  // cout << endl;

  repp(i,1,n) get(i);



  vector<ll> ans;

  queue<ll> q;

  repp(i,1,m){

    if (deg[i] == 0){

      ans.pb(i);

      q.push(i);

    }

  }

  while(q.size()){

    ll a = q.front(); q.pop();

    for (auto i : ad[a]){

      deg[i]--;

      if (deg[i] <= 0){

        q.push(i);

        ans.pb(i);

      }

    }

  }

  for (auto i : ans) cout << i << " ";

  cout << endl; 

}





int main(){

  //freopen("input.txt", "r", stdin);

  //freopen("output.txt", "w", stdout);

  fastt();

  //cin >> tc;

  //cout << tc << endl;

  while(tc--){

    input();

    solve();

  }

}



/*



*/