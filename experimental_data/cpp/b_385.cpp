/************************************************\

*                                                *

* Submission By Deepanshu Luhach aka DragonFist  *

* Institution Name: Army Institute of Technology *

*            Go on Hack MY Code.                 *

*                                                *

\************************************************/

#include<bits/stdc++.h>

using namespace std;



typedef long long ll;

typedef unsigned long long ull;

typedef vector<long long int> vl;

#define PI 3.14159265359



int main()

{

    //    freopen("easy.in","r",stdin);

    //freopen("easy.out","w",stdout);

    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

    string s;

    int x=0,n,y=0,z=0,a=0,b=0,i;

    cin>>s;

    n=s.length();

    for(i=0;i<n-3;i++)

    {

        if(s[i]=='b'&&s[i+1]=='e'&&s[i+2]=='a'&&s[i+3]=='r')

        {

            y=y+(i-x+1)*(n-i-3);

            x=i+1;

        }

    }

    cout<<y;

}