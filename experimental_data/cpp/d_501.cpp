#include<cstdio>

#include<cstring>

const int N=2e5+5;

int n,m,i,v[N],f[N],a[N];

int read(){

	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());

	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;

}

void write(int x){if (x>9) write(x/10);putchar(x%10+48);}

void add(int x){for (;x<=n;x+=x&-x) f[x]++;}

void dec(int x){for (;x<=n;x+=x&-x) f[x]--;}

int sum(int x){int k=0;for (;x;x-=x&-x) k+=f[x];return k;}

int ask(int k){

	int x=0;

	for (int i=m;i;i>>=1)

		if (x+i<=n&&k>=f[x+i]) x+=i,k-=f[x];

	return x+1;

}

void work(int x){

	int k=sum(x);add(x);

	a[i]+=k;if (a[i]>=i) a[i]-=i,a[i+1]++;

}

int main(){

	for (n=read(),i=1;i<=n;i++) v[i]=read()+1;

	for (i=1;i<=n;i++) work(v[n+1-i]);

	memset(f,0,sizeof(f));

	for (i=1;i<=n;i++) v[i]=read()+1;

	for (i=1;i<=n;i++) work(v[n+1-i]);

	for (m=1;m<=n;m<<=1);m>>=1;

	for (i=n;i;i--){

		int x=ask(a[i]);dec(x);

		write(x-1);putchar(' ');

	}

}