#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <time.h>
#include <string.h>
#include <queue>
#include <stack>
#define pb push_back
using namespace std;
typedef long long int ll;
ll mod=1e9+7;
ll exp(ll t,ll x){if(x==0) return 1;if(x==1) return t;if(x%2==1) return (t*exp((t*t),x/2));if(x%2==0) return exp((t*t),x/2);} 
ll gcd(ll x,ll y){return x%y==0?y:gcd(y,x%y);}
ll lcm(ll x,ll y){return x*(y/gcd(x,y));}
ll bsum(ll u,ll b){return u<b?u:bsum(u/b,b)+u%b;}
ll prival(ll u,ll p){int cn=0;while(u%p==0){cn++;u=u/p;}return cn;}
bool isprime(ll x){for(ll i=2;i*i<=x;i++){if(x%i==0){return false;}}return true;}
void YAY(void){cout<<"YES"<<endl;}
void NAY(void){cout<<"NO"<<endl;}
int n, T;
int t[222222];
int cnt[222222];
//int tree[844444]; // T-1 �̸� ~T-n �̸� 
int ans, cur;

int main(void)
{
	cin>>n>>T;
	int i, j;
	for(i=1 ; i<=n ; i++)
	{
		scanf("%d",&t[i]);
		t[i]=max(t[i],i);
		t[i]-=i;
	}
	for(i=1 ; i<=n ; i++)
	{
		if(t[i]<T-i)
		{
			cur++;	
		}
		cur-=cnt[i]; // T-i cut
		if(1<=T-t[i] && T-t[i]<=n)
		{
			cnt[T-t[i]]++;	
		}
		ans=max(ans,cur);		
	}
	cout<<ans;
		
}