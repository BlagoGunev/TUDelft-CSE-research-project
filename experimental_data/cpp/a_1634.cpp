#include<bits/stdc++.h>

using namespace std;



#define uwu ios::sync_with_stdio(false);cin.tie(NULL);



const int MOD = 1e9 + 7;

const int N = 3e5 + 5;

const long long INF = 2e18;



int main()

{

    uwu

    int t;

    cin>>t;

    while(t--)

    {

        int n,k,pal=1;

        string s,temp;

        cin>>n>>k;

        cin>>s;

        temp=s;

        reverse(s.begin(),s.end());

        if(k==0 || temp == s)

            cout<<1<<endl;

        else cout<<2<<endl;



    }

}