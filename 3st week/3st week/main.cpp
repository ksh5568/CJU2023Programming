#include <stdio.h>

int main(void)
{
	char ch;

	printf("Typing : ");
	scanf_s("%c", &ch);
	printf("The ASCII value of the %c characters is %d\n", ch, ch);

	return 0;
}