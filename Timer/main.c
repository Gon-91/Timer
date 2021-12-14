#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

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
				printf("아무키나 누르면 시작 합니다.");
				system("pause");
				clock_t start_time = clock();
				while (1) {
					clock_t curr_time = clock() - start_time;

					//UI개선 하기
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
					
					//키 입력을 받았을때 멈추기(일시정지)
					if (_kbhit()) {
						
						printf("1.재시작\t2.초기화\t3.종료\n");
						printf("원하는 기능을 선택 하세요 : ");
						scanf_s("%d", &input);
						//1. 재시작 선택시 스톱워치가 이어서 진행
						if (input == 1) {
							start_time = clock() - curr_time;
							continue;
						}
						//2. 초기화 선택시 스톱워치가 초기화 후 진행
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
				* 시간 / 분 / 초를 이용한 타이머 카운팅 시작하게 구현 예정
				* 최대 100시간 ? 
				* 입력을 통해 카운팅 시간 설정 
				* 시작 | 정지 | 초기화 
				*/
				//printf("2번\n");

				//타이머 설정 입력 
				int set_total = 0;;
				printf("시간을 입력해 주세요 : ");
				scanf_s("%d", &input);
				set_total = input * 60 * 60;
				printf("분을 입력해 주세요 : ");
				scanf_s("%d", &input);
				set_total += input * 60;
				printf("초를 입력해 주세요 : ");
				scanf_s("%d", &input);
				set_total += input;
				printf("%d\n", set_total);

				printf("아무키나 누르면 타이머가 실행됩니다.\n");
				printf("설정 시간 %d:%d:%d\n", set_total/60/60, set_total/60%60, set_total%60);
				system("pause");


				// 시간 카운팅 시작 값
				clock_t start_time2 = clock();
				while (1) {
					system("cls");

					// 0초로 맞춤
					clock_t curr_time = clock() - start_time2;

					double time_double = (double)curr_time / 1000;
					int trans;
					int undersec;
					int sec;
					int min;
					int hour;

					int curr_sec = (int)time_double;
					
					int target = set_total - curr_sec;
					printf("\n\n\t%d:%d:%d\n\n", target / 60 / 60, target / 60 % 60, target % 60);

					if (target == 0) {
						printf("설정하신 시간이 모두 소모되었습니다.\n");
						system("pause");

					}
					printf("%d\n", target / 60 / 60);
					printf("%d\n", target / 60 % 60);
					printf("%d\n", target % 60);


				}

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