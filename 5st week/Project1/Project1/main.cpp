#include <stdio.h>

int main(void)
{
	int chest = 95;  // 가슴둘레의 크기를 저장할 변수
	char size;  // 옷의 사이즈를 결정해서 조장할 변수

	if (chest <= 90)  // 'S'사이즈에 대한 범위 설정
	{
		size = 'S';
	}
	else if ((chest > 90) && (chest <= 100))  // 'M'사이즈에 대한 범위 설정
	{
		size = 'M';
	}
	else  // 그 이상의 사이즈는 'L'로 출력
	{
		size = 'L';
	}

	printf("SIZE : '%C'\n", size);  // if문을 통한 가슴크기의 변수에 맞는 사이즈 출력

	return 0;

}
