#include <stdio.h>
#include <string.h>

int main(void)
{
	// 각 char형 배열 초기화
	char str1[80] = { 'p', 'i', 'g' }; 
	char str2[] = "elephant";
	char str3[5] = "apple";
	char str4[2] = { "sun","moon" };

	// 각 char형 배열 출력
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	printf("%s\n", str4);

	return 0;
}
