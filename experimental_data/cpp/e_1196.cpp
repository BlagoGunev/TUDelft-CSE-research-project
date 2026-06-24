#include <cstdio>
int T, w, b;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &b, &w);
		if(w>=b)
		{
			if(w-1>3*b) puts("NO");
			else
			{
				puts("YES");
				if(w>3*b) --w, puts("1 3");
				int i;
				for(i=2; w-b>=2; i+=2) printf("%d %d\n%d %d\n%d %d\n%d %d\n", i, 2, i, 3, i, 4, i+1, 3), w-=3, b-=1;
				if(w-b==1) printf("%d %d\n%d %d\n%d %d\n", i, 2, i, 3, i, 4), w-=2, b-=1, ++i;
				for(; w; ++i) printf("%d %d\n%d %d\n", i, 2, i, 3), --w;
			}
		}
		else if(w<b)
		{
			if(w*3<b-1) puts("NO");
			else
			{
				puts("YES");
				if(b>3*w) --b, puts("1 2");
				int i;
				for(i=2; b-w>=2; i+=2) printf("%d %d\n%d %d\n%d %d\n%d %d\n", i, 1, i, 2, i, 3, i+1, 2), b-=3, w-=1;
				if(b-w==1) printf("%d %d\n%d %d\n%d %d\n", i, 1, i, 2, i, 3), b-=2, w-=1, ++i;
				for(; b; ++i) printf("%d %d\n%d %d\n", i, 1, i, 2), --b;
			}
		}
	}
	return 0;
}