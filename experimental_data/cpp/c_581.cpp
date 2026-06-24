#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> a(101,0),b(10,0);
    int x;
    long long ans=0;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        b[x%10]++;
        a[x]++;
        ans=ans+x/10;
    }
    for(int i=9;i>0;i--){
        //cout<<b[i]<<" "<<i<<endl;
        if(k<=b[i]*(10-i)){
            ans=ans+k/(10-i);
            cout<<ans;
            return 0;
        }
        k=k-b[i]*(10-i);
        //cout<<k<<endl;
        ans+=b[i];
        for(int j=i;j<=100;j+=10){
            a[j+10-i]+=a[j];
        }
    }
    for(int i=0;i<100;i+=10){
        if(i!=0)
            a[i]=a[i]+a[i-10];
        if(k<=a[i]*10){
            ans=ans+k/10;
            cout<<ans;
            return 0;
        }
        k=k-a[i]*10;
        ans+=a[i];
    }
    cout<<ans;
    return 0;
}