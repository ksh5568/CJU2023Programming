#include <stdio.h>

int get_operation(int x, int y);  // ��ģ���� �Լ� ����

int main(void)
{
	int nA = 0;  // ù��°�� ���� ����
	int nB = 0;  // �ι�°�� ���� ����
	int res = 0;  // ��ȯ���� ������ ���� ����

	res = get_operation(nA, nB);

	return 0;
}

int get_operation(int x, int y)  // get_operation �Լ� ���� ����
{
	printf("Enter the two number : ");  // "�� ���� �Է��ϼ���" ��� 
	scanf_s("%d%d", &x, &y);  // "�Է� ���� �� ������ ����"

	printf("Plus : %d\n", x + y);  // ���ϱ� ���
	printf("Subtraction : %d\n", x - y);  // ���� ���
	printf("Multiplication : %d\n", x * y);  // ���ϱ� ���
	printf("Divide : %d\n", x / y);  // ������ �� ���
	printf("Remaider : %d\n", x % y);  // ������ ������ ���

	return x;  // ����� ��ȯ
}
