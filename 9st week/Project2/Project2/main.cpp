#include <stdio.h>

#define ONE 1  // 1�� ���� ��ũ�� ����
#define TWO 2  // 2�� ���� ��ũ�� ���� 
#define THREE 3  // 3�� ���� ��ũ�� ����
#define MAX_NUM 6  // 6�� ���� ��ũ�� ����

int main(void)
{
	// �迭�� ���� �ʱ�ȭ �� ù��° ���� ����°������ �迭 ��� ����
	int ary[MAX_NUM] = { ONE,TWO,THREE };  

	// �ݺ����� ���� ������ �迭 ��� ���
	for (int i = 0; i < MAX_NUM; i++)  
	{
		printf("%d\t", ary[i]);
	}
	printf("\n");

	return 0;
}