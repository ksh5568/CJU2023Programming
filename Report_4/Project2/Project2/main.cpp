#include <stdio.h>
#include <math.h>

#define D_NUMBER {-5, 3, 3, -4, 3}

// ����ü ����
typedef struct
{
	double nX;  // ������ x��ǥ
	double nY;  // ������ y��ǥ
	double nA;  // 2�� �������� a��
	double nB;  // 2�� �������� b��
	double nC;  // 2�� �������� c��

}Num;

// ����б� ���а������� �ִܰŸ� ���ϴ� ���� �Լ� ����
void Distance_Calculation(Num i_list)
{
	double temp = 0;

	temp = fabs((i_list.nA * i_list.nX) + (i_list.nB * i_list.nY) + i_list.nC) / (sqrt(pow(i_list.nA, 2) + pow(i_list.nB, 2)));
	
	// ù��° ����� ���
	printf("Result_Distance#1 : %.2lf\n", temp);
}

// ���� ������ �̿��� �ִܰŸ� ���ϴ� ���� �Լ� ����
void Distance_vector(Num i_list)
{
	double n_dot = 0;
	double n_vol = 0;
	double n_res = 0;

	// 2�� �����Ŀ����� ���� ����
	double la_vector = - (i_list.nA / i_list.nC);
	double lb_vector = - (i_list.nA / i_list.nB);

	n_dot = (la_vector * i_list.nX) + (lb_vector * i_list.nY);  // ������ ������ ���
	n_vol = sqrt(pow(la_vector, 2) + pow(lb_vector, 2));  // ������ ũ�� ���

	n_res = fabs(n_dot) / n_vol;

	// �ι�° ����� ���
	printf("Result_Distance#2 : %.2lf\n", n_res);
	printf("Result_Distance#2 : %.2lf\n", la_vector);
	printf("Result_Distance#2 : %.2lf\n", lb_vector);
}

int main(void)
{
	Num i_list = D_NUMBER;

	// ���α׷� ���� ���
	printf("This is a program that calculates distance.\n");
	printf("\n");

	// �Ÿ��� ����ϴ� �ΰ��� ����� �Լ� ȣ��
	Distance_Calculation(i_list);
	Distance_vector(i_list);

	return 0;
}