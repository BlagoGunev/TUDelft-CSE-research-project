#include<bits/stdc++.h>

using namespace std;



#define lli long long int

const long long int mod = 998244353 ;

const long long int INF = 1e18 ;

#define endl '\n'





bool possible(lli b[],lli n)

{

    lli a[n];

    for(lli i=0;i<n;i++)

        a[i]=b[i];



    for(lli i=0;i<n-1;i++)

    {

        if(a[i+1]<a[i])

        {

            return false;

        }

        a[i+1]-=a[i];

    }

    if(a[n-1]==0)

        return true;



    return false;

}



bool ok(vector<lli> a)

{

    lli n=a.size();

    for(lli i=0;i<n-1;i++)

    {

        if(a[i+1]<a[i])

        {

            return false;

        }

        a[i+1]-=a[i];

    }

    if(a[n-1]==0)

        return true;



    return false;



}



void Print(lli a[],lli n)

{

    for(lli i=0;i<n;i++)

        cout<<a[i]<<" ";

    cout<<endl;

}





void solve()

{

    lli n;

    cin>>n;

    lli a[n];

    for(lli i=0;i<n;i++)

        cin>>a[i];



    if(possible(a,n))

    {

        cout<<"YES"<<endl;

        return;

    }



    lli pre[n],suff[n];

    pre[0]=a[0];

    for(lli i=1;i<n-1;i++)

    {

        if((a[i]>=pre[i-1])&&pre[i-1]!=-1)

            pre[i]=a[i]-pre[i-1];

        else

            pre[i]=-1;

    }



    suff[n-1]=a[n-1];

    for(lli i=n-2;i>=0;i--)

    {

        if(a[i]>=suff[i+1]&&(suff[i+1]!=-1))

            suff[i]=a[i]-suff[i+1];

        else

            suff[i]=-1;

    }



    for(lli i=1;i<n-2;i++)

    {

        if(pre[i-1]!=-1&&suff[i+2]!=-1)

        {

            lli x=pre[i-1],y=a[i],z=a[i+1],w=suff[i+2];

            vector<lli> v={x,y,z,w};

            if(ok(v))

            {

                cout<<"YES"<<endl;

                return;

            }

            v={x,z,y,w};

            if(ok(v))

            {

                cout<<"YES"<<endl;

                return;

            }

        }

    }



    swap(a[0],a[1]);

    if(possible(a,n))

    {

        cout<<"YES"<<endl;

        return;

    }

    swap(a[0],a[1]);

 

    swap(a[n-1],a[n-2]);

    if(possible(a,n))

    {

        cout<<"YES"<<endl;

        return;

    }

 

    cout<<"NO"<<endl;













   

}





int main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

    // freopen("input.txt", "r", stdin);

    // freopen("output.txt", "w", stdout);

    //seive();

    int t=1;

    cin>>t;

    while(t--)

    {

        solve();

    }

}