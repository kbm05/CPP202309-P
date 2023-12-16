#ifndef MAIN_CPP    // ���� ��� ������ �ߺ��ؼ� ���ԵǴ� ���� ����
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
	cout << endl << seat << " �¼����� ���ϰڽ��ϴ�." << endl;
	cout << "���� ī�並 ã�ƿ� �ּż� �����մϴ�. �ȳ��� ������." << endl;
}

int main() {
	Floor1 f1;
	Floor2 f2;
	Floor *currentFloor = &f1;

	string out;
	cout << "ī�信�� ����� �ϰ����ϴ� ��� 1�� �Է��Ͻÿ�. (�ٸ� ����/���ڸ� �Է��� �� ����� ����մϴ�)" << endl;
	cin >> out;
	
	string floor;
	string seat;
	if (out == "1") {
		vector<string> seatList;

		vector<string> selectedSeats;

		SelectedSeats(f1, f2);

		while (1) {
			cout << endl << "����/����Ʈ�� �� ���̽��ϱ�? �ɾҴ� ������ �Է��� �ּ���. (���ڸ� �Է��Ͻÿ�)" << endl;
			cout << "(����ϰ��� �ϴ� ��� 0�� �Է��Ͻÿ�.)" << endl;
			cout << " >> ";
			cin >> floor;

			if (floor == "1") currentFloor = &f1;
			else if (floor == "2") currentFloor = &f2;

			if (floor == "0")  break;

			if (floor != "1" && floor != "2") {
				cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���." << endl;
				continue;
			}
			else currentFloor->PrintFloor();

			while (1) {
				cout << endl << "�ɾҴ� �¼��� �Է��� �ּ���. (�빮�ڷ� �Է��Ͻÿ�)" << endl;
				cout << "(���� �ٲٰ��� �ϴ� ��� 0�� �Է��Ͻÿ�.)" << endl;
				cout << " >> ";
				cin >> seat;

				bool check;
				if (seat == "0")	break;

				check = CheckSeats(floor, seat, seatList);
				
				if (check == true)  break; 
				else {
					cout << endl << seat << " �¼��� ���� ������ �����ϴ�. �ٽ� �Է����ּ���." << endl;
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
			cout << endl << "** 2���� ���θ� ���� ��ҷ� �ٸ� �մԵ鿡�� ���ذ� ���� �ʵ��� ������ ���ּ��� **" << endl;
			cout << endl << "1��, 2�� �� ���ϴ� ���� �����Ͻÿ�. (���ڸ� �Է��Ͻÿ�)" << endl;
			cout << "(Take Out�� ���ϴ� ���, 0�� �Է��Ͻÿ�. �ٽ� �ڷ� ���ư��ϴ�.)" << endl;
			cout << " >> ";
			cin >> floorSelect;

			if (floorSelect == "1") currentFloor = &f1;
			else if (floorSelect == "2") currentFloor = &f2;

			if (floorSelect == "1" || floorSelect == "2" || floorSelect == "0")	break;
			else {
				cout << endl << "�߸��� �Է��Դϴ�. ��Ŀ� �°� �ٽ� �Է����ּ���." << endl;
				continue;
			}
		}
		if (floorSelect == "0") break;
		else 	currentFloor->PrintFloor();

		string seatSelect;
		while (1) {
			cout << endl << floorSelect << "������ ���ϴ� �¼��� �Է����ּ���. (�빮�ڷ� �Է��Ͻÿ�)" << endl;
			cout << "(���� �ٲٰ��� �ϴ� ��� 0�� �Է��Ͻÿ�.)" << endl;
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
					cout << endl << "�̹� ���õ� �¼��Դϴ�. �ٸ� �¼��� �������ּ���." << endl;
				else
					cout << endl << "�ùٸ��� �ʴ� �¼� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
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
		cout << endl << " ~~ " << floorSelect << "���� " << seatSelect << " �¼��� ���õǾ����ϴ�." << endl;
		break;
	}

	return 0;
}

#endif // MAIN_CPP