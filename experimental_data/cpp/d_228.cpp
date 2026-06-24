#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
#define LL long long
vector<LL> a;
vector<LL> st[16][16];

void bit_inc(vector<LL>& st,int x,LL inc) {
  while (x<(int)st.size()) {
    st[x]+=inc;
    x|=x+1;
  }
}

LL bit_sum(const vector<LL>& st,int x){
  LL s=0;
  while (x>=0) {
    s+=st[x];
    x=(x&(x+1))-1;
  }
  return s;
}

void ins(LL p,LL x) {
	LL delta=x-a[p];
	a[p]=x;
	for (int i=2;i<=6;i++)
		bit_inc(st[i][p%((i-1)*2)],p,delta);
}

LL qry(LL l,LL r,LL z) {
	LL ans=0;
	for (int i=0;i<(z-1)*2;i++)
		ans+=(bit_sum(st[z][(l+i)%((z-1)*2)],r)-bit_sum(st[z][(l+i)%((z-1)*2)],l-1))*min<LL>(i+1,z*2-(i+1));
	return ans;
}

int main() {
	int n;
	scanf("%d",&n);
	a.resize(n);
	for (int i=2;i<=6;i++)
    for (int j=0;j<(i-1)*2;j++)
      st[i][j].resize(n);

	for (int i=0;i<n;i++) {
		LL ai;
		scanf("%lld",&ai);
		ins(i,ai);
	}

	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++) {
		int t;
    scanf("%d",&t);
		switch (t) {
      case 1:
        LL p,x;
        scanf("%lld%lld",&p,&x);
        ins(--p,x);
        break;
      case 2:
        LL l,r,z;
        scanf("%lld%lld%lld",&l,&r,&z);
        printf("%lld\n",qry(--l,--r,z));
		}
	}
}