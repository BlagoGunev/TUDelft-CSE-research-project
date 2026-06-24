#include<bits/stdc++.h>
using namespace std;
int n,a,b,c,xs[4],ys[4];
long long t,ts[4];
string ans;
long long calc(long long x){
	return x*(x+1)/2;
}
bool check(int x,int y,int xs,int ys,long long ts){
	long long d1=abs(x-xs)+abs(y-ys);
	long long d2=abs(n-xs)+abs(n-ys);
	if(x<=xs&&y<=ys)return calc(d1)+calc(d2)<=ts;
	else if(x<=xs)return calc(d2)-calc(y-ys-1)+calc(d1)-calc(y-ys)<=ts;
	else if(y<=ys)return calc(d2)-calc(x-xs-1)+calc(d1)-calc(x-xs)<=ts;
	return calc(d2)-calc(d1-1)<=ts;
}
bool check(int x,int y){
	for(int i=0;i<4;i++)if(!check(x,y,xs[i],ys[i],ts[i]))return 0;
	return 1;
}
int main(){
	scanf("%d%lld%d%d%d",&n,&t,&a,&b,&c);
	for(int i=0;i<4;i++){
		xs[i]=a+(i/2)*(c-1);
		ys[i]=b+(i%2)*(c-1);
		ts[i]=t;
	}
	int x=1,y=1;
	while(!(x==n&&y==n)){
		if(x<n&&check(x+1,y))x++,ans+="R";
		else if(y<n&&check(x,y+1))y++,ans+="U";
		else return puts("Impossible"),0;
		for(int i=0;i<4;i++)ts[i]-=abs(x-xs[i])+abs(y-ys[i]);
	}
	cout<<ans;
}