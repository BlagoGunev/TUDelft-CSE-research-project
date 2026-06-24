#include <cstdio>
#include <algorithm>
using namespace std;
int v[30];
FILE *in,*out;
int main()
{
	int x,y,i;
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	fscanf(in,"%d",&x);
	v[x]=1;
	for (i=1;i<=3;i++)
	{
		fscanf(in,"%d%d",&x,&y);
		swap(v[x],v[y]);
	}
	for (i=1;i<=3;i++)
		if (v[i])
			fprintf(out,"%d\n",i);
	fclose(in);
	fclose(out);
	return 0;

}