#include<bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define ll long long
#define endl "\n"
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define Fi first
#define Se second
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define itr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define mod 1000000007

void solve() {
    string s; cin>>s;
    int n=s.size();
    if(n==1){
        if((s[0]-'0')&1){
            cout<<-1<<endl; return;
        }
        cout<<0<<endl; return;
    }
    int temp=s[n-1]-'0';
    if(temp&1){
        if(!((s[0]-'0')&1)){
            cout<<1<<endl; return;
        }
        for(int i=1;i<n;i++){
            temp=s[i]-'0';
            if(!(temp&1)){
                cout<<2<<endl; return;
            }
        }
        cout<<-1<<endl; return;
    }
    else {
        cout<<0<<endl; return;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int test = 1;
    cin >> test;
    //int i=1;
    while(test--) {
      //cout<<"test case "<<i++<<" :"<<endl;
      solve();
    }
    return 0;
}