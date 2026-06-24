#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

template <typename T> inline T read(){
    T sum=0;
    int fl=1,ch=getchar();
    for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
    for(;isdigit(ch);ch=getchar()) sum=(sum<<3)+(sum<<1)+ch-'0';
    return sum*fl;
}

const int maxn=300000+5;

int c[maxn],n;


int main(){
	n=read<int>();
	int r=n,l=1;
	for(int i=1;i<=n;i++){
		c[i]=read<int>();
	}
	if(c[l]!=c[r]){
		printf("%d\n",n-1);
		return 0;
	}
	int ans=0,tmp=0;
	while(c[l]==c[r]) l++;
	ans=max(ans,r-l),l=1;
	while(c[l]==c[r]) r--;
	ans=max(ans,r-l),r=n;
	while(c[l]==c[r]){
		if(!tmp){
			l++;
		}else r--;
		tmp^=1;
	}
	printf("%d\n",max(ans,r-l));
	return 0;
}