#include "Utility.h"

// ��� - ����ó�� �޴� �Է�
int Intinput(int min, int max) {
	int input;
	while (1) {
		scanf_s("%d", &input);
		if (input >= min && input <= max) {
			return input;
		}
		else {
			while (getchar() != '\n') {}
			printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���. : ");
		}
	}
}
// ��� - �ð� ó��
Time_format GetTime(clock_t time) {
	Time_format data;
	double tempd = (double)time / 1000;
	int tempi = (int)tempd;
	data.hour = tempi / 60 / 60;
	data.min = tempi / 60 % 60;
	data.sec = tempi % 60;
	data.undersec = time % 1000;
	return data;
}
Time_format SetTime() {
	Time_format data;
	int set_total = 0;
	system("cls");
	set_total = 0;
	printf("�ð��� �Է��� �ּ��� : ");
	set_total = Intinput(0, INT_MAX) * 60 * 60;
	system("cls");
	printf("���� �Է��� �ּ��� : ");
	set_total += Intinput(0, INT_MAX) * 60;
	system("cls");
	printf("�ʸ� �Է��� �ּ��� : ");
	set_total += Intinput(0, INT_MAX);
	system("cls");
	data = GetTime((clock_t)(set_total * 1000));
	data.total = set_total;
	return data;
}