#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n;
    while(cin>>n)
    {
        string s;
        cin>> s;
        set<ll> k;
        ll ans=0;
        int fg=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='a'&&s[i]<='z'){
                k.insert(s[i]);
            }
            else{
                ans=max(ans,(ll)k.size());
                k.clear();
            }
            if(i==s.size()-1){
                ans=max(ans,(ll)k.size());
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}