#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int t;cin>>t;while(t--){
string s;cin>>s;char ch;cin>>ch;int stat=0;
for(int i=0;i<s.size();i++){
    if(s[i]==ch){
        if(i%2==0)stat++;
    }
}
if(stat)cout<<"yes\n";else cout<<"no\n";
}

	
}