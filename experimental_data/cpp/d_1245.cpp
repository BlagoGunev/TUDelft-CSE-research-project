#include <bits/stdc++.h>

using namespace std;

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<algorithm>

#define rg register
#define il inline
#define MX (2000 + 5)
#define ll long long


ll abs(ll a){return a > 0 ? a : -a;}
ll min(ll a ,ll b){return a < b ? a : b;}

int read(){
	rg char k = getchar();
	int x = 0 ,flag = 1;
	while(k < '0' || k > '9'){
		if(k == '-')	flag = -1;
		k = getchar();
	}
	while(k >= '0' && k <= '9'){
		x = x * 10 + k - '0';
		k = getchar();
	}
	return x * flag;
}

int c[MX] ,k[MX] ,n;
int x[MX] ,y[MX] ,light[MX] ,from[MX];
ll dis[MX];

int cnct[MX][2] ,cnt1;
int gen[MX] ,cnt2;

void prim(){
	memset(dis ,0x3f ,sizeof(dis));
	int now = 1;
	ll Ans = 0;
	for(rg int i = 1 ; i <= n ; ++i){
		if(c[i] < c[now])	now = i;
	}
	gen[++cnt2] = now;
	Ans += c[now];
	for(rg int i = 1 ; i < n ; ++i){
		light[now] = true;
		ll nxt = 0 ,far = 1LL << 60 ,type = 0;
		for(rg int j = 1 ; j <= n ; ++j){
			if(light[j])	continue;
			if(dis[j] > 1LL * (abs(x[now] - x[j]) + abs(y[now] - y[j]))
				* (k[now] + k[j])){
				from[j] = now;
				dis[j] = 1LL * (abs(x[now] - x[j]) + abs(y[now] - y[j]))
				* (k[now] + k[j]);
			}
			if(dis[j] < far){
				type = 0;
				nxt = j;
				far = dis[j];
			}
			if(c[j] < far){
				type = 1;
				nxt = j;
				far = c[j];
			}
		}
		if(type == 0){
			++cnt1;
			cnct[cnt1][0] = from[nxt];
			cnct[cnt1][1] = nxt;
		}
		else{
			gen[++cnt2] = nxt;
		}
		Ans += far;
		now = nxt;
	}
	printf("%lld\n%d\n" ,Ans ,cnt2);
	for(rg int i = 1 ; i <= cnt2 ; ++i)
		printf("%d " ,gen[i]);
	puts("");
	printf("%d\n" ,cnt1);
	for(rg int j = 1 ; j <= cnt1 ; ++j)
		printf("%d %d\n" ,cnct[j][0] ,cnct[j][1]);
}

int main(){
	n = read();
	for(rg int i = 1 ; i <= n ; ++i)
		x[i] = read() ,y[i] = read();
	for(rg int i = 1 ; i <= n ; ++i)
		c[i] = read();
	for(rg int i = 1 ; i <= n ; ++i)
		k[i] = read();
	prim();
}