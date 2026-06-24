#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(c) (c).begin(),(c).end() 
#define tr(c,it) for(auto it = (c).begin(); it != (c).end(); it++) 
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
#define TRACE
#ifdef TRACE
#define trace1(x)     	   cerr << #x << ": " << x << endl;
#define trace2(x, y)       cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)    cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#else
#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#endif
typedef long long LL;
const LL MOD = 1000000007;
typedef pair<LL,LL> PII;
typedef vector<LL> VI;
typedef vector<PII> VPII;
LL gcd1(LL a,LL b){while(b){LL t=a%b;b=a;a=t;}return a;}
int main(){
	LL a,b,c,n,d,sz,i;
	vector <LL> v;v.clear();
	double ans;
	cin >> a >> b >> c >> d;
	n = a*d - b*c;
	for(i=0;i<16;i++){
		LL temp=0;
		int a1=0,a2=0;
		if(i&(1<<0))a1^=1;
		if(i&(1<<3))a1^=1;
		if(i&(1<<1))a2^=1;
		if(i&(1<<2))a2^=1;
		if(a1!=a2)continue;

		if(i&(1<<0))temp+=a;else temp-=a;
		if(i&(1<<1))temp+=b;else temp-=b;
		if(i&(1<<2))temp+=c;else temp-=c;
		if(i&(1<<3))temp+=d;else temp-=d;
		if(temp!=0)v.pb(fabs(temp));
	}
	cout << fixed;
	cout << setprecision(11);
	d = 0;
	sz = (int)v.size();
	for(i=0;i<sz;i++){
		d = max(d,v[i]);
	}
	ans = 0;
	if(d!=0)
		ans  = (double)((double)n/(double)d);
	ans =  fabs(ans);
	cout << ans << "\n";
	return 0;
}