#include<bits/stdc++.h>
#define maxn 600000
using namespace std;
int n,m;
char s[maxn];
bool fr[maxn];
int mn=0;
int mx=0;
bool bo(int j) {
    if(s[j]==s[j-1] && s[j-1]=='1') return true;
    return false;
}
int main() {
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%s",s);
        for(int j=0;j<m;j++) fr[j]=true;
        int cnt=m/4;
        for(int j=1;j<m;j++) {
            if(fr[j] && fr[j-1] && bo(j) && cnt>0) {
                fr[j]=fr[j-1]=false;
                mn++;
                cnt--;
            }
        }
        for(int j=0;j<m;j++) {
            if(s[j]=='1' && fr[j]) mn++;
        }

        for(int j=0;j<m;j++) fr[j]=true;
        cnt=m/4;
        for(int j=1;j<m;j++) {
            if(fr[j] && fr[j-1] && !bo(j) && cnt>0) {
                fr[j]=fr[j-1]=false;
                if(s[j]!=s[j-1]) mx++;
                cnt--;
            }
        }
        for(int j=1;j<m;j++) {
            if(fr[j] && fr[j-1] && bo(j) && cnt>0) {
                fr[j]=fr[j-1]=false;
                mx++;
                cnt--;
            }
        }
        for(int j=0;j<m;j++) {
            if(s[j]=='1' && fr[j]) mx++;
        }
    }
    printf("%d %d",mn,mx);
    return 0;
}