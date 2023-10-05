#include <stdio.h>
#define AGE 25  //  25에 대한 변수 메크로 설정
#define CHESTSIZE 95  //  95에 대한 변수 메크로 설정
#define TWENTY 20  //  20에 대한 변수 메크로 설정
#define S_SIZE 85  //  85에 대한 변수 메크로 설정
#define M_SIZE 90  //  90에 대한 변수 메크로 설정
#define L_SIZE 100  //  100에 대한 변수 메크로 설정

int main(void)
{
	int age = AGE;  // 나이의 크기를 저장할 변수
	int chest = CHESTSIZE;  // 가슴둘레의 크기를 저장할 변수
	char size;  // 옷의 사이즈를 결정해서 저장할 변수

	if (age < TWENTY)  // '20'살 이하에 대한 범위 설정
	{
		if (chest < S_SIZE)  // '20'살 이하에서 'S'사이즈에 대한 범위 설정
		{
			size = 'S';
		}
		else if ((chest >= S_SIZE) && (chest < CHESTSIZE))  // '20'살 이하에서 'M'사이즈에 대한 범위 설정
		{
			size = 'M';
		}
		else    // '20'살 이하에서 그외 사이즈 'L'사이즈로 출력
		{
			size = 'L';
		}
	}
	else  // '20'살 이상에 대한 범위 설정
	{
		if (chest < M_SIZE)  // '20'살 이상에서 'S'사이즈에 대한 범위 설정
		{
			size = 'S';
		}
		else if ((chest >= M_SIZE) && (chest < L_SIZE  // '20'살 이상에서 'M'사이즈에 대한 범위 설정
		{
			size = 'M';
		}
		else    // '20'살 이상에서 그외 사이즈 'L'사이즈로 출력
		{
			size = 'L';
		}
	}
	printf("Size is %c.\n", size);  // if문을 통한 가슴크기와 나이에 대한 변수에 맞는 사이즈 출력

	return 0;
}
