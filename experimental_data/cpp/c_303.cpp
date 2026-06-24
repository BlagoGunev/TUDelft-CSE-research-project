#include<cstdio>

#include<algorithm>

using namespace std;

#define MAXN 5000

#define MAXM 1000000



int a[MAXN+10],n,k,mx,cnt[MAXM+10];

bool vis[MAXM+10];



void Read(int &x){

	char c;

	while(c=getchar(),c!=EOF){

		if(c>='0'&&c<='9'){

			x=c-'0';

			while(c=getchar(),c>='0'&&c<='9')

				x=x*10+c-'0';

			ungetc(c,stdin);

			return ;

		}

	}

}

int main()

{

	Read(n),Read(k);

	for(int i=1;i<=n;i++){

		Read(a[i]);

		mx=max(mx,a[i]);

	}

	for(int i=1;i<=n;i++)

		for(int j=1;j<i;j++)

			cnt[abs(a[i]-a[j])]++;

	for(int m=1;m<=mx+1;m++){

		int sum=0;

		for(int i=m;i<=mx;i+=m){

			sum+=cnt[i];

			if(sum>k*(k+1)/2)

				break;

		}

		if(sum>k*(k+1)/2) continue;

		int p=0;

		for(int i=1;i<=n;i++){

			if(!vis[a[i]%m])

				vis[a[i]%m]=true;

			else{

				p++;

				if(p>k) break;

			}

		}

		if(p<=k){

			printf("%d\n",m);

			return 0;

		}

		for(int i=1;i<=n;i++)

			vis[a[i]%m]=false;

	}

}