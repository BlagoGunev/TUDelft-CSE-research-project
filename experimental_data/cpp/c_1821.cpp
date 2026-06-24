#include<bits/stdc++.h>
using namespace std;
#define pn(x) cout<<x<<endl;
#define ps(x) cout<<x<<' ';
#define endo cout<<endl;
#define printv(v) for(auto x:v){ps(x);}endo;
#define printve(v) for(auto x:v){ps(x);};
typedef long long int ll;

int help(string &s,ll &n){
    int maxi=0;
    // count maximum number of consecutive '0' in the string s
    int count=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            count++;
        }
        else{
            maxi=max(maxi,count);
            count=0;
        }
    }
    maxi=max(maxi,count);
    vector<int>v(maxi+1,0);
    for(int i=0;i<v.size();i++){
        if(i==0)v[0]=0;
        if(i==1)v[1]=1;
        if(i==2)v[2]=2;
        if(i==3)v[3]=2;
        if(i==4)v[4]=3;
        if(i>4){
            v[i]=v[i/2]+1;
        }
    }
    // if(v.size()>6)cout<<v[6]<<endl;
    return v[maxi];
}

void solution(){
    ll n,m;
    // cin>>n;
    // cin>>m;
    string s;
    cin>>s;
    n=s.length();
    m=INT_MAX;
    for(char c='a';c<='z';c++){
        string t=s;
        for(int i=0;i<n;i++){
            if(t[i]==c){
                t[i]='1';
            }
            else t[i]='0';
        }
        m=min(m,(long long)help(t,n));
        // if(s=="mewheniseearulhiiarul" && m==5)cout<<c<<" ";
    }
    pn(m);
    return;
}
int main(){
    int _=1;
    cin>>_;
    while(_--){
        solution();
    }
    return 0;
}