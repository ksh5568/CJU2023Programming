#include <stdio.h>
#define G 9.81  // �߷°��ӵ� (���� : m/s^2)
#define H 100.00  // �ʱ� ���� (���� : m)
#define KG 1  // ��Ʋ�� ���� (���� : kg)

int main(void)
{
	double nTIME = 0.0000;  // �ð��� ���� ���� ����
	double height = 0.0000;  // ���� ������ ���� ���� ����

	printf("This is a program that calculates free fall motion.\n");  // �������� ��� ���� ���α׷��̶�� ���� ���
	printf("When Youngsu lets a 1kg kettlebell fall freely from a height of 100m,\n");  // 1kg ��Ʋ���� 100m ���̿��� ������ ���� ���
	printf("how long does it take for it to reach the ground?\n");  // ���鿡 �����ϱ���� �ɸ��� �ð��� ���ΰ��� ���

	do
	{
		height = 0.5 * G * (nTIME * nTIME);  // �������Ͽ ����
		nTIME = nTIME + 0.0001;  // �ݺ� �ɶ� 0.0001s �� ����

	} while (height < H);  // �ʱ� ���̰����� ���� �� ����Ͽ� ����
	
	printf("\n");
	printf("Time : %.3lf s\n", nTIME);  // ����� ���
}