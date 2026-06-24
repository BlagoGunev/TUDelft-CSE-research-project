#include<iostream>

#include<cstdio>

#include<vector>

using namespace std;



const int R=3005,C=3005;

const int go[8][2]={{1,0},{1,1},{1,-1},{0,1},{0,-1},{-1,-1},{-1,1},{-1,0}};

int par[3*R*C],r,c,n;



int find(int x){

	return par[x]<0?x:par[x]=find(par[x]);

}



void join(int x,int y){

	x=find(x);y=find(y);

	if(x==y) return;

	if(par[x]<par[y]){

		par[x]+=par[y];

		par[y]=x;

	}else{

		par[y]+=par[x];

		par[x]=y;

	}

}



int id(int x,int y){

	return x*2*c+y+1;

}



vector<int> getneighbour(int x,int y){

	vector<int> ans(0);

	for(int i=0;i<8;i++){

		int x1=x+go[i][0],y1=(y+go[i][1]+2*c)%(2*c);

		if(x1>=0&&x1<r&&par[id(x1,y1)]!=0){

			ans.push_back(find(id(x1,y1)));

		}

	}

	return ans;

}



bool canadd(int x,int y){

	vector<int> a=getneighbour(x,y);

	vector<int> b=getneighbour(x,y+c);

	for(int i=0;i<a.size();i++){

		for(int j=0;j<b.size();j++){

			if(a[i]==b[j]) return false;

		}

	}

	return true;

}



void addpoint(int x,int y){

	for(int i=0;i<2;i++){

		par[id(x,y+i*c)]=-1;

		vector<int> near=getneighbour(x,y+i*c);

		for(int j=0;j<near.size();j++){

			join(id(x,y+i*c),near[j]);

		}

	}

}



int main(){

	scanf("%d%d%d",&r,&c,&n);

	if(c==1){

		printf("0\n");

		return 0;

	}

	int ans=0;

	while(n--){

		int x,y;

		scanf("%d%d",&x,&y);

		x--;y--;

		if(canadd(x,y)){

			addpoint(x,y);

			ans++;

		}

	}

	printf("%d\n",ans);

	return 0;

}