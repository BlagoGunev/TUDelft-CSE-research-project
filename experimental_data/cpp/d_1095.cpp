#include<bits/stdc++.h>
using namespace std;
const int size = 2e5+10;
int a[size][3];
bool vis[size];
int n;
int ans[size];
bool flag = true;
template <typename T> inline void read(T &x){
   x=0;int f=1;char ch=getchar();
   for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
   for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
   x*=f;
}
int main(){
   read(n);
   for(register int i=1;i<=n;++i) read(a[i][1]),read(a[i][2]);
   
   ans[1]=1;  //使第一个人站1； 
   ans[2]=a[1][1];
   for(register int i=3;i<=n;++i){
   	  int x1,x2,x3,x4;int comm=0;
   	  x1=a[ans[i-2]][1],x2=a[ans[i-2]][2],x3=a[ans[i-1]][1],x4=a[ans[i-1]][2];
   	  if(x1==x3||x1==x4) comm=x1;
   	  if(x2==x3||x2==x4) comm=x2;
   	  if(!comm) flag=false;
	  ans[i]=comm; 
}
   ans[0]=ans[n];
   for(register int i=1;i<=n;++i){
   	  if(vis[ans[i]]) flag=false;//填了两次
   	  vis[ans[i]]=true;
	  if(ans[i]!=a[ans[(i+n-2)%n]][1]&&ans[i]!=a[ans[(i+n-2)%n]][2]) flag= false;
	  if(ans[i]!=a[ans[(i+n-1)%n]][1]&&ans[i]!=a[ans[(i+n-1)%n]][2]) flag= false;		  
   }
    if(flag) {
    	for(register int i=1;i<=n;++i) printf("%d ",ans[i]);
    	return 0;
    }
   //-----------------------------------------------------------------------------
   ans[2]=a[1][2];flag=true;
   memset(vis,false,sizeof(vis));
   for(register int i=3;i<=n;++i){
   	  int x1,x2,x3,x4;int comm=0;
   	  x1=a[ans[i-2]][1],x2=a[ans[i-2]][2],x3=a[ans[i-1]][1],x4=a[ans[i-1]][2];
   	  if(x1==x3||x1==x4) comm=x1;
   	  if(x2==x3||x2==x4) comm=x2;
   	  if(!comm) flag=false;
	  ans[i]=comm; 
}
   ans[0]=ans[n];
   for(register int i=1;i<=n;++i){
   	  if(vis[ans[i]]) flag=false;//填了两次
   	  vis[ans[i]]=true;
	  //cout<<flag<<endl;
	  //cout<<a[ans[(i+n-1)%n]][1]<<" "<<a[ans[(i+n-1)%n]][2]<<endl;
	  if(ans[i]!=a[ans[(i+n-2)%n]][1]&&ans[i]!=a[ans[(i+n-2)%n]][2]) flag= false;
	  if(ans[i]!=a[ans[(i+n-1)%n]][1]&&ans[i]!=a[ans[(i+n-1)%n]][2]) flag= false;	  
   }
    
    if(flag) {
    	for(register int i=1;i<=n;++i) printf("%d ",ans[i]);
    	return 0;
    }
}