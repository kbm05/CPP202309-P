#ifndef MAIN_CPP    // ���� ��� ������ �ߺ��ؼ� ���ԵǴ� ���� ����
#define MAIN_CPP

#include "menu.h"
#include "finalOrder.h"
#include "floor_1.h"
#include "floor_2.h"
#include <exception>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

Coffee coffee;
NonCoffee non_coffee;
Tea tea;
Smoothie smoothie;
Frappe frappe;
Ade ade;
Dessert dessert;

// ��� 1
// �߸� �Է� �� ���
void PrintError();
// try-catch���� �̿��� �Է� ���� üũ
void CheckInput(vector<string> v, string input);
// ó������ ���ư� �� ���
void PrintReset();
// ���Ⱑ ���� ���ڿ��� ��ȯ 
string NonSpace(string str);
// ó���� ������ ����
void SelectChoice(string& choice);
// ��ü �޴� ���
void TotalMenuPrint();
// �ֹ� ����
void SelectOrder(string& order);
// ���� ī�װ� ����
void SelectCategory(string& category);
// �޴� ����
void SelectMenu(vector<Cafe> c, string& menu, Cafe& selectMenu);
// ���� �޴� ���� �� ����
void SelectSubMenu(Cafe& c, string& subMenu);
// ������ Ice/Hot ����
void SelectIceHot(int currentMenu, string& ice_hot);
// ���ڿ��� ��� ���ڸ� �빮�ڷ� �ٲٴ� �Լ�
string toUpperStr(string str);
// ������ ���� ����
void SelectToppings(vector<string>& toppings, FinalOrder& f);
// ���Ⱑ ���Ե� ���ڿ����� ���Ⱑ ���� ���ڵ��� �������� ���� 
vector<string> SplitStringBySpace(string str);
// �ֹ� ����� ���� �������� ����
void SelectOrderList(string& orderList);
// �ֹ� ��� ���
void PrintOrderList(vector<FinalOrder>& basket);
// �ֹ� ��� ����
void DeleteOrderList(vector<FinalOrder>& basket);
// �ֹ� ��� ���� ��, ����� �߸� �Է��Ͽ��� �� ���
void PrintDeleteError();
// ���� �ݾ�
double FinalPrice(vector<FinalOrder> basket);
// ���� ����
void SelectYes_No(string& yes_no);
// ���� �� ���� ����
void SelectTake_out_In(string& take);
// ���� ����
void SelectPayMethod(string& pay_method, vector<FinalOrder>& basket);

// ��� 2
// ���õ� �¼� �̸��� ���̰� �ҷ�����
void SelectedSeatUpdate(Floor1& f1, Floor2& f2);
// ���õ� �¼� �ҷ����� 
void UpdateSeat(Floor1& f1, Floor2& f2);
// �Է��� �¼��� �����ϴ��� Ȯ��
bool CheckSeats(string floor, string seat, set<string>& s);
// �𼮽� ���
void PrintExit(string floor, string seat);
// ���� �� �����, ���� �� ����
void SelectFloor(string& floor);
// ���� �� �����, ���� �¼� ����
void SelectSeat(string floor, string& seat, Floor* currentFloor);
// ���� �� �����, ���� �¼� txt���Ͽ� �߰�
void AddSeat(string floor, string seat);
// ���忡�� ����� ��, ���� �� ����
void SelectExitFloor(string& floor);
// ���忡�� ����� ��, ���� �¼� ����
void SelectExitSeats(string floor, string& seat, set<string>& seatList);
// ���忡�� ����� ��, ���� �¼� txt���Ͽ��� ����
void UpdateExitSeat(string floor, set<string>& selectedSeats, Floor1& f1, Floor2& f2);



int main() {
	vector<Menu*> m = { &coffee, &non_coffee, &tea, &smoothie, &frappe, &ade, &dessert };
	int currentMenu;

	vector<FinalOrder> basket;   // �ֹ� ���� �޴����� ���� (�ֹ� ���)

	while (1) {
		Floor1 f1;
		Floor2 f2;

		UpdateSeat(f1, f2);  // txt������ �о�� ������� �¼� ������Ʈ 

		bool back = false;  // back�� true�� �Ǹ� ó������ ���ƿ�

		string choice;
		SelectChoice(choice);

		// 1. �޴��� ���� ���
		if (choice == "1") {
			TotalMenuPrint();
		}
		// 2. �ֹ�
		else if (choice == "2") {
			string order;
			SelectOrder(order);

			// ���� & ����Ʈ �ֹ�
			if (order == "3") { PrintReset(); continue; }
			else {
				string category;
				if (order == "1") {  // ����
					SelectCategory(category);

					if (category == "7") {  // ó������ ���ư���
						PrintReset();
						continue;
					}
					else {
						if (category == "1") currentMenu = 0;
						else if (category == "2") currentMenu = 1;
						else if (category == "3") currentMenu = 2;
						else if (category == "4") currentMenu = 3;
						else if (category == "5") currentMenu = 4;
						else if (category == "6") currentMenu = 5;
					}
				}
				else {  // order == "2", ����Ʈ
					currentMenu = 6;
				}

				m[currentMenu]->Print();

				// �޴� ����
				string menu;
				Cafe selectMenu = m[currentMenu]->menu[0];
				SelectMenu(m[currentMenu]->menu, menu, selectMenu);


				if (menu == "0") {   // ó������ ���ư���
					PrintReset(); continue;
				}

				string subMenu;  // ���� �޴�
				if (!selectMenu.GetSubMenu().empty()) {
					cout << endl;
					selectMenu.PrintSub();

					SelectSubMenu(selectMenu, subMenu);  // ���� �޴� ����

					if (subMenu == "0") {
						PrintReset();
						continue;  // ó�� ȭ������ ���ư�
					}
				}

				FinalOrder f = FinalOrder();
				if (order == "1") {
					string ice_hot;
					SelectIceHot(currentMenu, ice_hot);  // ICE / HOT ����

					if (ice_hot == "0") {
						PrintReset();
						continue;  // ó�� ȭ������ ���ư�
					}

					vector<string> toppings;
					if (!selectMenu.GetSubMenu().empty()) {
						f = FinalOrder(category, menu, subMenu, ice_hot, selectMenu.GetPrice());
					}
					else {
						f = FinalOrder(category, menu, ice_hot, selectMenu.GetPrice());
					}
					SelectToppings(toppings, f);
				}
				else {  // order == 2
					if (!selectMenu.GetSubMenu().empty()) {
						f = FinalOrder(menu, subMenu, selectMenu.GetPrice());
					}
					else {
						f = FinalOrder(menu, selectMenu.GetPrice());
					}
				}
				basket.push_back(f);
				cout << endl << " ** ";
				f.PrintFinal();
				cout << "��(��) ���� ���� ��Ͽ� ��ҽ��ϴ�." << endl;
				cin.clear();
			}
		}
		// �ֹ� ���
		else if (choice == "3") {
			string orderList;
			SelectOrderList(orderList);

			if (orderList == "1") {  // �ֹ� ��� ����
				PrintOrderList(basket);
				if (basket.empty()) {
					cout << endl << "���� ������ �� �ִ� ����� �����ϴ�." << endl;
					continue;
				}
				else DeleteOrderList(basket);
			}
			else if (orderList == "2") {  // ���� �ֹ� ��� ���
				PrintOrderList(basket);
			}
			else { PrintReset(); continue; }  //orderList == "3"�� �� ó������ ���ư���
		}

		// ����
		else if (choice == "4") {
			if (basket.empty()) {  // �ֹ� ����� ������� ��, ���� ��� & ó������ ���ư�
				cout << endl;
				cout << "�ֹ� ����� ����ֽ��ϴ�." << endl;
				continue;
			}
			else {  // �ֹ� ����� ������� ���� ��

				PrintOrderList(basket);  // ���� �ֹ� ����� ���

				cout << endl;
				cout << "���� ���� �ݾ��� �� " << FinalPrice(basket) << "�� �Դϴ�." << endl;

				string pay_ok;  // ���� ����
				SelectYes_No(pay_ok);   // ���� ���� ����
				if (pay_ok == "�ƴϿ�") { PrintReset(); continue; }  // ���� ��� �� ó������ ���ư�
				else {  // ���� ����
					while (1) {
						bool take_select = false;  // take_select == true�� �Ǹ� take out ���� �ٽ� ����
						string take;  // take out �� ���� or take in �� ����
						string pay_method;  // ���� ����
						SelectTake_out_In(take);  // take out ���� ����

						double sumPrice = FinalPrice(basket);
						if (take == "2") {  // take out �� ��
							sumPrice *= 0.95;  // ���� �ݾ��� 5% ����
							cout << endl << "Take Out �������� ���� ���� ���� �ݾ��� " << sumPrice << "�� �Դϴ�. " << endl;
							SelectPayMethod(pay_method, basket);  // ���� ���� ����

							if (pay_method == "6") back = true;  // ���� ��ҽ� ó������ ���ư�
							break;
						}
						else {  // take in �� �� 
							string floor;  // ������ ���� ������ ����
							string seat;   // ������ �¼��� ������ ����
							Floor* currentFloor = &f1;
							while (1) {
								SelectFloor(floor);  // �� ����
								if (floor == "0") {   // take out ���θ� �ٽ� ����
									take_select = true;
									break;
								}
								else if (floor == "1") currentFloor = &f1;
								else currentFloor = &f2;

								currentFloor->PrintFloor();   // ������ ���� �¼� ���

								SelectSeat(floor, seat, currentFloor);  // ���� �¼� ����
								if (seat == "0") continue;  // �� �������� ���ư�
								else {
									currentFloor->SelectSeats(seat);   // ������ �¼� ���� "��"->"��"
									AddSeat(floor, seat);  // ������ �¼� txt ���Ͽ� �߰�

									currentFloor->PrintFloor();  // ���õ� �¼��� ����� (�ش� ����) ��ü �¼� ���
									cout << endl << " ~~ " << floor << "���� " << seat << " �¼��� ���õǾ����ϴ�." << endl;

									SelectPayMethod(pay_method, basket);  // ���� ���� ����

									if (pay_method == "6") {  // ���� ���

										set<string> list;  // txt ���Ͽ� ���� �¼� ����Ʈ(����)
										set<string> updateList;  // ������ ������ �¼��� ������ �¼� ����Ʈ(����)
										CheckSeats(floor, seat, list);  // txt ���Ͽ��� �¼��� �о�ͼ� list�� ����

										for (string s : list) {  // ������ ������ �¼��� ������ list�� updateList�� ����
											if (s == seat);
											else updateList.insert(s);
										}

										currentFloor->ResetSeats(seat);  // ������ ������ �¼� �ٽ� ���� "��"->"��"

										UpdateExitSeat(floor, updateList, f1, f2);   // ���õ� �¼��� ���ŵ� ����Ʈ�� �ٽ� txt ���Ͽ� ����(�����)
										back = true;  // ó������ ���ư�
										break;
									}
									else break;
								}
							}
							if (take_select == true) continue;   // take out ���� �������� ���ư�
							else break;
						}
					}
					if (back == true) {  // ó������ ���ư�
						continue;
					}
					break;
				}

			}
		}
		// ���� ī�� �� �¼�(����) ���
		else if (choice == "5") {
			f1.PrintFloor();
			cout << endl;
			f2.PrintFloor();
		}
		// ���
		else if (choice == "6") {
			Floor1 f3; Floor2 f4;
			set<string> seatList;   // ������� �¼��� ����Ʈ(����)
			set<string> selectedSeats;   // ������� �¼��鿡�� ���� �¼��� ������ ����Ʈ(����)

			Floor* current_exitFloor = &f3;

			SelectedSeatUpdate(f3, f4);  // ���õ� �¼��� �̸��� ���̵��� ������Ʈ
			while (1) {
				string exit_floor;  // ���� �¼��� ��
				SelectExitFloor(exit_floor);  // ���� �¼��� �� ����

				if (exit_floor == "0") {  // ��� ���, ó������ ���ư�
					cout << endl << "����� ����ϰ�, ó�� ȭ������ ���ư��ϴ�.";
					back = true;
					break;
				}
				else if (exit_floor == "1") current_exitFloor = &f3;
				else current_exitFloor = &f4;

				current_exitFloor->PrintFloor();

				string exit_seat;  // ���� �¼�
				SelectExitSeats(exit_floor, exit_seat, seatList);  // ���� �¼� ����, ���� ������� �¼��� ����Ʈ seatList�� ����

				if (exit_seat == "0") continue;  // ���� �¼��� �� �������� ���ư�
				else {
					for (string s : seatList) {  // ���� �¼��� ������ ������� �¼��� ����Ʈ selectedSeats�� ����
						if (s == exit_seat);
						else selectedSeats.insert(s);
					}
				}
				current_exitFloor->ResetSeats(exit_seat);  // ���� �¼��� �� �¼����� ������Ʈ "��"->"��"

				UpdateExitSeat(exit_floor, selectedSeats, f3, f4);   // ���� �¼��� ���ŵ� ����Ʈ�� �ٽ� txt ���Ͽ� ����(�����)
				PrintExit(exit_floor, exit_seat);   // ���� ��, �¼�, ������ �λ縻 ���
				break;
			}
			if (back == true) continue;  // ó������ ���ư�
			else break;  // ����
		}
		// choice == "7" ����
		else {
			cout << endl << "�����մϴ�. ������ �� ã�ƿ� �ּ���. :D" << endl;
			break;
		}
	}
	return 0;
}


// ��� 1
// try-catch���� �̿��� �Է� ���� üũ
void CheckInput(vector<string> v, string input) {
	int count = 0;
	for (string& s : v) {
		if (s == input) count++;
	}
	if (count == 0) {
		throw exception("�߸��� �Է��Դϴ�. ��Ŀ� �°� �ٽ� �Է����ּ���.");
	}
}

// �߸� �Է� �� ���
void PrintError() {
	cout << endl << "�߸��� �Է��Դϴ�. ��Ŀ� �°� �ٽ� �Է����ּ���." << endl;
}

// ó������ ���ư� �� ���
void PrintReset() {
	cout << endl << "ó�� ȭ������ ���ư��ϴ�." << endl;
}

// ���Ⱑ ���� ���ڿ��� ��ȯ 
string NonSpace(string str) {
	string result;
	for (char ch : str) {
		if (ch != ' ') result += ch;
	}
	return result;
}

// ó���� ������ ����
void SelectChoice(string& choice) {
	try {
		cout << endl << "(���ڸ� �Է��Ͻÿ�)" << endl;
		cout << "1. �޴� & ����  2. �ֹ�  3. �ֹ� ���  4. ����  5. ī�� �� ����  6. ���  7. ����" << endl;
		cout << " >> ";
		getline(cin, choice);
		choice = NonSpace(choice);
		vector<string> v1 = { "1", "2", "3", "4", "5", "6", "7" }; // ù ��° ������ ����
		CheckInput(v1, choice);  // ���� & �������� ���� ���� �Է� �� error
	}
	catch (exception& e) {   // �߸��� �Է����� �ٽ� ����
		cout << endl << e.what() << endl;
		SelectChoice(choice);
	}
}

// ��ü �޴� ���
void TotalMenuPrint() {
	coffee.Print();
	non_coffee.Print();
	tea.Print();
	smoothie.Print();
	frappe.Print();
	ade.Print();
	dessert.Print();
}

// �ֹ� ����
void SelectOrder(string& order) {
	try {
		cout << endl << "������ �ֹ��Ͻðڽ��ϱ�? (���ڸ� �Է��Ͻÿ�)" << endl;
		cout << "1. ����  2. ����Ʈ  3. ó������ ���ư���" << endl;
		cout << " >> ";
		getline(cin, order);
		order = NonSpace(order);
		vector<string> v2 = { "1", "2", "3" };  // �������� ������ ����
		CheckInput(v2, order);  // ���� & �������� ���� ���� �Է� �� error
	}
	catch (exception& e) {   // �߸��� �Է����� �ٽ� ����
		cout << endl << e.what() << endl;
		SelectOrder(order);
	}
}

// ���� ī�װ� ����
void SelectCategory(string& category) {
	try {
		cout << endl << "(���ڸ� �Է��Ͻÿ�)" << endl;
		cout << "1. Ŀ��  2. ��Ŀ��  3. Ƽ  4. ������  5. ������  6. ���̵�  7. ó������ ���ư���" << endl;
		cout << " >> ";
		getline(cin, category);
		category = NonSpace(category);
		vector<string> v3 = { "1", "2", "3", "4", "5", "6", "7" };   // �������� ������ ����
		CheckInput(v3, category);  // ���� & �������� ���� ���� �Է� �� error
	}
	catch (exception& e) {   // �߸��� �Է����� �ٽ� ����
		cout << endl << e.what() << endl;
		SelectCategory(category);
	}
}

// �޴� ����
void SelectMenu(vector<Cafe> c, string& menu, Cafe& selectMenu) {
	cout << "���ϴ� �޴��� �����Ͻÿ� (���ڸ� �Է��Ͻÿ�)" << endl;
	cout << "(0�� �Է��ϸ� ó������ ���ư��ϴ�)" << endl;
	cout << " >> ";
	getline(cin, menu);
	menu = NonSpace(menu);

	if (menu == "0") { return; }

	int count = 0;
	for (auto& e : c) {
		if (e.GetName() == menu) {
			selectMenu = e;
			count++;
		}
	}
	if (count == 0) {
		PrintError(); cout << endl;
		SelectMenu(c, menu, selectMenu);
	}
}

// ���� �޴�(��) ���� �� ����
void SelectSubMenu(Cafe& c, string& subMenu) {
	cout << "�ش� �޴����� ���ϴ� ���� �����Ͻÿ� (���ڸ� �Է��Ͻÿ�)" << endl;
	cout << "(0�� �Է��ϸ� ó������ ���ư��ϴ�)" << endl;
	cout << " >> ";
	getline(cin, subMenu);
	subMenu = NonSpace(subMenu);

	if (subMenu == "0") { return; }

	int count = 0;
	for (string s : c.GetSubMenu()) {
		if (s == subMenu) count++;
	}
	if (count == 0) {
		PrintError(); cout << endl;
		SelectSubMenu(c, subMenu);
	}
}

// ������ Ice/Hot ����
void SelectIceHot(int currentMenu, string& ice_hot) {
	if (currentMenu == 0 || currentMenu == 1 || currentMenu == 2) {
		cout << endl << "ICE / HOT �� �ϳ��� �����Ͻÿ�. (�빮��/�ҹ��� ������� ����� �Է��Ͻÿ�)" << endl;
		cout << "(0�� �Է��ϸ� ó������ ���ư��ϴ�)" << endl;
		cout << " >> ";
		getline(cin, ice_hot);
		ice_hot = NonSpace(ice_hot);

		ice_hot = toUpperStr(ice_hot);
		if (ice_hot == "0") { return; }

		if (ice_hot != "ICE" && ice_hot != "HOT") {
			PrintError();
			SelectIceHot(currentMenu, ice_hot);
		}
	}
	else ice_hot = "ICE";
}

// ���ڿ��� ��� ���ڸ� �빮�ڷ� �ٲٴ� �Լ�
string toUpperStr(string str) {
	for (char& c : str)
		c = toupper(c);
	return str;
}

// ���Ⱑ ���Ե� ���ڿ����� ���Ⱑ ���� ���ڵ��� �������� ���� 
vector<string> SplitStringBySpace(string str) {
	vector<string> result;
	string temp;
	for (char ch : str) {
		if (ch == ' ') {
			if (!temp.empty()) {
				result.push_back(temp);
				temp.clear();
			}
		}
		else {
			temp += ch;
		}
	}
	if (!temp.empty()) {
		result.push_back(temp);
	}
	return result;
}

// ������ ���� ����
void SelectToppings(vector<string>& toppings, FinalOrder& f) {
	map<string, pair<string, int>> options = {
	   {"1", {"Size UP", 800}},
	   {"2", {"�� �߰�", 500}},
	   {"3", {"�� �߰�", 500}},
	   {"4", {"����ũ�� �߰�", 300}},
	   {"5", {"�ٴҶ�÷� �߰�", 300}}
	};
	set<string> setTopping;

	cout << endl << "** 6�� �Է��ϸ� ����ǰ�, 6 ������ �Է��� ���õ˴ϴ�. �ߺ��� ���� ������ �� ���� ����˴ϴ�.** " << endl;
	while (1) {
		cout << endl << "���ϴ� �߰� �ɼ��� ��� �Է��Ͻÿ�. (���ڸ� �Է��Ͻÿ�)" << endl;
		cout << "1. Size UP(+800��)  2. �� �߰�(+500��)  3. �� �߰�(+500��)  4. �ٴҶ�÷� �߰�(+300��)  5. ����ũ�� �߰�(+300��)  6. NO" << endl;
		cout << " >> ";

		bool check = true;  // check == false�� �� ���, ���� ���� �ٽ� ����

		string inputTopping;
		getline(cin, inputTopping);
		vector<string> vectorTopping = SplitStringBySpace(inputTopping);

		int count = 0;
		for (auto& a : vectorTopping) {
			if (a == "6") { count++;  break; }
			else setTopping.insert(a);
		}
		if (count == 0) {
			cout << endl << "�Է��Ͻ� ���ڿ� 6�� �����ϴ�. ���� ������ �����մϴ�. �ٽ� �Է����ּ���." << endl;
			check = false;
		}
		else {
			for (auto& a : setTopping) {
				if (options.find(a) == options.end()) {
					cout << endl << "�ùٸ��� ���� �Է��� �����մϴ�. �Է��Ͻ� ���� ������ ���µ˴ϴ�. �ٽ� �Է����ּ���." << endl;
					check = false; break;
				}
			}
		}
		if (check == false) {
			vectorTopping.clear();	setTopping.clear();
			continue;
		}
		else break;
	}

	for (auto& a : setTopping) {
		pair<string, int>& toppingInfo = options[a];
		string toppingName = toppingInfo.first;
		int price = toppingInfo.second;
		toppings.push_back(toppingName);
		f.IncreasePrice(price);
	}
	f.SetTopping(toppings);

	if (!toppings.empty()) {
		cout << endl << "�����Ͻ� �ɼ��� '";
		f.PrintTopping();
		cout << "' �Դϴ�." << endl;
	}
	else {
		cout << endl << "������ �߰����� �ʾҽ��ϴ�." << endl;
	}
}

// �ֹ� ����� ���� �������� ����
void SelectOrderList(string& orderList) {
	cout << endl << "(���ڸ� �Է��Ͻÿ�)" << endl;
	cout << "1. �ֹ� ��� ����  2. ���� �ֹ� ���  3. ó������ ���ư���" << endl;
	cout << " >> ";
	getline(cin, orderList);
	orderList = NonSpace(orderList);

	vector<string> v = { "1", "2", "3" };
	try {
		CheckInput(v, orderList);
	}
	catch (exception& e) {
		cout << endl << e.what() << endl;
		SelectOrderList(orderList);
	}
}

// �ֹ� ��� ���
void PrintOrderList(vector<FinalOrder>& basket) {
	int n = 0;
	cout << endl << "-- �ֹ� ��� --" << endl;
	if (basket.empty()) {
		cout << " >> (����)" << endl;
	}
	else {
		for (auto& e : basket) {
			cout << " >> " << ++n << ". ";
			e.PrintFinal();
			cout << endl;
		}
	}
}

// �ֹ� ��� ���� ��, ����� �߸� �Է��Ͽ��� �� ���
void PrintDeleteError() {
	cout << endl << "�߸��� �Է����� ������ �����Ͽ����ϴ�. �����ϰ��� �ϴ� �ùٸ� ����� ���� �ٽ� �Է����ּ���." << endl;
}

// �ֹ� ��� ����
void DeleteOrderList(vector<FinalOrder>& basket) {
	string del_Index;
	while (1) {
		cout << endl << "�� ��° ����� �����Ͻðڽ��ϱ�?" << endl;
		cout << "(0�� �Է��ϸ� ó������ ���ư��ϴ�)" << endl;
		cout << " >> ";

		getline(cin, del_Index);
		stringstream ss(del_Index);
		int index;
		ss >> index;
		
		bool check = true;

		if (del_Index.empty()) { PrintDeleteError();  continue; }
		
		if (index == 0) {
			if (del_Index == "0") {
				cout << endl << "�ֹ� ����� �������� �ʰ� ó������ ���ư��ϴ�." << endl;
				return;
			}
			else { PrintDeleteError();  continue; }
		}

		if (index < 1 || index > basket.size()) { PrintDeleteError();  continue; }

		if (del_Index == to_string(index)) {
			cout << endl << " >> ";
			basket[index - 1].PrintFinal();
			cout << "�� �����մϴ�." << endl;
			basket.erase(basket.begin() + index - 1);
			break;
		}
		else { PrintDeleteError();  continue; }
	}
}

// ���� �ݾ�
double FinalPrice(vector<FinalOrder> basket) {
	double sum = 0;  // ���� �ݾ�
	for (auto& a : basket) {
		sum += a.GetPrice();
	}
	return sum;
}

// ���� ����
void SelectYes_No(string& yes_no) {
	cout << endl << "���� �ֹ� ����� �����Ͻðڽ��ϱ�? (�� / �ƴϿ�)" << endl;
	cout << " >> ";
	getline(cin, yes_no);
	yes_no = NonSpace(yes_no);

	if (yes_no != "��" && yes_no != "�ƴϿ�") {
		PrintError();
		SelectYes_No(yes_no);
	}
}

// ���� �� ���� ����
void SelectTake_out_In(string& take) {
	cout << endl << "Take Out�� ������ ��, �����Ͻ� �ݾ��� 5%�� ���� �˴ϴ�." << endl;
	cout << "1. Take In  2. Take Out (���ڸ� �Է��Ͻÿ�)" << endl;
	cout << " >> ";
	getline(cin, take);
	take = NonSpace(take);

	if (take != "1" && take != "2") {
		PrintError();
		SelectTake_out_In(take);
	}
}

// ���� ����
void SelectPayMethod(string& pay_method, vector<FinalOrder>& basket) {
	cout << endl << "���� ������ �������� �Ͻðڽ��ϱ�? (���ڸ� �Է��Ͻÿ�)" << endl;
	cout << "1. ����  2. �ſ�ī�� / üũī��  3. īī������  4. �Ｚ����  5. ��������  6. ���� ���" << endl;
	cout << " >> ";
	getline(cin, pay_method);
	pay_method = NonSpace(pay_method);

	vector<string> v = { "1", "2", "3", "4", "5", "6" };
	try {
		CheckInput(v, pay_method);
	}
	catch (exception& e) {
		cout << endl << e.what() << endl;
		SelectPayMethod(pay_method, basket);
	}

	if (pay_method == "6") {
		cout << endl << "������ ����ϰ�, ó�� ȭ������ ���ư��ϴ�." << endl;
		return;
	}
	else {
		string m;
		if (pay_method == "1") m = "����";
		else if (pay_method == "2") m = "�ſ�ī�� / üũī��";
		else if (pay_method == "3") m = "īī������";
		else if (pay_method == "4") m = "�Ｚ����";
		else  m = "��������";

		PrintOrderList(basket);
		cout << endl << m << "(��)�� ������ �Ϸ� �Ǿ����ϴ�. �޴��� ������� ������ ��ø� ��ٷ� �ּ���. :)" << endl;
	}
}

// ��� 2
// ������ ������� �¼� �ҷ����� 
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

// ������� �¼� �̸��� ���̰� �ҷ�����
void SelectedSeatUpdate(Floor1& f1, Floor2& f2) {
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


// �Է��� �¼��� �����ϴ��� Ȯ��
bool CheckSeats(string floor, string seat, set<string>& s) {
	bool check = false;
	if (floor == "1") {  // 1��
		ifstream is_1{ "seats_floor_1.txt" };
		string s_1;
		while (is_1 >> s_1) {
			s.insert(s_1);
		}
		is_1.close();
	}
	else {  // 2��
		ifstream is_2{ "seats_floor_2.txt" };
		string s_2;
		while (is_2 >> s_2) {
			s.insert(s_2);
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

// ��ǽ� ���
void PrintExit(string floor, string seat) {
	cout << endl << floor << "���� " << seat << " �¼����� ���ϰڽ��ϴ�." << endl;
	cout << "���� ī�並 ã�ƿ� �ּż� �����մϴ�. �ȳ��� ������. :)" << endl;
}

// ���� �� �����, ���� �� ����
void SelectFloor(string& floor) {
	cout << endl << "** 2���� ���θ� ���� ��ҷ� �ٸ� �մԵ鿡�� ���ذ� ���� �ʵ��� ������ ���ּ��� **" << endl;
	cout << endl << "1��, 2�� �� ���ϴ� ���� �����Ͻÿ�. (���ڸ� �Է��Ͻÿ�)" << endl;
	cout << "(Take Out�� ���ϴ� ���, 0�� �Է��Ͻÿ�. �ٽ� �ڷ� ���ư��ϴ�.)" << endl;
	cout << " >> ";
	getline(cin, floor);
	floor = NonSpace(floor);

	if (floor != "1" && floor != "2" && floor != "0") {
		cout << endl << "�߸��� �Է��Դϴ�. ��Ŀ� �°� �ٽ� �Է����ּ���." << endl;
		SelectFloor(floor);
	}
}

// ���� �� �����, ���� �¼� ����
void SelectSeat(string floor, string& seat, Floor* currentFloor) {
	cout << endl << floor << "������ ���ϴ� �¼��� �Է����ּ���. (�빮��/�ҹ��� �������)" << endl;
	cout << "(���� �ٲٰ��� �ϴ� ��� 0�� �Է��Ͻÿ�.)" << endl;
	cout << " >> ";
	getline(cin, seat);
	seat = NonSpace(seat);
	seat = toUpperStr(seat);

	bool check;
	bool checkSelected;
	if (seat == "0") return;

	check = currentFloor->CheckSeats(seat);  // ���õ� �¼��� ��ȿ���� Ȯ��

	if (check == true) return;
	else {
		checkSelected = currentFloor->CheckSelected(seat);  // ������ �¼��� �ٸ� ���� ������� �¼����� Ȯ��
		if (checkSelected == true)
			cout << endl << "�̹� ���õ� �¼��Դϴ�. �ٸ� �¼��� �������ּ���." << endl;
		else
			cout << endl << "�ùٸ��� �ʴ� �¼� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
		SelectSeat(floor, seat, currentFloor);
	}
}

// ���� �� �����, ���� �¼� txt���Ͽ� �߰�
void AddSeat(string floor, string seat) {
	if (floor == "1") {
		ofstream os_1C{ "seats_floor_1.txt", ios::out | ios::app };
		if (os_1C.is_open()) {
			os_1C << seat << endl;
			os_1C.close();
		}
	}
	else {
		ofstream os_2C{ "seats_floor_2.txt", ios::out | ios::app };
		if (os_2C.is_open()) {
			os_2C << seat << endl;
			os_2C.close();
		}
	}
}

// ���忡�� ����� ��, ���� �� ����
void SelectExitFloor(string& floor) {
	cout << endl << "����/����Ʈ�� �� ���̽��ϱ�? �ɾҴ� ������ �Է��� �ּ���. (���ڸ� �Է��Ͻÿ�)" << endl;
	cout << "(����ϰ��� �ϴ� ��� 0�� �Է��Ͻÿ�.)" << endl;
	cout << " >> ";
	getline(cin, floor);
	floor = NonSpace(floor);

	if (floor == "0") return;
	if (floor != "1" && floor != "2") {
		cout << endl << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���." << endl;
		SelectExitFloor(floor);
	}

}

// ���忡�� ����� ��, ���� �¼� ����
void SelectExitSeats(string floor, string& seat, set<string>& seatList) {
	cout << endl << "�ɾҴ� �¼��� �Է��� �ּ���. (�빮��/�ҹ��� �������)" << endl;
	cout << "(���� �ٲٰ��� �ϴ� ��� 0�� �Է��Ͻÿ�.)" << endl;
	cout << " >> ";
	getline(cin, seat);
	seat = NonSpace(seat);
	seat = toUpperStr(seat);

	bool check;
	if (seat == "0") return;

	check = CheckSeats(floor, seat, seatList);

	if (check == false) {
		cout << endl << seat << " �¼��� ���� ������ �����ϴ�. �ٽ� �Է����ּ���." << endl;
		SelectExitSeats(floor, seat, seatList);
	}
}

// ���忡�� ����� ��, ���� �¼� txt���Ͽ��� ����
void UpdateExitSeat(string floor, set<string>& selectedSeats, Floor1& f1, Floor2& f2) {
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
}


#endif // MAIN_CPP