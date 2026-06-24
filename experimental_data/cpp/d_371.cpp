#include <iostream>
#include <iomanip>
#include <string>
#include "stdio.h"
using namespace std;  
#pragma warning(disable:4996)

int n,m;
int d[200010],e[200010],p[200010];
int o;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt","rt",stdin);
		//freopen("output.txt","wt",stdout);
	#endif
 
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
		scanf("%d",&d[i]);

	for (int i=0; i<=n; i++)
		p[i]=i+1;

	scanf("%d",&m);
	for (int z=0; z<m; z++) {
		scanf("%d",&o);
		if (o==1) {
			int s,v,i;
			scanf("%d%d",&s,&v);
			
			i=s;
			while (i!=n+1) {
				int k = min(v,d[i]-e[i]);
				v-=k;
				e[i]+=k;
				if (v==0) break;
				i=p[i];
			}

			int j = s;
			while (j<i) {
				s = p[j];
				p[j]=i;
				j=s;
			};
			e[n+1]=0;
		};
		if (o==2) {
			int s;
			scanf("%d",&s);
			printf("%d\n", e[s]);
		}
	};

	return 0;
};