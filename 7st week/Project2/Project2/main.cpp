#include <stdio.h>

int main(void)
{

	for (int i = 0; i < 5; i++)  // i������ ����Ǵ� �ݺ��� ����
	{
		for (int j = 0; j < 5; j++)  // j������ ����Ǵ� �ݺ��� ����
		{
			if (i == j)  // ���������� ���� ǥ���ϴ� ���ǹ� ����
			{
				printf("*");
			}
			else if ( i + j == 4)  // ���������� ���� ǥ���ϴ� ���ǹ� ����
			{
				printf("*");
			}
			else  // �׿� �������� ǥ�� 
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}