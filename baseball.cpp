#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 3
using namespace std;

int main() {
	srand((unsigned int)time(NULL));
	int board[SIZE];
	bool board_visit[10];
	fill(&board_visit[0], &board_visit[10], false);

	for (int i = 0; i < SIZE; i++) {
		int r = rand() % 10;
		while (board_visit[r]) {
			r = rand() % 10;
		}
		board[i] = r;
		board_visit[r] = true;
	}

	cout << "숫자 야구를 시작합니다" << endl << endl;
	int input[SIZE];
	bool visited[SIZE];
	int count = 1;
	while (count<10) {
		cout << "-------------" << count << "회-------------" << endl;
		int strike = 0;
		int ball = 0;
		fill(&visited[0], &visited[SIZE], false);
		cout << SIZE << "개의 숫자를 입력해주세요 : ";
		
		for (int i = 0; i < SIZE; i++) {
			cin >> input[i];
			if (input[i] == board[i]) {
				strike++;
				visited[i] = true;
			}
		}

		if (strike == SIZE) {
			cout << "정답입니다" << endl << endl;
			break;
		}

		for (int i = 0; i < SIZE; i++) {
			if (!visited[i]) {
				if (board_visit[input[i]]) {
					ball++;
				}
			}
		}

		cout << strike << "스트라이크 " << ball << "볼 입니다." << endl << endl;
		count++;
	}
	cout << "게임이 종료되었습니다." << endl;
	cout << "정답은 ";
	for (int i = 0; i < SIZE; i++) {
		cout << board[i] << " ";
	}
	cout << " 입니다." << endl;
}