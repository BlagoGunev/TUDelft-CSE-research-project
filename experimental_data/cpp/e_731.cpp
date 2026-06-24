#include<bits/stdc++.h>

#define rep(x,fr,to) for(int x=fr;x<=to;x++)

#define vep(x,fr,to) for(int x=fr;x>=to;x--)

#define g() getchar()

using namespace std;

int read(){int r=0,f=1,c=g();while(c<'0'||c>'9'){if(c=='-') f=-1;c=g();};while(c>='0'&&c<='9')r=r*10+c-'0',c=g();return r*f;}

int n;

int a[200005];

int main(){

	scanf("%d",&n);

	rep(i,1,n) a[i]=read()+a[i-1];

	int mx=a[n];

	vep(i,n-1,2) mx=max(a[i]=a[i]-mx,mx);

	cout<<mx<<endl;

	return 0;

}