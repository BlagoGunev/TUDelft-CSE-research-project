#include <iostream>

#include <cstring>

#include <algorithm>

#include <cmath>

#include <vector>

#include <queue>

#include <unordered_map>

#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int lcm(int a,int b){return a*b/gcd(a,b);}

#define int long long 

#define x first

#define y second

#define NO {puts("NO") ; return ;}

#define YES {puts("YES") ; return ;}

typedef pair<int, int> PII;

//#pragma GCC optimize(2)

//#pragma G++ optimize(2) 

const int N = 2e5+10, INF = 0x3f3f3f3f; 

int a[N];

int n,k;

queue<int>q[N];

void solve(){



cin>>n;

for(int i=1;i<=n;i++){

	cin>>a[i];

	q[a[i]].push(i);

}

int k=0;

int res=1;

for(int i=1;i<=n;i++){

	if(q[a[i]].size()>=2){

		k=1;

		for(int j=0;j<q[a[i]].size();j++){

			int l=q[a[i]].front();

			q[a[i]].pop();

			int r=q[a[i]].front();

			res=max(res,n+l-r);

		}

		

	}

}

for(int i=1;i<=n;i++){

while(!q[a[i]].empty())	q[a[i]].pop();

}

if(k==0){

	cout<<-1<<endl;

	return;

}

cout<<res<<endl;

}

signed  main(){

ios;

int t;

cin>>t;

while(t--)solve();

}