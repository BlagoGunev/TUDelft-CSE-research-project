#include<bits/stdc++.h>

#define int long long

using namespace std;

 

int M=(1e15);

int MOD=998244353;





int binexp(int a,int n)

{

	if(n==0) return 1;

 

	else

	{

		int z=binexp(a,n/2);

		int y=(z*z)%MOD;

 

		if(n&1) return (a*y)%MOD;

		else return y%MOD;

	}

}





signed main()

{



	ios::sync_with_stdio(0);

	cin.tie(0);

	cout.tie(0);





	int t;

	cin>>t;



	while(t--)

	{

		

		int n;

		cin>>n;



		int ca[n+1];

		int cb[n+1];

		for(int i=1;i<=n;i++) cin>>ca[i];

		for(int i=1;i<=n;i++) cin>>cb[i];





		int p[n+1];

		for(int i=1;i<=n;i++) p[ca[i]]=cb[i];



		int vis[n+1]={false};



		int odd=0;



		for(int i=1;i<=n;i++)

		{

			if(!vis[i])

			{

				int j=i;

				vis[j]=true;

				int c=1;

				

				while(p[j]!=i)

				{

					j=p[j];

					vis[j]=true;

					c++;

				}



				if(c&1) odd++;

			}

		}



		int ans=0;



		for(int i=(n+odd)/2+1;i<=n;i++) ans+=2*i;



		for(int i=1;i<=(n-odd)/2;i++) ans-=2*i;



		cout<<ans<<"\n";



	}



}