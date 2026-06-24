#include<map>

#include<vector>

#include<cstdio>

#include<cstring>

#include<iostream>



#define fi first

#define se second

#define nn 200010

#define Bas 500009ll

#define mk make_pair

#define ll long long

#define Mod 1000000007ll

using namespace std;



char str[nn];int n;

ll pow[nn],bas[nn];

map<pair<ll,int>,vector<int> > f[nn];



inline ll Hash(int l,int r) {

	if (r<l) return(0);

	return(bas[r]-bas[l-1]*pow[r-l+1]%Mod+Mod)%Mod;

}



inline void Solv()

{

	int ans=0;

	for (int i=1;i<=n;i++)

	f[1][mk(Hash(i,i),1)].push_back(i);

	

	for (int i=1;i<n;i++) if (f[i].size())

	{

		map<pair<ll,int>,vector<int> >::iterator it;

		for (it=f[i].begin();it!=f[i].end();it++)

		{

			vector<ll> del;

			int len=(it->fi).se;

			vector<int> lstpos=it->se;

			for (int j=0;j<lstpos.size()-1;j++) 

			del.push_back(Hash(lstpos[j]+len,lstpos[j+1]-1));

			

			for (int r=0,l=0;l<lstpos.size()-1;l=r)

			{

				for (r=l+1;r+1<lstpos.size()&&del[r]==del[l];r++);

				int len_=len+lstpos[r]-lstpos[l],i_=i+r-l;

				f[i_][mk(Hash(lstpos[l],lstpos[l]+len_-1),len_)].push_back(lstpos[l]);

			}

		}

		ans=i;

	}

	if (f[n].size()) ans=n;

	printf("%d\n",ans);

} 



int main()

{

	scanf("%d%s",&n,str+1);

	pow[0]=1;for (int i=1;i<=n;i++) pow[i]=pow[i-1]*Bas%Mod;

	for (int i=1;i<=n;i++) bas[i]=(bas[i-1]*Bas+str[i])%Mod;

	

	Solv();

}