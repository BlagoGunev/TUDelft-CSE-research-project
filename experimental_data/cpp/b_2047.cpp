#include <bits/stdc++.h>
using namespace std;
int main(){
	  ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        vector<pair<int,char>>v;
        for(auto i:mp)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end());
        int m=v.size();
        char ch1=v[0].second;
        char ch2=v[m-1].second;
        for(int i=0;i<n;i++)
        {
             if(s[i]==ch1)
             {
                s[i]=ch2;
                break;
             }
        }
        cout<<s<<endl;



    } 
}