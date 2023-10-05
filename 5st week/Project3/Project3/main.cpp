#include <stdio.h>


int main(void)
{
	int a = 0;
	int b = 0;
	int res = 0;
	char symbol;

	printf("Enter the basic operations : ");
	scanf_s("%d", &a);
	scanf_s("%c", &symbol);
	scanf_s("%d", &b);

	if (symbol == '+')
	{
		res = a + b;
	}
	else if (symbol == '-')
	{
		res = a - b;
	}
	else if (symbol == '*')
	{
		res = a * b;
	}
	else 
	{
		res = a / b;
	}

	printf("%d%c%d=%d\n", a, symbol, b, res);

	return 0;
}