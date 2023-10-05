#include <stdio.h>

int main(void)
{
	int year = 0;  // '출생년도' 저장할 변수
	int month = 0;  // '월' 저장할 변수
	int day = 0;  // '일' 저장할 변수
	int res = 0;  // 수식 계산한 결과값 저장할 변수

	printf("Enter the birth date : ");  // '출생년도', '월', '일' 입력
	scanf_s("%d%d%d", &year, &month, &day);  // 각 변수에 저장

	res = year - month + day;  // 결과값 계산


	if (res % 10 == 0)  // 결과값에 '10'을 나누어 나머지가 '0'인경우를 판단함
	{
		printf("You are very good\n");  // 나머지가 '0'인 경우 'very goog'출력
	} 
	else
	{
		printf("You are so so\n");  // 나머지가 '0'이 아닌 경우 'so so'출력
	}

	return 0;
}