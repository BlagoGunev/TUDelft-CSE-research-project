#include<cstdio>
#define re register
#define aofjodijf 505

namespace cltstream{
	#define size 1048576
	char cltin[size+1],*ih=cltin,*it=cltin;
	inline char gc(){
		#ifdef ONLINE_JUDGE
			if(ih==it){
				it=(ih=cltin)+fread(cltin,1,size,stdin);
				if(ih==it)
					return EOF;
			}
			return *ih++;
		#else
			return getchar();
		#endif
	}

	char cltout[size+1],*oh=cltout,*ot=cltout+size;
	inline void pc(char c){
		if(oh==ot){
			fwrite(cltout,1,size,stdout);
			oh=cltout;
		}
		*oh++=c;
	}
	#define clop() fwrite(cltstream::cltout,1,cltstream::oh-cltstream::cltout,stdout)
	#undef size

	template <typename _tp>
	inline void read(_tp& x){
		int sn=1;
		char c=gc();
		for(;c!=45&&(c<48||c>57)&&c!=EOF;c=gc());
		if(c==45&&c!=EOF)
			sn=-1,c=gc();
		for(x=0;c>=48&&c<=57&&c!=EOF;x=(x<<3)+(x<<1)+(c^48),c=gc());
		x*=sn;
	}

	template <typename _tp>
	inline void write(_tp x,char text=-1){
		if(x<0)
			pc(45),x=-x;
		if(!x)
			pc(48);
		else{
			int digit[22];
			for(digit[0]=0;x;digit[++digit[0]]=x%10,x/=10);
			for(;digit[0];pc(digit[digit[0]--]^48));
		}
		if(text>=0)
			pc(text);
	}
}

int a[aofjodijf][aofjodijf],f[aofjodijf],b[aofjodijf][aofjodijf];
int n,m;

int main(){
	cltstream::read(n);
	cltstream::read(m);
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=m;j++)
			cltstream::read(a[i][j]);
	for(re int w=0;w<12;w++){
		for(re int i=1;i<=n;i++)
			for(re int j=1;j<=m;j++)
				if(a[i][j]&(1<<w))
					b[i][j]=1;
				else
					b[i][j]=0;
		re int t=0,k=0;
		for(re int i=1;i<=n;i++)
			f[i]=2;
		for(re int i=1;i<=n;i++){
			re int tmp=0;
			for(re int j=1;j<=m;j++)
				if(b[i][j]){
					tmp=1;
					break;
				}
			if(!tmp){
				t++;
				f[i]=0;
			}
		}
		for(re int i=1;i<=n;i++){
			re int tmp=0;
			for(re int j=1;j<=m;j++)
				if(!b[i][j]){
					tmp=1;
					break;
				}
			if(!tmp){
				k++;
				f[i]=1;
			}
		}
		if(n-k-t>=1||(k&1)){
			cltstream::pc('T');
			cltstream::pc('A');
			cltstream::pc('K');
			cltstream::pc(10);
			for(re int i=1;i<=n;i++){
				if(f[i]==0||f[i]==1)
					cltstream::write(1,32);
				if(f[i]==2){
					if(k&1){
						for(re int j=1;j<=m;j++)
							if(b[i][j]==0){
								cltstream::write(j,32);
								break;
							}
						continue;
					}
					else{
						for(re int j=1;j<=m;j++)
							if(b[i][j]==1){
								cltstream::write(j,32);
								break;
							}
						k++;
						continue;
					}
				}
			}
			clop();
			return 0;
		}
	}
	cltstream::pc('N');
	cltstream::pc('I');
	cltstream::pc('E');
	cltstream::pc(10);
	clop();
	return 0;
}