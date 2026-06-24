#include <bits/stdc++.h>
#define mk make_pair
#define pb push_back
using namespace std;

int main () {

    bool check [101];
    int arr[105],n,k,d,t;
    cin>>t;
    while (t--) {
        scanf("%d%d%d",&n,&k,&d);
        for (int i=1;i<=n;i++) {
            scanf("%d",&arr[i]);
        }
        int m=INT_MAX,cnt;
        for (int i=1,j=d;j<=n;i++,j++){
            memset(check,true,sizeof(check));
            cnt=0;
            for (int p=i;p<=j;p++) {
                if (check[arr[p]]) {
                    check[arr[p]]=false;
                    cnt++;
                }
            }
            m=min(m,cnt);
        }
        cout << m << endl;
    }
    return 0;
}