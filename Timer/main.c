#include "Utility.h"

int main() {

	//���α׷� ����
	while (1) {
		//���� ȭ�� �κ�
		system("cls");
		printf("\t=== Test Program ==\n\n");
		int input;
		printf("1.�����ġ\t2.Ÿ�̸�\t3.����\n\n");
		printf("���ϴ� �޴��� �Է� �ϼ��� : ");
		input = Intinput(1, 3);
		//�޴� �Է� �� �����ϱ�
		//�������� �Է��̸�
		if (input > 0 && input < 4) {
			//���� �Է½�
			if (input == 3) {
				printf("���α׷��� ���� �մϴ�.");
				break;
			}
			//�����ġ �Ǵ� Ÿ�̸� �κ�
			switch (input)
			{
			//�����ġ
			case 1:
				StopWatch();
				break;
			//Ÿ�̸�
			case 2:
				Timer();
				break;
			}
		}
		//���� �߻� �� 
		else {
			while (getchar() != '\n') {}
			printf("�߸��� �Է��Դϴ�.");
			system("pause");
		}
	}
	return 0;
}