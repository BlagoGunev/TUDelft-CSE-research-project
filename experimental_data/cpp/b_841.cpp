#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int inline readint(){
	int Num;char ch;
	while((ch=getchar())<'0'||ch>'9');Num=ch-'0';
	while((ch=getchar())>='0'&&ch<='9') Num=Num*10+ch-'0';
	return Num;
}
int n;
ll sum=0;
int main(){
	bool flag=false;
	n=readint();
	for(int i=1;i<=n;i++){
		int a=readint();
		sum+=a;
		if(a&1) flag=true;
	}
	if(sum&1) printf("First\n");
	else if(flag) printf("First\n");
	else printf("Second\n");
	return 0;
}