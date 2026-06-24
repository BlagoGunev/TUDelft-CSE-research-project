#include<bits/stdc++.h>

#define LL long long
#define inf 1E20
#define pb push_back
#define vsort(v) sort(v.begin(),v.end())
#define pi acos(-1)
#define clr(a) memset(a,0,sizeof a)
#define bclr(a) memset(a,false,sizeof a)
#define MOD 1073741824
#define MX 200000

using namespace std;
int sum[MX+10];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n,k;
    cin>>n>>k;
    int val;
    for(int i=1;i<=n;i++){
        cin>>val;
        sum[i]=sum[i-1]+val;
    }
    int mn=sum[k];
    int pos=1;
    for(int i=k+1;i<=n;i++){
        if(sum[i]-sum[i-k]<mn){
            mn=sum[i]-sum[i-k];
            pos=i-k+1;
        }
    }
    cout<<pos<<endl;
    return 0;
}