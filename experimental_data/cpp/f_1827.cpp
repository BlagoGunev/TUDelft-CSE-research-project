#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,a[maxn];
struct node{
	int l,r;
	node* ch[2];
	int mn,cnt,fs,add=0;
	void pushup(){
		mn=min(ch[0]->mn,ch[1]->mn);
		cnt=0;
		if(mn==ch[1]->mn){
			cnt+=ch[1]->cnt;
			fs=ch[1]->fs;
		}
		if(mn==ch[0]->mn){
			cnt+=ch[0]->cnt;
			fs=ch[0]->fs;
		}
	}
	node(int l,int r):l(l),r(r),mn(l-1),cnt(1),fs(l){
		if(l==r) return;
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
	}
	void pushtag(int k){
		mn+=k;
		add+=k;
	}
	void pushdown(){
		ch[0]->pushtag(add);
		ch[1]->pushtag(add);
		add=0;
	}
	void modify(int ql,int qr,int k){
		if(ql>r||qr<l) return;
		if(ql<=l&&qr>=r){
			pushtag(k);
			return;
		}
		pushdown();
		ch[0]->modify(ql,qr,k);
		ch[1]->modify(ql,qr,k);
		pushup();
	}
	~node(){
		if(l==r) return;
		delete ch[0];
		delete ch[1];
	}
}*rt;
set<int> st;
int s[maxn],tp,mn[maxn],mx[maxn],p1[maxn],p2[maxn];
bool t1[maxn],t2[maxn];
ll calc1(int x){
	return 1ll*p1[x]*(mn[x]-*--st.lower_bound(mn[x])-1);
}
ll calc2(int x){
	return 1ll*p2[x]*(*st.upper_bound(mx[x])-mx[x]-1);
}
int s1[maxn],tp1,s2[maxn],tp2;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read();
		st={0,a[1],n+1};
		s[tp=1]=s1[tp1=1]=s2[tp2=1]=1;
		rt=new node(1,n);
		mn[1]=mx[1]=a[1];
		p1[1]=p2[1]=t1[1]=t2[1]=1;
		auto C2=[](int x){
			return 1ll*x*(x+1)/2;
		};
		ll ans=C2(a[1]-1)+C2(n-a[1])+n;
		printf("%lld %lld",C2(n),ans);
		for(int i=2;i<=n;i++){
			int l=*--st.lower_bound(a[i]),r=*st.upper_bound(a[i]);
			while(mn[s[tp]]>r||mx[s[tp]]<l){
				ans--;
				if(t1[s[tp]]) ans-=calc1(s[tp]);
				if(t2[s[tp]]) ans-=calc2(s[tp]);
				mn[s[tp-1]]=min(mn[s[tp-1]],mn[s[tp]]);
				mx[s[tp-1]]=max(mx[s[tp-1]],mx[s[tp]]);
				tp--;
			}
			mn[i]=mx[i]=a[i];
			int x=lower_bound(s+1,s+tp+1,rt->fs)-s;
			if(mn[s[tp]]>a[i]){
				p1[i]=max(p1[s[tp]],tp-x+2);
				t1[s[tp]]=0;
				ans-=calc1(s[tp]);
			}
			else{
				p1[i]=1;
				if(!t1[s[tp]]){
					t1[s[tp]]=1;
					ans+=calc1(s[tp]);
				}
			}
			if(mx[s[tp]]<a[i]){
				p2[i]=max(p2[s[tp]],tp-x+2);
				t2[s[tp]]=0;
				ans-=calc2(s[tp]);
			}
			else{
				p2[i]=1;
				if(!t2[s[tp]]){
					t2[s[tp]]=1;
					ans+=calc2(s[tp]);
				}
			}
			st.insert(a[i]);
			t1[i]=t2[i]=1;
			ans+=calc1(i)+calc2(i)+1;
			s[++tp]=i;
			ans+=rt->cnt+C2(r-a[i]-1)+C2(a[i]-l-1)-C2(r-l-1);
			printf(" %lld",ans);
			rt->pushtag(-1);
			while(tp1&&a[i]<a[s1[tp1]]){
				rt->modify(s1[tp1-1]+1,s1[tp1],a[s1[tp1]]);
				tp1--;
			}
			rt->modify(s1[tp1]+1,i,-a[i]);
			s1[++tp1]=i;
			while(tp2&&a[i]>a[s2[tp2]]){
				rt->modify(s2[tp2-1]+1,s2[tp2],-a[s2[tp2]]);
				tp2--;
			}
			rt->modify(s2[tp2]+1,i,a[i]);
			s2[++tp2]=i;
		}
		printf("\n");
		delete rt;
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}