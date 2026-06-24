#include <bits/stdc++.h>

using namespace std;

int main()

{

    string s;cin>>s;

    string a="hello";

    int sz=s.size();

    int k=0;

   for(int i=0;i<sz;i++){

   	if(s[i]==a[k]){k++;}

   }

   

   if(k==5) cout<<"YES";

   else cout<<"NO";

   

    return 0;

}