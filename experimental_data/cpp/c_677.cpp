#include<iostream>

#include<bits/stdc++.h>

#include<cstdio>

#include<string>

#include<cstring>

#include<map>

#include<queue>

#include<set>

#include<stack>

#include<ctime>

#include<algorithm>

#include<cmath>

#include<vector>

#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)

#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

typedef long long ll;

typedef long long LL;

#define MP make_pair

#define PII pair<int,int>

#define PFI pair<double,int>

#define PLL pair<ll,ll>

#define F first

#define S second

#define lson l,mid,rt<<1

#define rson mid+1,r,rt<<1|1

#define debug cout<<"?????"<<endl;

//freopen("1005.in","r",stdin);

//freopen("data.out","w",stdout);

const int INF = 0x3f3f3f3f;

const double eps = 1e-2;

const int N = 3e5 + 50;

const double PI = acos(-1.);

const double E = 2.71828182845904523536;

const int MOD = 1e9+7;

typedef vector<ll> Vec;

typedef vector<Vec> Mat;

string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_";

map<char,int> mp;

char s[(int)1e5+7];

int main(){



	mp.clear();

	for(int i = 0 ; i < str.length() ; i ++){

		for(int j = 0 ; j < str.length() ; j ++){

			mp[str[i&j]] ++;

		}

	}

	ll ans = 1;

	scanf("%s",s);

	for(int i = 0 ; s[i] ; i ++){

	   	ans = ans * mp[s[i]] % MOD;

	}

	cout << ans << endl;

	return 0;

}