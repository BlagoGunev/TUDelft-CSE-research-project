#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define fastread ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll cal_prod(ll num)
{
    ll prod=1;
    while(num>0){
        prod*=(num%10);
        num/=10;
    }
    return prod;
}
int main()
{
	ll n,dup,dig=10,temp_ans,ans=-1;
	cin>>n;
	dup=n;
	ans=cal_prod(n);
	while(dig<=n){
        dup = n-((n%dig)+1);
        temp_ans=cal_prod(dup);
        //cout<<temp_ans<<" "<<dup<<"\n";
        dig*=10;
        ans=max(ans,temp_ans);
	}
    cout<<ans;
	return 0;
}