#include <bits/stdc++.h>

#define vi vector<int>
#define vll vector<long long>
#define vc vector<char>
#define vvi vector<vector<int> >
#define vvll vector<vector<long, long> >
#define vvc vector<vector<char, char> >
#define str string
#define mii map<int, int>
#define mll map<long long, long long>
#define mis map<int, string>
#define mss map<string, string>
#define msi map<string, int>
#define mci map<char, int>
#define mcc map<char, char>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pis pair<int, string>
#define pss pair<string, string>
#define si set<int>
#define sll set<long long>
#define sc set<char>
#define pb push_back
#define all(a) a.begin(), a.end()
#define allrev(a) a.rbegin(), a.rend()
#define fori(a, n) for (int i = a; i < n; i++)
#define forj(a, n) for (int j = a; j < n; j++)
#define fork(a, n) for (int k = a; k < n; k++)
#define ll long long
#define ull unsigned long long
#define intCielDiv(n, k) (n) / (k) + ((n) % (k) > 0)
#define sp << ' ' <<
#define spl << ' '
#define nl << '\n' 

using namespace std;

int n;
ll x, pf[2005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--){
      cin >> n;
      if(n == 1){ 
        cout<<"NO\n";
        continue;
      }
      fori(0, n) {
        cin >> x;
        if(i == 0) pf[i] = x;
        else pf[i] = x ^ pf[i-1];
        // cout << pf[i] spl;
      }
      // cout nl;
      int ind = -1;
      bool flag = false;
      fori(0, n){
        if(ind == -1){
          if(pf[i] == (pf[n-1] ^ pf[i])){
            flag = true;
            break;
          }else if((pf[n-1] ^ pf[i]) == 0){
            ind = i;
          }
        }else{
          if((pf[i] ^ pf[ind]) == pf[ind]){
            flag = true;
            break;
          }
        }
      }
      if(flag) cout << "YES\n";
      else cout << "NO\n";
    }

    return 0;
}