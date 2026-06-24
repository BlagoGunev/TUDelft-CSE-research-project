//13feb2023(1:41AM)

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;



//Definition Section

//--------------------------------------------------------------

#define fl(i,x,y) for( i=x; i<y; i++)

#define flc(i,x,y,z) for(int i=x; i<y; i+=z)

#define nl cout<<endl

#define yes cout<<"YES"<<endl;

#define no cout<<"NO"<<endl;

#define p-1 cout<<"-1"<<endl;

#define vcd(v) vector<ll> (v);

#define vcsort(vc) sort(v.begin(), v.end());

#define vcsortg(vc) sort(v.begin(), v.end(), greater<int>());

#define getintovc(vc,n) { while(n--) {long long yyy; cin>>yyy; vc.push_back(yyy);}}

#define all(x) x.begin(),x.end()

#define pb push_back

#define printvc(vc) for(int i=0; i<vc.size(); i++) cout<<vc[i]<<" ";

#define ff first

#define ss second

#define faster; {ios::sync_with_stdio(false); cin.tie(NULL);}

//--------------------------------------------------------------

void sol()

{

    ll n,k,i,p1=0,n1=0,p2=0,n2=0;

    cin>>n;

    k=n;

    vcd(vc1);vcd(vc2);

    getintovc(vc1,n);

    n=k;

    getintovc(vc2,n);

    ll x=0,y=0,mm=0;

        if(vc1[0]==1)x++;

        if(vc1[0]==-1)y++;

        if(vc1[0]!=vc2[0])mm=1;



        for(int i=1;i<k;i++)

        {



            if(vc1[i]<vc2[i] && x==0)mm=1;

            else if(vc1[i]>vc2[i] && y==0)mm=1;

            if(vc1[i]==1)x=1;

            if(vc1[i]==-1)y=1;

        }

        if(mm)cout<<"NO"<<endl;

        else cout<<"YES"<<endl;









}



int main()

{

    faster;

    ll tc;

    cin>>tc;

    while(tc--)

        sol();













  //main();

}