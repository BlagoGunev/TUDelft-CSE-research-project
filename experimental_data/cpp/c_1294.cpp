#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
const int INF=0x3f3f3f3f;
typedef long long LL;
const int mod=1e9+7;
const int maxn=1e5+10;
using namespace std;
struct node{
	int x,num;
	node(){
		x=0;
		num=0;
	}
}p[105];
int cnt=0,num=0;
void fun(int n) 
{	
	if(n%2==0){
		p[++cnt].x=2;
		p[cnt].num=0;
		while(n%2==0){
			p[cnt].num++;
			num++;
			n/=2;
		}
	}
	for(int i=3;i<=sqrt(n);i+=2){
		if(n%i==0){
			p[++cnt].x=i;
			p[cnt].num=0;
			while(n%i==0){
				p[cnt].num++;
				num++;
				n/=i;
			}
		}
	}
	if(n!=1){
		p[++cnt].x=n;
		p[cnt].num=1;
		num++;
	}
}
int main()
{
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cnt=0,num=0;
		fun(n);		
		if(cnt>=3){
			cout<<"YES"<<endl;
			printf("%d %d %d\n",p[1].x,p[2].x,n/(p[1].x*p[2].x));
		}
		else if(cnt==2){
			if(num>3){
				cout<<"YES"<<endl;
				printf("%d %d %d\n",p[1].x,p[2].x,n/(p[1].x*p[2].x));
			}
			else cout<<"NO"<<endl;
		}
		else if(cnt==1){
			if(num<6) cout<<"NO"<<endl;
			else{
				cout<<"YES"<<endl;
				printf("%d %d %d\n",p[1].x,2*p[1].x,n/(2*p[1].x*p[1].x));
			}	
		}
	}	
	return 0;
}