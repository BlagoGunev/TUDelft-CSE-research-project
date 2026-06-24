#include <bits/stdc++.h>
/*************************************************************************
    > File Name: C.cpp
    > Author: PumpkinYing
    > Created Time: 2018/12/30 22:54:50
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;

set<ll> st;

int main() {
	int n;
	scanf("%d",&n);
	for(int i = 1;i <= (int)sqrt(n)+1;i++) {
		if(n%i == 0) {
			ll d = __gcd(i,n);
			ll num = n/d;
			ll first = 1;
			ll last = 1+d*(num-1);
			st.insert((first+last)*num/2);

			d = __gcd(n/i,n);
			num = n/d;
			first = 1;
			last = 1+d*(num-1);
			st.insert((first+last)*num/2);
		}
	}

	for(auto x:st) {
		printf("%lld ",x);
	}
	printf("\n");

    return 0;
}