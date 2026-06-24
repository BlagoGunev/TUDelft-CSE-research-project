/*CODE BY VIJAY MUKHIJA*/
#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define lli long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define MOD 1000000007
using namespace std;
vector<int>fwd(201,0),bwd(201,0);
void process(string a,string b)
{
    int n = a.length();
    int j = 0;
    // store subsequence count in forward direction
    for (int i = 1; i <=a.length(); i++) {
        if (j < b.length() && a[i - 1] == b[j])
            j++;

        // store number of matches till now
        fwd[i] = j;
    }
    j = 0;
    // store subsequence count in backward direction
    for (int i = a.length(); i >= 1; i--) {
        if (j < b.length() &&
            a[i - 1] == b[b.length() - j - 1])
            j++;

        // store number of matches till now
        bwd[i] = j;
    }
}
int main()
{
    string s;
    cin>>s;
    string t;
    cin>>t;
    process(s,t);
    int ans=0;
    for(int i=1;i<=s.length();i++)
    {
        for(int j=i;j<=s.length();j++)
        {
            if(fwd[i-1]+bwd[j+1]>=t.length())
            {
                ans=max(ans,j-i+1);
            }
        }
    }
    cout<<ans<<endl;
}