#include<bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

typedef long long ll;

typedef long double ld;

void test_case()

{

    string s;

    cin>>s;

    ll sz=s.size();

    for(int i=0;i<sz;i++)

    {

        if(i%2==0)

        {

            for(char a='a';;a++)

            {

                if(s[i]!=a)

                {

                    s[i]=a;

                    break;

                }

            }

        }

        else

        {

            for(char a='z';;a--)

            {

                if(s[i]!=a)

                {

                    s[i]=a;

                    break;

                }

            }

        }

    }

    cout<<s<<endl;



}

int main()

{

    FIO

//  freopen("input.txt","rt",stdin);

//  freopen("output.txt","wt",stdout);

    ll t;

    t=1;

    cin>>t;

    while(t--)

    {

        test_case();

    }

}