#include <cstdio>
#include <algorithm>
using namespace std;

int s,x1,x2,t1,t2,p,d,ans;

int abs(int x){return x<0?-x:x;}

int main(){
	scanf("%d %d %d %d %d %d %d",&s,&x1,&x2,&t1,&t2,&p,&d);
	if(t1>=t2){
		printf("%d\n",abs(x1-x2)*t2);
		return 0;
	}
	if(x1<x2){
		ans=(x2-x1)*t2;
		if(p<=x1&&d==1) ans=min(ans,(x2-p)*t1);
		else if(p<=x1&&d==-1) ans=min(ans,(x2+p)*t1);
		else if(p>x1&&p<x2&&d==1) ans=min(ans,(2*s+x2-p)*t1);
		else if(p>x1&&p<x2&&d==-1) ans=min(ans,(x2+p)*t1);
		else if(p>=x2&&d==1) ans=min(ans,(2*s-p+x2)*t1);
		else if(p>=x2&&d==-1) ans=min(ans,(x2+p)*t1);
	}
	else{
		ans=(x1-x2)*t2;
		if(p>=x1&&d==-1) ans=min(ans,(p-x2)*t1);
		else if(p>=x1&&d==1) ans=min(ans,(2*s-x2-p)*t1);
		else if(p<x1&&p>x2&&d==-1) ans=min(ans,(2*s+p-x2)*t1);
		else if(p<x1&&p>x2&&d==1) ans=min(ans,(2*s-x2-p)*t1);
		else if(p<=x2&&d==-1) ans=min(ans,(2*s-x2+p)*t1);
		else if(p<=x2&&d==1) ans=min(ans,(2*s-x2-p)*t1);
	}
	printf("%d\n",ans);
	return 0;
}