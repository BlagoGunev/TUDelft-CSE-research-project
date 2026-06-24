#include<bits/stdc++.h>
using namespace std;

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
	inline bool read(int &x) {
		char ch;
		while(blank(ch = nc()));
		if(IOerror) return false;
		for(x = ch - '0'; (ch = nc()) >= '0' && ch <= '9'; x = x * 10 + ch - '0');
		return true;
	}
	#undef BUF_SIZE
};
using namespace fastIO;

void out(int x)
{
    if(x>9)out(x/10);
    putchar(x%10+'0');
}

#define ll long long
#define print(n,ans) for(int i=1;i<=n;i++)out(ans[i]),putchar(" \n"[i==n])
#define pa pair<int,int>

const int maxn=1e5+10;
char s[maxn];

int main()
{
    scanf("%s",s);int len=strlen(s);
    while((s[0]=='b' && s[len-1]=='w')|| (s[0]=='w' && s[len-1]=='b')){
        if(s[0]=='b'){
            int i;
            for(i=1;i<len;i++){
                if(s[i]==s[i-1]){
                    break;
                }
            }
            //cout<<i<<endl;
            if(i==len)break;i--;
            for(int j=0;j<=i/2;j++)swap(s[j],s[i-j]);
            for(int j=i+1;j<=(i+len)/2;j++)swap(s[j],s[len-j+i]);
            //cout<<s<<endl;
        }
        else {
            reverse(s,s+len);
        }
    }
    int ma=0,tot=1;
    for(int i=1;i<len;i++){
        if(s[i-1]!=s[i])tot++;
        else {
            ma=max(ma,tot);tot=1;
        }
    }
    ma=max(ma,tot);
    printf("%d\n",ma);
}