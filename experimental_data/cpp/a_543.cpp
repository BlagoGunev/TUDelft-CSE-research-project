#include<cstdio>

#include<cstring>



int programmar, number_of_task, total_bugs, modulas, ans;

int a[555];

int f[555][555];



int add(int a, int b)

{

    return (a+=b)>=modulas ? a-modulas : a;

}



int main()

{

    scanf("%d%d%d%d", &programmar, &number_of_task, &total_bugs, &modulas);

    for(int i=0; i<programmar; i++)

    scanf("%d",&a[i]);



    memset(f,0,sizeof f);



    f[0][0] = 1;



    for(int i=0; i<programmar; i++)

        for(int j=1; j<=number_of_task; j++)

            for(int k=a[i]; k<=total_bugs; k++)

                f[j][k] = add(f[j][k], f[j-1][k-a[i]]);



    ans = 0;

    for(int i=0; i<=total_bugs; i++)

        ans = add(ans, f[number_of_task][i]);

    printf("%d\n", ans);



    return 0;

}