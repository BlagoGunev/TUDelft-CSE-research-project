#include <bits/stdc++.h>

using namespace std;

#include<stdio.h>

int main() {
	int n, m, s;
	long long res=0;
	scanf("%d%d%d", &n, &m, &s);
	for(int xl=1;xl<=n;xl+=2) {
		int ly=(s+xl-1)/xl;
		if(ly%2==0) ly++;
		for(int yl=ly;yl<=m;yl+=2) {
			long long num=(n-xl+1)*(m-yl+1);
			int sz=xl*yl-s;
			if(sz==0) {
				res+=num*(xl/2+1)*(yl/2+1)*2-num;
			}
			else if(sz%4==0) {
				for(int xp=2;xp<xl;xp+=2) {
					if(sz%xp==0) {
						int t=sz/xp;
						if(t<yl&&t%2==0)
							res+=2*num;
					}
				}
			}
		}
	}
	printf("%lld\n", res);
}