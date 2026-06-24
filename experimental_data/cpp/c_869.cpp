#include<bits/stdc++.h>
#define ll long long int
#define N 5100
#define m 998244353
using namespace std;
ll fact[N];
void pre(){
	fact[0]=1;
	for(ll i=1;i<N;i++)
	fact[i]=(i*fact[i-1])%m;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y);
ll modInverse(ll b)
{
    ll x, y;
    ll g = gcdExtended(b, m, &x, &y);
    if (g != 1)
        return -1;

    return (x%m + m) % m;
}
ll modDivide(ll a, ll b)
{
    a = a % m;
    ll inv = modInverse(b);
    return  (inv * a) % m;
}
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    ll x1, y1; 
    ll gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
ll calculate(ll a,ll b){
    ll n=0,p,d;
	for(ll i=0;i<=a;i++){
	   p=(fact[a]*fact[b])%m;
	   d=(fact[b-i]*fact[a-i])%m;
	   d=(fact[i]*d)%m;
	   n=(n+modDivide(p,d))%m;}
	return n;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll a[3],ans;
	cin>>a[0]>>a[1]>>a[2];
	pre();
	sort(a,a+3);
	ans=(calculate(a[0],a[1])*calculate(a[1],a[2]))%m;
	ans=(ans*calculate(a[0],a[2]))%m;
	cout<<ans<<endl;
}