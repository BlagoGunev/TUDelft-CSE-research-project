#include <bits/stdc++.h>

using namespace std ; 

#define s(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define sc(n) scanf("%c",&n)
#define forall(i,a,b) for(i=a;i<b;i++)
#define vi vector<int>
#define vvi vector< vi >
#define pb push_back
#define tr(it,c) for( typeof ( (c).begin() ) it = c.begin();it!=(c).end();++it)
#define max_const 1000000000
#define ii pair<int , int >

//int find_answer(int n , int m , int k) ; 

int ans[31][31][51] ; 

int main()
{
	int t,counter;

	for(int i=1;i<=30;++i)
	{
		for(int j=1;j<=30;++j)
		{
			for(int k=1;k<=50;++k)
			{
				
				if(k>=i*j)
				{
					ans[i][j][k] = 0 ;
					//cout<<i<<"  "<<j<<"  "<<k<<"  "<<ans[i][j][k]<<endl ; 
					continue ; 
				}
				if((i==1)||(j==1))
				{
					ans[i][j][k] = 1 ; 
					//cout<<i<<"  "<<j<<"  "<<k<<"  "<<ans[i][j][k]<<endl ; 
					continue ; 
				}

				if(i>k)
				{
					ans[i][j][k] = ans[i][1][k] + i*i ;  
				}
				else if(k%i==0)
				{
					ans[i][j][k] = i*i ;
				}
				else
				{
					ans[i][j][k] = max_const ; 
					int t = 1 ; 
					while(t<=j)
					{
						if(k>t*i)
						{
							ans[i][j][k] = min(ans[i][j-t][k-t*i] + i*i , ans[i][j][k]) ;
						}
						if(i*j-t*i>k)
						{
							ans[i][j][k] = min(ans[i][j-t][k] + i*i , ans[i][j][k]) ; 
						}
						t++ ;  
					}
				}

				if(j>k)
				{
					ans[i][j][k] = min(ans[1][j][k] + j*j , ans[i][j][k]) ; 
				}
				else if(k%j==0)
				{
					ans[i][j][k] = min(ans[i][j][k] , j*j) ; 
				}
				else
				{
					//ans[i][j][k] = min(ans[i][j][k] , ans[i-(k/j)][j][k%j] + j*j) ; 
					 
					
					int t = 1 ; 
					while(t<=i)
					{
						if(k>t*j)
						{
							ans[i][j][k] = min(ans[i-t][j][k-t*j] + j*j , ans[i][j][k]) ;
						}
						if(i*j-t*j>k)
						{
							ans[i][j][k] = min(ans[i-t][j][k] +j*j , ans[i][j][k]) ; 
						}
						t++ ;  
					}

				}

				//cout<<i<<"  "<<j<<"  "<<k<<"  "<<ans[i][j][k]<<endl ; 
			}
		}
	}

	
	s(t) ; 
	forall(counter,0,t)
	{
		int n,m,k ; 
		s(n) ; 
		s(m) ;
		s(k) ;  
		printf("%d\n",ans[n][m][k]) ; 
	}
	
	

	return 0;
}


/*
int find_answer(int l , int b , int k)
{
	cout<<"Entered "<<l<<"  "<<b<<"  "<<k<<endl ; 

	int v1,v2 ;

	if(k%l==0)
	{
		v1 = l*l ; 
	}
	else 
	{

		v1 = find_answer(l , k/l+1 , k%l) ; 	
	}

	if(k%b==0)
	{
		v2 = b*b ; 
	}
	else if(k>b)
	{
		v2 = find_answer(b , k/b+1 , k%b) ;	
	}

	return min(v1,v2) ; 
	

	
}*/