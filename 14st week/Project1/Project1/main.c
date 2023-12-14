#include <stdio.h>
#include <string.h>

#define A 90
#define B 80
#define C 70
#define MAX_NUM 5

// 구조체 설정
typedef struct 
{
	int id;
	char name[20];
	int kor;
	int eng;
	int math;
	int tot;
	int avg;
	char grade;

}Student;

// 정보 출력 함수 정의
void First_Output(Student *s_list)
{
	Student temp[MAX_NUM] =
	{
		{ 315, "Hong_gil_dong", 80, 75, 90},
		{ 316, "Lee sun sin", 80, 92, 100 },
		{ 317, "Seo ha yoon", 95, 99, 98 },
		{ 318, "Yu gwan sun", 84, 70, 72 },
		{ 319, "Park shin hye", 60, 65, 40 }
	};

	for (int i = 0; i < MAX_NUM; i++)
	{
		printf("Id : %d\n", temp[i].id);
		s_list[i].id = temp[i].id;

		printf("Name : %s\n", temp[i].name);
		strcpy_s(s_list[i].name, 20, temp[i].name);
		
		printf("KOR, ENG, MATH of Score : %5d%5d%5d\n", temp[i].kor, temp[i].eng, temp[i].math);
		s_list[i].kor = temp[i].kor;
		s_list[i].eng = temp[i].eng;
		s_list[i].math = temp[i].math;
	}
}

// 합계 및 평균 계산 함수 정의
Calculate_Grade(Student* s_list)
{
	for (int j = 0; j < 5; j++)
	{
		s_list[j].tot = s_list[j].kor + s_list[j].eng + s_list[j].math;
		s_list[j].avg = s_list[j].tot / 3;

		if (s_list[j].avg >= A)
		{
			s_list[j].grade = 'A';
		}
		else if (s_list[j].avg < A && s_list[j].avg >= B)
		{
			s_list[j].grade = 'B';
		}
		else if (s_list[j].avg < B && s_list[j].avg >= C)
		{
			s_list[j].grade = 'C';
		}
		else
		{
			s_list[j].grade = 'F';
		}
	}
};

// 내림 차순 함수 정의
void line_up(Student *s_list)
{
	Student temp;

	for (int i = 0; i < MAX_NUM; i++)
	{
		for (int j = i; j < MAX_NUM; j++)
		{
			if (s_list[i].tot < s_list[j].tot)
			{
				temp = s_list[i];
				s_list[i] = s_list[j];
				s_list[j] = temp;
			}
		}
	}
}

int main(void)
{
	int k = 0;
	Student s_list[5];
	
	First_Output(s_list); // 정보 출력 함수 호출
	Calculate_Grade(s_list); // 합계 및 평균 계산 함수 호출

	// 정렬 전 결과값 출력
	printf("\nBefore\n");
	for (k = 0; k < MAX_NUM; k++)
	{
		printf("Id : %5d%20s%5d%5d%5d%5d%5d%5c\n", 
			s_list[k].id, s_list[k].name, s_list[k].kor, s_list[k].eng, s_list[k].math, s_list[k].tot, s_list[k].avg, s_list[k].grade);
	}

	// 내림 차순 함수 호출
	line_up(s_list);

	// 정렬 후 결과값 출력
	printf("\nAfter\n");
	for (k = 0; k < MAX_NUM; k++)
	{
		printf("Id : %5d%20s%5d%5d%5d%5d%5d%5c\n",
			s_list[k].id, s_list[k].name, s_list[k].kor, s_list[k].eng, s_list[k].math, s_list[k].tot, s_list[k].avg, s_list[k].grade);
	}
}