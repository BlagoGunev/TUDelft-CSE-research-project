#include <bits/stdc++.h>



using namespace std;

#define ll long long int

#define all(a) (a).begin(),(a).end()

#define endl '\n'



void TOS()

{

   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    #ifndef ONLINE_JUDGE 

    freopen("input.txt","r",stdin);

    freopen("output.txt","w",stdout);

    #endif      

}



#ifndef ONLINE_JUDGE

   #include <one.hpp>

#else

   #define debug (...)

#endif





vector<pair<ll,ll>> dx={{0,-1},{0,-1},{1,1},{-1,-1},{1,0},{0,1},{0,1},{0,1},{-1,-1},{1,1},

                        {-1,0},{0,-1}};



vector<pair<ll,ll>> dy={{-1,-1},{1,0},{0,1},{0,1},{0,1},{-1,-1},{1,1},{-1,0},{0,-1},{0,-1},

                        {0,1},{1,1}};



ll dxx[]={-1,-1,0,1,1,1,0,-1};

ll dyy[]={0,1,1,1,0,-1,-1,-1};









void solve()

{   

    ll n,m;

    cin >> n >> m;

    char arr[n+1][m+1];

    for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) cin >> arr[i][j];

    

    

    ll cnt=1;

    for(ll i=1;i<=n;i++)

    {

        for(ll j=1;j<=m;j++)

        {

            if(arr[i][j]=='*')

            {

                for(ll k=0;k<12;k++)

                {

                    if(i+dx[k].first>0 && i+dx[k].first<=n && i+dx[k].second>0 && i+dx[k].second<=n

                        && j+dy[k].first>0 && j+dy[k].first<=m && j+dy[k].second>0 && j+dy[k].second<=m

                        && arr[i+dx[k].first][j+dy[k].first]=='*' && arr[i+dx[k].second][j+dy[k].second]=='*')

                    {

                        arr[i][j]=cnt;

                        arr[i+dx[k].first][j+dy[k].first]=cnt;

                        arr[i+dx[k].second][j+dy[k].second]=cnt++;

                        break;

                    }



                }

            }

        }

    }







    for(ll i=1;i<=n;i++)

    {

        for(ll j=1;j<=m;j++)

        {

            if(arr[i][j]!='.')

            {

                char d=arr[i][j];

                for(ll k=0;k<8;k++)

                {

                    if(i+dxx[k]>0 && i+dxx[k]<=n && j+dyy[k]>0 && j+dyy[k]<=m

                        && arr[i+dxx[k]][j+dyy[k]] != '.'&& arr[i+dxx[k]][j+dyy[k]] != d)

                    {

                        cout<<"NO"<<endl;

                        return;

                    }

                }

            }

            if(arr[i][j]=='*')

            {

                cout<<"NO"<<endl;

                return;

            }

        }

    }      

    cout<<"YES"<<endl; 

}





int main()

{

    TOS();





    

    ll qq_itr=1;

    cin >> qq_itr;

    while (qq_itr--)

        solve();

}