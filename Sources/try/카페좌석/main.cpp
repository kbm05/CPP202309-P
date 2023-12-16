#ifndef MAIN_CPP    // 여러 헤더 파일이 중복해서 포함되는 것을 방지
#define MAIN_CPP

#include "floor_1.h"
#include "floor_2.h"

void SelectedSeats(Floor1& f1, Floor2& f2) {
	ifstream is_1{ "seats_floor_1.txt" };
	string s_1;
	while (is_1 >> s_1) {
		f1.ExitSeats(s_1);
	}
	is_1.close();

	ifstream is_2{ "seats_floor_2.txt" };
	string s_2;
	while (is_2 >> s_2) {
		f2.ExitSeats(s_2);
	}
	is_2.close();
}

void UpdateSeat(Floor1& f1, Floor2& f2) {
	ifstream is_1{ "seats_floor_1.txt" };
	string s_1;
	while (is_1 >> s_1) {
		f1.SelectSeats(s_1);
	}
	is_1.close();

	ifstream is_2{ "seats_floor_2.txt" };
	string s_2;
	while (is_2 >> s_2) {
		f2.SelectSeats(s_2);
	}
	is_2.close();
}

bool CheckSeats(string floor, string seat, vector<string>& s) {
	bool check = false;
	if (floor == "1") {
		ifstream is_1{ "seats_floor_1.txt" };
		string s_1;
		while (is_1 >> s_1) {
			s.push_back(s_1);
		}
		is_1.close();
	}
	else {
		ifstream is_2{ "seats_floor_2.txt" };
		string s_2;
		while (is_2 >> s_2) {
			s.push_back(s_2);
		}
		is_2.close();
	}
	for (string s : s) {
		if (s == seat) {
			check = true;
			break;
		}
	}

	return check;
}

void PrintExit(string seat) {
	cout << endl << seat << " 좌석에서 퇴석하겠습니다." << endl;
	cout << "저희 카페를 찾아와 주셔서 감사합니다. 안녕히 가세요." << endl;
}

int main() {
	Floor1 f1;
	Floor2 f2;
	Floor *currentFloor = &f1;

	string out;
	cout << "카페에서 퇴실을 하고자하는 경우 1을 입력하시오. (다른 숫자/문자를 입력할 시 퇴실을 취소합니다)" << endl;
	cin >> out;
	
	string floor;
	string seat;
	if (out == "1") {
		vector<string> seatList;

		vector<string> selectedSeats;

		SelectedSeats(f1, f2);

		while (1) {
			cout << endl << "음료/디저트를 잘 즐기셨습니까? 앉았던 층수를 입력해 주세요. (숫자만 입력하시오)" << endl;
			cout << "(취소하고자 하는 경우 0을 입력하시오.)" << endl;
			cout << " >> ";
			cin >> floor;

			if (floor == "1") currentFloor = &f1;
			else if (floor == "2") currentFloor = &f2;

			if (floor == "0")  break;

			if (floor != "1" && floor != "2") {
				cout << "잘못된 입력입니다. 다시 입력해 주세요." << endl;
				continue;
			}
			else currentFloor->PrintFloor();

			while (1) {
				cout << endl << "앉았던 좌석을 입력해 주세요. (대문자로 입력하시오)" << endl;
				cout << "(층을 바꾸고자 하는 경우 0을 입력하시오.)" << endl;
				cout << " >> ";
				cin >> seat;

				bool check;
				if (seat == "0")	break;

				check = CheckSeats(floor, seat, seatList);
				
				if (check == true)  break; 
				else {
					cout << endl << seat << " 좌석에 대한 정보가 없습니다. 다시 입력해주세요." << endl;
					continue;
				}
			}

			if (seat == "0")	continue;

			for (string s : seatList) {
				if (s == seat);
				else
					selectedSeats.push_back(s);
			}
			currentFloor->ResetSeats(seat);

			if (floor == "1") {
				ofstream os_1B{ "seats_floor_1.txt", ios::trunc };
				for (string s : selectedSeats) {
					os_1B << s << endl;
				}
				os_1B.close();
			}
			else {
				ofstream os_2B{ "seats_floor_2.txt", ios::trunc };
				for (string s : selectedSeats) {
					os_2B << s << endl;
				}
				os_2B.close();
			}
			UpdateSeat(f1, f2);

			PrintExit(seat);
			break;
		}
	}
	UpdateSeat(f1, f2);
	

	f1.PrintFloor();
	cout << endl;
	f2.PrintFloor();

	while (1) {
		string floorSelect;
		while (1) {
			cout << endl << "** 2층은 공부를 위한 장소로 다른 손님들에게 피해가 가지 않도록 조용히 해주세요 **" << endl;
			cout << endl << "1층, 2층 중 원하는 층을 선택하시오. (숫자를 입력하시오)" << endl;
			cout << "(Take Out을 원하는 경우, 0을 입력하시오. 다시 뒤로 돌아갑니다.)" << endl;
			cout << " >> ";
			cin >> floorSelect;

			if (floorSelect == "1") currentFloor = &f1;
			else if (floorSelect == "2") currentFloor = &f2;

			if (floorSelect == "1" || floorSelect == "2" || floorSelect == "0")	break;
			else {
				cout << endl << "잘못된 입력입니다. 양식에 맞게 다시 입력해주세요." << endl;
				continue;
			}
		}
		if (floorSelect == "0") break;
		else 	currentFloor->PrintFloor();

		string seatSelect;
		while (1) {
			cout << endl << floorSelect << "층에서 원하는 좌석을 입력해주세요. (대문자로 입력하시오)" << endl;
			cout << "(층을 바꾸고자 하는 경우 0을 입력하시오.)" << endl;
			cout << " >> ";
			cin >> seatSelect;

			bool check;
			bool checkSelected;
			if (seatSelect == "0")	break;

			check = currentFloor->CheckSeats(seatSelect);

			if (check == true) break;
			else {
				checkSelected = currentFloor->CheckSelected(seatSelect);
				if (checkSelected == true)
					cout << endl << "이미 선택된 좌석입니다. 다른 좌석을 선택해주세요." << endl;
				else
					cout << endl << "올바르지 않는 좌석 입력입니다. 다시 입력해주세요." << endl;
				continue;
			}
		}
		if (seatSelect == "0")	continue;

		currentFloor->SelectSeats(seatSelect);

		if (floorSelect == "1") {
			ofstream os_1C{ "seats_floor_1.txt", ios::out | ios::app };
			if (os_1C.is_open()) {
				os_1C << seatSelect << endl;
				os_1C.close();
			}
		}
		else {
			ofstream os_2C{ "seats_floor_2.txt", ios::out | ios::app };
			if (os_2C.is_open()) {
				os_2C << seatSelect << endl;
				os_2C.close();
			}
		}

		currentFloor->PrintFloor();
		cout << endl << " ~~ " << floorSelect << "층의 " << seatSelect << " 좌석이 선택되었습니다." << endl;
		break;
	}

	return 0;
}

#endif // MAIN_CPP