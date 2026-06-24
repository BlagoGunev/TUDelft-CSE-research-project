/*

*DIV 2 B. Spoilt Permutation

*nilabja10201992

*/

#include <bits/stdc++.h>

using namespace std;



#define inf (1<<30)

#define INF (int)1e9

#define EPS 1e-9

#define PI 3.1415926535897932384626433832795

#define MOD 1000000007

#define MAX 1000000



#define write(x) freopen(x,"w",stdout);

#define read(x) freopen(x,"r",stdin);



typedef long long i64;

typedef unsigned long long ui64;

typedef string st;

typedef long long int lli;

typedef vector<int> vi;

typedef vector<st> vs;

typedef map<int,int> mii;

typedef map<st,int> msi;

typedef set<int> si;

typedef set<st> ss;

typedef pair<int,int> pii;

typedef vector<pii> vpii;

typedef vector<lli> vlli;



int main() {

     ios_base::sync_with_stdio(false);

     cin.tie(NULL);

	int n;

	cin>>n;

	vector<int> a(n);

	for(int i=0;i<n;i++){

		cin>>a[i];

		a[i]--;

	}

	int l=0;

	while(l<n && a[l]==l) ++l;

	if(l==n){

		cout<<0<<" "<<0<<endl;

		return 0;

	}

	int r=n-1;

	while(r>=0 && a[r]==r) --r;

	reverse(a.begin()+l,a.begin()+r+1);

	for(int i=0;i<n;i++){

		if(a[i]!=i){

			cout<<0<<" "<<0<<endl;

			return 0;

		}

	}

	cout<<l+1<<" "<<r+1<<endl;

	//cout<<"Execution time : "<<tick();

     return 0;

}