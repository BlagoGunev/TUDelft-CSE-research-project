#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;



//#define PI acos(-1.0)



#define vpii vector<pair<int,int>>

#define vi vector<int>

#define vll vector<long long>

#define ll long long

#define pii pair<int,int>

#define f first

#define s second

#define pb push_back

#define mp make_pair



void debug(){

	fflush(stdin);

	printf("Press any key to continue");

	getc(stdin);

	fflush(stdin);

}



ll pp(int x){

	if(x==0) return 1;

	if(x==1) return 10;

	ll ans = pp(x/2);

	ans = ans*ans;

	if(x&1) ans*=10;

	return ans;

}



ll pre[20];

ll l,r;



ll fun(ll x){

	if(x==0) return 0;

	if(x>=1 && x<=9) return x;

	ll t = x;

	int c = 0;

	vi a;

	while(t){

		c++;

		a.pb(t%10);

		t/=10;

	}

	ll ans = 0;

	for(int i =1 ; i<c;i++) ans+=pre[i];

	reverse(a.begin(),a.end());

	//printf("ans = %d\n",ans);

	//debug();

	ans = ans + max(0,a[0]-1)*pp(c-2);

	//printf("ans = %lld\n",ans);

	for(int i = 1 ; i<c -1 ; i++){

	//	printf("a[i] = %d pow = %d\n",a[i],c-2-i);

		ans = ans + a[i]*pp(c-2-i);

	//	printf("ans = %lld\n",ans);

	//	debug();

	}

	if(a[0] <= a[c-1]) ans++;

	//printf("final ans = %lld\n",ans);

	//debug();

	return ans;

}





int main()

{

	pre[1] = 9;

	pre[2] = 9;

	for(int i =3 ; i<=19;i++) pre[i] = pre[i-1]*10;

	scanf("%lld%lld",&l,&r);



	ll ans  = fun(r) - fun(l-1);

	printf("%lld\n",ans);



//	debug();

	return 0;

}