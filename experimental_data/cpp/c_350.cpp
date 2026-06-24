#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,pair<int,int> > P;
P p[100000];
int abs(int a){
	if(a>0) return a;
	else return -a;
}
int main(){
	int n;
	int ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&p[i].second.first,&p[i].second.second);
		if(p[i].second.first==0 || p[i].second.second==0) ans+=4;
		else ans+=6;
		p[i].first=abs(p[i].second.first)+abs(p[i].second.second);
	}
	printf("%d\n",ans);
	sort(p,p+n);
	for(int i=0;i<n;i++){
		if(p[i].second.first==0){
			if(p[i].second.second>0) printf("1 %d U\n",p[i].second.second);
			else printf("1 %d D\n",-p[i].second.second);
			printf("2\n");
			if(p[i].second.second>0) printf("1 %d D\n",p[i].second.second);
			else printf("1 %d U\n",-p[i].second.second);			
			printf("3\n");
		}
		else if(p[i].second.second==0){
			if(p[i].second.first>0) printf("1 %d R\n",p[i].second.first);
			else printf("1 %d L\n",-p[i].second.first);
			printf("2\n");
			if(p[i].second.first>0) printf("1 %d L\n",p[i].second.first);
			else printf("1 %d R\n",-p[i].second.first);
			printf("3\n");		
		}
		else{
			if(p[i].second.first>0 && p[i].second.second>0){
				printf("1 %d R\n1 %d U\n2\n1 %d L\n1 %d D\n3\n",p[i].second.first,p[i].second.second,p[i].second.first,p[i].second.second);
			}	
			else if(p[i].second.first<0 && p[i].second.second>0){
				printf("1 %d L\n1 %d U\n2\n1 %d R\n1 %d D\n3\n",-p[i].second.first,p[i].second.second,-p[i].second.first,p[i].second.second);
			}
			else if(p[i].second.first>0 && p[i].second.second<0){
				printf("1 %d R\n1 %d D\n2\n1 %d L\n1 %d U\n3\n",p[i].second.first,-p[i].second.second,p[i].second.first,-p[i].second.second);
			}
			else{
				printf("1 %d L\n1 %d D\n2\n1 %d R\n1 %d U\n3\n",-p[i].second.first,-p[i].second.second,-p[i].second.first,-p[i].second.second);
			}
		}
	}
	return 0;
}