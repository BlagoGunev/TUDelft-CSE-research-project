#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	map<int,int>mp;
	int maxj=-4,minj=90000,max=0,m1,n1,m2,n2;
	int stri=-1,endi=-1;
	char a[n][m];
	bool b=true;
	int bb=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			
			if(a[i][j]=='B'){
				bb++;
				
				if(stri==-1)
				stri=i;
				
				if(endi<i)
				endi=i;
				
				if(maxj<j)
				maxj=j;
				
				if(minj>j)
				minj=j;
				
			}
			
		}
	}
	
	n1=endi-stri+1;
	m1=maxj-minj+1;

	if(n1<m1)
	n1=m1;
		int mm=n1;
	
	if(n<n1||m<n1)
	cout<<"-1";
	
	else if(bb==0)
	cout<<1<<endl;
	
	else {
		int c=0,r=0;
		for(int i=stri;i<=endi;i++){
			for(int j=minj;j<=maxj;j++){
				if(a[i][j]=='W')
				c++;
			}
		}
		
		n1=endi-stri;
		m1=maxj-minj;
		if(m1==n1);
		else {
			r=abs(n1-m1);
		}
		c=c+r*mm;
		cout<<c<<endl;
	}
	
	// your code goes here
	return 0;
}