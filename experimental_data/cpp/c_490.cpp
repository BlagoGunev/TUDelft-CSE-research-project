#include <bits/stdc++.h>

#define ll long long int

#define fio ios_base::sync_with_stdio(0);cin.tie(0)

#define sd(t) scanf("%d",&t)

#define pd(t) printf("%d\n",t)

#define slld(t) scanf("%lld",&t)

#define plld(t) printf("%lld\n",t)

#define sc(t) scanf("%c",&t)

#define pb(x) push_back(x)

#define ii pair<int,int>

#define vi vector<int>

#define vvi vector<vi >

#define vii vector<ii >

#define vvii vector<vii >

#define clr(x) memset(x,0,sizeof(x))

#define rep(i,begin,end) for(__typeof(end) i=begin-(begin>end);i!=end-(begin>end);i+=1-2*(begin>end))

#define MOD 1000000007

#define MAX 1000005

#define EPS 1e-9

using namespace std;



string n;

int a,b,pre_mod=1;

int Lmod[MAX],Rmod[MAX];



void go()

{

	Lmod[0] = (n[0]-'0')%a;

	rep(i,1,n.size()-1) Lmod[i] = (Lmod[i-1]*10 + n[i]-'0')%a;



	Rmod[n.size()-2] = (n[n.size()-1]-'0')%b;

	rep(i,n.size()-2,0) 

	{

		pre_mod = (pre_mod*10)%b;

		Rmod[i] = ((n[i+1]-'0')*(pre_mod) + (Rmod[i+1]))%b;

	}

}





int main()

{

	fio;

	cin>>n>>a>>b;

	if(n.size()==1)

	{

		cout<<"NO\n";

		return 0;

	}

	go();

	rep(i,0,n.size()-1)

	{

		if(n[i+1]=='0') continue;

		if(Lmod[i]==0 && Rmod[i]==0)

		{

			cout<<"YES\n";

			cout<<n.substr(0,i+1)<<"\n"<<n.substr(i+1,n.size()-i-1)<<"\n";

			return 0;

		}

	}

	cout<<"NO\n";

	return 0;

}