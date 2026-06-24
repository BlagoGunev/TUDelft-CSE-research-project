#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[200010];
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;scanf("%d",&n);
        ll mid=0,ans=0;
        map<ll,int>used;used[mid]=1;
        for(int i=1;i<=n;i++){
            int x;scanf("%d",&x);
            if(i%2)mid+=x;
            else mid-=x;
            if(used[mid]++)ans=1;
        }puts(ans?"YES":"NO");
    }
}