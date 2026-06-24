#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
pair<int,int>x[1000050];
pair<int,int>ans[1000050];
int lk[1000050];
pair<int,int> stk[1000050];
int tp=0;
bool cmp(pair<int,int>a,pair<int,int>b){
    return a.second<b.second;
}
bool cmp1(pair<int,int>a,pair<int,int>b){
    return a.first>b.first;
}
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i].first;
        x[i].second=i;
    }
    sort(x+1,x+n+1,cmp1);
    int nw=0,lst;
    for(int i=1;i<=n;i++){
        if(x[i].first==0){
            nw++;
            ans[x[i].second]=make_pair(nw,1);
            lst=x[i].second;
            lk[x[i].second]=x[i].second;
            continue;
        }
        if(i<n&&x[i].first==x[i+1].first){
            nw++;
            ans[x[i].second]=make_pair(nw,x[i].first);
            nw++;
            ans[x[i+1].second]=make_pair(nw,1);
            lk[x[i].second]=x[i+1].second;
            lk[x[i+1].second]=x[i].second;
            lst=x[i+1].second;
            i++;
            continue;
        }else{
            stk[++tp]=x[i];
        }
    }
    int cnt=1;
    for(int i=1;i<=tp;i++){
        if(cnt-stk[i].first+1>=1){
            cnt=cnt-stk[i].first+1;
        }else{
            cnt=cnt+stk[i].first-1;
        }
        nw++;
        ans[stk[i].second]=make_pair(nw,cnt);
        lk[stk[i].second]=lst;
        lst=stk[i].second;
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
    for(int i=1;i<=n;i++){
        printf("%d ",lk[i]);
    }
}