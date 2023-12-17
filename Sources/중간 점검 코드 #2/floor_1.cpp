#include "floor_1.h"

Floor1::Floor1() {
	int n = 0;
	for (char i = 'A'; i <= 'Z'; i++) {
		floor1[n][0] = i;
		if (i >= 'A' && i <= 'E') {
			floor1[n][1] = "  □ □  ";
			floor1[n][2] = "1";  // 첫 번째 줄
			floor1[n][3] = "2";  // 2*2 인석
		}
		else if (i >= 'F' && i <= 'K') {
			floor1[n][1] = "   □  ";
			floor1[n][2] = "2";  // 두 번째 줄
			floor1[n][3] = "1";  // 1*2 인석
		}
		else if (i >= 'L' && i <= 'O') {
			floor1[n][1] = " □ □ □  ";
			floor1[n][2] = "3";  // 세 번째 줄
			floor1[n][3] = "3";  // 3*2 인석
		}
		else if (i >= 'P' && i <= 'U') {
			floor1[n][1] = "   □  ";
			floor1[n][2] = "4";  // 네 번째 줄
			floor1[n][3] = "1";  // 1*2 인석
		}
		else {
			floor1[n][1] = "  □ □  ";
			floor1[n][2] = "5";  // 다섯 번째 줄
			floor1[n][3] = "2";  // 2*2 인석
		}
		n++;
	}
}

void Floor1::PrintSeats(string line) {
	cout << endl;
	for (int i = 0; i < 26; i++) {
		if (floor1[i][2] == line)
			cout << floor1[i][1];
	}
	cout << endl;
}

void Floor1::PrintSeats(string line, int space) {
	cout << endl << " ";
	for (int i = 0; i < 26; i++) {
		if (floor1[i][2] == line)
			cout << floor1[i][1];
	}
	cout << endl;
}

void Floor1::PrintNaming(string line) {
	if (line == "2" || line == "4")
		cout << " ";

	for (int i = 0; i < 26; i++) {
		if (line == floor1[i][2]) {
			if (line == "1" || line == "5") cout << " [  ";
			else if (line == "2" || line == "4") cout << " [ ";
			else  cout << " [   ";

			cout << floor1[i][0];

			if (line == "1" || line == "5") cout << "  ] ";
			else if (line == "2" || line == "4") cout << " ] ";
			else  cout << "   ] ";
		}
	}
}

void Floor1::PrintFloor() {
	cout << endl << "  <1층>  " << endl;
	cout << "---------------------------------------------" << endl;
	for (char i = '1'; i <= '5'; i++) {
		string n = "";	n += i;
		if (n == "2" || n == "3" || n == "4")
			PrintSeats(n, 1);
		else
			PrintSeats(n);
		PrintNaming(n);
		PrintSeats(n);
	}
}

bool Floor1::CheckSeats(string seatSelect) {
	for (int i = 0; i < 26; i++) {
		if (floor1[i][0] == seatSelect)
			return true;
	}
	return false;
}

bool Floor1::CheckSelected(string seatSelect) {
	ifstream is_1{ "seats_floor_1.txt" };
	string s_1;
	while (is_1 >> s_1) {
		if (s_1 == seatSelect) return true;
	}
	is_1.close();
	return false;
}

void Floor1::SelectSeats(string seatSelect) {
	for (int i = 0; i < 26; i++) {
		if (floor1[i][0] == seatSelect) {
			floor1[i][0] = "-";

			if (floor1[i][3] == "1")	floor1[i][1] = "   ■  ";
			else if (floor1[i][3] == "2")	floor1[i][1] = "  ■ ■  ";
			else	floor1[i][1] = " ■ ■ ■  ";
			return;
		}
	}
}

void Floor1::ExitSeats(string seatSelect) {
	for (int i = 0; i < 26; i++) {
		if (floor1[i][0] == seatSelect) {
			if (floor1[i][3] == "1")	floor1[i][1] = "   ■  ";
			else if (floor1[i][3] == "2")	floor1[i][1] = "  ■ ■  ";
			else	floor1[i][1] = " ■ ■ ■  ";
			return;
		}
	}
}

void Floor1::ResetSeats(string seatSelect) {
	for (int i = 0; i < 26; i++) {
		if (floor1[i][0] == seatSelect) {
			if (floor1[i][3] == "1")	floor1[i][1] = "   □  ";
			else if (floor1[i][3] == "2")	floor1[i][1] = "  □ □  ";
			else	floor1[i][1] = " □ □ □  ";
			return;
		}
	}
}