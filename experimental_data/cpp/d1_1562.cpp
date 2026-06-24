#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define P pair<int,int>
#define pll pair<long,long>
using namespace std;
template<typename T>void write(T x) {
    if(x<0) { putchar('-'); x=-x; }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], str[64];
    int l = SIZE, r = SIZE;
    int read(char *s) {
        while (r) {
            for (; l < r && buf[l] <= ' '; l++);
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        int cur = 0;
        while (r) {
            for (; l < r && buf[l] > ' '; l++) s[cur++] = buf[l];
            if (l < r) break;
            l = 0, r = int(fread(buf, 1, SIZE, stdin));
        }
        s[cur] = '\0';
        return cur;
    }
    template<typename type>
    bool read(type &x, int len = 0, int cur = 0, bool flag = false) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        if (flag) x = -x;
        return true;
    }
    template <typename type>
    type read(int len = 0, int cur = 0, bool flag = false, type x = 0) {
        if (!(len = read(str))) return false;
        if (str[cur] == '-') flag = true, cur++;
        for (x = 0; cur < len; cur++) x = x * 10 + str[cur] - '0';
        return flag ? -x : x;
    }
} using FastIO::read;
const int maxn=2e5+10,MAXN=(1<<15)*16,mod=1e9+7,INF=0x3f3f3f3f;
#include<bits/stdc++.h>
using namespace std;
struct node{
	int len,fa,s[26];
}a[maxn];
int lst=1,cnt=1;
void ins(int c) {
	int p=lst,np=lst=++cnt;a[np].len=a[p].len+1;
	for(;p&&!a[p].s[c];p=a[p].fa) a[p].s[c]=np;
	if(!p) return(void)(a[np].fa=1);
	int q=a[p].s[c];
	if(a[q].len==a[p].len+1) return(void)(a[np].fa=q);
	int nq=++cnt;a[nq]=a[q],a[nq].len=a[p].len+1,a[q].fa=a[np].fa=nq;
	for(;p&&a[p].s[c]==q;p=a[p].fa) a[p].s[c]=nq;
}
char s[maxn];
int n,res,pos[maxn],ans[maxn];
bool vis[maxn];
void dfs(int now, int num, int cnt) {
	if (vis[num]) {
		if (res>cnt) {
			res=cnt;
			for (int j=1; j<=cnt; j++) ans[j]=pos[j];
		}
		return;
	}
	if (cnt>4) return;
	if (now>n) return;
	dfs(now+1,num,cnt);
	pos[cnt+1]=now;
	dfs(now+1,num*10+s[now]-'0',cnt+1);
}
int sum[maxn];
int main() {
	int t;
	read(t);
	while (t--) {
		int n,q;
		read(n),read(q);
		read(s+1);
		for (int i=1; i<=n; i++) {
			if (s[i]=='+') sum[i]=1;
			else sum[i]=-1;
			if (i%2==0) sum[i]=-sum[i];
			sum[i]+=sum[i-1];
		}
		while (q--) {
			int l,r;
			read(l),read(r);
			if (abs(sum[r]-sum[l-1])==0) printf("0\n");
			else if (abs(sum[r]-sum[l-1])%2==0) printf("2\n");
			else printf("1\n");
		}
	}
	return 0;
}