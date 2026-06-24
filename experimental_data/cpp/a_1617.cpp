#include<bits/stdc++.h>

using namespace std;

#define ll long long



int main()

{

ios_base::sync_with_stdio(0);

cin.tie(0); cout.tie(0);

int t; cin>>t;

while(t--){

    string s,t; cin>>s>>t;

int a{},b{},c{},bi{},ci{};

string test = "abc";

string r{};

sort(s.begin(),s.end());

for (int i = 0; i < s.length(); i++)

{

    if (s[i]=='b')

    {

        b=i;

        break;

    }

    

}

for (int i = 0; i < s.length(); i++)

{

    if (s[i]=='c')

    {

        c=i;

    }

    if (s[i]=='a')

    {

        a++;

    }

    else if (s[i]=='b')

    {

        bi++;

    }

    else if (s[i]=='c')

    {

        ci++;

    }

    

    

    

}

if (t==test && a!=0 && b!=0 && c!=0)

{

    sort(s.begin()+b,s.begin()+c+1,greater<char>());

    cout<<s<<endl;

}

else

{

    cout<<s<<endl;

}

}

return 0;

}