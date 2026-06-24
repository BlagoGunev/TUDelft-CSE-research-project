#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cstdio>
#include<list>
#include<sstream>
//#include<regex>
using namespace std;
typedef long long ll;
int INF=2147483647;
int inf=-2147483648;
#define read(x) scanf("%d",&x);
#define fo(i,n) for(int i=0;i<(n);i++)
#define me(a) memset(a,0,sizeof(a));
#define one(x) cout<<(x)<<endl;
#define two(a,b) cout<<(a)<<" "<<(b)<<endl;
#define three(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl;
#define four(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl;
//int dir[4][2]={-1,0,1,0,0,-1,0,1};
//int dir[8][2]={-1,0,1,0,0,-1,0,1,-1,-1,1,1,1,-1,-1,1};
//int dir[4][2]={-2,0,2,0,0,-2,0,2};
int a[1005];
int main()
{
	for(int i=0;i<6;i++){
		cin>>a[i];
	}
	cout<<(a[0]+a[1]+a[2])*(a[0]+a[1]+a[2])-(a[0]*a[0]+a[2]*a[2]+a[4]*a[4])<<endl;
	return 0;
}