#include<bits/stdc++.h>

using namespace std;

#define ll long long int

#define ull unsigned long long int

#define pb push_back

#define vi vector<int>

#define vll vector<ll>

#define vs vector<string>

#define vull vector<ull>

#define all(v) v.begin(),v.end()

#define mp make_pair

#define bitcount(x) __builtin_popcountll(x)

//min_arr(v) min_element(v,v+n);

#define dulo 1000000007

#define charcount(s,c) count(s.begin(), s.end(), c)

#define each(a,b) memset(a,b,sizeof a) //for b=0/-1, all pos,s for multidim arr too;

#define tofsi(s,c,t) memset(s,c,t) // for char s[n],first t;

#define tofs(s,pos,c,t) fill_n(s.begin()+pos, t, c);



ll power(ll x, ll y){

    ll temp;

    if( y == 0)

       return 1;

    temp = power(x, y/2)%dulo;       

    if (y%2 == 0)

        return (temp*temp)%dulo;

    else

    {

        if(y > 0)

            return (((x*temp)%dulo)*temp)%dulo;

        else

            return (temp*temp)/x%dulo;

    }

}

long long int mul_inv(long long int n,long long int p,long long int m){

	if(p==1){

		return n;

	}

	else if(p%2==0){

		long long int t= mul_inv(n,p/2,m);

		return ((t)*(t))%m;

	}

	else{	

		long long int t= mul_inv(n,p/2,m);

		return ((((n%m)*t)%m)*t)%m;

	}

}

bool isprime(ll n){

	if(n==2){

		return true;

	}

	if(n%2==0){

		return false; 

	}

	for(ll i=3;i<=sqrt(n);i+=2){

		if(n%i==0){

			return false;

		}

	}

	return true;

}

int h1,h2,h3,p1,p2,p3;

ll r;

ll ra=0,rb=0,rc=0;

int c1=0,c2=0,c3=0;

int can(ll a){

	ll x,y,z;

	if(a*p1*c1<=ra){

		x=0;

	}

	else{

		x=a*p1*c1-ra;

	}

	if(a*p2*c2<=rb){

		y=0;

	}

	else{

		y=a*p2*c2-rb;

	}

	if(a*p3*c3<=rc){

		z=0;

	}

	else{

		z=a*p3*c3-rc;

	}

	if(x+y+z<=r){

		return 1;

	}

	else{

		return 0;

	}

}

int dig(ll a){

	int ans=0;

	while(a){

		a/=10;

		ans++;

	}

	return ans;

}

int main(){

	

	/*freopen("cc.in","r",stdin);

    freopen("cc.out","w",stdout);

    */

	/*

	float ans;

	std::cout << std::fixed;

    std::cout << std::setprecision(9);

    std::cout << ans;

    */

    ll w,m,k;

    cin>>w>>m>>k;

    ll ans=0;

    int d=0;

    ll p=m;

    while(p){

    	p/=10;

    	d++;

	}

	ll cur=0;

	ll l=1;

	for(int i=1;i<=d;i++){

		cur+=9*l;

		l*=10;

	}

	//cout<<cur<<" "<<d<<" "<<m<<endl;

	

	while((dig(cur-m+1)+dig(d)+dig(k)-3<=dig(w))&&w-((cur-m+1)*d*k)>=0){

		w-=((cur-m+1)*d*k);

		ans+=cur-m+1;

		m=cur+1;

		cur*=10;

		cur+=9;

		d++;

	}

	ans+=w/(d*k);

	cout<<ans;

    return 0;

}