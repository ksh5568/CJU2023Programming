#include <stdio.h>

int main(void)
{
	FILE* fp;                     // ���� ������
	char str[20] = "empty";       // ���ڿ� �Է� �迭
	int ch;                       // ���ڿ� �Է� ����

	fp = fopen_s(&fp, "a.txt", "r");     // ���� ����
	ch = fgetc(fp);                // ���� �Է�
	while (fgetc(fp) != EOF);     // ���� ���

	fgets(str, sizeof(str), fp);  // �� �� �Է�
	printf("%s", str);            // ���
	fclose(fp);                   // ���� ����

	return 0;
}