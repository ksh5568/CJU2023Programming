#include <stdio.h>

int main(void)
{
	double angle = 0.0;  // ������ �ʱ�ȭ
	double res = 0.0;  // ����� �ʱ�ȭ
	
	printf("Enter the angle : ");  // ������ �Է� �ޱ�
	scanf_s("%lf", &angle); // ������ �Ǽ��� �Է� 

	res = ((int)angle + 180) % 360 - 180;  // +-180�� �κ�ȯ�� �������� ������� ��ȯ
	printf("Converted posture value : %.2lf\n", res);  // ��ȯ�� �������� �Ǽ��� ���

	return 0;
}