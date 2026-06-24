#include<bits/stdc++.h>
int gcd(int a,int b)
{
	if(b==0)
	  return a;
	else
	  return gcd(b,a%b);
}
int main(void)
  {
  	long long int a,b,c,d;
  	while(std::cin>>a>>b>>c>>d)
  	  {
  	  	int temp=gcd(a,c);
  	  	if(temp!=1)
  	  	  {
  	  	  	
  	  	  	if((std::max(b,d)-std::min(b,d))%temp!=0)
  	  	  	  {
  	  	  	  	std::cout<<-1<<'\n';
  	  	  	  	continue;
					}
			  }
		while(b!=d)
		  {
			if(b<d)
			  b=b+a;
			else
			  d=d+c;
		  }
		std::cout<<b<<'\n';
		}
  }