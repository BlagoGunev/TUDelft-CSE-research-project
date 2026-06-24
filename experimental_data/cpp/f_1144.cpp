#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
#define bug1(g) cout<<"test: "<<g<<endl
#define bug2(g,i) cout<<"test: "<<g<<" "<<i<<endl
#define bug3(g,i,k) cout<<"test: "<<g<<" "<<i<<" "<<k<<endl
typedef long long ll;
const int maxn = 2e5 + 100;
struct node {
	int u, v;
	node(){u=v=0;}
}edge[maxn];
int cnt[maxn];
bool vis[maxn];
vector<int> v[maxn];
namespace fastIO {
    #define BUF_SIZE 100000
    //fread -> read
    bool IOerror = 0;
    inline char nc() {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p1 == pend) {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == p1) {
                IOerror = 1;
                return -1;
            }
        }
        return *p1++;
    }
    inline bool blank(char ch) {
        return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    inline void read(int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    inline void readll(long long int &x) {
        char ch;
        while(blank(ch = nc()));
        if(IOerror)
            return;
        for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
    }
    #undef BUF_SIZE
};
using namespace fastIO;
int n, m,flag=1;
int main()
{
	read(n);read(m);
	for (int i = 1; i <= m; i++) {
		read(edge[i-1].u);
		read(edge[i-1].v);
		v[edge[i-1].u].push_back(edge[i-1].v);
		v[edge[i-1].v].push_back(edge[i-1].u);
	}
	queue<int> q;
	q.push(1);
	cnt[1] = 1;
	vis[1] = 1;
	while (!q.empty()&&flag) {
		int top = q.front();q.pop();
		for (int i = 0; i < v[top].size()&&flag; i++) {
			if (!vis[v[top][i]]) {
                q.push(v[top][i]);
				cnt[v[top][i]] = -1 * cnt[top];
				vis[v[top][i]] = 1;
			}
			else {
				if (cnt[v[top][i]] == cnt[top]) {flag=0;break;}
			}
		}
	}
	printf("%s\n",flag?"YES":"NO");
	if (flag) {
		for (int i = 0; i < m; i++) {
                printf("%d",cnt[edge[i].u] == 1?1:0);
		}
	}
    return 0;
}