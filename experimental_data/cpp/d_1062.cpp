#include<bits/stdc++.h>
    #define ll long long 
    #define pb push_back 
    #define ins insert
    #define rs resize
    #define br break;
    #define cont continue;
    #define vi vector<int>
    #define vll vector<long long>
    #define si set<int>
    #define sll set<long long>
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
    #define vec vector
    #define cend cout<<endl;
    #define sc second
    #define fr first
    using namespace std;
    


    //###############--MATHS--##################
    ll modex(ll a,ll b,ll m){
      if(b==0)return 1;
      ll ans=a;
      ll save=1;
      while(b!=1){
          if(b%2==1){
              save*=ans;
             save%=m;
        }
        ans*=ans;
        ans%=m;
        b/=2;
      }
      return (ans*save)%m;
     }

    ll mx,my;

    void solve(ll a,ll b){
      if(b==0){
          mx=1;
          my=0;
          return;
      }
      solve(b,a%b);
      ll x1=mx;
      ll y1=my;
      mx=y1;
      my=x1-(a/b)*y1;
    }

   ll mi(ll x,ll m){
      solve(x,m);
      return (mx+m)%m;
    }
    vector<ll>p;
    vector<bool>prime;
    void seive(int n){
      prime.resize(n+1);
      for(int i=2;i<prime.size();i++)prime[i]=1;
      for(int i=2;i*i<=n;i++){
          if(!prime[i])continue;
          int j=i+i;
          while(j<=n){
            prime[j]=0;
            j+=i;
          }


      }
        for(int i=2;i<=n;i++)if(prime[i])p.pb(i);


    }

    vector<ll>lpd;

    void lpdgen(int n){
      prime.resize(n+1);
      lpd.resize(n+1,0);
      for(int i=2;i<=n;i++)prime[i]=1;
      for(int i=2;i*i<=n;i++){
          if(!prime[i])continue;
          int j=i+i;
          while(j<=n){
            prime[j]=0;
            if(lpd[j]==0)lpd[j]=i;
            j+=i;
          }

      }
        for(int i=2;i<=n;i++)if(prime[i])lpd[i]=i;

    }
    template<typename T>
    vector<T> compfactor(T x){
      vector<T>ret;
      while(x!=1){
        ret.pb(lpd[x]);
        x/=lpd[x];
      }
      return ret;
    }
    template<typename T>
    vector<T> pfactor(T x){
      vector<T>ret;
      while(x!=1){
        if(ret.size()==0 || ret[ret.size()-1]!=lpd[x])ret.pb(lpd[x]);
        x/=lpd[x];
      }
      return ret;
    }

    vector<ll>fact;
    void factgen(ll n,ll m){
      fact.resize(n+1);
      fact[0]=1;
      for(ll i=1;i<=n;i++){fact[i]=i*fact[i-1];fact[i]%=m;}
    }
    template<typename T>
    vector<T> factor(T x){
      vector<T>ret;
      for(ll i=1;i*i<=x;i++){
        if(i*i==x){
          ret.push_back(i);
          break;
        }

        if(x%i==0){ret.push_back(i);ret.push_back(x/i);}
      }
      return ret;

    }


    //##########################################


    //#######--initializers--###################
        template<typename T>
        void init(vector<T>& x,T n){
          for(int i=0;i<x.size();i++)x[i]=n;
        }
        template<typename T>
        void init2(vector<vector<T> >& x,T n){
          for(int i=0;i<x.size();i++)
            for(int j=0;j<x[i].size();j++)x[i][j]=n;
        }
      template<typename T>
        void init3(vector<vector<vector<T> >  >& x,T n){
          for(int i=0;i<x.size();i++)
            for(int j=0;j<x[i].size();j++)
                for(int k=0;k<x[i][j].size();k++)x[i][j][k]=n;
        }

        template<typename T>
        void inits2(vector<vector<T> >& x,int a,int b){
          x.rs(a);
          for(int i=0;i<x.size();i++)x[i].rs(b);
        } 
      template<typename T>
        void inits3(vector<vector<T> >& x,int a,int b,int c){
          x.rs(a);
          for(int i=0;i<x.size();i++){x[i].rs(b);for(int j=0;j<x[i].size();j++)x[i][j].rs(c);}
        } 

    //############################################



    //#########--min&&max--##############
      template<typename T>
      T minarr(T* arr,int n){
        T x=arr[0];
        for(int i=0;i<n;i++)x=min(x,arr[i]);
        return x;
      }
      template<typename T>
      T maxarr(T* arr,int n){
        T x=arr[0];
        for(int i=0;i<n;i++)x=max(x,arr[i]);
        return x;
      }
      template<typename T>
      T minarr(vector<T>& arr){
        T x=arr[0];
        for(int i=0;i<arr.size();i++)x=min(x,arr[i]);
        return x;
      }
      template<typename T>
      T maxarr(vector<T>& arr){
        T x=arr[0];
        for(int i=0;i<arr.size();i++)x=max(x,arr[i]);
        return x;
      }

    //################################




    //############--printer&&scanner--############
    

    template<typename T>
    void prt(vector<T>& x,int n){
      for(int i=0;i<n;i++)cout<<x[i]<<" ";
    }
    template<typename T>
    void prt(T* x,int n){
      for(int i=0;i<n;i++)cout<<x[i]<<" ";
    }
    template<typename T>
    void prtl(vector<T>& x,int n){
      for(int i=0;i<n;i++)cout<<x[i]<<endl;
    }
    template<typename T>
    void prtl(T* x,int n){
      for(int i=0;i<n;i++)cout<<x[i]<<endl;
    }
    template<typename T>
    void scan(T* arr,int n){
      for(int i=0;i<n;i++)cin>>arr[i];
    }
    template<typename T>
    void scan(vector<T>& ret,int n){
      for(int i=0;i<n;i++)cin>>ret[i];
    }

    //#################--string--################

    vector<int> failure(string& s){
      vector<int> f(s.size(),0);
      int ex=0;
      for(int i=1;i<s.size();i++){
        while(ex!=0 && s[ex]!=s[i])ex=f[ex-1];
        if(ex==0){
          if(s[ex]!=s[i]){
            f[i]=0;
            ex=0;
            continue;
          }
        }
        f[i]=ex+1;
        ex++;
      }
      return f;
    }

    //###########################################
  

    
    int main(){
      int n;
      cin>>n;
      seive(n);
      ll ans=0;
      for(int i=2;i<=n;i++){
        int j=2*i;
        while(j<=n){
          ans+=(ll)4*(j/i);
          j+=i;
        }
      }
      cout<<ans<<endl;

    }