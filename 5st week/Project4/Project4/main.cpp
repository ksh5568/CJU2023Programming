#include <stdio.h>


int main(void)
{
	int a = 0;  // ù���� �� ������ ����
	int b = 0;  // �ι��� �� ������ ����
	int res = 0;  // ����� ������ ����
	char symbol;  // �����ȣ �����ؼ� ������ ����

	printf("Enter the basic operations : ");  // ��Ģ���� �Է�
	scanf_s("%d", &a);  // ù��° �� ����
	scanf_s("%c", &symbol);  // �ι�° �� ����
	scanf_s("%d", &b);  // �����ȣ ����

	switch (symbol)
	{
	case '+':   // �����ȣ�� ���ϱ� �� �� ���� ���
		res = a + b;
		break;

	case '-':   // �����ȣ�� ���� �� �� ���� ���
		res = a - b;
		break;

	case '*':   // �����ȣ�� ���ϱ� �� �� ���� ���
		res = a * b;
		break;

	default:  // �� �� �������� ������� ���� ���
		res = a / b;
		break;
	}

	printf("%d%c%d=%d\n", a, symbol, b, res);  // if���� ���� �Է� ���� ������ ���Ŀ� �°� ���

	return 0;
}