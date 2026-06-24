#include <bits/stdc++.h> 
#define pb push_back 
#define gc getchar 
#define mp make_pair
#define pii pair<int,int> 
#define pll pair<lli,lli>
#define vi vector<int>
#define vc vector<char>
#define pdd pair<double,double>
#define rep(i,n) for(lli i=0;i<n;i++)
#define repi(i,a,b) for(lli i=a;i<=b;i++)
#define repd(i,a,b) for(lli i=a;i>=b;i--)
#define vvi vector<vector<int> >
#define vvli vector<vector<long long int> >
#define vli vector<long long int> 
#define vpli vector<pair<lli,lli> >  
#define pq priority_queue 
#define lli long long int
#define li long int
#define ff first
#define len length
#define ss second
#define take(n,inp) rep(i,n){int x;cin>>x;inp.pb(x);}
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define M 1000000007
#define PI 3.14159265358979323
using namespace std;
     /*ios_base::sync_with_stdio(false);
         cin.tie(NULL);*/
template <typename T>
void printvec(vector<T>& vec){
   rep(i,vec.size()){
       cout<<vec[i]<<" ";
   }
   cout<<endl;
}


int main() {
	ios_base::sync_with_stdio(false);

	lli n,k;
	cin>>n>>k;

	string s;
	cin>>s;

	string p;

	lli a=0;
	lli b=0;
	lli x = k/2;

	rep(i,s.len())
	{
		if(s[i]=='(')
		{
			if(a<x)
			{
				p.pb('(');
					a++;
			}
		}
		else
		{
			if(b<x)
			{
				p.pb(')');
				b++;
			}
		}



	}





	cout<<p<<"\n";







}