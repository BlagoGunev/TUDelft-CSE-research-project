// Sunny Singh IPG2012086 ABV-IIITM GWALIOR	

#include<bits/stdc++.h>

using namespace std;



#define loop(i,k,n) for(int i=k;i<n;i++)

#define revloop(i,n,k) for(int i=n;i>=k;i--)

#define scan(a)  scanf("%d",&a)

#define scanst(a) scanf("%s",&a)

#define scanch(a) scanf("%c",&a)

int mat[100][100];

int main()

{

 

 

 int n,m,v,b,x,y;

 cin>>n>>m>>v>>b;



  loop(j,0,v)

     {

     	cin>>x>>y;

     	mat[--x][--y]=1;

     }

 int rsum =0;

 loop(i,0,n)

 {

    rsum =0;

 	loop(j,0,m)

 	 {   rsum+=mat[i][j];

 	 	 mat[i][j]=rsum;

 	 	 if(i>0)

          mat[i][j] += mat[i-1][j];

       // cout<<mat[i][j]<<" ";

 	 }

 	// cout<<endl;

 }



 int ans = 0;

 loop(i,0,n)

 {

 	loop(j,0,m)

 	  {

 	  	  loop(k,i,n)

 	  	   {

 	  	   	  loop(l,j,m)

 	  	   	    {



                    int subsum = mat[k][l];

                    if(i>0)

                    	subsum -= mat[i-1][l];

                    if(j>0)

                    	subsum -= mat[k][j-1];

                    if(i>0 && j>0)

                    	subsum += mat[i-1][j-1];

                    if(subsum>=b)

                    	ans++;

                    //cout<<i<<","<<j<<" - "<<k<<","<<l<<" :"<<subsum<<endl; 	  	   	    

 	  	   }

 	  }

   }

}

 //cout<<"here"<<endl;

 cout<<ans<<endl;

 

 return 0;

}