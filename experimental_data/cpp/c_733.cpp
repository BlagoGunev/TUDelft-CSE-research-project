#include <iostream>

#include <cstdio>

#include <algorithm>

#include <cstring>

#include <cmath>

using namespace std;

const int N=505,INF=1e9+5;

inline int read(){

    char c=getchar();int x=0,f=1;

    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}

    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}

    return x*f;

}

int n,a[N],s[N],m,b[N];

int t[N];

struct eat{

	int id;

	char s;

}ans[N];

int cnt=0,fail=0;

void print(int n,int a[],int id){//printf("print %d %d\n",n,id);

	while(n>1){

		int mx=-1,p=-1;

		for(int i=1;i<=n;i++)

		if(a[i]>mx&& ((i!=1&&a[i-1]<a[i]) || (i!=n&&a[i+1]<a[i])) ) mx=a[i],p=i;

		if(p==-1){fail=1;return;} 

	

		cnt++;ans[cnt].id=id+p;

		if(p!=1&&a[p-1]<a[p]){

			ans[cnt].s='L';

			a[p-1]+=a[p];n--;

			for(int i=p;i<=n;i++) a[i]=a[i+1];

		}else{

			ans[cnt].s='R';

			a[p]+=a[p+1];n--;

			for(int i=p+1;i<=n;i++) a[i]=a[i+1];

		}

	}

}

void sol(){

	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];

	

	int j=0;

	for(int i=1;i<=m;i++){//printf("sol i %d\n",i);

		int s=0,p=0;

		for(j++;j<=n;j++){//printf("sol j %d\n",j);

			s+=a[j];t[++p]=a[j];

			if(s>=b[i]) break;

		}

		if(s!=b[i]){printf("NO");return;}

		

		print(p,t,i-1);

		if(fail){printf("NO");return;}

	}

	if(j<n) {puts("NO");return;}//!

	

	puts("YES");

	for(int i=1;i<=cnt;i++) printf("%d %c\n",ans[i].id,ans[i].s);

}

int main(){

	n=read();

	for(int i=1;i<=n;i++) a[i]=read();

	m=read();

	for(int i=1;i<=m;i++) b[i]=read();

	sol();

}