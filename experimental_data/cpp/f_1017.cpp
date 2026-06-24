#include<bits/stdc++.h>
using namespace std;
#define ll long long
const unsigned N = 1e5+5;
unsigned A,B,C,D,Sqr,zhi[N],pri[N],sp[N],spp[N],sppp[N],tot,m,id1[N],id2[N],g[N],h[N],G[N],H[N],n,w[N];
void Sieve(unsigned n){
    zhi[1]=1;
    for (unsigned i=2;i<=n;++i){
        if (!zhi[i]) pri[++tot]=i,sp[tot]=(sp[tot-1]+i),spp[tot]=(spp[tot-1]+i*i),sppp[tot]=(sppp[tot-1]+i*i*i);
        for (unsigned j=1;i*pri[j]<=n;++j){
            zhi[i*pri[j]]=1;
            if (i%pri[j]==0) break;
        }
    }
}
unsigned get2(unsigned x) {
	unsigned a = x;
	unsigned b = x + 1;
	unsigned c = 2 * x + 1;
	if (a % 2 == 0) a /= 2;
	else if (b % 2 == 0) b /= 2;
	else c /= 2;
	if (a % 3 == 0) a /= 3;
	else if (b % 3 == 0) b /= 3;
	else c /= 3;
	return a * b * c;
}
unsigned get3(unsigned x) {
	unsigned a = x;
	unsigned b = x + 1;
	if (a % 2 == 0) a /= 2;
	else b /= 2;
	return a * b * a * b;
}
int main(){
    cin >> n >> A >> B >> C >> D;
    Sqr=sqrt(n);Sieve(Sqr);
    for (ll i=1,j;i<=n;i=j+1){
        j=n/(n/i);w[++m]=n/i;
        if (w[m]<=Sqr) id1[w[m]]=m;
        else id2[n/w[m]]=m;
        h[m]=(w[m]-1);
        if ((w[m] + 2) % 2 == 0) g[m]=((w[m]+2) / 2)*((w[m]-1));
        else g[m]=((w[m]+2))*((w[m]-1) / 2);
        H[m]=get2(w[m])-1;
        G[m]=get3(w[m])-1;
    }
    for (unsigned j=1;j<=tot;++j)
        for (unsigned i=1;i<=m&&1ll*pri[j]*pri[j]<=w[i];++i){
            unsigned k=(w[i]/pri[j]<=Sqr)?id1[w[i]/pri[j]]:id2[n/(w[i]/pri[j])];
            G[i]=(G[i]-pri[j]*pri[j]*pri[j]*(G[k]-sppp[j-1]));
            H[i]=(H[i]-pri[j]*pri[j]*(H[k]-spp[j-1]));
            g[i]=(g[i]-pri[j]*(g[k]-sp[j-1]));
            h[i]=(h[i]-h[k]+j-1);
        }
    unsigned ans = 0;
    for (int i = 1; i <= tot; i++) {
    	unsigned cnt = 0;
    	unsigned tmp = n;
    	while (tmp >= pri[i]) {
    		cnt += tmp / pri[i];
    		tmp /= pri[i];
	    }
    	ans += cnt * (A * pri[i] * pri[i] * pri[i] + B * pri[i] * pri[i] + C * pri[i] + D);
    }
    for (unsigned i = 1; w[i] > Sqr; i++) {
    	ans += i * (G[i] - G[i + 1]) * A;
    	ans += i * (H[i] - H[i + 1]) * B;
    	ans += i * (g[i] - g[i + 1]) * C;
    	ans += i * (h[i] - h[i + 1]) * D;
    }
    printf("%u\n", ans);
    return 0;
}