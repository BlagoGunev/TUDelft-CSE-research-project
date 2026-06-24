/*#include<iostream>
#include<algorithm>
#include<string>*/
#include<bits/stdc++.h>
using namespace std;
#define f(i,low,up) for(int i=low;i<up;i++)
#define f1(i,low,up) for(int i=low;i<=up;i++)
#define f2(i,up,low) for(int i=up;i>=low;i--)
#define ll long long
#define m(v,i) memset(v,i,sizeof(v))
#define sc(t)  scanf("%d",&t)
#define MOD 1000000007 
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}


int main(){
    int n;
    cin>>n;
    
    int a[6],x,sum=0;
    memset(a,0,sizeof(a));
    f(i,0,n)
    {
    	cin>>x;
    	a[x]++;
    	sum+=x;
	}
	
	double s;
	s=sum;
	if(s/n>=4.5)
	{
	  cout<<"0\n";
	  return 0;
    }
  
  int cnt=0;
  
    f1(i,2,5)
    {
        
    	if(a[i]!=0&&i!=5)
    	{

    	  double diff=5-i;
    	  if((s+diff*a[i])/n<4.5)
    	  {
		     s+=diff*a[i];
		     cnt+=a[i];
	      }
	      else
	      {
	      	double req=(4.5*n-s)/diff;
	      	int r=req;
	      	double r1=r;
	      	if(req!=r)
	      	cnt=cnt+r+1;
	      	else
	      	cnt+=r;
	      	break;
		  }
		  
		}
	}
	
	cout<<cnt<<"\n";
 
    
	return 0;
}