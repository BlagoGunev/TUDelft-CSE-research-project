#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define pii pair<ll int,ll int>
#define umap unordered_map
#define popcount(x) __builtin_popcountll(x)
#define all(v) v.begin() , v.end()
#define PI 3.141592653589793238
#define E 2.7182818284590452353602874713527
#define M 1000000007
const long long INF = 1e18;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
ll int t=1,n,oo=0,k;
cin>>t;
ll int qq=t;
while(t--)
{
cin>>n>>k;
string s;
cin >> s;
ll int l[k], r[k];
for (int i = 0; i < k; i++)
{
  cin>>l[i];
  l[i]--;
}
for (int i = 0; i < k; i++)
{
  cin>>r[i];
  r[i]--;
}
ll int q;
cin >> q;
ll int x[q];
// map<pii,ll int>p;
for (int i = 0; i <q; i++)
{
  cin >> x[i];
  x[i]--;
}
// error(s);
sort(x, x + q);
ll int p = 0;
ll int c[n+1]={};
for (int i = 0; i < k; i++) {

  while (p < q && x[p] >= l[i] && x[p] <= r[i])
    c[min(x[p], r[i] + l[i] - x[p])]++, p++;
  // error(p,x[p-1]);
  // error(l[i],r[i]);
  ll int cnt=0;
  for (int j = l[i]; j <=(r[i]+l[i])/2; j++)
  {
    if (j > l[i])
      c[j] += c[j - 1];
    if (c[j] % 2 == 1)
      swap(s[r[i] - cnt], s[l[i] + cnt]);
    cnt++;
  }
  
}
cout<<s<<'\n';

//cout<<"Case #"<<qq-t<<": "<<
}
}