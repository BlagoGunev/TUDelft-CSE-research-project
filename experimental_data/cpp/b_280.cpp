#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<string>
#include<queue>
#include<iomanip>
using namespace std;

typedef pair<int,int> pie;
#define PB push_back
#define X first
#define Y second

int n,a[1000*100+100],t,start,Max;

bool check(){
	for(int i=1;i<=n;i++)
		if(a[i]<t)
			return false;
	return true;		
}
bool mark[1000*100+100];

void calc(int x,int y){
	int tmax=0;
	if(a[x]!=0)
	for(int i=x+1;i<y;i++){
		tmax=max(tmax,a[i]);
		Max=max(Max,tmax^a[x]);	
	}
	tmax=0;
	if(a[y]!=0)
	for(int i=y-1;i>x;i--){
		tmax=max(tmax,a[i]);
		Max=max(Max,tmax^a[y]);
	}
}

int main(){
	ios_base::sync_with_stdio(false) ; 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(check()){
		for(int i=1;i<=n;i++)
			a[i]-=t;
		t=1;
		for(int i=1;i<=n;i++){
			while(a[i]>=2*t)
				t*=2;
		}
	}
	mark[0]=true;
	mark[n+1]=true;
	for(int i=1;i<=n;i++)
		if(a[i]>=t)
			mark[i]=true;
	for(int i=1;i<=n+1;i++)
		if(mark[i]){
			calc(start,i);
			start=i;
		}
	cout<<Max;	
}