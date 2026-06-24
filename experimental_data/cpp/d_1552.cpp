#include<bits/stdc++.h>

using namespace std;



const int N=1e5+5;

const int mod=1e9+7;

#define int long long

#define lson 2*p

#define rson 2*p+1

int flag=0;

int n,a[N];

void dfs(int step,int sum,int f)

{

	if(step>n)

	{

		//cout<<sum<<endl;

		if(sum==0&&f) flag=1;

		return ;

	}

	for(int i=-1;i<=1;i++)

	{

		dfs(step+1,sum+i*a[step],f|(i!=0));

	}

}



signed main()

{

	

	int t;

	cin>>t;

	while(t--)

	{

		cin>>n;

		for(int i=1;i<=n;i++) cin>>a[i];

		flag=0;

		dfs(1,0,0);

		if(flag) puts("YES");

		else puts("NO");

	}

}