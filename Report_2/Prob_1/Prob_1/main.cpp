#include <stdio.h>
#define START 0000  // 시작에 대한 메크로 설정
#define END 9999  // 종료에 대한 메크로 설정

int main(void)
{
	int sys = 0;  // 시작여부에 대한 변수 설정
	int nA = 0;  // 입력받을 첫번째수 변수 설정
	int nB = 0;  // 입력받을 두번쨰수 변수 설정
	int sum_GCD = 0;  // 최대공약수 값 변수 설정
	int sum_LCM = 0;  // 최소공배수 값 변수 설정
	int min = 0;  // 최소값 변수 설정
	int max = 0;  // 최대값 변수 설정

	while (true)
	{
		printf("Start is 0000 or End is 9999 : ");  // 시작 혹은 종료를 출력
		scanf_s("%d", &sys);  // 시작여부에 대한 변수 저장

		if (sys == START)  // 시작에 대한 변수 일경우
		{
			printf("Please enter the two integer : ");  // "두개의 정수를 입력하세요"를 출력
			scanf_s("%d%d", &nA, &nB);  // 입력 받은 두개의 정수를 변수에 저장

			if (nA < nB ? min = nA : min = nB)  // 두 정수중 작은 값을 최소값으로 설정
			{
				for (int i = 1; i <= min; i++)  // 최소값 만큼 반복하면서 1씩 증가
				{
					if (nA % i == 0 && nB % i == 0)  // 두 조건에 만족하면
					{
						sum_GCD = i;  // i값을 최대 공약수로 저장
						sum_LCM = (nA * nB) / sum_GCD;  // 최소공배수를 계산 후 결과값 저장
					}
				}
				printf("The greatest common divisor is %d\n", sum_GCD);  // 최대공약수 변수에 저장된 값 출력
				printf("The largest common multiple is %d\n", sum_LCM);  // 최소공배수 변수에 저장된 값 출력
				printf("\n");
			}
		}

		if (sys == END)  // 종료에 대한 변수일 경우
		{
			printf("Program exit.");  // 프로그램 종료를 출력
			break;  // 프로그램 종료
		}
	}
	return 0;
}