#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef long long LL;
const int inf=1000000000;//1e9
int f[100];
int main(){
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		int cnt=0;
		while (x){
			if (x&1) cnt++;
			x/=2;
		}
		f[cnt]++;
	}
	LL ans =0;
	for (int i=0;i<100;i++)
	{
		ans+=1LL*f[i]*(f[i]-1)/2;
	}
	cout<<ans<<endl;
}