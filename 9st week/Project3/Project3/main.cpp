#include <stdio.h>

int main(void)
{
	int nA[3] = { 1,2,3 };  // �ʰ�ȭ�� A�迭
	int nB[10] = {};  // �ʱ�ȭ���� ���� B�迭
	int i = 0;  // i�� ���� ���� �ʱ�ȭ

	// B�迭�� ä��� ���� B�迭 ��ҿ줿 ������ŭ �ݺ�
	for (i = 0; i < 10; i++)  
	{
		// A�迭 ÷�ڰ� 0~2�� ������ ������ ������ ���
		nB[i] = nA[i % 3]; 
	}

	// B�迭 ���
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", nB[i]);
	}
	printf("\n");
	return 0;
}