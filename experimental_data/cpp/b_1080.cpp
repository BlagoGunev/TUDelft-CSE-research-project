#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007//10^9+7
void input_arr( ll arr[],ll n)
{
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
map <ll , int > m;


void print_arr(ll arr[],ll n)
{    cout<<'\n';
    for(ll i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    cout<<'\n';
}

int main()
{     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int q;
    cin>>q;
    while(q--)
    {   ll r,l;
        cin>>l>>r;
        long long int sum=0;
        sum=(r*(r+1))/2-((l-1)*(l))/2;
       // cout<<sum<<'\n';
    
        ll l1=l,r1=r;

        if(l%2==0)
        {//cout<<'l';
            l1=l+1;
        }
        if(r%2==0)
        {  // cout<<'r';
            r1=r-1;
        }

     
         //cout<<r1<<' '<<l1<<'\n';
         ll n=((r1-l1)/2)+1;
         ll a=l1;
         ll d=2;
         //cout<<n<<' '<<a<<' '<<d<<'\n';
         long long  sumn;
         if(l1==r1)
         {
             sumn=2*l1;
         }
         else{
        sumn =(n) * ( a + (n - 1) ); 
        sumn*=2;}
        //cout<<"sumn "<<sumn<<'\n';
        cout<<sum-sumn<<'\n';
        
    }


    
    return 0;

}