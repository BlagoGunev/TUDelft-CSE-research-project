#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
#define MAXN 300010
const ll MOD = 1e9+7;

ll ind[MAXN],x[MAXN],a[MAXN],b[MAXN];
vector<int> adj[20000];
ll n,m,k;


void solve() 
{
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> ind[i];
    }
    for (int i=  0; i < k; i++) {
        cin >> x[i];
    }
    if (ind[0] < x[0]) {
        cout << "NO" << endl;
        return;
    }
    for (int i =1; i < k; i++) {
        if (ind[i]-ind[i-1] < x[i]-x[i-1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    int abc = 0;

    int curr =  0;

    int numUsed = 0;

    for (int i = 0; i < k; i++) {
        int workReq = 0;
         int fillReq = 0;
        if (i==0) {
            workReq = x[0];
            fillReq = ind[0]-x[0];
        } else {
            workReq = x[i]-x[i-1];
            fillReq = (ind[i]-ind[i-1])-workReq;
        }
        for (int j = 0; j < workReq; j++) {
            if (numUsed == 0) {
                cout << 'a';
                numUsed++;
            } else if (numUsed == 1) {
                cout << 'b';
                numUsed++;
            } else if (numUsed == 2) {
                cout << 'c';
                numUsed++;
            } else if (numUsed == 3) {
                cout << 'd';
                numUsed++;
            } else {
                cout << (char) ('e'+i);
                
            }
            
        }
        for (int j = 0; j < fillReq; j++) {
            cout << (char) ('a'+abc);
            abc = (1+abc)%3;
        }
     
    
    }
    for (int i = ind[k-1]; i < n; i++) {
        cout << (char) ('a'+abc);
            abc = (1+abc)%3;
    }
    cout << endl;





}


int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
 
	ll t;
	cin >> t;
	while (t--) {
        solve();
	}
	return EXIT_SUCCESS;
}