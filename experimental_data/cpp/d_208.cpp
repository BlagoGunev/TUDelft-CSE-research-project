#include<bits/stdc++.h>

using namespace std;

int main()

{

    ios::sync_with_stdio(false);

    cin.tie(NULL);

    long long n,a,b,c,d,e,p[54];

    long long bra=0,brb=0,brc=0,brd=0,bre=0,ans=0;

    cin>>n;

    for(int i=0;i<n;i++)

        cin>>p[i];

    cin>>a>>b>>c>>d>>e;

    for(int i=0;i<n;i++)

    {

        ans+=p[i];

        bre+=ans/e;

        ans%=e;

        brd+=ans/d;

        ans%=d;

        brc+=ans/c;

        ans%=c;

        brb+=ans/b;

        ans%=b;

        bra+=ans/a;

        ans%=a;

    }

    cout<<bra<<" "<<brb<<" "<<brc<<" "<<brd<<" "<<bre<<endl;

    cout<<ans<<endl;

    return 0;

}