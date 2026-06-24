#include <iostream>
#include <string>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include<unordered_map>
#include <set>
#include <cstring>
#include <iomanip>
#include <list>
#include <bitset>
//#include<bits/stdc++.h>
#define itn int
#define mp make_pair
#define endl "\n"
#define M_PI 3.14159265358979323846
using namespace std;
typedef long long ll;
int mod = 1e9 + 7 ;
ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
ll gcd(ll a , ll b){return b==0?a:gcd(b,a%b); }
int mat[40][40];
int mark[40];
int reach[40];
vector<ll> vec;
int before[40];
void dfs(ll ver)
{
    ll i,j;
    reach[ver]=1;
    //cout<<(char)(ver+'a')<<endl;
    for(i=0;i<26;i++)
    {
        if(mat[ver][i]==1 && reach[i]==0)
        {
            dfs(i);
        }
    }
    vec.push_back(ver);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n,i,j;
    string str;
    cin>>n;
    for(i=0;i<n;i++)
    {
        
        cin>>str;
        for(j=0;j<str.length();j++)
        {   mark[str[j]-'a']=1;
            if(j>0)
                before[str[j]-'a']=1;
        }
        for(j=0;j<str.length()-1;j++)
        {
            mat[str[j]-'a'][str[j+1]-'a']=1;
            
        }
    }
    /*for(i=0;i<26;i++)
    {
        //for(j=0;j<26;j++)
            cout<<before[i]<<" ";
        //cout<<endl;
    }*/
    for(i=0;i<26;i++)
    {
        if(reach[i]==0&& before[i]==0)
        {
            dfs(i);
        }
    }
    //cout<<"here";
    memset(reach,0,sizeof(reach));
    for(i=vec.size()-1;i>=0;i--)
    {
        if(mark[vec[i]])
        {
               cout<<(char)(vec[i]+'a');
            reach[vec[i]]=1;
        }
    }
    //cout<<"hrere also";
    for(i=0;i<26;i++)
    {
        if(mark[i] && reach[i]==0)
            cout<<(char)(i+'a');
    }
    
}