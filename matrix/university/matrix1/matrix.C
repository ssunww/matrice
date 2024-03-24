#include <stdio.h>
#define N 4
void copyarrline(double* arr1, double* arr2)
{
    for (int i = 0; i < N; ++i)
        *(arr2 + i) = *(arr1 + i);
}
int copy(double(*arr3)[N], double(*arr4)[N])
{
    for (int i = 0; i < N; ++i)
        copyarrline(arr3[i], arr4[i]);
    return 0;
}
int add(double(*arr3)[N], double(*arr4)[N], double c[N][N])
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            c[i][j] = arr3[i][j] + arr4[i][j];
    return 0;
}
int mul(double(*arr3)[N], double(*arr4)[N], double c[N][N])
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int t = 0; t < N; ++t)
                c[i][j] += arr3[i][t] * arr4[t][j];
    return 0;
}
