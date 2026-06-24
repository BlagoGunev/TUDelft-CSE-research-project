#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;++i)
#define drp(i,j,k) for(int i=j;i>=k;--i)
using namespace std;
char buf[25];
string s;
int p[1500010];
int n,m;
int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return f?-x:x; 
}
void write(int x){
	if(!x){putchar('0');return;}
	if(x<0){putchar('-');x=-x;}
	int cnt=0;
	while(x){buf[++cnt]='0'+x%10;x/=10;}
	drp(i,cnt,1)putchar(buf[i]);
}
string Getline(){
	char ch=getchar();string s="";
	while(ch<'a'||ch>'z') ch=getchar();
	while(ch>='a'&&ch<='z'){
		s+=ch;ch=getchar();
	}
	return s;
}
int main(){
	n=read();
	rep(i,1,n){
		s=Getline();
		int len=s.length();m=0;
		for(int j=0;j+2<=len-1;++j){
			if(s[j]=='o'&&s[j+1]=='n'&&s[j+2]=='e'){
				if(m>0&&p[m]==j) p[m]=j+1;
					else p[++m]=j+2; 
			}
			if(s[j]=='t'&&s[j+1]=='w'&&s[j+2]=='o') p[++m]=j+2;
		}
		write(m);putchar('\n');
		rep(j,1,m){
			write(p[j]);
			if(j!=m) putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}