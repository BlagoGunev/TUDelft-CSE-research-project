#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define mod 1000000007
#define pb push_back  
#define endl "\n"
#define fi first
#define se second 
#define ll long long
#define inf 9000000000000000000
#define PI 3.14159265359

int power(int a,int b,int m=mod)
{
     if(b==0)	return 1;
     if(b==1)	return a;
	 int res=power(a,b/2,m);
	 res=(res*res)%m;
     if(b&1)	res=(res*a)%m;
     return res;
}
int modinv(int a,int m=mod){ return power(a,m-2,m);}
int add(int a,int b,int m=mod){	int c=(a%m+b%m);	if(c>=m)	c-=m;	return c;}
int sub(int a,int b,int m=mod){	int c=(a%m-b%m);	if(c<0)		c+=m;	return c;}
int mul(int a,int b,int m=mod){	return (a*b)%m;}


int32_t main()
{
   IOS

   int t;
   cin>>t;
   
   while(t--)
   {
   	 int a,b,c,d;
   	 cin>>a>>b>>c>>d;
   	 
     cout<<max(a+b,c+d)<<endl;
   }
   
   

 
 
}