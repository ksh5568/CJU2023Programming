#include <stdio.h>
#define START 0000  // �����ϴ� ���� ��ũ�� ����
#define END 9999  // �����ϴ� ���� ��ũ�� ����

int main(void)
{
	int sys = 0;  // ���� Ȥ�� ���ῡ ���� ����
	int nA = 0;  // �Է¹޴� ����
	int i = 0;  // ���ǹ� �ݺ� ����
	int sum = 0;  // ����� ����

	while (true)  // ���� �ݺ��� ����
	{
		printf("Enter the start(0000) and end(9999) : ");  // ������"0000"�� ����� "9999"�� ���
		scanf_s("%d", &sys);  // ���� Ȥ�� ���ῡ ���� ���� ����

		if (sys == START)  // ���ۿ����� ������ ���
		{
			for (i = 0; i < 5; i++)  // 5�� �ݺ�
			{
				printf("Please enter the DNA number : ");  // DNA ���ڸ� �Է� ����
				scanf_s("%d", &nA);  // �Է� ���������� ����

				sum = sum + nA;  // �Է� ���� ������ sum�� ���� �� ����
			}

			if ((sum % 5) == 3)  // 5�γ������� �� 3�̸�
			{
				printf("Suspect\n");  // �����ڶ�� ���
				printf("\n");
			}
			else  // �ƴҰ��
			{
				printf("Citizen\n\n");  // �ù����� ���
				printf("\n");
			}
			continue;  // ���α׷� �ٽ� �ݺ�
		}

		if (sys == END)  // ���ῡ ���� ������ ���
		{
			break;  // ���α׷� ����
		}
	}
	return 0;
}