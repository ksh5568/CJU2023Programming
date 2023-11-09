#include <stdio.h>

#define ONE 1  // 1에 대한 메크로 설정
#define TWO 2  // 2에 대한 메크로 설정 
#define THREE 3  // 3에 대한 메크로 설정
#define MAX_NUM 6  // 6에 대한 메크로 설정

int main(void)
{
	// 배열에 대한 초기화 및 첫번째 부터 세번째까지의 배열 요소 설정
	int ary[MAX_NUM] = { ONE,TWO,THREE };  

	// 반복문을 통한 각각의 배열 요소 출력
	for (int i = 0; i < MAX_NUM; i++)  
	{
		printf("%d\t", ary[i]);
	}
	printf("\n");

	return 0;
}