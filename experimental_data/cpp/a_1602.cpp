#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef pair<int,int> ppair;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,i,n;
    string s;
    char a;
    cin>>t;
    while(t--){
        cin>>s;
        n = s.length();
        auto it = min_element(s.begin(),s.end());
        a = *it;
        s.erase(it);
        cout<<a<<" "<<s<<"\n";
    }
}