#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



int main(){ios_base::sync_with_stdio(false);

cin.tie(NULL);

ll t;cin>>t;

while (t--)

{

    ll x;cin>>x;

    if (x==1)

    {

        cout<<3<<endl;

    }

    else{



    ll cnt=0;

    while (x%2!=1)

    {

        x=x/2;

        cnt++;

    }

    ll ans=1;

    if (cnt==0)

    {

        ans=1;

    }

    else

    {

        while (cnt!=0)

        {

           ans=ans*2;

           cnt--;

        }

        if(x==1){

        ans+=1;}

        

        

    }

    cout<<ans<<endl;

}

    

}





return 0;

}