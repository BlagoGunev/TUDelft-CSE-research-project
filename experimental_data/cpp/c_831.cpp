#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define mp make_pair
#define pb push_back
//#define m 1000000007
#define all(c) c.begin(),c.end()
#define fl(i,n) for(i=0;i<n;i++)
#define fl1(i,a,b) for(i=a;i<=b;i++)
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define matrix(v,n)	std::vector<std::vector<int> > v(n,std::vector<int> (n));
#define trace1(x)                cout << #x << ": " << x << endl;
#define trace2(x, y)             cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
using namespace std;

int main(){
	
	int n,m,k,i,j;
	cin>>k>>n;
	
	vector<int> v1(k),v2(n);
	fl(i,k){
		cin>>v1[i];
	}
	
	fl(i,n){
		cin>>v2[i];
	}
	
	vector<int> v3(k);
	v3[0]=v1[0];
	
	for(i=1;i<=k-1;i++){
		v3[i]=v3[i-1]+v1[i];
//		cout<<"Fsd";
//		trace1(v3[i]);
	}
	
	sort(all(v3));
	int count=0;
	sort(all(v2));
	int a,b,c,val=0,l;
//	fl(i,k){
//		cout<<v3[i]<<endl;
//	}
	set<int> s;
//	fl(i,n){
		count=0;
//		a=v2[0]-v3[i];
		fl(j,k){
			count=0;
			a=v2[0]-v3[j];
			i=0;
			for(l=j;l<=k-1;l++){
				if(v3[l]+a==v2[i] && i<n){
					count++;
					i++;
				}
			}
			if(count==n){
				s.insert(a);
//				val++;
//				trace1(j);
			}
		}
//	}
	
	cout<<s.size()<<endl;
}