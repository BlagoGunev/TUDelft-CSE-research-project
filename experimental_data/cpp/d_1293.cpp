#include<bits/stdc++.h>

using namespace std;
long long x[100],y[100],xs,ys,t,ax,ay,bx,by;
int main(){
cin>>x[0]>>y[0];
cin>>ax>>ay>>bx>>by;
cin>>xs>>ys>>t; 	int ans=0;	int z;
for(z=1;x[z-1]<=3*1e16&&y[z-1]<=3*1e16;z++){
x[z]=x[z-1]*ax+bx;
y[z]=y[z-1]*ay+by;	}
for(int i=0;i<z;i++){
for(int j=0;j<z;j++){
if(abs(xs-x[i])+abs(ys-y[i])+abs(x[i]-x[j])+abs(y[i]-y[j])<=t){
ans=max(abs(i-j)+1,ans);
}}}cout<<ans<<endl;}