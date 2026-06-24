#include <bits/stdc++.h>

using namespace std;

 

#define maxn 400400

#define pb push_back

#define debug 

#define pii pair<int,int>

#define ll long long

#define mod 998244353

main(){

	int nt;
	scanf("%d",&nt);

	while(nt--){

		int n,k;
		scanf("%d%d",&n,&k);

		int a = -1, b = -1;

		for(int i=0;i<=n;i++){

			int men = n-i;
			int tot = (i*i-i)/2 + (men*men-men)/2;
			if(tot == k)
				a = i, b = men;

		}

		if(a == -1)
			printf("NO\n");
		else{
			printf("YES\n");
			for(int i=0;i<a;i++)
				printf("1 ");
			for(int i=0;i<b;i++)
				printf("-1 ");
			printf("\n");
		}

		
	}

}