#include <cstdio>
#include <cstdlib>
using namespace std;

const int permut[][3] = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

int kocka[8][3];
int kocka2[8][3];

long long sq(long long x)
{
    return x*x;
}

long long my_min(long long t[], int b, int e)
{
    long long ret = t[b]; b++;
    while (b < e)
    {
        if (t[b] < ret) ret = t[b];
        b++;
    }
    return ret;
}

long long skal_prod(int a[3], int b[3], int v[3])
{
    long long ret = 0;
    for (int i=0; i<3; i++)
        ret += 1LL * (a[i] - v[i]) * (b[i] - v[i]);
    return ret;
}

void pristej(int *c, int a[3], int v[3])
{
    for (int i=0; i<3; i++)
    {
        *(c+i) += a[i] - v[i];
    }
}

bool vec_eq(int a[3], int b[3])
{
    for (int i=0; i<3; i++)
    {
        if (b[i] != a[i]) return false;
    }
    return true;
}


bool dobra()
{
    long long dist2[8];
    int baza[3];
    for (int i=0; i<8; i++)
        dist2[i] = sq(kocka2[i][0] - kocka2[0][0]) +
                   sq(kocka2[i][1] - kocka2[0][1]) +
                   sq(kocka2[i][2] - kocka2[0][2]);
    long long m = my_min(dist2, 1, 8);
    if (m == 0) return false;
    int p = 0;
    for (int i=1; i<8; i++)
    {
        if (dist2[i] != m) continue;
        if (p > 2) return false;
        baza[p] = i;
        p++;
    }
    if (p != 3) return false;
    if (skal_prod(kocka2[baza[0]], kocka2[baza[1]], kocka2[0]) != 0) return false;
    if (skal_prod(kocka2[baza[0]], kocka2[baza[2]], kocka2[0]) != 0) return false;
    if (skal_prod(kocka2[baza[1]], kocka2[baza[2]], kocka2[0]) != 0) return false;
    // printf("Prisli do tukaj!\n");
    
    int ac[3];
    for (int i=0; i<3; i++) ac[i] = kocka2[0][i];
    pristej(ac, kocka2[baza[0]], kocka2[0]);
    pristej(ac, kocka2[baza[2]], kocka2[0]);
    bool found = false;
    for (int i=1; i<8; i++)
        if (vec_eq(kocka2[i], ac))
        {
            found = true;
            break;
        }
    if (!found)
    {
        // printf("%d %d %d not found!\n", ac[0], ac[1], ac[2]);
        return false;
    }
    int ab[3];
    for (int i=0; i<3; i++) ab[i] = kocka2[0][i];
    pristej(ab, kocka2[baza[0]], kocka2[0]);
    pristej(ab, kocka2[baza[1]], kocka2[0]);
    found = false;
    for (int i=1; i<8; i++)
        if (vec_eq(kocka2[i], ab))
        {
            found = true;
            break;
        }
    if (!found) return false;
    int bc[3];
    for (int i=0; i<3; i++) bc[i] = kocka2[0][i];
    pristej(bc, kocka2[baza[2]], kocka2[0]);
    pristej(bc, kocka2[baza[1]], kocka2[0]);
    found = false;
    for (int i=1; i<8; i++)
        if (vec_eq(kocka2[i], bc))
        {
            found = true;
            break;
        }
    if (!found) return false;
    int abc[3];
    for (int i=0; i<3; i++) abc[i] = kocka2[0][i];
    pristej(abc, kocka2[baza[2]], kocka2[0]);
    pristej(abc, kocka2[baza[1]], kocka2[0]);
    pristej(abc, kocka2[baza[0]], kocka2[0]);
    found = false;
    for (int i=1; i<8; i++)
        if (vec_eq(kocka2[i], abc))
        {
            found = true;
            break;
        }
    if (!found) return false;
    return true;
}

void permutiraj(int level)
{
    if (level == 8)
    {            
        if (dobra())
        {
            printf("YES\n");
            for (int i=0; i<8; i++)
                printf("%d %d %d\n", kocka2[i][0], kocka2[i][1], kocka2[i][2]);
            exit(0);
        }
        return;
    }
    for (int i=0; i<6; i++)
    {
        for (int j=0; j<3; j++)
            kocka2[level][j] = kocka[level][permut[i][j]];
        permutiraj(level + 1);
    }
}

int main()
{
    for (int i=0; i<8; i++)
        scanf("%d %d %d", &kocka[i][0], &kocka[i][1], &kocka[i][2]);
    for (int i=0; i<3; i++)
        kocka2[0][i] = kocka[0][i];
    permutiraj(1);
    printf("NO\n");
    return 0;
}