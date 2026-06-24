#include <cstdio>
using namespace std;
int a[100001],isint[100001];
struct number{
	int value;
	int negative;
};
number get(){
	number n;
	char c=getchar();
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')n.negative=1;else n.negative=0;
	while(c<'0'||c>'9')c=getchar();
	n.value=0;
	while(c>='0'&&c<='9'){
		n.value=n.value*10+(c-'0');
		c=getchar();
	}
	return n;
}
int main(){
	int n;
	scanf("%d",&n);
	long long sum=0;
	for(int i=0;i<n;i++){
		number A=get(),B=get();
		if(A.negative){
			a[i]=-A.value-1;
			if(B.value){
				sum+=(100000-B.value);
			}else{
				a[i]=-A.value;isint[i]=1;
			}
		}else{
			a[i]=A.value;
			if(B.value){
				sum+=B.value;
			}else{
				a[i]=A.value;isint[i]=1;
			}
		}
	}
	sum/=100000;
	for(int i=0;i<n;i++){
		if(isint[i]){
			printf("%d\n",a[i]);
		}else{
			if(sum){
				printf("%d\n",a[i]+1);
				sum--;
			}else{
				printf("%d\n",a[i]);
			}
		}
	}
	return 0;
}