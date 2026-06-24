#include <bits/stdc++.h>
using namespace std;
vector<int>v;
bool prime(int num) {
    for(int i=2; i*i<=num+1; i++)if(num%i==0) return false;
    return true;
}
int main()
{
    int i, k, len, n, coun;
    bool ck=false;
    cin>>n>>k;

    if(k==1) return printf("%d\n", n), 0;
    if(prime(n))return puts("-1"), 0;

    for(i=2, coun=0; i<=n && !ck; i++){
        if(n%i==0) {
            while(n%i==0){
                coun++;
                if(coun==k && n>1){
                    ck=true;
                    v.push_back(n);
                    break;
                }
                v.push_back(i); n/=i;
            }
            if(coun==k-1 && n>1){
                ck=true;
                v.push_back(n);
                break;
            }
            i = 2;
            if(ck) break;
        }
    }
    if(ck){
        for(i=0; i<(int)v.size(); i++){
            if(i) printf(" ");
            printf("%d", v[i]);
        }puts("");
    }
    else puts("-1");
}