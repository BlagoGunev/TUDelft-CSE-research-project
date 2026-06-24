#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod7=1000000007LL;
inline ll getint() {
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
inline ll add(ll _x, ll _y, ll _mod=mod7) {
  _x+=_y;
  return _x>=_mod ? _x-_mod : _x;
}
inline ll sub(ll _x, ll _y, ll _mod=mod7) {
  _x-=_y;
  return _x<0 ? _x+_mod : _x;
}
inline ll mul(ll _x, ll _y ,ll _mod=mod7) {
  _x*=_y;
  return _x>=_mod ? _x%_mod : _x;
}
ll mypow(ll _a, ll _x, ll _mod) {
  if(_x == 0) return 1ll;
  ll _ret = mypow(mul(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=mul(_ret, _a, _mod);
  return _ret;
}
ll mymul(ll _a, ll _x, ll _mod) {
  if(_x == 0) return 0ll;
  ll _ret = mymul(add(_a, _a, _mod), _x>>1, _mod);
  if(_x & 1) _ret=add(_ret, _a, _mod);
  return _ret;
}
void sleep(double sec = 1021) {
	clock_t s = clock();
	while(clock() - s < CLOCKS_PER_SEC * sec);
}
#define Bye exit(0)
int __ = 1 , _cs;
/*********default*********/

const int mxN=1e6, M=998244353;
string a, l, r, l2, r2;
ll dp[mxN+2];
int n, z1[2*mxN+1], z2[2*mxN+1];

void cz(string &s, int z[2*mxN+1]) {
	int l=0, r=0;
	for(int i=1; i<s.size(); ++i) {
		if(i>r) {
			l=r=i;
			while(r<s.size()&&s[r-l]==s[r])
				++r;
			z[i]=r-l;
			--r;
		} else {
			int k=i-l;
			if(z[k]>=r-i+1) {
				l=i;
				while(r<s.size()&&s[r-l]==s[r])
					++r;
				z[i]=r-l;
				--r;
			} else
				z[i]=z[k];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> l >> r;
	n=a.size();
	l2=l+'!'+a;
	r2=r+'!'+a;
//	cout << l << " " << r << endl;
	cz(l2, z1);
	cz(r2, z2);
//	for(int i=0; i<l.size(); ++i)
//		cout << z1[i] << " ";
//	cout << endl;
//	for(int i=0; i<r.size(); ++i)
//		cout << z2[i] << " ";
//	cout << endl;
	dp[0]=1;
	dp[1]=-1;
	for(int i=0; i<n; ++i) {
//		cout << i << " " << dp[i] << endl;
		dp[i]=(dp[i]%M+M)%M;
		dp[i+1]+=dp[i];
		if(a[i]=='0') {
			if(l=="0") {
				dp[i+1]+=dp[i];
				dp[i+2]-=dp[i];
			}
			continue;
		}
		int al=l.size()+1, ar=r.size(), zl=z1[l.size()+1+i], zr=z2[r.size()+1+i];
		if(i+l.size()<=n&&(zl>=l.size()||a[i+zl]>l[zl]))
			--al;
		if(i+r.size()<=n&&(zr>=r.size()||a[i+zr]<r[zr]))
			++ar;
//		cout << i << " " << i+al << " " << i+ar << endl;
		dp[min(i+al, n+1)]+=dp[i];
		dp[min(i+ar, n+1)]-=dp[i];
	}
	cout << (dp[n]%M+M)%M;
}