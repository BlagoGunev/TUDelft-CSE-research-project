#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
inline void getint(int &_int){
	char ch=_int=0;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		_int=_int*10+ch-48;
		ch=getchar();
	}
}
int n,a,b,c;
int t;
int cnt;
int main(){
	int i,j;
	getint(n);
	getint(a);
	getint(b);
	for(i=1;i<=n;i++){
		getint(t);
		if(t==1){
			if(a){
				a--;
			}else{
				if(b){
					b--;
					c++;
				}else{
					if(c){
						c--;
					}else{
						cnt++;
					}
				}
			}
		}
		if(t==2){
			if(b){
				b--;
			}else{
				cnt+=2;
			}
		}
	}
	printf("%d\n",cnt);
}