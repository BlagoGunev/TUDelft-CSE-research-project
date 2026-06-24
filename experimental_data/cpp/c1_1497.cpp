#include<bits/stdc++.h>

using namespace std;



#define ll long long int 



#define no cout<<"NO"<<endl

#define yes cout<<"YES"<<endl



#define f0(i,a,b) for(auto i=a;i<b;i++)

#define f2(i,a,b) for(auto i=a;i>b;i--)

#define f1(i,a,b) for(auto i=a;i<=b;i++)





// void reverseStr(string& str, int n, int i)

// {

     

//   if(n<=i){return;}

// //  Swaping the character

//   swap(str[i],str[n]);

//   reverseStr(str,n-1,i+1);

 

//}

void solve()

{

    int n,k;

    cin>>n>>k;

    if(n%2==1)

    cout<<n/2<<" "<<n/2<<" "<<1<<endl;

  else if(n%4==0)

  cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;

  else

  cout<<(n-1)/2<<" "<<(n-1)/2<<" "<<2<<endl;

}



int main()

{

     ios_base::sync_with_stdio(0);

    cin.tie(0);

    #ifndef ONLINE_JUDGE

	    freopen("input.txt", "r", stdin);

        freopen("output.txt", "w", stdout);

    #endif

    int t;

    

    string s;

    cin>>t;

    while(t--)

    {

    solve();  

    }//end of t

}//end of main