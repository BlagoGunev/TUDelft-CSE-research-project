#include<string>

#include<iostream>

#include<vector>

#include<utility>

#include<algorithm>

using std::cin;

using std::cout;

int a[200010],c[200010],f[200010],n,p[200010],q[200010],m,stk[200010],tp,cnt[30];

void update(int i,int p){

	for(;i<=n;i+=i&-i) c[i]+=p;

}

int query(int i){

	int ans=0;

	for(;i;i&=i-1) ans+=c[i];

	return ans;

}

int find(int i){

	while(f[i]!=i) i=f[i]=f[f[i]];

	return i;

}

int main(){

	std::ios::sync_with_stdio(false),cin.tie(nullptr);

	int T;

	cin>>T;

	while(T--){

		std::string s;

		std::vector<std::pair<int,int>> ans;

		cin>>s;

		n=s.size();

		for(int i=1;i<=n;i++) a[i]=s[i-1]-'a'+1,f[i]=i,c[i]=0;

		f[n+1]=n+1;

		for(int i=1;i<=26;i++) cnt[i]=0;

		for(int i=1;i<=n;i++) update(i,1);

		m=tp=0;

		for(int i=2;i<=n;i++) if(a[i]==a[i-1]) ++m,p[m]=a[i],q[m]=i-1,++cnt[p[m]];

		for(int i=1,lt=m;i<=m;i++){

			int mx=std::max_element(cnt+1,cnt+27)-cnt;

			if(tp==0||p[stk[tp]]==p[i]){stk[++tp]=i;continue;}

			if(cnt[mx]*2>=lt&&p[stk[tp]]!=mx&&p[i]!=mx){stk[++tp]=i;continue;}

			--cnt[p[stk[tp]]],--cnt[p[i]];

			ans.emplace_back(query(q[stk[tp]]+1),query(q[i]));

			for(int j=find(q[stk[tp]]+1);j<=q[i];j=find(j)) update(j,-1),f[j]=j+1;

			--tp,lt-=2;

		}

		q[++m]=n,stk[++tp]=m;

		for(int i=1;i<=tp;i++){

			ans.emplace_back(1,query(q[stk[i]]));

			for(int j=find(1);j<=q[stk[i]];j=find(j)) update(j,-1),f[j]=j+1;

		}

		cout<<ans.size()<<'\n';

		for(auto [u,v]:ans) cout<<u<<' '<<v<<'\n';

	}

	return 0;

}