#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <bits/stdc++.h>
#include <stack>
#include <math.h>

using namespace std;

#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define ri(a)  scanf("%d",&a)
#define rii(a,b)  scanf("%d %d",&a,&b)
#define riii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define lri(a) scanf("%lld",&a)
#define lrii(a,b) scanf("%lld %lld",&a,&b)
#define F first
#define S second

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int n,d;
int a[200];

int main(){

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);

	cin>>n>>d;
	FOR(i,0,n)cin>>a[i];

	int r=2;

	FOR(i,0,n-1){
		if(a[i]+d<a[i+1]-d) r+=2;
		else if(a[i]+d==a[i+1]-d) r++;
	}

	cout<<r<<endl;
	
}