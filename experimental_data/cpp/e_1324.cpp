#include<bits/stdc++.h>

using namespace std;

#define N 2005

#define Mems(i,j)memset(i,j,sizeof i)
#define Memc(i,j)memcpy(i,j,sizeof i)

int g[N],f[N];
bool vis[N],bo[N];

inline int read(){
    int AK = 1, IOI = 0;
    char ch = 0;
    while (ch < '0' || ch > '9'){
        AK = ch=='-'?-1:1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0'){
        IOI *= 10;
        IOI += ch - 48;
        ch =  getchar();
    }
    return AK * IOI;
}
inline  void Print(int x){
    if (x < 0){
        printf("-");
        Print(-x);
        return ;
    }
    if (x < 10){
        putchar(x + '0');
        return;
    }
    Print(x / 10);
    putchar(x % 10 + '0');
}

int main(){
	int n = read(), h = read(), l = read(), r = read();
    int answer = 0;
	bo[0]=1;
	while(n--){
		int a = read();
        for (int i = 0; i < h; i ++){
		if(bo[i]){
			int j = (i+a)%h;
			g[j] = f[i]+(j>=l&&j<=r);
			vis[j] = 1;
		}
        }
        for (int i = 0; i < h; i ++)
		if(bo[i])
		{
			int j=(i+a-1)%h;
			g[j]=std::max(g[j],f[i]+(j>=l&&j<=r));
			vis[j]=1;
		}
		Memc(f,g);
		Mems(g,0);
		Memc(bo,vis);
		Mems(vis,0);
		/*cout<<g[23]<<endl;*/
	}
    for (int i = 0; i < h; i ++)
	  if(bo[i])answer=std::max(answer,f[i]);
	printf("%d\n", answer);
}