#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<fstream>
#include<set>
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define mst(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const double eps=1e-10;
const int maxn=100+9;
const double pi=3.14159265358979323846264338328;
const int inf=1<<29;
int main()
{
	ll r;
	cin>>r;
	if(r%2==0||r==1||r==3) cout<<"NO";
	else{
		cout<<1<<" "<<(r-1)/2-1;
	}
	return 0;
}