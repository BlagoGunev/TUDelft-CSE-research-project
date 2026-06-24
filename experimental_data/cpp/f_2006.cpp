#include<bits/stdc++.h>
using namespace std;using ll=long long;using ld=long double;using pii=pair<int,int>;
const int M=998244353,N=1e6+10;const ll inf=1e17;const double eps=1e-10;
ll poww(ll bs,ll x){ll res=1;for(;x;x>>=1,(bs*=bs)%=M)if(x&1)(res*=bs)%=M;return res;}
ll invv(ll bs){return poww(bs,M-2);}
int R_ots[N],C_ots[N];
int R_sto[N],C_sto[N];
struct S
{
	int n,m;ll res=0;
	vector<int>cR,cC;set<pii>xS;
	ll calc(int se)
	{
		vector<int>v{0};
		for(int x=n,y=0,sw=0,cc=0,ns;;)
		{
			if(!x||y==n){if(cc)v.push_back(cc);v.push_back(x+n-y);break;}
			if(cC[C_sto[y]]==x)ns=1,y++;else ns=0,x--;
			if(sw==ns)cc++;else v.push_back(cc),cc=1,sw=ns;
		}
		int len=v.size()-1;v.push_back(0);//0xxx^0 [0,len+1]
		ll Bas=1,f=0;for(int i=1;i<len;i++)for(int z=1;z<=v[i];z++)(Bas*=z)%=M;if(se==1)return Bas;
		for(int i=1;i<len;i++)
		{
			ll A=invv(v[i]);if(v[i]==1)(A*=(v[i-1]+1))%=M;
			ll B=invv(v[i+1]);if(i==len-1)B=1;
			if(v[i+1]==1&&i!=len-2)(B*=(v[i+2]+1))%=M;
			ll C=ll(v[i])*v[i+1]%M;ll D=A*B%M*C%M;(f+=D)%=M;
		}
		return Bas*f%M;
	}
	void opr(pii a)
	{
		if(xS.count(a))xS.erase(a),cR[a.first]--,cC[a.second]--;
		else xS.insert(a),cR[a.first]++,cC[a.second]++;
	}
	void sol_adj(vector<int>v)
	{
		for(int e=0;e<2;e++)for(int f=2;f<4;f++)
		{
			pii a={v[e],v[f]};opr(a);			
			if(jud()[0]==-1)(res+=calc(1))%=M;opr(a);
		}
	}
	void sol_ok(){res=calc(2);}
	pii p_ots(pii a){return {R_ots[a.first],C_ots[a.second]};}
	pii p_sto(pii a){return {R_sto[a.first],C_sto[a.second]};}
	vector<int>jud()
	{
		mdf();
		for(auto Ao:xS)
		{
			auto As=p_ots(Ao);auto[x,y]=As;
			if(x)
			{
				pii Bs={x-1,y},Bo=p_sto(Bs);
				if(!xS.count(Bo))
				{
					for(int i=0;i<n;i++)
					{
						pii Co=p_sto({x,i}),Do=p_sto({x-1,i});
						if(!xS.count(Co)&&xS.count(Do))
							return vector<int>{Ao.first,Do.first,Ao.second,Do.second};
					}
					exit(1);
				}
			}
			if(y)
			{
				pii Bs={x,y-1},Bo=p_sto(Bs);
				if(!xS.count(Bo))
				{
					for(int i=0;i<n;i++)
					{
						pii Co=p_sto({i,y}),Do=p_sto({i,y-1});
						if(!xS.count(Co)&&xS.count(Do))
							return vector<int>{Ao.first,Do.first,Ao.second,Do.second};
					}
					exit(1);
				}
			}
		}
		return vector<int>{-1};
	}
	void mdf()
	{
		sort(R_sto,R_sto+n,[&](int a,int b){return cR[a]>cR[b];});for(int i=0;i<n;i++)R_ots[R_sto[i]]=i;
		sort(C_sto,C_sto+n,[&](int a,int b){return cC[a]>cC[b];});for(int i=0;i<n;i++)C_ots[C_sto[i]]=i;
	}
	void ini()
	{
		cin>>n>>m;cR.resize(n,0);cC=cR;for(int i=0;i<n;i++)R_ots[i]=R_sto[i]=C_ots[i]=C_sto[i]=i;
		for(int i=1,x,y;i<=m;i++)cin>>x>>y,x--,y--,cR[x]++,cC[y]++,xS.insert({x,y});
		auto v=jud();if(v[0]==-1)sol_ok();else sol_adj(v);ll Inv=invv(n);(Inv*=Inv)%=M;cout<<res*Inv%M<<"\n";
	}
	void solve()
	{
		
	}
};
void precal(){}
int main()
{
	//freopen("1.in","r",stdin);
	//cout<<fixed<<setprecision(12);
	ios::sync_with_stdio(0);cin.tie(0);precal();
	int t=1;cin>>t;
	//clock_t a=clock();
	while(t--){S SS;SS.ini();SS.solve();}
	//cout<<"Time:"<<double(clock()-a)<<'\n';
}