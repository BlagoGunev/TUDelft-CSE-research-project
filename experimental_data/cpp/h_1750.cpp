// LUOGU_RID: 100352010
#include <bits/stdc++.h>
#define seg pair<int,int>
#define l first
#define r second
using namespace std;
vector<seg>dp[200005];
deque<seg>buc[200005];
int n; char s[200005];
int qry(int L,int R) {
	if(R>n) return n+1;
	int lp=0,rp=dp[L].size(),ans=n+1;
	while(lp<rp) {
		int mid=lp+rp>>1;
		if(dp[L][mid].r>=R) ans=min(ans,max(dp[L][mid].l,R)),rp=mid; else lp=mid+1;
	} return ans;
}
void prework(vector<pair<int,int>>&sg) {
	for(int L=1,R=1;L<=n;L=++R) if(s[L]=='0') {
		while(R<n&&s[R+1]=='0') R++;
		for(int i=max(1,L-(R-L));i<L;i++) buc[i].push_back({L,R});
	}
	for(int i=n,lst=n+1;i;i--) {
		if(s[lst]!=s[i]) lst=i;
		int L=i,R;
		if(s[i]=='0') L=qry(lst+1,lst+(lst-i+1));
		while(L<=n) {
			for(R=n;buc[i].size();) if(buc[i].front().r>=L) { R=buc[i].front().l-1; break ; } else buc[i].pop_front();
			if(L<=R) dp[i].emplace_back(L,R);
			if(buc[i].empty()) L=n+1;
			else {
				seg S=buc[i].front();
				L=qry(S.r+1,S.r+(S.r-S.l+1));
			}
		}
	}
	for(int i=1;i<=n;i++) {
		for(auto [l,r]:dp[i]) sg.emplace_back(l,i),sg.emplace_back(r+1,-i);
		buc[i].clear(),dp[i].clear();
	}
	// for(auto [p,x]:sg) printf("(%d,%d)",p,x); puts("");
}
vector<pair<int,int>>ldp,rdp;
int sl[200005],sr[200005],el[200005],er[200005],le[200005],id[200005];
struct bit {
	int vl[200005],n;
	void clr(int sz) { for(int i=1;i<=sz;i++) vl[i]=0; n=sz; }
	void mdf(int p,int x) { for(;p<=n;p+=p&-p) vl[p]+=x; }
	int qry(int L,int R) {
		if(L>R) return 0; int res=0;
		for(;R;R-=R&-R) res+=vl[R]; for(L--;L;L-=L&-L) res-=vl[L];
		return res;
	}
}Bl,Br;
void work() {
	scanf("%d%s",&n,s+1); ldp.clear(); rdp.clear();
	prework(ldp); reverse(s+1,s+1+n); prework(rdp); reverse(s+1,s+1+n);
	for(auto &[p,x]:rdp) {
		p=n+1-p;
		if(x<0) x+=n+1; else x-=n+1;
	}
	long long ans=0;
	Bl.clr(n); Br.clr(n);
	sort(ldp.begin(),ldp.end());
	sort(rdp.begin(),rdp.end()); int m=0;
	for(int L=1,R=1;L<=n;L=++R) {
		for(;R<n&&s[R+1]==s[L];) R++;
		if(s[L]=='0') m++,el[id[m]=m]=m-1,er[m]=m+1,le[m]=R-L+1,sl[m]=L,sr[m]=R;
		else ans+=1ll*(R-L+2)*(R-L+1)/2;
	}
	int pl=0,pr=0;
	// cerr<<'*'<<endl;
	stable_sort(id+1,id+1+m,[&](int x,int y){return le[x]==le[y]?(sl[x]>sl[y]):le[x]<le[y];});
	for(int i=1;i<=m;i++) er[el[id[i]]]=er[id[i]],el[er[id[i]]]=el[id[i]];
	// for(auto [p,x]:ldp) printf("(%d,%d)",p,x); puts("");
	// for(auto [p,x]:rdp) printf("(%d,%d)",p,x); puts("");
	// cerr<<"!"<<ans<<endl;
	for(int i=1;i<=m;i++) {
		int L=sl[i],R=sr[i];
		for(int x;pl<ldp.size()&&ldp[pl].first<L;pl++)
			x=ldp[pl].second,Bl.mdf(abs(x),(x<0)?-1:1);//,printf("mdf Bl(%d,%d,%d,%d) %d,%d\n",pl,ldp[pl].l,x,L,abs(x),(x<0)?-1:1);
		for(int x;pr<rdp.size()&&rdp[pr].first<=R;pr++)
			x=rdp[pr].second,Br.mdf(abs(x),(x<0)?-1:1);//,printf("mdf Br(%d,%d,%d,%d) %d,%d\n",pr,rdp[pr].l,x,R,abs(x),(x<0)?-1:1);
		// liml
		int lu=i-1;
		for(int l0=1;l0<le[i];l0++) {
			while(lu&&le[lu]<l0) lu=el[lu];
			int pos=lu==0?1:(sr[lu]-l0+2);
			// printf("lsub len=%d pos=%d res=%d\n",l0,pos,Bl.qry(pos,L-l0));
			ans+=Bl.qry(pos,L-l0);
		}
		// limr
		int ru=i+1;
		for(int r0=1;r0<le[i];r0++) {
			while(ru<=m&&le[ru]<=r0) ru=er[ru];
			int pos=ru>m?n:(sl[ru]+r0-1);
			// printf("rsub len=%d pos=%d res=%d\n",r0,pos,Br.qry(R+r0,pos));
			ans+=Br.qry(R+r0,pos);
		}
		// cerr<<'*'<<endl;
		// full
		while(lu&&le[lu]<le[i]) lu=el[lu];
		while(ru<=m&&le[ru]<=le[i]) ru=er[ru];
		int posl=lu==0?1:(sr[lu]-le[i]+2);
		int posr=ru>m?n:(sl[ru]+le[i]-1);
		int resl=Bl.qry(posl,L-le[i]),resr=Br.qry(R+le[i],posr);
		// printf(">%lld\n",ans);
		ans+=1ll*(posr-R+1)*(L-posl+1)-1ll*(posr-R+1-resr)*(L-posl+1-resl);
		// printf(">> %lld %d %d %d %d %d %d\n",ans,resl,resr,posl,posr,L,R);
	}
	printf("%lld\n",ans);
}
int main() {int we=12; for(int i=1;i<=2e8;++i)we=we*i;int t; for(scanf("%d",&t);t--;) work(); }