#include <stdio.h>
#include <math.h>
#define TEN 10.0

int main(void)
{
	double num = 0.0;  // �Է� ������ ���� ����
	double num_a = 0.0; 
	double sum = 0.0;  // ���� ���� ����
	double avg = 0.0;  // ��հ� ���� ����
	double dis = 0.0;  // �л꿡 ���� ���� ����
	double std = 0.0;  // ǥ�������� ���� ���� ����
	int i = 0;  // �ݺ��ϴ� �� ���� ����

	printf("Enter the 10 number :\n");  // 10���� ���ڸ� �Է��ϼ���
	for(i=0; i<TEN; i++)  // i�� 10���� �ݺ��ϸ鼭 1�� ������ ��
	{
		scanf_s("%lf", &num);  // �Է� �������� ����
		sum += num;  // ������ ���ϴ� ����
		num_a += pow(num, 2);  // �Է� ���� ���� �������� �ٸ� ������ ����
	}

	avg = sum / TEN;  // ��հ� ���

	dis = (num_a + 10*pow(avg, 2) - (2 * avg * sum)) / 10;  // �л� ���ϴ� ����

	std = sqrt(dis);  // ǥ������ ���ϴ� ����

	printf("Sum : %.2lf\n", sum);  //���հ� ���
	printf("avg : %.2lf\n", avg);  // ��հ� ���
	printf("Dispersion : %.2lf\n", dis);  // �л갪 ���
	printf("StdDispersoin : %.2lf\n", std);  // ǥ�������� ���

}