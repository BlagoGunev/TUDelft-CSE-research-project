/*

        author :- sairaj

*/

#pragma GCC optimize("O1")

#include<bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()

#define sortv(a) sort(all(a))

#define sortvg(a) sort(all(a),greater<>());

#define int long long

#define endl "\n"

#define SPEED {ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);}

template<class T>

void display(T a)

{

    for(auto& it:a)

    {

        cout<<it<<" ";

        cout<<endl;

    }

}

int mul(int n)

{

    int a,b;

    a=n%10;

    b=a;

    n=n/10;

    while(n)

    {

        int temp = n%10;

        n=n/10;

        a=max(a,temp);

        b=min(b,temp);

    }

    return a*b;

}

bool iszero(int n)

{

    while(n)

    {

        int temp = n%10;

        n/=10;

        if(!temp)

            return true;

    }

    return false;

}

void jawab()

{

    int pre,k;

    cin>>pre>>k;

    for(int i=1;i<k;i++)

    {

        if(iszero(pre))

        {

            break;

        }

        pre=pre+mul(pre);

    }

    cout<<pre<<endl;

}

int32_t main()

{

    SPEED;

    int t=1;

    cin>>t;

    while(t--)

    {

        jawab();

    }

    return 0;

}