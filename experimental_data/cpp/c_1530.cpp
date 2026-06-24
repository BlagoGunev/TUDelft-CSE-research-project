/*
    Author : SharpnessV
    Right Output ! & Accepted !
*/
#include<bits/stdc++.h>

#define rep(i, a, b) for(int i = a;i <= b;i++)
#define pre(i, a, b) for(int i = a;i >= b;i--)
#define rp(i, a) for(int i = 1; i <= a; i++)
#define pr(i, a) for(int i = a; i >= 1; i--)
#define go(i, x) for(auto i : x)

#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define ze(p) memset(p, 0, sizeof(p))
#define YES puts("YES")
#define NO puts("NO")
#define si(x) (int)(x).size()

using namespace std;
const double eps = 1e-15, pi = 3.1415926535897932385;
typedef long long LL;
typedef pair<int,int> Pr;
const int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}, inf = 0x7fffffff;

//char buf[1<<22],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline int read(){
    int x = 0, f = 1;char ch = getchar();
    while(!isdigit(ch))f = ('-' == ch ? -1 : 1), ch = getchar();
    while(isdigit(ch))x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    if(~f)return x;return -x;
}
int gcd(int x,int y){return y ? gcd(y, x % y) : x;}
int lcm(int x,int y){return x / gcd(x, y) * y;}
#define P 1000000007
//#define P 998244353
inline void ad(int &x, int y){x += y; if(x >= P) x -= P;}
inline void su(int &x, int y){x -= y; if(x < 0) x += P;}
int Pow(int x, int y){
	if(y < 0)return Pow(Pow(x, P - 2), -y);
	int now = 1 ;
	for(;y;y >>= 1, x = 1LL * x * x % P)if(y & 1) now = 1LL * now * x % P;
	return now;
}
#define N 100005
int n, m, a[N], b[N];
void solve(){
	n = read();
	rp(i, n)a[i] = read();
	rp(i, n)b[i] = read();
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	int ans = 0, k = n / 4, sum = 0, p = k;
	rep(i, k + 1, n)sum += a[i] - b[i];
	while(sum < 0){
		ans ++;
		sum += 100;
		int w = (n + ans) / 4;
		if(w > k){
			if(k < n)sum -= a[++k];
			else sum -= 100;
		}
		if(p > 0 && p + ans > w)sum -= b[p--];
		//cout<<"ss "<<w<<" "<<k<<" "<<p<<" "<<sum<<endl;
	}
	printf("%d\n",ans);
}
int main(){
	int T = read();while(T--)solve();

	return 0;
}