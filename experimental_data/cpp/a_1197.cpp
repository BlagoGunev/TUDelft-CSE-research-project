/*DennyQi 2019*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 100010;
const int P = 998244353;
const int INF = 0x3f3f3f3f;
inline int mul(const int& a, const int& b){ return 1ll*a*b%P; }
inline int add(const int& a, const int& b){ return (a+b>=P)?a+b-P:a+b; }
inline int sub(const int& a, const int& b){ return (a-b<0)?a-b+P:a-b; }
inline int read(){
    int x(0),w(1); char c = getchar();
    while(c^'-' && (c<'0' || c>'9')) c = getchar();
    if(c=='-') w = -1, c = getchar();
    while(c>='0' && c<='9') x = (x<<3)+(x<<1)+c-'0', c = getchar(); 
    return x*w;
}
int T,n,a[N],mx,cmx,p;
int main(){
	// freopen("file.in","r",stdin);
	T = read();
	while(T--){
		n = read();
		for(int i = 1; i <= n; ++i){
			a[i] = read();
		}
		mx = cmx = p = -1;
		for(int i = 1; i <= n; ++i){
			if(a[i] > mx){
				mx = a[i];
				p = i;
			}
		}
		for(int i = 1; i <= n; ++i){
			if(i == p) continue;
			if(a[i] > cmx){
				cmx = a[i];
			}
		}
		printf("%d\n",min(cmx-1,n-2));
	}
	return 0;
}