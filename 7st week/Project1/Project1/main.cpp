#include <stdio.h>

int main(void)
{
	int a = 0;  // ������ �ܼ��� �Է� �޴� ����

	printf("Enter the singular number : ");  // ������ �ܼ��� ���� ������ �Է� �ޱ�
	scanf_s("%d", &a);  // ������ �ܼ��� ���� ������ ����
	
	if(0<a,a<10)  // 1~9������ ���ڸ� Ȱ���ϰ� ���ǹ� ����
		for (int i = 1; i < 10; i++)  // 9�� ������ �ݺ� ����
		{
			printf("%d * %d = %d\n", a, i, a * i);  // ������ ��� �� ����� ���
		}
	else
	{
		printf("You entered it incorrectly\n"); // 1~9������ ���ڰ� �ƴҽ� ���α׷� ����
	}

	return 0;
}