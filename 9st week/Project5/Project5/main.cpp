#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[80] = { 0 }, str2[80] = { 0 };  // 첫번째와 두번째 배열 선언
	char temp[80] = { 0 };  // 세번째 배열 선언

	printf("Enter the two word :");  // 두 개의 문자를 입력 받기 출력
	scanf("%s  %s", str1, str2);  // 입력 받은 두개의 문자 저장
	printf("Before : %s, %s\n", str1, str2);  // 바꾸기 전 출력
	// strcpy_s함수를 이용하여 위치 바꿈
	strcpy(temp, str1);
	strcpy(str1, str2);
	strcpy(str2, temp);

	printf("After : %s, %s\n", str1, str2);  // 바꾼 후 출력

	return 0;
}