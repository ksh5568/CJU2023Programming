#include <stdio.h>

int main(void)
{
	int inputprice = 0; // ������ �ݾ� ���� �ʱ�ȭ
	int itemprice = 0;  // ���ǰ� ���� �ʱ�ȭ
	int change = 0;  // �Ž����� ���� �ʱ�ȭ
	int c100 = 0;  // 100�� ���� �ʱ�ȭ
	int c500 = 0;  // 500�� ���� �ʱ�ȭ
	int c1000 = 0;  // 1000�� ���� �ʱ�ȭ

	printf("Enter the amount you put in : ");  // ������ �ݾ� �Է� �ޱ�
	scanf_s("%d", &inputprice);  // ������ �ݾ� ������ �Է�

	printf("Enter the price of the item : ");  // ���ǰ� �Է� �ޱ�
	scanf_s("%d", &itemprice);  // ���ǰ� ������ �Է�

	change = inputprice - itemprice;  // �Ž����� ��� ����

	c1000 = change / 1000;  // 1000�� ��� ����
	c500 = change / 500;  // 500�� ��� ����
	c100 = change / 100;  // 100�� ��� ����

	printf("change money : %d\n", change);  // ���� �Ž����� ���
	printf("change 1000 : %d\n", c1000);  // ���� 1000���� ���� ���
	printf("change 500 : %d\n", c500);  // ���� 500���� ���� ���
	printf("change 100 : %d\n", c100);  // ���� 100���� ���� ���

	return 0;
}