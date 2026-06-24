#include<iostream>
#include<cstdio>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
inline int Get_Int()
{
	char x=getchar();
	int num=0,bj=1;
	while(x<'0'||x>'9')
	{
		if(x=='-') bj=-1;
		x=getchar();
	}
	while(x>='0'&&x<='9')
	{
		num=num*10+x-'0';
		x=getchar();
	}
	return num*bj;

 }
int x,y,T,i,j,k,g,s,b,n;
int main()
{
    T=Get_Int();
    while(T--)
    {
    	n=Get_Int();
    	int sum=0;
    	g=s=b=0;
    	sum=1;
    	x=Get_Int();
    	for(i=2;i<=n;i++)
    	{
    		y=Get_Int();
    		if(x==y) sum++;
    		else {
    		 if(i-1>n/2){
    		//cout<<"s"<<i<<" "<<sum<<endl;
			 sum=1;}
    		else if(!g) g=sum;
    			 else if(s<=g) s+=sum;
    			  else  b+=sum;
    			  sum=1;
			}
			x=y;
		}
			 if(n>n/2){
    		
			 sum=1;}
    		else if(!g) g=sum;
    			 else if(s<=g) s+=sum;
    			  else  b+=sum;
    			  sum=1;
    		//	  cout<<g<<" "<<s<<" "<<b<<endl;
    	if(s+g+b<=n/2&&s>g&&b>g) printf("%d %d %d\n",g,s,b);
		else printf("0 0 0\n");		  
	}
	return 0;
}