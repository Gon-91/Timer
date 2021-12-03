#include<stdio.h>
#include<time.h>
#include<Windows.h>

int main() {
	while (1) {
		//메뉴 입력
		system("cls");
		printf("\t=== Test Program ==\n\n");
		int input;
		printf("1.스톱워치\t2.타이머\t3.종료\n\n");
		printf("원하는 메뉴를 입력 하세요 : ");
		scanf_s("%d", &input);

		//메뉴에 따른 제어
		if (input > 0 && input < 4) {
			if (input == 3) {
				printf("프로그램을 종료 합니다.");
				break;
			}
			switch (input)
			{
			case 1:
				/*
				* 아래 기능을 포함하여 구현 예정
				* 시작 | 기록 | 정지 | 초기화
				*/
				printf("1번\n");
				system("pause");
				break;
			case 2:
				/*
				* 시간 / 분 / 초를 이용한 타이머 카운팅 시작하게 구현 예정
				* 최대 100시간 ? 
				* 입력을 통해 카운팅 시간 설정 
				* 시작 | 정지 | 초기화 
				*/
				printf("2번\n");
				system("pause");
				break;
			}
		}
		//예외 처리
		else {
			while (getchar() != '\n') {}
			printf("잘못된 입력입니다.");
			system("pause");
		}
	}
	return 0;
}