#include <stdio.h>
#define START 0000  // ���ۿ� ���� ��ũ�� ����
#define END 9999  // ���ῡ ���� ��ũ�� ����

int main(void)
{
	int sys = 0;  // ���ۿ��ο� ���� ���� ����
	int nA = 0;  // �Է¹��� ù������ ���� ����
	int nB = 0;  // �Է¹��� �ι����� ���� ����
	int sum_GCD = 0;  // �ִ����� �� ���� ����
	int sum_LCM = 0;  // �ּҰ���� �� ���� ����
	int min = 0;  // �ּҰ� ���� ����
	int max = 0;  // �ִ밪 ���� ����

	while (true)
	{
		printf("Start is 0000 or End is 9999 : ");  // ���� Ȥ�� ���Ḧ ���
		scanf_s("%d", &sys);  // ���ۿ��ο� ���� ���� ����

		if (sys == START)  // ���ۿ� ���� ���� �ϰ��
		{
			printf("Please enter the two integer : ");  // "�ΰ��� ������ �Է��ϼ���"�� ���
			scanf_s("%d%d", &nA, &nB);  // �Է� ���� �ΰ��� ������ ������ ����

			if (nA < nB ? min = nA : min = nB)  // �� ������ ���� ���� �ּҰ����� ����
			{
				for (int i = 1; i <= min; i++)  // �ּҰ� ��ŭ �ݺ��ϸ鼭 1�� ����
				{
					if (nA % i == 0 && nB % i == 0)  // �� ���ǿ� �����ϸ�
					{
						sum_GCD = i;  // i���� �ִ� ������� ����
						sum_LCM = (nA * nB) / sum_GCD;  // �ּҰ������ ��� �� ����� ����
					}
				}
				printf("The greatest common divisor is %d\n", sum_GCD);  // �ִ����� ������ ����� �� ���
				printf("The largest common multiple is %d\n", sum_LCM);  // �ּҰ���� ������ ����� �� ���
				printf("\n");
			}
		}

		if (sys == END)  // ���ῡ ���� ������ ���
		{
			printf("Program exit.");  // ���α׷� ���Ḧ ���
			break;  // ���α׷� ����
		}
	}
	return 0;
}