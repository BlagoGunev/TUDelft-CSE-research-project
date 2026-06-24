/*************************************/
/************************************/
/**\ BISMILLAHIR RAHMANIR RAHEEM    /
/**\      SHARIFUL ISLAM           /
/**\       Dept of ICE            /
/**\          NSTU               /
/**\                            /
/******************************/
/*****************************/

#include<bits/stdc++.h>
using namespace std;

#define     ll              long long int
#define     ul              unsigned long long int
#define     dob             double
#define     st              string
#define     pairl           pair<ll,ll>
#define     max3(a,b,c)     max(a,max(b,c))
#define     min3(a,b,c)     min(a,min(b,c))
#define     fr              first
#define     se              second
#define     T               true
#define     F               false
#define     nl              "\n"
#define     all(v)          v.begin(),v.end()
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     maxi            1000000000000000014
#define     mini            -100000000000014
#define     mod             1000000007
#define     an              100007
#define     mapi            map<ll,ll>
#define     pi              push_back
#define     po              pop_back
#define     ve              vector<ll>
#define     mp              make_pair
#define     PI              3.14159265
#define IOS   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    int t,p,n,sum=0;
    cin>>t;
    int arr[t];
    int arr1[t];
    for(int i=0; i<t; i++)
    {
        cin>>arr[i];
        arr1[i]=arr[i];
    }
    sort(arr,arr+t);
    int r=1;
    for(int c=t-2;c>=0;c--)
    {
        sum=sum+(arr[c]*r)+1;
        r=r+1;
    }

     cout<<sum+1<<endl;




    ///serialization...............
    int f=0;
    for(int j=t-1;j>=0;j--)
    {
        for(int i=0;i<t;i++)
        {
            if(arr[j]==arr1[i]&&f==0)
            {
                cout<<i+1;arr1[i]=-23;f++;

            }
            else if(arr[j]==arr1[i]&&f!=0)
            {
                cout<<" "<<i+1;arr1[i]=-23;
                 break;
            }
        }
    }
    cout<<endl;


    return 0;
}

///.................

///Alhamdulillah...........