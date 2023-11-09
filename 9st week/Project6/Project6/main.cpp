#include <stdio.h>

int main(void)
{
	char str[80];  // 입력 받을 문장 배열 선언
	int count = 0;  // 바뀐 문자 수 변수 초기화
	int i = 0;  // 반복할 횟수 변수 초기화

	printf("Enter the text :");  // 문장을 입력하세요 출력
	gets_s(str);  // 문자열 입력

	for (i = 0; str[i]!='\0'; i++)  // '\0'문자 나올때 까지 반복
	{
		if (str[i] >= 'A' && str[i] <= 'Z')  // 알파벳 구간 정의
		{
			str[i] += ('a' - 'A');  // 대문자, 소문자 변환 정의
			count++;  // 횟수 증가
		}
	}
	printf("After : %s\n", str);  // 바뀐 문자열 출력 
	printf("count : %d\n", count);  // 바뀐 수 출력
	return 0;
}