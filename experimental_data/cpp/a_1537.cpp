/*************************************************************
 *  > File Name        : A.cpp
 *  > Author           : Zjkai
 *  > Created Time     : 2021/6/18 22:34:35
**************************************************************/

#include<set>
#include<map>
#include<cstdio>
#include<cmath>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fs first
#define sc second
#define mk make_pair
#define pb push_back
#define int long long
#define db double
#define MOD 1000000007
#define INF 0x7ffffffffffffff
#define Y cout << 'Y' << 'E' << 'S' << endl
#define N cout << 'N' << 'O' << endl
#define pii pair<int, int >
#define vvi vector<vector<int> >
#define dbg(x) cerr << #x << '=' << x << endl
using namespace std;
int qr(){
    int x=0,f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
    while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    return x*f;
}
 
void work(){
	int n = qr(), ans = 0;
	for(int i=1;i<=n;i++){
		int x = qr();
		ans += x;
	}
	if(ans < n) cout << "1" << endl;
	else if(ans >= n) cout << ans - n << endl;
}

signed main(){
	int T = 1;
	T = qr();
	while(T--) work();
	return 0;
}