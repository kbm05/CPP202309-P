#include "floor_2.h"

Floor2::Floor2() {
	int index = 0;
	char eng = 'A';
	for (int i = 0; i < 7; i++) {
		char num = '1';
		for (int j = 0; j < 7; j++) {
			floor2_seats[i][j] += eng;
			floor2_seats[i][j] += num;

			floor2[index][2] = num;
			floor2[index][3] = eng;
			floor2[index][0] = floor2_seats[i][j];
			floor2[index][1] = "   бр   ";

			num++;
			index++;
		}
		eng++;
	}
}
	
void Floor2::PrintSeats(string num) {
	cout << endl;
	for (int i = 0; i < 49; i++) {
		if (floor2[i][2] == num) {
			if (floor2[i][3] == "D")
				cout << "|      |";
			cout << floor2[i][1];
		}
	}
	cout << endl;
}

void Floor2::PrintNaming(string num) {
	for (int i = 0; i < 49; i++) {
		if (floor2[i][2] == num) {
			if (floor2[i][3] == "D")
				cout << "|      |";
			cout << " [ " << floor2[i][0] << " ] ";
		}
	}
}

void Floor2::PrintFloor() {
	cout << endl << "  <2├■>  -Study Only-  " << endl;
	cout << "---------------------------------------------------------------" << endl;
	for (char i = '1'; i <= '7'; i++) {
		string n = "";	n += i;
		cout << endl;
		PrintNaming(n);
		PrintSeats(n);
	}
}

bool Floor2::CheckSeats(string seatSelect) {
	for (int i = 0; i < 49; i++) {
		if (floor2[i][0] == seatSelect)
			return true;
	}
	return false;
}

bool Floor2::CheckSelected(string seatSelect) {
	ifstream is_2{ "seats_floor_2.txt" };
	string s_2;
	while (is_2 >> s_2) {
		if (s_2 == seatSelect) return true;
	}
	is_2.close();
	return false;
}

void Floor2::SelectSeats(string seatSelect) {
	for (int i = 0; i < 49; i++) {
		if (floor2[i][0] == seatSelect) {
			floor2[i][0] = "--";
			floor2[i][1] = "   бс   ";
		}
	}
}

void Floor2::ExitSeats(string seatSelect) {
	for (int i = 0; i < 49; i++) {
		if (floor2[i][0] == seatSelect) {
			floor2[i][1] = "   бс   ";
		}
	}
}

void Floor2::ResetSeats(string seatSelect) {
	for (int i = 0; i < 49; i++) {
		if (floor2[i][0] == seatSelect) {
			floor2[i][1] = "   бр   ";
		}
	}
}