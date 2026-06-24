#include <bits/stdc++.h>
using namespace std;

int a[21];

int main()
{
long long n,q=0;

string v[21][201];
cin>>n;
	int l;
	for(int i=0;i<n;i++)a[i]=1;
	
for(int i=0;i<n;i++){
	string s;
	cin>>s;
	int k;
	cin>>k;

	for(l=0;l<q;l++){
		if(v[l][0].compare(s)==0){
			break;
		}
	}
	if(l==q){
		v[q++][0]=s;	
	}
	
	for(int j=0;j<k;j++){
		string s1;
		int w;
		cin>>s1;
		reverse(s1.begin(),s1.end());
		for( w=1;w<a[l];w++){
			if(v[l][w].length()>=s1.length()){
			//	cout<<v[l][w].substr(0,s1.length())<<' '<<s1<<endl;
				if(v[l][w].substr(0,s1.length()).compare(s1)==0)break;
			}
			else {
				//	cout<<v[l][w].substr(0,s1.length())<<' '<<s1<<endl;
					if(s1.substr(0,v[l][w].length()).compare(v[l][w])==0)
					{
						v[l][w]=s1;break;
					}
			}
		}
		if(w==a[l]){
			v[l][a[l]++]=s1;
		}
	
	}
}
cout<<q<<endl;
for(int i=0;i<q;i++){
	cout<<v[i][0]<<" ";
	cout<<a[i]-1<<" ";
	for(int j=1;j<a[i];j++){
		string e=v[i][j];
		reverse(e.begin(),e.end());
		cout<< e<<" ";
	}
	cout<<endl;
}

 
   return 0;
}