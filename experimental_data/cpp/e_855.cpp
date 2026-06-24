#include<bits/stdc++.h>

#define MOD 1000000007
#define MAX 100005
#define ll long long
#define slld(t) scanf("%lld",&t)
#define sd(t) scanf("%d",&t)
#define ss(x) scanf("%s",x)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%lld\n",t)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mp(a,b) make_pair(a,b)
#define FF first
#define SS second
#define pb(x) push_back(x)
#define vi vector<int>
#define vpii vector<pii >
#define vll vector<ll>
#define clr(x) memset(x,0,sizeof(x))

#define FILEIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);

using namespace std;

ll power(ll a,ll b,ll m){
	ll x=1%m; a%=m;
	while(b){
		if((1&b)) x = x * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return x;
}

ll pre_table[80][11][11];
ll pre_table_lead[80][11];

int cnt[2049];
void pre(){
	clr(pre_table);
	for(int base=2;base<=10;base++) pre_table[0][base][0]=1;
	for(int num_digit=1;num_digit<80;num_digit++){
		for(int choices=2;choices<11;choices++){
			for(int num_odd=0;num_odd<=choices;num_odd++){
				if(num_odd>num_digit) break;
				pre_table[num_digit][choices][num_odd];
				// reduce 1 odd
				pre_table[num_digit][choices][num_odd]+=num_odd*pre_table[num_digit-1][choices][num_odd-1];
				// increase 1 odd
				pre_table[num_digit][choices][num_odd]+=(choices-num_odd)*pre_table[num_digit-1][choices][num_odd+1];
			}
		}
	}
	for(int i=0;i<2049;i++){
		cnt[i]=0;
		for(int j=0;j<20;j++) if(i&(1<<j)) cnt[i]++;
	}
	clr(pre_table_lead);
	for(int base=2;base<=10;base++) pre_table_lead[2][base]=base-1;
	for(int num_digit=3;num_digit<80;num_digit++){
		for(int base=2;base<11;base++){
			pre_table_lead[num_digit][base]=pre_table_lead[num_digit-1][base];
			pre_table_lead[num_digit][base]+=(base-1)*pre_table[num_digit-1][base][1];
		}
	}
	// cout<<pre_table_lead[3][2]<<endl;
}

vll vec;

ll solver(int ind,int b,int mask){
	if(ind==-1){
		if(mask) return 0;
		return 1;
	}
	// chota rakho
	ll ans = 0;
	
	bool flag=0;
	if(ind==vec.size()-1) flag=1;
	
	for(int i=0;i<vec[ind];i++){
		int num_odd = cnt[mask];
		
		if(mask&(1<<i)) num_odd--;
		else num_odd++;
		
		if(flag && i==0){
			ans += pre_table_lead[ind][b];
			continue;
		}
		
		ans += pre_table[ind][b][num_odd];
	}
	return ans+solver(ind-1,b,mask^(1<<vec[ind]));
}

ll solve(ll n,int b){
	if(!n) return 0;
	vec.clear();
	while(n){
		vec.pb(n%b);
		n/=b;
	}
	return solver(vec.size()-1,b,0);
}

int main(){
	pre();
	int q;sd(q);
	while(q--){
		int b;sd(b);
		ll l,r;
		slld(l);
		slld(r);
		// cout<<solve(r,b)<<endl;
		ll ans = solve(r,b) - solve(l-1,b);
		plld(ans);
	}
}