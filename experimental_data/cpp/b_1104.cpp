#include<bits/stdc++.h>
#define pb push_back
#define mod 1000000007
#define ll long long int
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll gcd(ll a,ll b){if(a==0)return b;return gcd(b%a,a);}          
ll lcm(ll a,ll b){return (max(a,b)/gcd(a,b))*min(a,b);}

void build()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}
ll modexp(ll base,ll exponent,ll modulus)
{if(modulus ==1)return 0;ll result=1;base=base % modulus;
while(exponent>0){if(exponent%2==1){result=(result*base) % modulus;}exponent=exponent>>1;
base = (base*base) % modulus;}return result;}
int main()
{
    FIO;
    build();
    string s;
    cin>>s;
    stack<int> st;
    st.push(s[0]-'a'+1);
    int count=0;
    for(int i=1;i<s.length();i++)
    {
        int x=s[i]-'a'+1;
        if(st.size() && st.top()==x)
        {
            st.pop();
            count++;
        }
        else
            st.push(x);
    }
    //cout<<count;
    if(count%2==0)
        cout<<"No";
    else
        cout<<"Yes";
}