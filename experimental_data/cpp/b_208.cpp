#include<iostream>

#include<string>

#include<map>

using namespace std;



const int MAX=55;

int n;

bool flag;

string a[MAX];

map<string,bool> vis;



void DFS(int i){

	if(i==1){

		flag=true;

		return;

	}

	if(i-1>=1&&(a[i][0]==a[i-1][0]||a[i][1]==a[i-1][1])){

		//�任 

		string tmp;

		tmp=a[i-1];

		a[i-1]=a[i];

		//�ж�ǰ����Ƿ�Ϸ� 

		string pre;

		for(int j=1;j<=i-1;j++){

			pre+=a[j];

		}

		if(vis[pre]!=true){

			vis[pre]=true;

			DFS(i-1);

		}

		if(flag) return;

		a[i-1]=tmp;

	}

	if(i-3>=1&&(a[i][0]==a[i-3][0]||a[i][1]==a[i-3][1])){

		//�任 

		string tmp;

		tmp=a[i-3];

		a[i-3]=a[i];

		//�ж�ǰ����Ƿ�Ϸ� 

		string pre;

		for(int j=1;j<=i-1;j++){

			pre+=a[j];

		}

		if(vis[pre]!=true){

			vis[pre]=true;

			DFS(i-1);

		}

		if(flag) return;

		a[i-3]=tmp;

	}

}



int main(){

	cin>>n;

	for(int i=1;i<=n;i++){

		cin>>a[i];

	}

	flag=false;

	DFS(n);

	if(flag) cout<<"YES"<<endl;

	else cout<<"NO"<<endl;

	return 0;

}