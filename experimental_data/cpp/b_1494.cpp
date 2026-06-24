#include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define int long long
    #define loop(o,n) for(int i=o;i<n;i++)
    #define sort(a) sort(a.begin(),a.end())
    #define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define print(a) for(auto &i : a)  
    #define endl "\n"
    #define lower_bound(v,x) lower_bound(v.begin(),v.end(),x)
    #define upper_bound(v,x) upper_bound(v.begin(),v.end(),x)
    #define pb push_back

    const int dx[] = { 0, 1, 0, -1 } ; 
    const int dy[] = { 1, 0, -1, 0 } ;

    bool flag ;
    void rec(vector<int>&u,int *a,int n,int i=1)
    {
       
       if(i==5)
       {
      
    if(a[0]==a[6]&&a[1]==a[2]&&a[4]==a[7]&&a[5]==a[3]){
      
        flag=true;
    }
            
            return;
       }
     
          if(u[i-1]<=n-2)
          {
             a[2*i-1]=0;
              a[2*i-2]=0;
             
             rec(u,a,n,i+1);
          }
          if(u[i-1]>=1&&u[i-1]<=n-1)
          {
              a[2*i-1]=0;
              a[2*i-2]=1;
                        

              rec(u,a,n,i+1);
              a[2*i-2]=0;
              a[2*i-1]=1;
              rec(u,a,n,i+1);



          }
          if(u[i-1]<=n&&u[i-1]>=2)
          {
            a[2*i-1]=1;
              a[2*i-2]=1;       

              rec(u,a,n,i+1);
          }

       
    }

 
   int32_t main()
   {
      int t;
      cin>>t;
      while(t--){
       int n;
       cin>>n;

       vector<int>u(4);
       int s[8]={0};
      loop(0,4){
      cin>>u[i];
  }
   
       flag = false;
       rec(u,s,n);
       if(flag)
        cout<<"YES"<<endl;
     else
     {
        cout<<"NO"<<endl;
     }


    }
    
     return 0;
          
    }