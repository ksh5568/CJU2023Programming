#include <stdio.h>
#define ONE 1  // '1'�� ���� �� ��ũ�� ����
#define TEN 10  // '10'�� ���� �� ��ũ�� ����

void swap(double *pa, double *pb);  // �� �Ǽ��� �ٲٴ� �Լ� ����
void line_up(double *sor);  // ���� ��Ű�� ���� �Լ� ����

int main(void)
{
	// �� ���� �ʱ�ȭ
	double ary[TEN] = {};  
	int i = 0;
	
	printf("Enter 10 real values : ");  // 10���� �Ǽ� �Է�

	// �ݺ����� ���Ͽ� �迭�� �ش��ϴ� �� ����
	for (i = 0; i < TEN; i++)
	{
		scanf_s("%lf", &ary[i]);
	}

	line_up(ary);  // �� �Ǽ��� �ٲٴ� �Լ� ȣ��


	// ����� ���
	for (i = 0; i < TEN; i++)
	{
		printf("Output Sorted Values : %.1lf\n", ary[i]);
	}
	
	return 0;
}

void swap(double *pa, double *pb) // �� �Ǽ��� �ٲٴ� �Լ� ����
{
	double temp = 0.0;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void line_up(double *sor)  // ���� ��Ű�� ���� �Լ� ����
{
	int temp = 0;
	int j = 0;
	int k = 0;

	for (j = 0; j < TEN; j++)
	{
		for (k = j; k < TEN; k++)
		{
			if(sor[j]<sor[k])swap(&sor[j], &sor[k]);  // ���ǿ� �����ϸ� �� �Ǽ��� �ٲٴ� �Լ� ȣ��
		}
	}
	
}