#include <bits/stdc++.h>

const int XN=2e3+11,P=998244353;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
    static char s[XN];
    static int c[XN][XN];
    std::cin>>(s+1);
    int n=strlen(s+1);
    //容斥?
    c[0][0]=1;
    for(int i=1;i<=n;++i) {
        c[i][0]=1;
        for(int j=1;j<=i;++j)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%P;
    }
    int Ans=0;
    for(int i=1;i<n;++i) {
        int cl=0,cr=0,q1=0,q2=0;
        for(int j=1;j<=i;++j)
            if(s[j]=='(') {
                cl++;
            } else if(s[j]=='?')
                q1++;
        for(int j=i+1;j<=n;++j)
            if(s[j]==')') {
                cr++;
            } else if(s[j]=='?')
                q2++;
        for(int cnt=std::max(cl,cr);cnt<=std::min(i,n-i);++cnt)
            if(cnt-cl<=q1 && cnt-cr<=q2) {
                (Ans+=1LL*cnt*c[q1][cnt-cl]%P*c[q2][cnt-cr]%P)%=P;
            }
    }
    std::cout<<Ans<<'\n';
	return 0;
}