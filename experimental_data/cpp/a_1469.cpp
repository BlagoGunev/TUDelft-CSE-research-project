#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#define ull unsigned long long int

#define endl '\n'

#define yes cout<<"YES\n"

#define no cout<<"NO\n"

#define f(i,a,b) for(ll i = a; i <= b; i++)

#define fr(i,a,b) for(ll i = a; i >= b; i--)

#define pb push_back

#define all(x) x.begin(),x.end()

#define sz(x) ((int)(x).size())

#define llceil(a,b) ceil(((double)a)/((double)b))

#define llfloor(a,b) floor(((double)a)/((double)b))

#define vec vector<ll>

#define dvec vector<vector<ll>>

//////*************Nitin1605***************//////



int main()

{

    ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);

    cout << fixed << setprecision(0);

    ll TESTCASES=1;

    cin>>TESTCASES;

    while(TESTCASES--)

    {

        string s;

        int c=0,flag=1,op=0;

        cin >> s;

        op=s.length()/2-count(all(s),'(');

        f(i,0,s.length()-1)

        {

            if(s[i]=='?')

            {

                if(op>0)

                {

                    s[i]='(';

                    op--;

                }

                else s[i]=')';

            }

        }

        for(auto i : s)

        {

            if(i=='(')c++;

            if(i==')')

            {

                if(c==0){flag=0;break;}

                else c--;

            }

        }

        if(c!=0)flag=0;

        if(flag)yes;

        else no;

    }

}