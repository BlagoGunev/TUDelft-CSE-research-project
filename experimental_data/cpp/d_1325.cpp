#include <bits/stdc++.h>



#define itn  long long

#define int  long long

#define double long double

//#define endl '\n'

#define p_b push_back

#define fi first

#define se second

#define pii std::pair<int, int>

#define oo LLONG_MAX

#define big INT_MAX

#define elif else if



using namespace std;



int input()

{

    int x;

    cin>>x;

    return x;

}



void solve()

{



    int x, s;

    cin>>x>>s;

    if(x>s)

    {

        cout<<-1;

        return;

    }

    if(s==0)

    {

        cout<<0;

        return;

    }

    if((s-x)%2!=0)

    {

        cout<<-1;

        return;

    }

    if(s==x)

    {

        cout<<1<<endl<<s;

        return;

    }

    itn p=(s-x)/2;

    if((x&p)==0)

    {

        cout<<2<<endl<<(p|x)<<' '<<p;

        return;

    }

    cout<<3<<endl<<p<<' '<<p<<' '<<x;





}



int32_t main()

{

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    cout.tie(NULL);



//        freopen("network.in", "r", stdin);

//        freopen("magic.txt", "w", stdout);





    int t=1;

//    cin>>t;

    while(t--)

    {

        solve();



        cout<<endl<<endl;

    }





}