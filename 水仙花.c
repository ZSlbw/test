#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ݹ�
int len(int i)
{
	if (i == 0)
		return 0;
	else
		return 1 + len(i / 10);
}

int Pow(int n, int k)//n��k�η�
{
	//n^k = n*n^(k-1)
	if (k == 0)
		return 1;
	else if (k < 0)
		return (1 / Pow(n, -k));
	else
		return n*Pow(n, k - 1);
}

//����ˮ�ɻ�(�ݹ�)
int Narcissus(int i, int d)
{
	if (i == 0)
		return Pow(i, d);
	else
		return Narcissus(i / 10, d) + Pow(i % 10, d);
}

int main()
{
	printf("���е�ˮ�ɻ���Ϊ:>\n");
	for (int i = 0; i <= 100000; i++)
	{
		int d = len(i);//����i�Ǽ�λ��
		int ret = Narcissus(i, d);//���ҷ���ˮ�ɻ�������
		if (ret == i)
			printf("%d ", i);
	}
	printf("\n");
	return 0;
}