#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
 #define mod 1000000007
 const int N=100005;
 const int inf=1e18;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin>>n;
	int a[4*n+1][2];
	int x2=-1,x1=51,y2=-1,y1=51;
	for(int x=0;x<4*n+1;x++){
		int xi,yi;
		cin>>xi>>yi;
		a[x][0]=xi;
		a[x][1]=yi;
		if(xi>x2){
			x2=xi;
		}
		if(xi<x1){
			x1=xi;
		}
		if(yi<y1){
			y1=yi;
		}
		if(yi>y2){
			y2=yi;
		}
	}
	int w1=0,w2=0,e1=0,e2=0;
	for(int i=0;i<4*n+1;i++){
		int x=a[i][0];
		int y=a[i][1];
		if(x==x1){
			
	
			w1++;
		}
		if(y==y1){
			e1++;
		}
		if(x==x2){
			w2++;
		}
		if(y==y2){
			e2++;
		}
	}
	if(w1<n){
		for(int i=0;i<4*n+1;i++){
			if(a[i][0]==x1){
				cout<<a[i][0]<<" "<<a[i][1];
				return 0;
			}
		}
	}
	if(w2<n){
		for(int i=0;i<4*n+1;i++){
			if(a[i][0]==x2){
				cout<<a[i][0]<<" "<<a[i][1];
				return 0;
			}
		}	
	}
	if(e1<n)
	{
	for(int i=0;i<4*n+1;i++){
			if(a[i][1]==y1){
				cout<<a[i][0]<<" "<<a[i][1];
				return 0;
			}
		}	
	}
if(e2<n){
		for(int i=0;i<4*n+1;i++){
			if(a[i][1]==y2){
				cout<<a[i][0]<<" "<<a[i][1];
				return 0;
			}
		}
}
for(int i=0;i<4*n+1;i++){
	int x=a[i][0];
	int y=a[i][1];
	if(x==x1||x==x2||y==y1||y==y2){
		
	}else{
		cout<<x<<" "<<y;
		return 0;
	}
}





	
	
return 0;	
}