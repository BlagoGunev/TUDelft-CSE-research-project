/*program by mangoyang*/
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define INF (0x7f7f7f7f)
#define Max(a,b) ((a) > (b) ? (a) : (b))
#define Min(a,b) ((a) < (b) ? (a) : (b))
#define mp make_pair
#define fi first 
#define N (100)
using namespace std;
inline void read(int &x){
	int w = 1; char ch = 0; x = 0;
	while (ch ^ '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
	x = x * w;
}
int s[N], n;
pair<char,int> Bit[N][N];
int main(){
	read(n);
	for(int i = 1; i <= n; i++){
		char ch; int x;
		for(ch = getchar(); ch != '|' && ch != '&' && ch != '^'; ch = getchar());
		read(x);
		if(ch == '|'){
			for(int j = 0; j < 10; j++)
				if(x >> j & 1) s[j] = 1, Bit[j][1] = mp(ch, 1);
		}else if(ch == '&'){
			for(int j = 0; j < 10; j++)
				if(!(x >> j & 1)) s[j] = 1, Bit[j][1] = mp(ch, 0);
		}else{
			for(int j = 0; j < 10; j++)
				if(x >> j & 1){
					if(s[j] && Bit[j][s[j]].fi == ch) s[j]--;
						else Bit[j][++s[j]] = mp(ch, 1);
				}
		}
	}
	printf("3\n");
	int x = 0;
	for(int i = 0; i < 10; i++) 
		if(!(s[i] && Bit[i][1].fi == '&')) x |= 1 << i; 
	printf("& %d\n",x);
	x = 0;
	for(int i = 0; i < 10; i++)
		if(s[i] && Bit[i][1].fi == '|') x |= 1 << i;
	printf("| %d\n",x);
	x = 0;
	for(int i = 0; i < 10; i++)
		if(s[i] && Bit[i][s[i]].fi == '^') x |= 1 << i;
	printf("^ %d\n",x);
	return 0;
}