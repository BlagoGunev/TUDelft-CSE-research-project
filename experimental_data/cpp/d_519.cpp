#include<bits/stdc++.h>

#include <stdio.h>

#define mod1 1000000007

#define pi 3.141592653589793238462643383279;



using namespace std;



int main()

{

    vector<unordered_map<long long int,long long int> > v(26);

    vector<long long int> value(26);

    for(int i=0;i<26;i++)

    {

        cin>>value[i];

    }

    string s;

    long long int sum=0,ans=0;



    cin>>s;

    for(int i=0;i<s.length();i++)

    {

        unordered_map<long long int,long long int>  &m=v[s[i]-'a'];

        if(m.find(sum)!=m.end())

            ans+=m[sum];

        sum+= value[s[i]-'a'];

        m[sum]++;

    }

    cout<<ans<<endl;

    //int zz;cin>>zz;

    return 0;

}