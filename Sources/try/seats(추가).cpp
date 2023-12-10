#include <iostream>
#include <fstream>
using namespace std;

void PrintSeats_1(string floor1[26][4], string line, int space = 0) {
	cout << endl;
	if (space == 1) {
		cout << " ";
	}

	for (int i = 0; i < 26; i++) {
		if (floor1[i][2] == line) 
			cout << floor1[i][1];
	}
	cout << endl;
}

void PrintSeats_2(string floor2[49][3], string num) {
	cout << endl;
	string d = "D";
	d += num;
	for (int i = 0; i < 49; i++) {
		if (floor2[i][2] == num) {
			if (floor2[i][0] == d)
				cout << "|      |";
			cout << floor2[i][1];
		}
	}
	cout << endl;
}

void PrintNaming_1(string floor1[26][4], string line) {
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

void PrintNaming_2(string floor2[49][3], string num) {
	string d = "D";
	d += num;
	for (int i = 0; i < 49; i++) {
		if (floor2[i][2] == num) {
			if (floor2[i][0] == d)
				cout << "|      |";
			cout << " [ " << floor2[i][0] << " ] ";
		}
	}
}

void PrintFloor_1(string floor1[26][4]) {
	cout << endl << "  <1��>  " << endl;
	cout << "--------------------------------------------" << endl;
	for (char i = '1'; i <= '5'; i++) {
		string n = "";	n += i;
		if (n == "2" || n == "3" || n == "4") 
			PrintSeats_1(floor1, n, 1);
		else
			PrintSeats_1(floor1, n);
		PrintNaming_1(floor1, n);
		PrintSeats_1(floor1, n);
	}
}

void PrintFloor_2(string floor2[49][3]) {
	cout << endl << "  <2��>  -Study Only-  " << endl;
	cout << "------------------------------------------------------------" << endl;
	for (char i = '1'; i <= '7'; i++) {
		string n = "";	n += i;
		cout << endl;
		PrintNaming_2(floor2, n);
		PrintSeats_2(floor2, n);
	}
}

bool CheckSeats_1(string floor1[26][4], string seatSelect) {
	for (int i = 0; i < 26; i++) {
		if (floor1[i][0] == seatSelect)
			return true;
	}
	return false;
}

bool CheckSeats_2(string floor2[49][3], string seatSelect) {
	for (int i = 0; i < 49; i++) {
		if (floor2[i][0] == seatSelect)
			return true;
	}
	return false;
}

void SelectSeats_1(string floor1[26][4], string seatSelect) {
	for (int i = 0; i < 26; i++) {
		if (floor1[i][0] == seatSelect) {
			floor1[i][0] = "-";
			
			if(floor1[i][3] == "1")	floor1[i][1] = "   ��  ";
			else if(floor1[i][3] == "2")	floor1[i][1] = "  �� ��  ";
			else	floor1[i][1] = " �� �� ��  ";
			return;
		}
	}
}

void SelectSeats_2(string floor2[49][3], string seatSelect) {
	for (int i = 0; i < 49; i++) {
		if (floor2[i][0] == seatSelect) {
			floor2[i][0] = "--";
			floor2[i][1] = "   ��   ";
		}
	}
}

int main() {
	string floor1[26][4];
	int n = 0;
	for (char i = 'A'; i <= 'Z'; i++) {
		floor1[n][0] = i;
		if (i >= 'A' && i <= 'E') {
			floor1[n][1] = "  �� ��  ";
			floor1[n][2] = "1";  // ù ��° ��
			floor1[n][3] = "2";  // 2*2 �μ�
		}
		else if (i >= 'F' && i <= 'K') {
			floor1[n][1] = "   ��  ";
			floor1[n][2] = "2";  // �� ��° ��
			floor1[n][3] = "1";  // 1*2 �μ�
		}
		else if (i >= 'L' && i <= 'O') {
			floor1[n][1] = " �� �� ��  ";
			floor1[n][2] = "3";  // �� ��° ��
			floor1[n][3] = "3";  // 3*2 �μ�
		}
		else if (i>='P'&&i<='U') {
			floor1[n][1] = "   ��  ";
			floor1[n][2] = "4";  // �� ��° ��
			floor1[n][3] = "1";  // 1*2 �μ�
		}
		else {
			floor1[n][1] = "  �� ��  ";
			floor1[n][2] = "5";  // �ټ� ��° ��
			floor1[n][3] = "2";  // 2*2 �μ�
		}
			n++;
	}

	string floor2[7][7];
	string floor2_seats[49][3];
	int index = 0;
	char eng = 'A';
	for (int i = 0; i < 7; i++) {
		char num = '1';
		for (int j = 0; j < 7; j++) {
			floor2[i][j] += eng;
			floor2[i][j] += num;
			floor2_seats[index][2] = num;

			floor2_seats[index][0] = floor2[i][j];
			floor2_seats[index][1] = "   ��   ";
			floor2_seats[index][2] = num;

			num++;
			index++;
		}
		eng++;
	}

	PrintFloor_1(floor1);
	cout << endl;
	PrintFloor_2(floor2_seats);

	while (1) {
		string floorSelect;
		while (1) {
			cout << endl << "** 2���� ���θ� ���� ��ҷ� �ٸ� �մԵ鿡�� ���ذ� ���� �ʵ��� ������ ���ּ��� **" << endl;
			cout << endl << "1��, 2�� �� ���ϴ� ���� �����Ͻÿ�. (���ڸ� �Է��Ͻÿ�)" << endl;
			cout << "(Take Out�� ���ϴ� ���, 0�� �Է��Ͻÿ�. �ٽ� �ڷ� ���ư��ϴ�.)" << endl;
			cout << " >> ";
			cin >> floorSelect;

			if (floorSelect == "1" || floorSelect == "2" || floorSelect == "0")	break;
			else {
				cout << endl << "�߸��� �Է��Դϴ�. ��Ŀ� �°� �ٽ� �Է����ּ���." << endl;
				continue;
			}
		}
		if (floorSelect == "1")		PrintFloor_1(floor1);
		else if (floorSelect == "2")	PrintFloor_2(floor2_seats);
		else break;

		string seatSelect;
		while (1) {
			cout << endl << floorSelect << "������ ���ϴ� �¼��� �Է����ּ���. (�빮�ڷ� �Է��Ͻÿ�)" << endl;
			cout << "(���� �ٲٰ��� �ϴ� ��� 0�� �Է��Ͻÿ�.)" << endl;
			cout << " >> ";
			cin >> seatSelect;

			bool check;
			if (seatSelect == "0")	break;

			if (floorSelect == "1") {
				check = CheckSeats_1(floor1, seatSelect);
			}
			else	check = CheckSeats_2(floor2_seats, seatSelect);

			if (check == true) break;
			else {
				cout << endl << "�̹� ���õ� �¼��̰ų� �ùٸ��� �ʴ� �¼� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
				continue;
			}
		}
		if (seatSelect == "0")	continue;

		if (floorSelect == "1") {
			SelectSeats_1(floor1, seatSelect);
			PrintFloor_1(floor1);
			cout << endl << " ~~ " << floorSelect << "���� " << seatSelect << " �¼��� ���õǾ����ϴ�." << endl;
		}
		else {
			SelectSeats_2(floor2_seats, seatSelect);
			PrintFloor_2(floor2_seats);
			cout << endl << " ~~ " << floorSelect << "���� " << seatSelect << " �¼��� ���õǾ����ϴ�." << endl;
		}
	}

	return 0;
}