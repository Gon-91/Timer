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
					double time_double = (double)curr_time / 1000;
					printf("%.3lf\n", time_double);
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
				printf("2��\n");
				system("pause");
				break;
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