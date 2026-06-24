#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,d,w,t,L;
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b,a%b); }
int main() {
//	freopen("sa1.in","r",stdin);
int T; cin>>T;
while (T--) {
scanf("%lld%lld%lld",&m,&d,&w);
w=w/gcd(d-1,w);
L=min(m,d); t=L/w;
printf("%lld\n",L*t-(t+1)*t/2*w);
}
return 0;
}