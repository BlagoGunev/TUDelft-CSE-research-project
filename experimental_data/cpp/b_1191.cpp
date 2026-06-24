#include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
     
    using namespace std;
    using namespace __gnu_pbds; 
     
    typedef long long int ll;
    typedef  tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>  ordered_set;
     
    const ll INF=1e15;
     
    #define fi first
    #define se second
    #define pb push_back
    #define mp make_pair
    #define fastt ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
    #define pll pair<ll,ll>
    #define debug1(x) cerr<<#x<<" : "<<x<<"\n";
    #define debug2(x,y) cerr<<#x<<" : "<<x<<'\t'<<#y<<" : "<<y<<'\n';
    #define debug3(x,y,z) cerr<<#x<<" : "<<x<<'\t'<<#y<<" : "<<y<<'\t'<<#z<<" : "<<z<<'\n'
    //--------------------------------------------------//
    ll arrs[100],arrp[100],arrm[100];
    int main()
    {
       ll i,flag=0;
       string s="";//m,p,s
       for(i=1;i<=3;i++)
       {
          cin>>s;
          if(s[1]=='m')
          {
             arrm[s[0]-'0']++;
             if(arrm[s[0]-'0']==3)
                flag=1;
          }
          else if(s[1]=='p')
          {
             arrp[s[0]-'0']++;
             if(arrp[s[0]-'0']==3)
                flag=1;
          }
          else if(s[1]=='s')
          {
             arrs[s[0]-'0']++;
             if(arrp[s[0]-'0']==3)
                flag=1;
          }
       }
     
       if(flag==1)
       {
          cout<<"0\n";
       }
       else
       {
          ll ans=2,cnt=2;
          for(i=1;i<=9;i++)
          {
             if(!(arrm[i]>=1)) continue;
             if( i+2<=9 && arrm[i]>=1 && arrm[i+1]>=1 && arrm[i+2]>=1)
                cnt=0;
             else if( i+1<=9 && arrm[i]>=1 && arrm[i+1]>=1 )
                cnt=1;
             else if(arrm[i]>=1)
                cnt=2;
             if(i+2<=9 && arrm[i]>=1 && arrm[i+1]<=0 && arrm[i+2]>=1)
            ans=min(1LL,ans);
             ans=min(ans,max(0LL,3-arrm[i]));
             ans=min(ans,cnt);
          }
          for(i=1;i<=9;i++)
          {
             if(!(arrp[i]>=1)) continue;
             if( i+2<=9 &&  arrp[i]>=1 && arrp[i+1]>=1 && arrp[i+2]>=1)
                cnt=0;
             else if( i+1<=9 && arrp[i]>=1 && arrp[i+1]>=1 )
                cnt=1;
             else if(arrp[i]>=1)
                cnt=2;
             if(i+2<=9 && arrp[i]>=1 && arrp[i+1]<=0 && arrp[i+2]>=1)
            ans=min(1LL,ans);

             ans=min(ans,max(0LL,3-arrp[i]));
             ans=min(ans,cnt);
          }
          for(i=1;i<=9;i++)
          {
             if(!(arrs[i]>=1)) continue;
             if(i+2<=9 &&  arrs[i]>=1 && arrs[i+1]>=1 && arrs[i+2]>=1)
                cnt=0;
             else if( i+1<=9 && arrs[i]>=1 && arrs[i+1]>=1 )
                cnt=1;
             else if(arrs[i]>=1)
                cnt=2;
             if(i+2<=9 && arrs[i]>=1 && arrs[i+1]<=0 && arrs[i+2]>=1)
            ans=min(1LL,ans);
             ans=min(ans,max(0LL,3-arrs[i]));
             ans=min(ans,cnt);
          }
          cout<<ans<<"\n";
       }
    }