#include<bits/stdc++.h>

#define rep(i,a,b) for(int i=(a);i<=(b);++i)

#define Rep(i,a,b) for(int i=(a);i<(b);++i)

#define rrep(i,a,b) for(int i=(a);i>=(b);--i)

using namespace std;

template <typename T>

inline void read(T &x){

    x=0;char ch=getchar();bool f=0;

    while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}

    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();

    if(f)x=-x;

}

template <typename T,typename ...Args>

inline void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}

const int N = 2e5 + 5;

int t,n,a[N];

signed main(){

	read(t);

	while(t--){

		int ans = 0;

		read(n);

		rep(i,1,n)read(a[i]);

		for(int i=1,nxt=1;i<=n;i=nxt){

			while(nxt <= n && a[nxt] == a[i])nxt++;

			if(nxt > n){

				ans = max(ans,nxt - i);

				break;	

			}

			int j = n,cnt = 1;

			while(nxt <= j){

				j = upper_bound(a+nxt,a+j,(a[i]+a[j]) / 2) - a - 1;

				if(j < nxt)break;

				cnt++;	

			}

			ans = max(ans,cnt+nxt-i);

		}

		printf("%d\n",n-ans);

	}

}