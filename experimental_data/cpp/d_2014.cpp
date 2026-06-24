#include<bits/stdc++.h>
using namespace std;
int n,d,k,bro,mom,bcnt,mcnt,l[100'005],r[100'005];
vector<int> vl[100'005],vr[100'005];
void solution(){
    cin>>n>>d>>k,bro=0,mom=0,bcnt=0,mcnt=INT_MAX;
    for(int i=1;i<=k;i++){
        cin>>l[i]>>r[i];
        vl[l[i]].push_back(i);
        vr[r[i]+1].push_back(i);
    }
    set<int> s;
    int ql=1,qr=0;
    while(ql+d-1<=n){
        while(qr-ql+1<d) for(int i:vl[++qr]) s.emplace(i);
        if(s.size()>bcnt) bro=ql,bcnt=s.size();
        if(s.size()<mcnt) mom=ql,mcnt=s.size();
        for(int i:vr[++ql]) s.erase(i);
    }
    cout<<bro<<' '<<mom<<'\n';
    for(int i=1;i<=n+1;i++) vl[i].clear(),vr[i].clear();
}
int T;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>T;
    while(T--) solution();
    return 0;
}