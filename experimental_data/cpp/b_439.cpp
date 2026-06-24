#include <iostream>
#include <algorithm>
using namespace std;
int n,x;
int t[100000];
long long input(){
    cin>>n>>x;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>t[i];
        sum+=t[i];
    }
    sort(t,t+n);
    long long sum1=0;
    long long ans=sum*x;
    for(int i=0;i<n&&x-i>1;i++){
        sum1+=t[i];
        ans-=(sum-sum1);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cout<<input();
    return 0;
}