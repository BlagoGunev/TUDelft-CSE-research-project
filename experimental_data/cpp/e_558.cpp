#include<cstdio>

#include<cstring>

#include<iostream>



#define nn 200010

using namespace std;



int n,m,a[nn],top;

struct Node{int x,l,r;}s[nn];

struct Data{int op,d[26];}t[nn*2],ans;



inline int Read()

{

	char c=getchar();int num=0,f=1;

	while ('0'>c||c>'9') {if(c=='-')f=-1;c=getchar();}

	while ('0'<=c&&c<='9') num=num*10+c-'0',c=getchar();

	return(num*f);

}



inline Data Merge(Data a,Data b){

	Data c;c.op=0;

	for (int i=0;i<26;i++) c.d[i]=a.d[i]+b.d[i];return(c);

}



inline void Build(int rt,int l,int r)

{

	int mid=(l+r)/2;

	if (l==r) {t[rt].d[a[l]]++;return;}

	Build(rt*2,l,mid),Build(rt*2+1,mid+1,r);

	t[rt]=Merge(t[rt*2],t[rt*2+1]);

}



inline void Down(int rt,int sz)

{

	if (!t[rt].op) return;

	int l=rt*2,r=rt*2+1,num=0,i;

	memset(t[l].d,0,sizeof(t[l].d));t[l].op=t[rt].op;

	memset(t[r].d,0,sizeof(t[r].d));t[r].op=t[rt].op;

	if (t[rt].op==1){

		for (i=0;i<26;i++){

			t[l].d[i]=min(sz-num,t[rt].d[i]);

			num+=t[l].d[i];if (num==sz) break;

		}

		t[r].d[i]=(t[rt].d[i]-t[l].d[i]);

		for (i++;i<26;i++) t[r].d[i]=t[rt].d[i];

	}else{

		for (i=25;i>=0;i--){

			t[l].d[i]=min(sz-num,t[rt].d[i]);

			num+=t[l].d[i];if (num==sz) break;

		}

		t[r].d[i]=(t[rt].d[i]-t[l].d[i]);

		for (i--;i>=0;i--) t[r].d[i]=t[rt].d[i];

	}

	t[rt].op=0;

}



inline void Get(int rt,int l,int r,int a,int b)

{

	if (l==a&&r==b) {

		ans=Merge(ans,t[rt]);

		s[++top]=(Node){rt,a,b};return;

	}

	int mid=(l+r)/2;Down(rt,mid-l+1);

	if (b<=mid) Get(rt*2,l,mid,a,b);

	if (mid<a) Get(rt*2+1,mid+1,r,a,b);

	if (a<=mid&&mid<b) Get(rt*2,l,mid,a,mid),Get(rt*2+1,mid+1,r,mid+1,b);

}



inline void Ask(int rt,int l,int r)

{

	int mid=(l+r)/2;

	if (l==r) {for (int i=0;i<26;i++) if (t[rt].d[i]) a[l]=i;return;}

	Down(rt,mid-l+1);

	Ask(rt*2,l,mid);Ask(rt*2+1,mid+1,r);

}



int main()

{

	

	n=Read(),m=Read();

	char c=getchar();while ('a'>c||c>'z') c=getchar();

	a[1]=c-'a';for (int i=2;i<=n;i++) a[i]=getchar()-'a';

	Build(1,1,n);

	

	for (int j,i=1;i<=m;i++)

	{

		int l=Read(),r=Read(),op=Read();if (op!=1) op=2;

		memset(ans.d,0,sizeof(ans.d));

		if (op==1) j=0;else j=25;top=0;Get(1,1,n,l,r);

		

		for (int k=1;k<=top;k++)

		{			

			int num=0;t[s[k].x].op=op;

			memset(t[s[k].x].d,0,sizeof(t[s[k].x].d));

			num=t[s[k].x].d[j]=min(ans.d[j],s[k].r-s[k].l+1);

			ans.d[j]-=num;

			if (num==s[k].r-s[k].l+1) {

				for (int rt=s[k].x/2;rt;rt/=2) t[rt]=Merge(t[rt*2],t[rt*2+1]);

				continue;

			}

			

			if (op==1) {

				for (j++;j<26;j++) {

					t[s[k].x].d[j]=min(ans.d[j],s[k].r-s[k].l+1-num);

					num+=t[s[k].x].d[j],ans.d[j]-=t[s[k].x].d[j];

					if (num==s[k].r-s[k].l+1) break;

				}

			}else{

				for (j--;j>=0;j--) {

					t[s[k].x].d[j]=min(ans.d[j],s[k].r-s[k].l+1-num);

					num+=t[s[k].x].d[j],ans.d[j]-=t[s[k].x].d[j];

					if (num==s[k].r-s[k].l+1) break;

				}

			}

			

			for (int rt=s[k].x/2;rt;rt/=2) t[rt]=Merge(t[rt*2],t[rt*2+1]);

		}

		

		//Ask(1,1,n);

		//for (int i=1;i<=n;i++) printf("%c",a[i]+'a');

		//puts("");

	}

	

	Ask(1,1,n);

	for (int i=1;i<=n;i++) printf("%c",a[i]+'a');

	puts("");

}