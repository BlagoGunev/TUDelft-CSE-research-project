#include<bits/stdc++.h>



using namespace std;

typedef long long ll;



int n,v,ii,x, a[3005],ans,t;



int main(int argc, char **argv) {

#ifndef ONLINE_JUDGE

	freopen("input.in", "r", stdin);

#endif

	scanf("%d%d",&n,&v);

	while(n--){

		scanf("%d%d",&ii,&x);

		a[ii] += x;

	}

	for(int i = 1; i<=3002; ++i){

		t = min(a[i-1],v);

		ans += t;

		t = min(a[i],v-t);

		ans += t;

		a[i] -= t;

	}

	printf("%d",ans);

	return 0;

}