#include<stdio.h>
#define LEN 5
#include"matrix.C"
void copyarrline(double* arr, double* to);
int copy(double(*ptra)[LEN], double(*ptrb)[LEN]);
int add(double(*ptra)[LEN], double(*ptrb)[LEN], double c[LEN][LEN]);
int mul(double(*ptra)[LEN], double(*ptrb)[LEN], double c[LEN][LEN]);
int matproc(double(*ptra)[LEN], double(*ptrb)[LEN], double(*c)[LEN], int(*proc)(double(*ptra)[LEN], double(*ptrb)[LEN], double c[LEN][LEN]))
{
	(*proc)(ptra, ptrb, c);
	return 0;
}
int main()
{
	double a[LEN][LEN], b[LEN][LEN], c[LEN][LEN];
	int(*fun)(double(*ptra)[LEN], double(*ptrb)[LEN], double c[LEN][LEN]);

	for (int i = 0; i < LEN; ++i)
		for (int j = 0; j < LEN; ++j)
		{
			scanf_s("%lf", &a[i][j]);
		}
	copy(a, b);
	printf("\nadd:\n===========\n");
	fun = add;
	matproc(a, b, c, fun);
	for (int i = 0; i < LEN; ++i)
	{
		for (int j = 0; j < LEN; ++j)
			printf("%.2lf ", c[i][j]);
		printf("\n");
	}
	for (int i = 0; i < LEN; ++i)
		for (int j = 0; j < LEN; ++j)
			c[i][j] = 0;
	printf("\nmul:\n==========\n");
	fun = mul;
	matproc(a, b, c, fun);
	for (int i = 0; i < LEN; ++i)
	{
		for (int j = 0; j < LEN; ++j)
			printf("%.2lf ", c[i][j]);
		printf("\n");
	}
	return 0;
}
