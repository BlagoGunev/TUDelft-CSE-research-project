#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#define lson i<<1
#define rson i<<1|1
#define LS l,mid,lson
#define RS mid+1,r,rson
#define mem(a,x) memset(a,x,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x&-x)
#define pb(x) push_back(x)
#define enld endl
#define mian main
#define itn int
#define prinft printf
#pragma GCC optimize(2)
#define pii pair<int,int>
//#pragma comment(linker, "/STACK:102400000,102400000")

const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int EXP = 1e-8;
const int N = 1e7 + 5;
const int MOD = 1e9 + 7;
const int MAXN = 1e5 + 10;

using namespace std;

int q;
ll ans[30],a;
ll b[30]= {0,
           1,
           1,
           5,
           1,
           21,
           1,
           85,
           73,
           341,
           89,
           1365,
           1,
           5461,
           4681,
           21845,
           1,
           87381,
           1,
           349525,
           299593,
           1398101,
           178481,
           5592405,
           1082401,22369621
          };
void init() {
	ans[0]=1;
	for(int i=1; i<=26; ++i) ans[i]=ans[i-1]*2;
}

int main() {
	init();
	cin>>q;
	while(q--) {
		cin>>a;
		int flag=0;
		for(int i=0; i<=26; ++i) {
			if(a+1==ans[i]) {
				cout<<b[i-1]<<endl;
				flag=1;
			}
		}
		if(flag) continue;
		int n=log(a+1)/log(2);
		cout<<ans[n+1]-1<<endl;
	}
}