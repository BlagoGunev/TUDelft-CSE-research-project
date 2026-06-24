#include <bits/stdc++.h>

using namespace std;

#define int long long int



string help(string s, string a){



    string ans; int carry=0;

    reverse(s.begin(),s.end());

    for(int i=0;i<s.length();i++){

        int sub=(a[i]-'0')-(s[i]-'0')-carry;

        if(sub<0){sub+=10;carry=1;}

        else{carry=0;}



        ans+=(sub+'0');

    }



    for(int i=s.length();i<a.length();i++){

        int sub=a[i]-'0' -carry;

        if(sub<0){sub+=10;carry=1;}

        else{carry=0;}



        ans+=(sub+'0');

    }



    reverse(ans.begin(),ans.end());

    return ans;

}



void solve()

{

    //cout<<"--------------------------------"<<endl;

    int n; string s,a,ans; cin>>n>>s;

    if(s[0]=='9'){for(int i=-1;i<n;i++){a+='1';}}

    else{for(int i=0;i<n;i++){a+='9';}}



    ans=help(s,a);

    if(ans.length()==n+1){ans.erase(0,1);}

    cout<<ans<<endl;



}



int32_t main()

{

   ios_base::sync_with_stdio(false);

   int t; cin>>t;

   while(t--){solve();}

   //solve();

}