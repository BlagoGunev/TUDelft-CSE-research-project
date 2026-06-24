#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define PI 3.14159265359
#define ff first
#define ss second
#define MAX(X,Y)  (X>Y ? X:Y)
#define MIN(X,Y)  (X<Y ? X:Y)
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi > vpi;


int main() {
    
    ios:: sync_with_stdio(0);
    cin.tie(NULL),cout.tie(NULL);
    
    int n,k;
    cin>>n>>k;
    string s;

    cin>>s;
    vi v(k);
    int minv = 1e6;
    for(int i=0;i<n;i++){
    	v[s[i] - 'A']++;
    }
    for(int i=0;i<k;i++){
    	minv = min(minv , v[i]);
    }
    cout<< minv * k <<endl;
	return 0;
}