#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

int main() {
	while (1) {
		//�޴� �Է�
		system("cls");
		printf("\t=== Test Program ==\n\n");
		int input;
		printf("1.�����ġ\t2.Ÿ�̸�\t3.����\n\n");
		printf("���ϴ� �޴��� �Է� �ϼ��� : ");
		scanf_s("%d", &input);
		//�޴��� ���� ����
		if (input > 0 && input < 4) {
			if (input == 3) {
				printf("���α׷��� ���� �մϴ�.");
				break;
			}

			switch (input)
			{
			case 1:
				/*
				* �Ʒ� ����� �����Ͽ� ���� ����
				* ���� | ��� | ���� | �ʱ�ȭ
				*/
				printf("�ƹ�Ű�� ������ ���� �մϴ�.");
				system("pause");
				clock_t start_time = clock();
				while (1) {
					clock_t curr_time = clock() - start_time;

					//UI���� �ϱ�
					double time_double = (double)curr_time / 1000;
					//printf("%.3lf\n", time_double);

					int trans;
					int undersec;
					int sec;
					int min;
					int hour;

					trans = (int)time_double;
					undersec = curr_time%1000;
					sec = trans % 60;
					min = trans /60%60;
					hour = trans /60/60;

					printf("\n\n\t%d:%d:%d.%d\n\n", hour,min,sec, undersec);
					
					//Ű �Է��� �޾����� ���߱�(�Ͻ�����)
					if (_kbhit()) {
						
						printf("1.�����\t2.�ʱ�ȭ\t3.����\n");
						printf("���ϴ� ����� ���� �ϼ��� : ");
						scanf_s("%d", &input);
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
				break;

			case 2:
				/*
				* �ð� / �� / �ʸ� �̿��� Ÿ�̸� ī���� �����ϰ� ���� ����
				* �ִ� 100�ð� ? 
				* �Է��� ���� ī���� �ð� ���� 
				* ���� | ���� | �ʱ�ȭ 
				*/
				//printf("2��\n");

				//Ÿ�̸� ���� �Է� 
				int set_hour;
				int set_min;
				int set_sec;
				printf("�ð��� �Է��� �ּ��� : ");
				scanf_s("%d", &set_hour);
				printf("���� �Է��� �ּ��� : ");
				scanf_s("%d", &set_min);
				printf("���� �Է��� �ּ��� : ");
				scanf_s("%d", &set_sec);

				printf("�ƹ�Ű�� ������ Ÿ�̸Ӱ� ����˴ϴ�.\n");
				printf("���� �ð� %d:%d:%d\n", set_hour, set_min, set_sec);
				system("pause");

				//ǥ�ÿ� ����
				int display_sec = set_sec;
				int display_min = set_min;
				int display_hour = set_hour;
				// �ð� ī���� ���� ��
				clock_t start_time2 = clock();
				while (1) {
					system("cls");

					// 0�ʷ� ����
					clock_t curr_time = clock() - start_time2;

					double time_double = (double)curr_time / 1000;
					int trans;
					int undersec;
					int sec;
					int min;
					int hour;

					trans = (int)time_double;
					undersec = curr_time % 1000;
					sec = trans % 60;
					min = trans / 60 % 60;
					hour = trans / 60 / 60;
					



					printf("\n\n\t%d:%d:%d\n\n", display_hour - hour, display_min - min, display_sec - sec);
					if (display_sec - sec == 0) {
						display_min--;
						display_sec = 59 + set_sec;
					}
					if (display_min - min == -1) {
						display_hour--;
						display_min = 59 + set_min;
					}

				}

			}
		}
		//���� ó��
		else {
			while (getchar() != '\n') {}
			printf("�߸��� �Է��Դϴ�.");
			system("pause");
		}
	}
	return 0;
}