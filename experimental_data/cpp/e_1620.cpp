// #include<bits/stdc++.h>
// // #define fastcall __attribute__((optimize("-O3")))
// // #pragma GCC optimize(1)
// // #pragma GCC optimize(2)
// // #pragma GCC optimize(3)
// // #pragma GCC optimize("Ofast")
// // #pragma GCC optimize("inline")
// // #pragma GCC optimize("-fgcse")
// // #pragma GCC optimize("-fgcse-lm")
// // #pragma GCC optimize("-fipa-sra")
// // #pragma GCC optimize("-ftree-pre")
// // #pragma GCC optimize("-ftree-vrp")
// // #pragma GCC optimize("-fpeephole2")
// // #pragma GCC optimize("-ffast-math")
// // #pragma GCC optimize("-fsched-spec")
// // #pragma GCC optimize("unroll-loops")
// // #pragma GCC optimize("-falign-jumps")
// // #pragma GCC optimize("-falign-loops")
// // #pragma GCC optimize("-falign-labels")
// // #pragma GCC optimize("-fdevirtualize")
// // #pragma GCC optimize("-fcaller-saves")
// // #pragma GCC optimize("-fcrossjumping")
// // #pragma GCC optimize("-fthread-jumps")
// // #pragma GCC optimize("-funroll-loops")
// // #pragma GCC optimize("-fwhole-program")
// // #pragma GCC optimize("-freorder-blocks")
// // #pragma GCC optimize("-fschedule-insns")
// // #pragma GCC optimize("inline-functions")
// // #pragma GCC optimize("-ftree-tail-merge")
// // #pragma GCC optimize("-fschedule-insns2")
// // #pragma GCC optimize("-fstrict-aliasing")
// // #pragma GCC optimize("-fstrict-overflow")
// // #pragma GCC optimize("-falign-functions")
// // #pragma GCC optimize("-fcse-skip-blocks")
// // #pragma GCC optimize("-fcse-follow-jumps")
// // #pragma GCC optimize("-fsched-interblock")
// // #pragma GCC optimize("-fpartial-inlining")
// // #pragma GCC optimize("no-stack-protector")
// // #pragma GCC optimize("-freorder-functions")
// // #pragma GCC optimize("-findirect-inlining")
// // #pragma GCC optimize("-fhoist-adjacent-loads")
// // #pragma GCC optimize("-frerun-cse-after-loop")
// // #pragma GCC optimize("inline-small-functions")
// // #pragma GCC optimize("-finline-small-functions")
// // #pragma GCC optimize("-ftree-switch-conversion")
// // #pragma GCC optimize("-foptimize-sibling-calls")
// // #pragma GCC optimize("-fexpensive-optimizations")
// // #pragma GCC optimize("-funsafe-loop-optimizations")
// // #pragma GCC optimize("inline-functions-called-once")
// // #pragma GCC optimize("-fdelete-null-pointer-checks")
// // #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #define db double
// #define il inline
// #define iL (1<<20)
// #define re register
// #define ll long long
// #define ui unsigned int
// #define ull unsigned long long
// #define TEM template<class T>il void
// #define Write(x,LC) write((x)),*iter++=LC
// #define Writeneg(x,LC) writeneg((x)),*iter++=LC
// #define flush() fwrite(Out,1,iter-Out,stdout),iter=Out
// #define gc() ((iS==iT)?(iT=(iS=ibuf)+fread(ibuf,1,iL,stdin),(iS==iT)?EOF:*iS++):*iS++)
// using namespace std;
// namespace IO{
// 	char ibuf[iL],*iS=ibuf+iL,*iT=ibuf+iL,Out[iL],*iter=Out;
// 	TEM Readneg(re T &x){re char c;re bool f;for(f=false,c=getchar();!isdigit(c);f|=c=='-',c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());if(f)x=~x+1;}
// 	TEM readneg(re T &x){re char c;re bool f;for(f=false,c=gc();!isdigit(c);f|=c=='-',c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());if(f)x=~x+1;}
// 	TEM writeneg(re T x){if(x<0)*iter++='-',x=~x+1;re T c[35],l;for(l=0;!l || x;c[l]=x%10,++l,x/=10);for(;l;--l,*iter++=c[l]+'0');flush();}
// 	TEM Read(re T &x){re char c;for(c=getchar();!isdigit(c);c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());}
// 	TEM read(re T &x){re char c;for(c=gc();!isdigit(c);c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());}
// 	TEM write(re T x){re T c[35],l;for(l=0;!l||x;c[l++]=x%10,x/=10);for(;l;*iter++=c[--l]+'0');flush();}
// }
// using namespace IO;
// //#define MAXN 55
// //#define MAXM 100005
// //#define mod 998244353
// //int pri[MAXM],cnt;bool vis[MAXM];
// //int n,m,l[MAXN],r[MAXN];ll mu[MAXM],f[MAXN][MAXM];
// //il ll Solve(int x){
// //	re ll ans=0;
// //	for(re int i=1;i*x<=m;++i)ans+=f[n][i],ans%=mod;
// //	printf("%d %lld\n",x,ans);
// //	return ans;
// //}

// //int main(){
// //	freopen("1.txt","r",stdin),freopen("2.txt","w",stdout);
// //	mu[1]=1;
// //	for(re int i=2;i<MAXM;++i){
// //		if(!vis[i])pri[cnt++]=i,mu[i]=-1;
// //		for(re int j=0;j<cnt&&i*pri[j]<MAXM;++j){
// //			vis[i*pri[j]]=true;
// //			if(!(i%pri[j]))break;
// //			mu[i*pri[j]]=-mu[i];
// //		}
// //	}
// //	scanf("%d%d",&n,&m);
// //	for(re int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]);
// //	f[0][0]=1;
// //	for(re int i=1;i<=n;++i){
// //		for(re int j=l[i];j<=r[i];++j){
// //			for(re int k=m;k>=j;--k){
// //				f[i][k]+=f[i-1][k-j],f[i][k]%=mod;
// //			}
// //		}
// //	}
// //	re ll sum=0;
// //	for(re int i=1;i<=m;++i)printf("%lld\n",f[n][i]);
// //	for(re int i=1;i<=m;++i)sum+=f[n][i];printf("sum %lld\n",sum);
// //	re ll ans=0;
// ////	for(re int i=1;i<=m;++i)printf("%d ",mu[i]);printf("\n");
// //	for(re int i=1;i<=m;++i)if(mu[i])ans+=1ll*mu[i]*Solve(i),ans%=mod;
// //	printf("%lld",(ans+mod)%mod);
// //}
// #define MAXN 100005
// int n,m[2],fa[2][MAXN];
// int find(int id,int x){return fa[id][x]^x?fa[id][x]=find(id,fa[id][x]):x;}
// il bool Check(int id,int x,int y){return find(id,x)^find(id,y);}
// il void unionn(int id,int x,int y){x=find(id,x),y=find(id,y);if(x^y)fa[id][y]=fa[id][x];}
// int main(){
// 	freopen("1.txt","r",stdin),freopen("2.txt","w",stdout);
// 	scanf("%d%d%d",&n,&m[0],&m[1]);
// 	for(re int i=1;i<=n;++i)fa[0][i]=fa[1][i]=i;
// 	for(re int i=1,x,y;i<=m[0];++i)scanf("%d%d",&x,&y),unionn(0,x,y);
// //	for(re int i=1,x,y;i<=m[1];++i)scanf("%d%d",&x,&y),unionn(1,x,y);
// 	for(re int i=1,x,y;i<=m[1];++i)scanf("%d%d",&x,&y),unionn(1,x,y);
// 	re int ans=0;vector<pair<int,int> >Ans;//vector<pair<int,int> >q;
// 	re int cnt1=0,cnt2=0,T=0;
// 	for(re int i=1;i<=n;++i)if(find(0,i)==i)++cnt1;
// 	for(re int i=1;i<=n;++i)if(find(1,i)==i)++cnt2;
// 	for(re int i=1;i<=n;++i){
// 		for(re int j=i+1;j<=n;++j){
// 			if(Check(0,i,j)&&Check(1,i,j)){
// 				unionn(0,i,j),unionn(1,i,j),++ans,Ans.push_back(make_pair(i,j)),--cnt1,--cnt2;
// 				if(cnt1==1||cnt2==1)break;
// 			}
// 			++T;
// 			if(T>=5e7)break;
// 		}
// 		if(cnt1==1||cnt2==1)break;
// 		if(T>=5e7)break;
// 	}
// //	printf("%d\n",ans);
// 	vector<int>q;
// //	for(re int i=1;i<=n;++i)if(find(0,i)==i)q.push_back(i),printf("%d ",i);
// //	for(re int i=1;i<q.size();++i)++ans,Ans.push_back(make_pair(q[0],q[i]));
// //	for(re int i=0;i<q.size();++i)for(re int j=i+1;j<q.size();++j)if(Check(1,q[i],q[j]))++ans,Ans.push_back(make_pair(q[i],q[j])),unionn(0,q[i],q[j]),unionn(1,q[i],q[j]);
// 	printf("%d\n",ans);for(re int i=0;i<ans;++i)printf("%d %d\n",Ans[i].first,Ans[i].second);
// }
// #include<bits/stdc++.h>
// // #define fastcall __attribute__((optimize("-O3")))
// // #pragma GCC optimize(1)
// // #pragma GCC optimize(2)
// // #pragma GCC optimize(3)
// // #pragma GCC optimize("Ofast")
// // #pragma GCC optimize("inline")
// // #pragma GCC optimize("-fgcse")
// // #pragma GCC optimize("-fgcse-lm")
// // #pragma GCC optimize("-fipa-sra")
// // #pragma GCC optimize("-ftree-pre")
// // #pragma GCC optimize("-ftree-vrp")
// // #pragma GCC optimize("-fpeephole2")
// // #pragma GCC optimize("-ffast-math")
// // #pragma GCC optimize("-fsched-spec")
// // #pragma GCC optimize("unroll-loops")
// // #pragma GCC optimize("-falign-jumps")
// // #pragma GCC optimize("-falign-loops")
// // #pragma GCC optimize("-falign-labels")
// // #pragma GCC optimize("-fdevirtualize")
// // #pragma GCC optimize("-fcaller-saves")
// // #pragma GCC optimize("-fcrossjumping")
// // #pragma GCC optimize("-fthread-jumps")
// // #pragma GCC optimize("-funroll-loops")
// // #pragma GCC optimize("-fwhole-program")
// // #pragma GCC optimize("-freorder-blocks")
// // #pragma GCC optimize("-fschedule-insns")
// // #pragma GCC optimize("inline-functions")
// // #pragma GCC optimize("-ftree-tail-merge")
// // #pragma GCC optimize("-fschedule-insns2")
// // #pragma GCC optimize("-fstrict-aliasing")
// // #pragma GCC optimize("-fstrict-overflow")
// // #pragma GCC optimize("-falign-functions")
// // #pragma GCC optimize("-fcse-skip-blocks")
// // #pragma GCC optimize("-fcse-follow-jumps")
// // #pragma GCC optimize("-fsched-interblock")
// // #pragma GCC optimize("-fpartial-inlining")
// // #pragma GCC optimize("no-stack-protector")
// // #pragma GCC optimize("-freorder-functions")
// // #pragma GCC optimize("-findirect-inlining")
// // #pragma GCC optimize("-fhoist-adjacent-loads")
// // #pragma GCC optimize("-frerun-cse-after-loop")
// // #pragma GCC optimize("inline-small-functions")
// // #pragma GCC optimize("-finline-small-functions")
// // #pragma GCC optimize("-ftree-switch-conversion")
// // #pragma GCC optimize("-foptimize-sibling-calls")
// // #pragma GCC optimize("-fexpensive-optimizations")
// // #pragma GCC optimize("-funsafe-loop-optimizations")
// // #pragma GCC optimize("inline-functions-called-once")
// // #pragma GCC optimize("-fdelete-null-pointer-checks")
// // #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #define db double
// #define il inline
// #define iL (1<<20)
// #define re register
// #define ll long long
// #define ui unsigned int
// #define ull unsigned long long
// #define TEM template<class T>il void
// #define Write(x,LC) write((x)),*iter++=LC
// #define Writeneg(x,LC) writeneg((x)),*iter++=LC
// #define flush() fwrite(Out,1,iter-Out,stdout),iter=Out
// #define gc() ((iS==iT)?(iT=(iS=ibuf)+fread(ibuf,1,iL,stdin),(iS==iT)?EOF:*iS++):*iS++)
// using namespace std;
// namespace IO{
// 	char ibuf[iL],*iS=ibuf+iL,*iT=ibuf+iL,Out[iL],*iter=Out;
// 	TEM Readneg(re T &x){re char c;re bool f;for(f=false,c=getchar();!isdigit(c);f|=c=='-',c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());if(f)x=~x+1;}
// 	TEM readneg(re T &x){re char c;re bool f;for(f=false,c=gc();!isdigit(c);f|=c=='-',c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());if(f)x=~x+1;}
// 	TEM writeneg(re T x){if(x<0)*iter++='-',x=~x+1;re T c[35],l;for(l=0;!l || x;c[l]=x%10,++l,x/=10);for(;l;--l,*iter++=c[l]+'0');flush();}
// 	TEM Read(re T &x){re char c;for(c=getchar();!isdigit(c);c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());}
// 	TEM read(re T &x){re char c;for(c=gc();!isdigit(c);c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());}
// 	TEM write(re T x){re T c[35],l;for(l=0;!l||x;c[l++]=x%10,x/=10);for(;l;*iter++=c[--l]+'0');flush();}
// }
// using namespace IO;
// //#define MAXN 55
// //#define MAXM 100005
// //#define mod 998244353
// //int pri[MAXM],cnt;bool vis[MAXM];
// //int n,m,l[MAXN],r[MAXN];ll mu[MAXM],f[MAXN][MAXM];
// //il ll Solve(int x){
// //	re ll ans=0;
// //	for(re int i=1;i*x<=m;++i)ans+=f[n][i],ans%=mod;
// //	printf("%d %lld\n",x,ans);
// //	return ans;
// //}

// //int main(){
// //	freopen("1.txt","r",stdin),freopen("2.txt","w",stdout);
// //	mu[1]=1;
// //	for(re int i=2;i<MAXM;++i){
// //		if(!vis[i])pri[cnt++]=i,mu[i]=-1;
// //		for(re int j=0;j<cnt&&i*pri[j]<MAXM;++j){
// //			vis[i*pri[j]]=true;
// //			if(!(i%pri[j]))break;
// //			mu[i*pri[j]]=-mu[i];
// //		}
// //	}
// //	scanf("%d%d",&n,&m);
// //	for(re int i=1;i<=n;++i)scanf("%d%d",&l[i],&r[i]);
// //	f[0][0]=1;
// //	for(re int i=1;i<=n;++i){
// //		for(re int j=l[i];j<=r[i];++j){
// //			for(re int k=m;k>=j;--k){
// //				f[i][k]+=f[i-1][k-j],f[i][k]%=mod;
// //			}
// //		}
// //	}
// //	re ll sum=0;
// //	for(re int i=1;i<=m;++i)printf("%lld\n",f[n][i]);
// //	for(re int i=1;i<=m;++i)sum+=f[n][i];printf("sum %lld\n",sum);
// //	re ll ans=0;
// ////	for(re int i=1;i<=m;++i)printf("%d ",mu[i]);printf("\n");
// //	for(re int i=1;i<=m;++i)if(mu[i])ans+=1ll*mu[i]*Solve(i),ans%=mod;
// //	printf("%lld",(ans+mod)%mod);
// //}
// #define MAXN 100005
// int n,m[2],fa[2][MAXN];
// int find(int id,int x){return fa[id][x]^x?fa[id][x]=find(id,fa[id][x]):x;}
// il bool Check(int id,int x,int y){return find(id,x)^find(id,y);}
// il void unionn(int id,int x,int y){x=find(id,x),y=find(id,y);if(x^y)fa[id][y]=fa[id][x];}
// int main(){
// 	freopen("1.txt","r",stdin),freopen("2.txt","w",stdout);
// 	scanf("%d%d%d",&n,&m[0],&m[1]);
// 	for(re int i=1;i<=n;++i)fa[0][i]=fa[1][i]=i;
// 	for(re int i=1,x,y;i<=m[0];++i)scanf("%d%d",&x,&y),unionn(0,x,y);
// //	for(re int i=1,x,y;i<=m[1];++i)scanf("%d%d",&x,&y),unionn(1,x,y);
// 	for(re int i=1,x,y;i<=m[1];++i)scanf("%d%d",&x,&y),unionn(1,x,y);
// 	re int ans=0;vector<pair<int,int> >Ans;//vector<pair<int,int> >q;
// 	re int cnt1=0,cnt2=0,T=0;
// 	for(re int i=1;i<=n;++i)if(find(0,i)==i)++cnt1;
// 	for(re int i=1;i<=n;++i)if(find(1,i)==i)++cnt2;
// 	for(re int i=1;i<=n;++i){
// 		for(re int j=i+1;j<=n;++j){
// 			if(Check(0,i,j)&&Check(1,i,j)){
// 				unionn(0,i,j),unionn(1,i,j),++ans,Ans.push_back(make_pair(i,j)),--cnt1,--cnt2;
// 				if(cnt1==1||cnt2==1)break;
// 			}
// 			++T;
// 			if(T>=5e7)break;
// 		}
// 		if(cnt1==1||cnt2==1)break;
// 		if(T>=5e7)break;
// 	}
// //	printf("%d\n",ans);
// 	vector<int>q;
// //	for(re int i=1;i<=n;++i)if(find(0,i)==i)q.push_back(i),printf("%d ",i);
// //	for(re int i=1;i<q.size();++i)++ans,Ans.push_back(make_pair(q[0],q[i]));
// //	for(re int i=0;i<q.size();++i)for(re int j=i+1;j<q.size();++j)if(Check(1,q[i],q[j]))++ans,Ans.push_back(make_pair(q[i],q[j])),unionn(0,q[i],q[j]),unionn(1,q[i],q[j]);
// 	printf("%d\n",ans);for(re int i=0;i<ans;++i)printf("%d %d\n",Ans[i].first,Ans[i].second);
// }
// ////#include<tr1/unordered_map>
// ////using namespace std::tr1;
// #include<bits/stdc++.h>
// // #define fastcall __attribute__((optimize("-O3")))
// // #pragma GCC optimize(1)
// // #pragma GCC optimize(2)
// // #pragma GCC optimize(3)
// // #pragma GCC optimize("Ofast")
// // #pragma GCC optimize("inline")
// // #pragma GCC optimize("-fgcse")
// // #pragma GCC optimize("-fgcse-lm")
// // #pragma GCC optimize("-fipa-sra")
// // #pragma GCC optimize("-ftree-pre")
// // #pragma GCC optimize("-ftree-vrp")
// // #pragma GCC optimize("-fpeephole2")
// // #pragma GCC optimize("-ffast-math")
// // #pragma GCC optimize("-fsched-spec")
// // #pragma GCC optimize("unroll-loops")
// // #pragma GCC optimize("-falign-jumps")
// // #pragma GCC optimize("-falign-loops")
// // #pragma GCC optimize("-falign-labels")
// // #pragma GCC optimize("-fdevirtualize")
// // #pragma GCC optimize("-fcaller-saves")
// // #pragma GCC optimize("-fcrossjumping")
// // #pragma GCC optimize("-fthread-jumps")
// // #pragma GCC optimize("-funroll-loops")
// // #pragma GCC optimize("-fwhole-program")
// // #pragma GCC optimize("-freorder-blocks")
// // #pragma GCC optimize("-fschedule-insns")
// // #pragma GCC optimize("inline-functions")
// // #pragma GCC optimize("-ftree-tail-merge")
// // #pragma GCC optimize("-fschedule-insns2")
// // #pragma GCC optimize("-fstrict-aliasing")
// // #pragma GCC optimize("-fstrict-overflow")
// // #pragma GCC optimize("-falign-functions")
// // #pragma GCC optimize("-fcse-skip-blocks")
// // #pragma GCC optimize("-fcse-follow-jumps")
// // #pragma GCC optimize("-fsched-interblock")
// // #pragma GCC optimize("-fpartial-inlining")
// // #pragma GCC optimize("no-stack-protector")
// // #pragma GCC optimize("-freorder-functions")
// // #pragma GCC optimize("-findirect-inlining")
// // #pragma GCC optimize("-fhoist-adjacent-loads")
// // #pragma GCC optimize("-frerun-cse-after-loop")
// // #pragma GCC optimize("inline-small-functions")
// // #pragma GCC optimize("-finline-small-functions")
// // #pragma GCC optimize("-ftree-switch-conversion")
// // #pragma GCC optimize("-foptimize-sibling-calls")
// // #pragma GCC optimize("-fexpensive-optimizations")
// // #pragma GCC optimize("-funsafe-loop-optimizations")
// // #pragma GCC optimize("inline-functions-called-once")
// // #pragma GCC optimize("-fdelete-null-pointer-checks")
// // #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #define db double
// #define il inline
// #define re register
// #define ldb long db
// #define ll long long
// #define ui unsigned int
// #define ull unsigned ll
// #define fi first
// #define se second
// #define pll pair<ll,ll>
// #define pil pair<int,ll>
// #define pli pair<ll,int>
// #define pii pair<int,int>
// #define MP(x,y) make_pair(x,y)
// #define lowbit(x) ((x)&(~(x)+1))
// #define iL (1<<20)
// #define TEM template<class T>il void
// #define Write(x,LC) write((x)),*iter++=LC
// #define Writeneg(x,LC) writeneg((x)),*iter++=LC
// #define flush() fwrite(Out,1,iter-Out,stdout),iter=Out
// #define gc() ((iS==iT)?(iT=(iS=ibuf)+fread(ibuf,1,iL,stdin),(iS==iT)?EOF:*iS++):*iS++)
// using namespace std;
// namespace IO{
//   char ibuf[iL],*iS=ibuf+iL,*iT=ibuf+iL,Out[iL],*iter=Out;
//   TEM Readneg(re T &x){re char c;re bool f;for(f=false,c=getchar();!isdigit(c);f|=c=='-',c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());if(f)x=~x+1;}
//   TEM readneg(re T &x){re char c;re bool f;for(f=false,c=gc();!isdigit(c);f|=c=='-',c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());if(f)x=~x+1;}
//   TEM writeneg(re T x){if(x<0)*iter++='-',x=~x+1;re T c[35],l;for(l=0;!l || x;c[l]=x%10,++l,x/=10);for(;l;--l,*iter++=c[l]+'0');flush();}
//   TEM Read(re T &x){re char c;for(c=getchar();!isdigit(c);c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());}
//   TEM read(re T &x){re char c;for(c=gc();!isdigit(c);c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());}
//   TEM write(re T x){re T c[35],l;for(l=0;!l||x;c[l++]=x%10,x/=10);for(;l;*iter++=c[--l]+'0');flush();}
// }
// using namespace IO;
// #define MAXL 20
// #define MAXB 405
// #define MAXA 500001
// // #define MAXA 50001
// #define MAXN 1000005
// #define MAXW 5005
// #define MAXC 100005
// #define MAXM 105
// #define MAXQ 500005
// #define MAXK 500005
// #define MAXS 500005
// #define MAXT 500005
// #define mod 998244353
// #define inv2 499122177
// #define BS 1919810
// #define mod1 1000000007
// #define mod2 1000000009
// #define begT 114514
// #define endT 1e-10
// #define chgT 0.9260871
// int N,M,n,m,q;
// struct Node{
//   int val,x;
//   il bool operator<(const Node&tmp)const{return x<tmp.x;}
// }a[MAXN],qr[MAXN];
// struct RNM{
//   int x,y,v;
//   il bool operator<(const RNM&tmp)const{return v<tmp.v;}
// }b[MAXN];
// int fa[MAXN],sz[MAXN];ll ans,Ans[MAXN];
// int Find(int x){return x^fa[x]?fa[x]=Find(fa[x]):x;}
// void Union(int x,int y){
//   x=Find(x),y=Find(y);if(x==y)return;ans-=1ll*sz[x]*a[x].x;
//   fa[x]=y,ans+=1ll*sz[x]*a[y].x,sz[y]+=sz[x];
// }
// int stk[MAXN],top;
// il void WORK(){
//   read(N),read(M),read(q);
//   for(re int i=1,x;i<=N;++i)read(x),a[++n]=Node{1,x};
//   for(re int i=1,x;i<=M;++i)read(x),a[++n]=Node{0,x};
//   for(re int i=1,x;i<=q;++i)read(x),qr[i]=Node{i,x};
//   sort(a+1,a+1+n),sort(qr+1,qr+1+q);
//   for(re int i=1;i<=n;++i)fa[i]=i,sz[i]=a[i].val,ans+=1ll*sz[i]*a[i].x;
//   for(re int i=1,lst=0;i<=n;++i){
//     if(!a[i].val){
//       if(lst)b[++m]=RNM{lst,i,a[i].x-a[lst].x};
//       for(;top;b[++m]=RNM{stk[top],i,a[i].x-a[stk[top]].x},--top);
//       lst=i;
//     }
//     else stk[++top]=i;
//   }
//   sort(b+1,b+1+m);
//   for(re int i=1;i<=n;++i)printf("%d %d\n",a[i].val,a[i].x);printf("\n");
//   for(re int i=1;i<=m;++i)printf("%d %d %d\n",b[i].x,b[i].y,b[i].v);printf("\n");
//   for(re int i=1,t=1;i<=q;++i){
//     for(;t<=m&&b[t].v<=qr[i].x;Union(b[t].x,b[t].y),++t);
//     Ans[qr[i].val]=ans;
//   }
//   for(re int i=1;i<=q;++i)Write(Ans[i],'\n');
// }
// int main(){
//   freopen("1.txt","r",stdin),freopen("2.txt","w",stdout);
//   re int T=1;
//   // scanf("%d",&T);
//   for(re int i=0;i<T;++i)WORK();
//   return 0;
// }

////#include<tr1/unordered_map>
////using namespace std::tr1;
#include<bits/stdc++.h>
// #define fastcall __attribute__((optimize("-O3")))
// #pragma GCC optimize(1)
// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC optimize("-falign-jumps")
// #pragma GCC optimize("-falign-loops")
// #pragma GCC optimize("-falign-labels")
// #pragma GCC optimize("-fdevirtualize")
// #pragma GCC optimize("-fcaller-saves")
// #pragma GCC optimize("-fcrossjumping")
// #pragma GCC optimize("-fthread-jumps")
// #pragma GCC optimize("-funroll-loops")
// #pragma GCC optimize("-fwhole-program")
// #pragma GCC optimize("-freorder-blocks")
// #pragma GCC optimize("-fschedule-insns")
// #pragma GCC optimize("inline-functions")
// #pragma GCC optimize("-ftree-tail-merge")
// #pragma GCC optimize("-fschedule-insns2")
// #pragma GCC optimize("-fstrict-aliasing")
// #pragma GCC optimize("-fstrict-overflow")
// #pragma GCC optimize("-falign-functions")
// #pragma GCC optimize("-fcse-skip-blocks")
// #pragma GCC optimize("-fcse-follow-jumps")
// #pragma GCC optimize("-fsched-interblock")
// #pragma GCC optimize("-fpartial-inlining")
// #pragma GCC optimize("no-stack-protector")
// #pragma GCC optimize("-freorder-functions")
// #pragma GCC optimize("-findirect-inlining")
// #pragma GCC optimize("-fhoist-adjacent-loads")
// #pragma GCC optimize("-frerun-cse-after-loop")
// #pragma GCC optimize("inline-small-functions")
// #pragma GCC optimize("-finline-small-functions")
// #pragma GCC optimize("-ftree-switch-conversion")
// #pragma GCC optimize("-foptimize-sibling-calls")
// #pragma GCC optimize("-fexpensive-optimizations")
// #pragma GCC optimize("-funsafe-loop-optimizations")
// #pragma GCC optimize("inline-functions-called-once")
// #pragma GCC optimize("-fdelete-null-pointer-checks")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define db double
#define il inline
#define re register
#define ldb long db
#define ll long long
// #define ll __int128
#define ui unsigned int
#define ull unsigned ll
#define fi first
#define se second
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pii pair<int,int>
#define MP(x,y) make_pair(x,y)
#define lowbit(x) ((x)&(~(x)+1))
#define iL (1<<20)
#define TEM template<class T>il void
#define Write(x,LC) write((x)),*iter++=LC
#define Writeneg(x,LC) writeneg((x)),*iter++=LC
#define flush() fwrite(Out,1,iter-Out,stdout),iter=Out
#define gc() ((iS==iT)?(iT=(iS=ibuf)+fread(ibuf,1,iL,stdin),(iS==iT)?EOF:*iS++):*iS++)
using namespace std;
namespace IO{
  char ibuf[iL],*iS=ibuf+iL,*iT=ibuf+iL,Out[iL],*iter=Out;
  TEM Readneg(re T &x){re char c;re bool f;for(f=false,c=getchar();!isdigit(c);f|=c=='-',c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());if(f)x=~x+1;}
  TEM readneg(re T &x){re char c;re bool f;for(f=false,c=gc();!isdigit(c);f|=c=='-',c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());if(f)x=~x+1;}
  TEM writeneg(re T x){if(x<0)*iter++='-',x=~x+1;re T c[35],l;for(l=0;!l || x;c[l]=x%10,++l,x/=10);for(;l;--l,*iter++=c[l]+'0');flush();}
  TEM Read(re T &x){re char c;for(c=getchar();!isdigit(c);c=getchar());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=getchar());}
  TEM read(re T &x){re char c;for(c=gc();!isdigit(c);c=gc());for(x=0;isdigit(c);x=(x<<1)+(x<<3)+(c^48),c=gc());}
  TEM write(re T x){re T c[35],l;for(l=0;!l||x;c[l++]=x%10,x/=10);for(;l;*iter++=c[--l]+'0');flush();}
}
using namespace IO;
#define MAXL 20
#define MAXB 405
#define MAXA 500001
// #define MAXA 50001
#define MAXN 500005
#define MAXW 100005
#define MAXC 100005
#define MAXM 805
#define MAXQ 500005
#define MAXK 500005
#define MAXS 500005
#define MAXT 500005
#define mod 998244353
#define inv2 499122177
#define BS 1919810
#define mod1 1000000007
#define mod2 1000000009
#define begT 114514
#define endT 1e-10
#define chgT 0.9260871
// il void WORK(){
// }
int T;
int n,m,a[MAXN],fa[MAXN];
pii q[MAXN];int id[MAXN];
int pre[MAXN],lst[MAXN];
vector<int>Q[MAXN];
int Find(int x){return x^fa[x]?fa[x]=Find(fa[x]):x;}
il void Union(int x,int y){
  x=Find(x),y=Find(y);
  if(x^y)fa[y]=x;
}
il void WORK(){
  read(T);
  for(re int i=1,op,x,y;i<=T;++i){
    read(op),read(x);
    if(op==1)a[++n]=x,Q[x].emplace_back(n);
    else read(y),q[++m]=MP(x,y),id[m]=n;
  }
  for(re int i=1;i<=m;++i)fa[i]=i;
  for(re int i=m;i>0;--i){
    if(pre[q[i].se])Union(pre[q[i].se],i);
    pre[q[i].fi]=i;
  }
  for(re int k=1;k<=m;++k){
    int x=Find(k),t=q[k].fi;
    // cerr<<t<<" "<<Q[t].size()<<endl;
    for(re int i=lst[t];i<Q[t].size();++i){if(Q[t][i]>id[k])break;++lst[t],a[Q[t][i]]=q[x].se;}
    // printf("%d\n",t);
  }
  for(re int i=1;i<=n;++i)Write(a[i],' ');
}
int main(){
  re int T=1;
  // scanf("%d",&T);
  // Read(T);
  // cin>>T;
  // read(T);
  for(re int i=0;i<T;++i)WORK();
  return 0;
}