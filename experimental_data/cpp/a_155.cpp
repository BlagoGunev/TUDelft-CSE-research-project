#include <iostream>
using namespace std;
int main(){

    int n,i,k,ans=0;
    cin >> n;
    cin >> k;
    int maxn=k,minn=k;
    for (i=1;i<n;i++){
        cin >> k;
        if (minn>k){ minn = k; ans++;}
        if (maxn<k){ maxn = k; ans++;}
    }
    cout << ans;
    return 0;
}