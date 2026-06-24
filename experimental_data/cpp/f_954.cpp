#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double 
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define I insert
#define vll vector<ll> 
#define pll pair<ll,ll>
#define vpll vector<pll >
#define endl "\n"
ll M=1e9+7;

 
ll a[3][3],b[3][3],c[3][3],d[3][3];

ll power(ll a, ll b, ll mod){
 ll x = 1, y = a;
 while (b > 0){
  if (b%2){
   x = (x*y)%mod;
  }
  y = (y*y)%mod;
  b /= 2;
 }
 return x%mod;
} 
 
 
 
void mmul(ll a[][3],ll b[][3],ll c[][3])
{
 ll i,j,k;
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   c[i][j]=0LL;
   for(k=0;k<3;k++)
   {
    c[i][j]+=(a[i][k]*b[k][j])%M;
    c[i][j]%=M;
   }
  }
 }
}
void Mnpower(ll n)
{
 ll x,y,z,i,j,k;
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   if(i==j)d[i][j]=1LL;else d[i][j]=0LL;
  }
 }
 
 x=1LL;
 while(n>=x)
 {
  if(x&n)
  {
   mmul(a,d,c);
   for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    d[i][j]=c[i][j];
   }
  }
  x<<=1LL;
  mmul(a,a,b);
  for(i=0;i<3;i++)
   {
    for(j=0;j<3;j++)
    a[i][j]=b[i][j];
   }
   
 }
}

int main() {
 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 cout<<setprecision(25);
 ll n,m,a1,b1,c1,d1,i,j,k,l,r,l1,r1;
 cin>>n>>m;
    vpll p[5],p1[5];
    
    ll kj[3][3] = {{1,1,0},{1,1,1},{0,1,1}};
    for(i=0;i<3;i++)for(j=0;j<3;j++)a[i][j]=kj[i][j];
    for(i=0;i<n;i++){
        cin>>a1>>b1>>c1;
        p[a1].pb({b1,c1});
    }
    for(i=0;i<5;i++)sort(p[i].begin(),p[i].end());
    for(i=1;i<=3;i++){
        
        if(p[i].size()==0)continue;
        j=0;
        while(true){
            l=p[i][j].F;r=p[i][j].S;j++;
            if(j>=p[i].size()) { p1[i].pb({l,r}); break; }
            while(p[i][j].F<=r+1){
                r=max(r,p[i][j].S);j++;
                if(j>=p[i].size()) { break; }
            }
            p1[i].pb({l,r});
            if(j>=p[i].size())break;
        }
        
    }
    for(i=1;i<=3;i++) 
    {p1[i].pb({m+1,m+1}); //for(j=0;j<p1[i].size();j++)// cout<<p1[i][j].F<<' '<<p1[i][j].S<<endl;cout<<endl;
    }
    
    
    ll o[]={0,0,0,0};
    ll mat[]={0,1,0}; ll cu=1;ll cu1=1;ll mat1[]={0,0,0};
    //l=1;
    ll tr=0;
    while(cu<m)
    {
        // tr++; cout<<cu<<endl;
        // if(tr>10) break; 
        for(i=1;i<=3;i++){
            a1=o[i];
            // if(a1 >= p1[i].size()) {cout<<a1<<' '<<p1[i].size()<<"\n"; return 0;}
            if(p1[i][a1].S<cu+1)o[i]++;
        }
        cu1=m;ll xo[]={0,0,0,0};ll noc=0;
        for(i=1;i<=3;i++){
            a1=o[i];
            if(p1[i][a1].F>cu+1)cu1=min(p1[i][a1].F-1,cu1);
            else{
                xo[i]++;noc++;
                cu1=min(cu1,p1[i][a1].S);
            }
        }
        if(noc==0){
            for(i=0;i<3;i++)for(j=0;j<3;j++)a[i][j]=kj[i][j];
            Mnpower(cu1-cu);
            for(i=0;i<3;i++){
                mat1[i]=0;
                for(j=0;j<3;j++){
                    mat1[i]+=mat[j]*d[i][j];mat1[i]%=M;
                }
            }
            for(i=0;i<3;i++)mat[i]=mat1[i];
        }
        else if (noc==1){
            if(xo[2]==1){
                mat[0]+=mat[1];mat[2]+=mat[1];mat[1]=0;mat[0]%=M;mat[1]%=M;mat[2]%=M;
            }
            else if(xo[1]==1){
                if(cu+1==cu1){
                    mat[2]+=mat[1];mat[1]=mat[2]+mat[0];mat[0]=0;mat[0]%=M;mat[1]%=M;mat[2]%=M;
                }
                else{
                    k=cu1-cu-2;
                    d1=power(2,k,M);
                    b1=2*(mat[1]+mat[2])+mat[0];
                    b1=(b1*d1)%M;
                    mat[1]=mat[2]=b1;mat[0]=0;
                }
            }
            else {
                if(cu+1==cu1){
                    mat[0]+=mat[1];mat[1]=mat[0]+mat[2];mat[2]=0;mat[0]%=M;mat[1]%=M;mat[2]%=M;
                }
                else{
                    k=cu1-cu-2;
                    d1=power(2,k,M);
                    b1=2*(mat[1]+mat[0])+mat[2];
                    b1=(b1*d1)%M;
                    mat[1]=mat[0]=b1;mat[2]=0;
                }
            }
        }
        else if(noc==3){
            for(j=0;j<3;j++)mat[j]=0;
        }
        else{
            if(xo[1]==0){mat[0]=mat[0]+mat[1];mat[1]=mat[2]=0;}
            if(xo[2]==0){mat[1]+=mat[0]+mat[2];mat[0]=mat[2]=0;}
            if(xo[3]==0){mat[2]=mat[2]+mat[1];mat[0]=mat[1]=0;}
        }
        cu=cu1;
        //cout<<cu<<'\n';
        //cout<<mat[0]<<' '<<mat[1]<<' '<<mat[2]<<endl;
    }
    cout<<mat[1];
 return 0;
}