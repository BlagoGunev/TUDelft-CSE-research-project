#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

template<class T>void read(T &x){
    x=0;int f=0;char ch=getchar();
    while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
    while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return ;
}

int t[200051], flag, n;

int main() {
	read(n);
	for(int i = 1; i <= n; i++)
		read(t[i]);
	for(int i = 1; i <= n; i++)
	{
		if(t[i] > t[i - 1] && flag == 0) continue;
		if(t[i] < t[i - 1] && i != 1)
			flag = 1;
		if(flag == 1 && t[i] > t[i - 1]) 
		{
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	return 0;
}