#include <stdio.h>

int main(void)
{
	int nA[3] = { 1,2,3 };  // 초가화된 A배열
	int nB[10] = {};  // 초기화되지 않은 B배열
	int i = 0;  // i에 대한 변수 초기화

	// B배열을 채우기 위해 B배열 요소우ㅏ 개수만큼 반복
	for (i = 0; i < 10; i++)  
	{
		// A배열 첨자가 0~2를 갖도록 나머지 연산자 사용
		nB[i] = nA[i % 3]; 
	}

	// B배열 출력
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", nB[i]);
	}
	printf("\n");
	return 0;
}