#include<bits/stdc++.h>

using namespace std;



namespace iobuff{

	const int LEN=1000000;

	char in[LEN+5],out[LEN+5];

	char *pin=in,*pout=out,*ed=in,*eout=out+LEN;

	inline char gc(void){

		#ifdef TQX

		return getchar();

		#endif

		return pin==ed&&(ed=(pin=in)+fread(in,1,LEN,stdin),ed==in)?EOF:*pin++;

	}

	inline void pc(char c){

		pout==eout&&(fwrite(out,1,LEN,stdout),pout=out);

		(*pout++)=c;

	}

	inline void flush(){fwrite(out,1,pout-out,stdout),pout=out;}

	template<typename T> inline void read(T &x){

		static int f;

		static char c;

		c=gc(),f=1,x=0;

		while(c<'0'||c>'9') f=(c=='-'?-1:1),c=gc();

		while(c>='0'&&c<='9') x= 10*x+c-'0',c=gc();

		x*=f;

	}

	template<typename T> inline void putint(T x,char div){

		static char s[15];

		static int top;

		top=0;

		x<0?pc('-'),x=-x:0;

		while(x) s[top++]=x%10,x/=10;

		!top?pc('0'),0:0;

		while(top--) pc(s[top]+'0');

		pc(div);

	}

}

using namespace iobuff;



const int N=2e5+10;

int T,n,a[N],ans[N],sz[N],fa[N],pos[N],pd[N];

vector<int> ve[N];

inline int find(int x){

	return fa[x]==x?x:fa[x]=find(fa[x]);

}

inline void work(int x,int y){

	swap(ans[x],ans[y]);

	fa[find(x)]=find(y);

}

int main(){

//	freopen("G.in","r",stdin);

	scanf("%d",&T);

	while(T--){

		scanf("%d",&n);

		for(int i=1;i<=n;++i) ve[i].clear(),pd[i]=0;

		for(int i=1;i<=n;++i) scanf("%d",&a[i]),ve[a[i]].push_back(i); 

		int p=0;

		for(int i=1;i<=n;++i)

			if(ve[i].size()&1){

				if(!p) p=i;

				else p=-1;

			} 

		if(p==-1){pc('N');pc('O');pc('\n');continue;}

		if(ve[p].size()==1&&ve[p][0]==(n+1)/2){pc('N');pc('O');pc('\n');continue;}

		int l=1;

		for(int i=1;i<=n;++i){

			if(ve[i].size()&1)

				if(ve[i].back()==(n+1)/2) swap(ve[i][0],ve[i][ve[i].size()-1]);

			if(ve[i].size()&1) ans[n/2+1]=ve[i].back(),ve[i].pop_back();

			while(ve[i].size()) ans[l]=ve[i].back(),ve[i].pop_back(),ans[n+1-l]=ve[i].back(),ve[i].pop_back(),l++;

		} 

		for(int i=1;i<=n;++i) fa[i]=i,pos[ans[i]]=i;

		for(int i=1;i<=n;++i) fa[find(i)]=find(ans[i]);

		for(int i=1;i<=n/2;++i)

			if(find(i)!=find(n-i+1)) work(i,n-i+1);

		vector<int> vec;

		for(int i=1;i<=n;++i){

			if(i==(n+1)/2) continue;

			if(!pd[find(i)]) vec.push_back(i),pd[find(i)]=1;

		}

		if(vec.size()>1){

			int recx=ans[vec[0]],recy=ans[n+1-vec[0]];

			for(int i=0;i<vec.size()-1;++i) ans[vec[i]]=ans[n+1-vec[i+1]],ans[n+1-vec[i]]=ans[vec[i+1]];

			ans[vec.back()]=recx;ans[n+1-vec.back()]=recy;

		}

		pc('Y');pc('E');pc('S');pc('\n');

		for(int i=1;i<=n;++i) putint(ans[i],' ');

		pc('\n');

	}flush();

	return 0;

}