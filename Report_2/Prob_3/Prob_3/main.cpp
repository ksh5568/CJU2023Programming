#include <stdio.h>
#define START 0000  // ���ۿ� ���� ��ũ�� ����
#define END 9999  // ���ῡ ���� ��ũ�� ����

int main(void)
{
	int sys = 0;  // ���� ���ο� ���� ���� ����
	int num = 0;  // �Է� �޴� ������ ���� ���� ����
	int count = 0;  // �ڼ�ġ�� Ƚ���� ���� ���� ����
	int i = 1;  // �ݺ� �ϴ� ���� ���� ���� ����

	while (true)  // ���ѹݺ��� ����
	{
		printf("Would you like to start the game?\n");  // "������ �����Ͻðڽ��ϱ�?"�� ���
		printf("Enter 0000 to start and 9999 to end : ");  // ���ۿ��ο� ���� �Է� ����
		scanf_s("%d", &sys);  // ���ۿ� ���ο� ���� �Է� ���� ������ ����

		if (sys == START)  // ���ۿ� ���� ������ ���
		{
			printf("\n"); 
			printf("Enter the number : ");  // ������ �Է� ���� 
			scanf_s("%d", &num);  // �Է� ���� ������ ����

			for (i = 1; i <= num; i++)  // i�� 1�� �ʱ�ȭ �ϰ� �Է� ���� ������ŭ �ݺ��ϰ� 1�� �����Ѵ�.
			{
				if (i % 3 == 0)  // �ڼ� ġ�� ������ ����
				{
					count++;  // ���ǿ� �����Ҷ� ���� ī��Ʈ ������ 1�� ����
				}
			}
			printf("Count of clap : %d\n", count);  // �ڼ��� ģ Ƚ���� ���
			printf("\n");
		}
		if (sys == END)  // ���ῡ ���� ���� �� ���
		{
			printf("\n");
			printf("Game Over\n");  // ���� ���Ḧ ���
			break;  // ���α׷� ����
		}
		if (sys != START && sys != END)  // ���� Ȥ�� ���ῡ ���� ������ �ƴҰ��
		{
			printf("\n");
			printf("Try again\n");  // �ٽ� �õ��ϼ��並 �����
			printf("\n");
		}
	}
	return 0;
}