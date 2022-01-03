#include<stdio.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>

// 시간 포맷 구조체
typedef struct Time_format
{
	int total;
	int hour;
	int min;
	int sec;
	int undersec;
}Time_format;



// 기능 - 예외처리 메뉴 입력
int Intinput(int min, int max) {
	int input;
	while (1) {
		scanf_s("%d", &input);
		if (input >= min && input <= max) {
			return input;
		}
		else {
			while (getchar() != '\n') {}
			printf("잘못된 입력입니다. 다시 입력해주세요. : ");
		}
	}
}
// 기능 - 시간 처리
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
	printf("시간을 입력해 주세요 : ");
	set_total = Intinput(0, INT_MAX) * 60 * 60;
	system("cls");
	printf("분을 입력해 주세요 : ");
	set_total += Intinput(0, INT_MAX) * 60;
	system("cls");
	printf("초를 입력해 주세요 : ");
	set_total += Intinput(0, INT_MAX);
	system("cls");
	data = GetTime((clock_t)(set_total * 1000));
	data.total = set_total;
	return data;
}
// 구조 - 스톱워치 부분
void StopWatch() {
	printf("===== 스톱워치 =====\n");
	printf("아무키나 누르면 시작 합니다.");
	system("pause");

	Time_format data;
	clock_t start_time = clock();
	while (1) {
		// 시간 계산 및 시간 포맷 만들기 
		clock_t curr_time = clock() - start_time;
		data = GetTime(curr_time);
		//시간 포맷으로 출력
		printf("\n\n\t%d:%d:%d.%d\n\n", data.hour, data.min, data.sec, data.undersec);

		//키 입력을 받았을때 멈추기(일시정지)
		if (_kbhit()) {

			//일시정지 후 질의 선택
			printf("1.재시작\t2.초기화\t3.종료\n");
			printf("원하는 기능을 선택 하세요 : ");
			int input = Intinput(1, 3);

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
}
// 구조 - 타이머 부분
void Timer() {

	Time_format data;
	//타이머 설정 입력 
	int input;
	while (1) {

		data = SetTime();

		//시간 설정 확인
		printf("설정 시간 %d:%d:%d\n", data.hour, data.min, data.sec);
		printf("1. 시작\t2. 재설정\n");
		printf("설정 시간을 확인 해 주세요. : ");
		input = Intinput(1,2);
		if (input == 1) {
			printf("아무키나 누르면 타이머가 실행됩니다.\n");
			system("pause");

			break;
		}
		else {
			printf("아무키나 누르면 타이머가 초기설정화면으로 돌아갑니다.\n");
			system("pause");
		}
	}
	// 시간 카운팅 시작 값
	clock_t start_time = clock();
	while (1) {
		system("cls");
		// 0초로 맞춤과 설정 시간 - 소모시간 출력
		clock_t curr_time = clock() - start_time;
		double time_double = (double)curr_time / 1000;
		int curr_sec = (int)time_double;
		int target = data.total - curr_sec;
		printf("\n\n\t%d:%d:%d\n\n", target / 60 / 60, target / 60 % 60, target % 60);

		//키입력시 일시정지
		if (_kbhit()) {
			system("pause");
			printf("1. 이어하기\t2. 재설정\t 3. 종료\n");
			printf("설정 시간을 확인 해 주세요. : ");
			input = Intinput(1, 3);

			//이어하기시
			if (input == 1) {
				printf("아무키나 누르면 타이머가 실행됩니다.\n");
				system("pause");
				clock_t stop_time = clock() - (curr_time + start_time);
				start_time += stop_time;
			}

			//다시 설정시
			else if (input == 2) {
				while (1) {
					data = SetTime();
					//시간 설정 확인
					printf("설정 시간 %d:%d:%d\n", data.hour, data.min, data.sec);
					printf("1. 시작\t2. 재설정\n");
					printf("설정 시간을 확인 해 주세요. : ");
					scanf_s("%d", &input);
					if (input == 1) {
						printf("아무키나 누르면 타이머가 실행됩니다.\n");
						system("pause");
						start_time = clock();
						break;
					}
					else {
						printf("아무키나 누르면 타이머가 초기설정화면으로 돌아갑니다.\n");
						system("pause");
					}
				}
			}
			else {
				break;
			}

		}

		//시간 소모시 탈출
		if (target == 0) {
			printf("설정하신 시간이 모두 소모되었습니다.\n");
			system("pause");
			break;

		}
	}
}
int main() {

	//프로그램 시작
	while (1) {
		//메인 화면 부분
		system("cls");
		printf("\t=== Test Program ==\n\n");
		int input;
		printf("1.스톱워치\t2.타이머\t3.종료\n\n");
		printf("원하는 메뉴를 입력 하세요 : ");
		input = Intinput(1, 3);
		//메뉴 입력 후 동작하기
		//정상적인 입력이면
		if (input > 0 && input < 4) {
			//종료 입력시
			if (input == 3) {
				printf("프로그램을 종료 합니다.");
				break;
			}
			//스톱워치 또는 타이머 부분
			switch (input)
			{
			//스톱워치
			case 1:
				StopWatch();
				break;
			//타이머
			case 2:
				Timer();
				break;
			}
		}
		//예외 발생 시 
		else {
			while (getchar() != '\n') {}
			printf("잘못된 입력입니다.");
			system("pause");
		}
	}
	return 0;
}