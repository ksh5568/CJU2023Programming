#include <stdio.h>

int main(void)
{
	char str[80];  // �Է� ���� ���� �迭 ����
	int count = 0;  // �ٲ� ���� �� ���� �ʱ�ȭ
	int i = 0;  // �ݺ��� Ƚ�� ���� �ʱ�ȭ

	printf("Enter the text :");  // ������ �Է��ϼ��� ���
	gets_s(str);  // ���ڿ� �Է�

	for (i = 0; str[i]!='\0'; i++)  // '\0'���� ���ö� ���� �ݺ�
	{
		if (str[i] >= 'A' && str[i] <= 'Z')  // ���ĺ� ���� ����
		{
			str[i] += ('a' - 'A');  // �빮��, �ҹ��� ��ȯ ����
			count++;  // Ƚ�� ����
		}
	}
	printf("After : %s\n", str);  // �ٲ� ���ڿ� ��� 
	printf("count : %d\n", count);  // �ٲ� �� ���
	return 0;
}