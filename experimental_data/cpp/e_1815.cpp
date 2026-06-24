#include<bits/stdc++.h>
using namespace std;
 
vector <int> prime;
bool p[1000001];
 
const long long int mod=998244353;
 
void init(){
    p[1]=0;
    for(int i=2;i<=1000000;i++){
        p[i]=1;
    }
    for(int i=2;i<=1000000;i++){
        if(p[i]){
            prime.push_back(i);
        }
        for(int j=i;j<=1000000;j+=i){
            p[j]=0;
        }
    }
    return;
}
 
long long int bigmod(long long int n,long long int k){
    long long int pown=n,ans=1;
    while(k>0){
        if(k%2){
            ans*=pown;
            ans%=mod;
        }
        pown*=pown;
        pown%=mod;
        k/=2;
    }
    return ans;
}
 
int vp(long long int n,int p){
    int ans=0;
    if(n==0){
        return 10000000;
    }
    while(n%p==0){
        n/=p;
        ans++;
    }
    return ans;
}
 
string rpc(string str){
    int i=0;
    int len=str.length();
    int j=-1;
    int nextval[len];
    nextval[i]=-1;
    while (i<len){
        if (j==-1||str[i]==str[j]){
            i++;
            j++;
            nextval[i]=j;
        }
        else
        j=nextval[j];
    }
    if ((len)%(len-nextval[len])==0) return str.substr(0,len-nextval[len]);
    else return str;
}
 
int main(){
    init();
    int n;
    cin >> n;
    int lim=n;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        s=rpc(s);
        int x=0,y=0,ptr=0;
        bool b=true;
        do{
            if(b){
                x++;
            }
            else{
                y++;
            }
            if(s[ptr]=='0'){
                b=1-b;
            }
            ptr++;
            ptr%=s.length();
        }while(!b||(ptr!=0));
        arr[i]={x,y};
        if(y==0&&lim==n){
            lim=i;
        }
    }
    long long int times[n+1];
    for(int i=0;i<=n;i++){
        times[i]=1;
    }
    for(int i=0;i<prime.size();i++){
        int p=prime[i],curl=0,curr=0,difp[lim+1]={0};
        for(int j=1;j<=lim;j++){
            int l=vp(arr[j-1].first,p);
            int r=vp(arr[j-1].second,p);
            if(curr<l){
                curl+=(l-curr);
                curr=r;
            }
            else{
                curr+=(r-l);
            }
            difp[j]=r-l;
        }
        int cur=curl;
        for(int j=0;j<=lim;j++){
            cur+=difp[j];
            times[j]*=bigmod(p,cur);
            times[j]%=mod;
        }
    }
    long long int ans=0;
    for(int i=0;i<=lim;i++){
        ans+=times[i];
        ans%=mod;
    }
    cout << (2*ans)%mod << endl;
}