#include "Utility.h"

// ���� - �����ġ �κ�
void StopWatch() {
	printf("===== �����ġ =====\n");
	printf("�ƹ�Ű�� ������ ���� �մϴ�.");
	system("pause");

	Time_format data;
	clock_t start_time = clock();
	while (1) {
		// �ð� ��� �� �ð� ���� ����� 
		clock_t curr_time = clock() - start_time;
		data = GetTime(curr_time);
		//�ð� �������� ���
		printf("\n\n\t%d:%d:%d.%d\n\n", data.hour, data.min, data.sec, data.undersec);

		//Ű �Է��� �޾����� ���߱�(�Ͻ�����)
		if (_kbhit()) {

			//�Ͻ����� �� ���� ����
			printf("1.�����\t2.�ʱ�ȭ\t3.����\n");
			printf("���ϴ� ����� ���� �ϼ��� : ");
			int input = Intinput(1, 3);

			//1. ����� ���ý� �����ġ�� �̾ ����
			if (input == 1) {
				start_time = clock() - curr_time;
				continue;
			}
			//2. �ʱ�ȭ ���ý� �����ġ�� �ʱ�ȭ �� ����
			if (input == 2) {
				start_time = clock();
				continue;
			}
			else {
				break;
			}

		}
		system("cls");
	}
	system("pause");
}