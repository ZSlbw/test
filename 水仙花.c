#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//递归
int len(int i)
{
	if (i == 0)
		return 0;
	else
		return 1 + len(i / 10);
}

int Pow(int n, int k)//n的k次方
{
	//n^k = n*n^(k-1)
	if (k == 0)
		return 1;
	else if (k < 0)
		return (1 / Pow(n, -k));
	else
		return n*Pow(n, k - 1);
}

//查找水仙花(递归)
int Narcissus(int i, int d)
{
	if (i == 0)
		return Pow(i, d);
	else
		return Narcissus(i / 10, d) + Pow(i % 10, d);
}

int main()
{
	printf("所有的水仙花数为:>\n");
	for (int i = 0; i <= 100000; i++)
	{
		int d = len(i);//计算i是几位数
		int ret = Narcissus(i, d);//查找符合水仙花数的数
		if (ret == i)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}