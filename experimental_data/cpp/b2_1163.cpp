#include<bits/stdc++.h>
using namespace std;
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int rd(){
    int x=0,fl=1;char ch=gc();
    for (;ch<48||ch>57;ch=gc())if(ch=='-')fl=-1;
    for (;48<=ch&&ch<=57;ch=gc())x=(x<<3)+(x<<1)+(ch^48);
    return x*fl;
}
inline void wri(int a){if(a<0)a=-a,putchar('-');if(a>=10)wri(a/10);putchar(a%10|48);}
inline void wln(int a){wri(a);puts("");}
const int N=100002;
int a[N],cnt[N],col[N],num,x,i,n;
int main(){
	n=rd();
	cnt[0]=n;
	for (i=1;i<=n;i++){
		a[i]=rd();
		cnt[col[a[i]]]--;
		col[a[i]]++;
		if (col[a[i]]==1) num++;
		cnt[col[a[i]]]++;
	}
	for (i=n;i;i--){
		x=i/num;
		if (i==num || num==1 || (i%x==1 || x==1) && cnt[x]==num-1 && cnt[x+1]==1 ||
		cnt[1]==1 && (num==1 || (i-1)%(num-1)==0 && cnt[(i-1)/(num-1)]==num-1)){
			printf("%d",i);
			return 0;
		}
		cnt[col[a[i]]]--;
		col[a[i]]--;
		if (col[a[i]]==0) num--;
		cnt[col[a[i]]]++;
	}
}