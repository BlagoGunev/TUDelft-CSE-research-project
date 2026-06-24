#include <bits/stdc++.h>
/*************************************************************************

    > File Name: P.cpp

    > Author: jiangyuzhu

    > Mail: 834138558@qq.com 

    > Created Time: 2016/7/14 13:01:26

 ************************************************************************/



#include<iostream>

#include<cstdio>

#include<cstring>

#include<queue>

#include<vector>

#include<set>

#include<map>

#include<algorithm>

#define sa(n) scanf("%d", &(n))

using namespace std;

typedef long long ll;

const ll maxm = 1e17;

int main (void)

{

	ll a;scanf("%lld" ,&a);

	//ll tmp = a - 45 % a * maxm % a * 18 % a; 

    ll t = 5 * (9 * (18 * maxm % a) % a) % a;

    printf("%lld %lld\n", a - t, maxm * 10 - 1 + a - t);

    return 0;

}