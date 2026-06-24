#include <iostream>
#include <vector>
#include<chrono>
#include <algorithm>
#include <iomanip>
#include<string>
#include<stack>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<random>
typedef long long ll;
std::mt19937 randnum(std::chrono::high_resolution_clock::now().time_since_epoch().count());
int main() {
    ll n,k;
    std::cin>>n>>k;
    std::vector<ll> a(n);
    for(int i=0;i<n;i++)
        std::cin>>a[i];
    std::sort(a.begin(),a.end());
    std::map<ll,ll> col,ans;
    ll out=1e9;
    for(int i=0;i<n;i++){
        ll tec=0;
        while(a[i]>0){
            col[a[i]]++;
            ans[a[i]]+=tec;
            if(col[a[i]]>=k)
                out=std::min(out,ans[a[i]]);
            a[i]/=2;
            tec++;
        }
    }
    std::cout<<out;
    }