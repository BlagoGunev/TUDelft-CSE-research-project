#include<bits/stdc++.h>

using namespace std;

#define N 1000010

int T,n,fa[N],E[N],A[N],B[N],F[N],ans[N];

signed main(){

	ios::sync_with_stdio(0);

	for(cin>>T;T--;){

		cin>>n;

		for(int i=1;i<=n;i++)

			E[i]=A[i]=B[i]=F[i]=ans[i]=0;

		for(int i=2;i<=n;i++)

			cin>>fa[i],(A[fa[i]])?B[fa[i]]=i:A[fa[i]]=i;

		for(int i=2;i<=n;i++)

			(i==4)?printf("%d\n",(fa[3]==fa[4])<<1):printf("%d\n",i&1);

		if(n==4&&fa[3]==fa[4]){

			puts("wbww");

			continue;

		}for(int i=n;i>1;i--)

			if(!F[i])E[fa[i]]++,F[fa[i]]=1;

		if(!F[1]){

			if(E[2]==2&&B[1]&&E[B[1]]==1){

				E[1]=E[B[1]]+1,

				E[B[1]]=0,F[B[1]]=0,

				F[1]=1,ans[1]=1;

			}else{

				E[1]=E[2]+1,E[2]=0,

				F[2]=0,F[1]=ans[1]=1;

				if(E[1]==3&&!B[1]){

					int ok=0;

					for(int i=2;i<=n;i++)

						if(E[i]==2) ok=1;

					if(!ok){

						int x=0,y=0;

						if(A[A[2]])x=A[2],y=A[A[2]];

						if(B[A[2]])x=A[2],y=B[A[2]];

						if(A[B[2]])x=B[2],y=A[B[2]];

						if(B[B[2]])x=B[2],y=B[B[2]];

						--E[1],F[x]=1,F[y]=0,ans[x]=1,

						E[x]=E[y]+1,E[y]=0;

					}

				}

			}

		}vector<pair<int,int> > vec;

		for(int i=1;i<=n;i++)

			if(E[i]>1)

				vec.push_back({E[i]-1,i});

		sort(vec.begin(),vec.end());

		reverse(vec.begin(),vec.end());

		int sum=0;

		for(auto [x,y]:vec)

			if(sum>0)sum-=x,ans[y]^=1;

			else sum+=x;

		for(int i=2;i<=n;i++)

			if(!F[i])ans[i]=ans[fa[i]]^1;

		for(int i=1;i<=n;i++)

			putchar(ans[i]?'w':'b');

		puts("");

	}

	return 0;

}