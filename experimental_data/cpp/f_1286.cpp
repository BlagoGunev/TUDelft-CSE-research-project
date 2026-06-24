#include <bits/stdc++.h>

using namespace std;



#define Int register int

#define MAXM 2000005

#define int long long

#define MAXN 25



//char buf[1<<21],*p1=buf,*p2=buf;

//#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)

template <typename T> inline void read (T &x){char c = getchar ();x = 0;int f = 1;while (c < '0' || c > '9') f = (c == '-' ? -1 : 1),c = getchar ();while (c >= '0' && c <= '9') x = x * 10 + c - '0',c = getchar ();x *= f;}

template <typename T,typename ... Args> inline void read (T &x,Args& ... args){read (x),read (args...);}

template <typename T> inline void write (T x){if (x < 0) x = -x,putchar ('-');if (x > 9) write (x / 10);putchar (x % 10 + '0');}

template <typename T> inline void chkmax (T &a,T b){a = max (a,b);}

template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}



int n,a[MAXN];



int z[MAXN],sl[MAXM],sr[MAXM],s0[MAXM],s1[MAXM];

void getnum (int *s,int &k,int l,int r){//将所有情况枚举出来并排序 

	k = 1,s[0] = 0;

	for (Int i = l;i < r;++ i,k <<= 1){

		for (Int j = 0;j < k;++ j) s0[j] = s[j] + z[i],s1[j] = s[j] - z[i];

		int p = 0,q = 0,now = 0;

		while (p < k && q < k){

			if (s0[p] <= s1[q]) s[now ++] = s0[p ++];

			else s[now ++] = s1[q ++];

		}

		while (p < k) s[now ++] = s0[p ++];

		while (q < k) s[now ++] = s1[q ++]; 

	}

}



bool checkit (int S){

	int siz = 0,sum = 0,ql,qr;

	for (Int x = 0;x < n;++ x) if (S >> x & 1) z[siz ++] = a[x],sum += a[x];

	if (abs(sum) % 2 != (siz - 1) % 2) return 0;

	getnum (sl,ql,0,siz >> 1),getnum (sr,qr,siz >> 1,siz);

	int ned = 1 + (abs(sum) < siz) * 2;//显然我们不能把所有的dep都设为相同的深度

	for (Int i = qr - 1,j = 0;~i;-- i){

		while (j < ql && sr[i] + sl[j] <= -siz) ++ j;

		for (Int k = j;k < ql && ned && sr[i] + sl[k] < siz;++ k) -- ned;

	}

	return !ned;

}



int f[MAXM],sum[MAXM];



signed main(){

	read (n);

	for (Int x = 0;x < n;++ x) read (a[x]);

	memset (f,0x3f,sizeof (f)),f[0] = 0;

	for (Int S = 1;S < (1 << n);++ S) sum[S] = sum[S >> 1] + (S & 1);

//	cout << checkit (3) << endl;return 0;

	for (Int S = 1;S < (1 << n);++ S) if (sum[S] == 1 || checkit (S)){

		int rst = ((1 << n) - 1) ^ S,con = (sum[S] != 1 ? sum[S] - 1 : (a[(int)log2(S)] == 0 ? 0 : 1));

		for (Int T = rst;T >= 0;T = (T - 1) & rst){

			if (f[T] <= n) chkmin (f[T | S],f[T] + con);

			if (!T) break;

		}

	}

	write (f[(1 << n) - 1]),putchar ('\n');

	return 0;

}