#include<bits/stdc++.h>
using namespace std;
int po[100010];
int hash1[100010];
int hash2[100010];
int f[100010][35];
int mod=1e9+71;
int h1(int x){
    if(x<0) return 0;
    return hash1[x];
}
int h2(int x){
    if(x<0) return 0;
    return hash2[x];
}
bool gethash(int i,int j,int x){
    if(((1LL*h1(i-1)*po[x]%mod)-h1(i+x-1) +mod) %mod == ((1LL*h2(j-1)*po[x]%mod)-h2(j+x-1) +mod) %mod) return 1;
    return 0;
}
string s,t;
int reachMax(int i,int j){
    int l=0,r=min(s.size()-i,t.size()-j);
    while(l<r){
        int mid = (l+r+1)/2;
        if(gethash(i,j,mid)){
            l=mid;
        }
        else r=mid-1;
    }
    return l;
}
int main()
{
    int x;
    //freopen("test.inp","r",stdin);
    po[0]=1;
    for(int i=1;i<=1e5;i++){
        po[i]=1LL*po[i-1]*27%mod;
    }
    cin>>x;
    cin>>s;
    for(int i=0;i<s.size();i++){
        hash1[i]=(1LL*h1(i-1)*27+s[i]-'a'+1)%mod;
        //printf("%d %d\n",hash1[i],h1(i)-h1(i-1));
    }
    hash1[s.size()]=1LL*h1((int)s.size()-1)*27%mod;
    cin>>x;
    cin>>t;
    for(int i=0;i<t.size();i++){
        hash2[i]=(1LL*h2(i-1)*27+t[i]-'a'+1)%mod;
        //printf("%d %d %lld\n",hash2[i],h2(i)-h2(i-1),(h2(i)-h2(i-1))*27LL);
    }
    hash2[s.size()]=1LL*h2((int)s.size()-1)*27%mod;
    cin>>x;
    for(int pos=0;pos<s.size();pos++){
        for(int chosen=0;chosen<=x;chosen++){
            int cur=f[pos][chosen];
            int tmp=reachMax(pos,cur);
            //printf("f[%d][%d] = %d and get max %d\n",pos,chosen,cur,tmp);
            f[tmp+pos][chosen+1]=max(tmp+cur,f[tmp+pos][chosen+1]);
            f[pos+1][chosen]=max(f[pos+1][chosen],cur);
            if(f[pos][chosen]>=t.size()){
                cout<<"YES"; exit(0);
            }
            if(chosen<x && f[pos][chosen]+tmp>=t.size()){
                cout<<"YES"; exit(0);
            }
        }
    }
    cout<<"NO";
}