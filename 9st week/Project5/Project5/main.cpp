#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[80] = { 0 }, str2[80] = { 0 };  // ù��°�� �ι�° �迭 ����
	char temp[80] = { 0 };  // ����° �迭 ����

	printf("Enter the two word :");  // �� ���� ���ڸ� �Է� �ޱ� ���
	scanf("%s  %s", str1, str2);  // �Է� ���� �ΰ��� ���� ����
	printf("Before : %s, %s\n", str1, str2);  // �ٲٱ� �� ���
	// strcpy_s�Լ��� �̿��Ͽ� ��ġ �ٲ�
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);

	printf("After : %s, %s\n", str1, str2);  // �ٲ� �� ���

	return 0;
}