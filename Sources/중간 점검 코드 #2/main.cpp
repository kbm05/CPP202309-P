#ifndef MAIN_CPP    // ���� ��� ������ �ߺ��ؼ� ���ԵǴ� ���� ����
#define MAIN_CPP

#include "menu.h"
#include "finalOrder.h"
#include "floor_1.h"
#include "floor_2.h"
#include <exception>
#include <map>
#include <set>

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
// ��ü �޴� ���
void TotalMenuPrint();
// �޴� ����
void SelectMenu(vector<Cafe> c, string& menu);
// ���� �޴� ���� �� ����
void SelectTaste(Cafe& c, string& taste);
// ������ Ice/Hot ����
void SelectIceHot(int currentMenu, string& ice_hot);
// ������ ���� ����
void SelectToppings(vector<string>& toppings, FinalOrder& f);
// �ֹ� ����� ���� �������� ����
void SelectOrderList(string& orderList);
// �ֹ� ��� ���
void PrintOrderList(vector<FinalOrder>& basket);
// �ֹ� ��� ����
void DeleteOrderList(vector<FinalOrder>& basket);
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

		string choice;
		bool back = false;  // back�� true�� �Ǹ� ó������ ���ƿ�

		UpdateSeat(f1, f2);

		try {
			cout << endl << "(���ڸ� �Է��Ͻÿ�)" << endl;
			cout << "1. �޴� & ����  2. �ֹ�  3. �ֹ� ���  4. ����  5. ī�� �� ����  6. ���  7. ����" << endl;
			cout << " >> ";
			cin >> choice;

			vector<string> v1 = { "1", "2", "3", "4", "5", "6", "7"}; // ù ��° ������ ����
			CheckInput(v1, choice);  // ���� & �������� ���� ���� �Է� �� error
		}
		catch (exception& e) {   // �߸��� �Է����� �ٽ� ����
			cout << endl << e.what() << endl;
			continue; 
		}
		// 1. �޴��� ���� ���
		if (choice == "1") {
			TotalMenuPrint();
		}
		// 2. �ֹ�
		else if (choice == "2") {
			string oreder;

			while (1) {
				try {
					cout << endl << "������ �ֹ��Ͻðڽ��ϱ�? (���ڸ� �Է��Ͻÿ�)" << endl;
					cout << "1. ����  2. ����Ʈ  3. ó������ ���ư���" << endl;
					cout << " >> ";
					cin >> oreder;

					vector<string> v2 = { "1", "2", "3" };  // �������� ������ ����
					CheckInput(v2, oreder);  // ���� & �������� ���� ���� �Է� �� error
					break;
				}
				catch (exception& e) {   // �߸��� �Է����� �ٽ� ����
					cout << endl << e.what() << endl;
					continue;
				}
			}
			// ���� �ֹ�
			if (oreder == "1") {
				string drink;
				bool found = false;
				while (1) {
					try {
						cout << endl << "(���ڸ� �Է��Ͻÿ�)" << endl;
						cout << "1. Ŀ��  2. ��Ŀ��  3. Ƽ  4. ������  5. ������  6. ���̵�  7. ó������ ���ư���" << endl;
						cout << " >> ";
						cin >> drink;

						vector<string> v3 = { "1", "2", "3", "4", "5", "6", "7" };   // �������� ������ ����
						CheckInput(v3, drink);  // ���� & �������� ���� ���� �Է� �� error
						break;
					}
					catch (exception& e) {   // �߸��� �Է����� �ٽ� ����
						cout << endl << e.what() << endl;
						continue;
					}
				}

				// ó������ ���ư���
				if (drink == "7") {
					PrintReset();
					continue;
				}
				else {
					string menu;

					if (drink == "1") currentMenu = 0;
					else if (drink == "2") currentMenu = 1;
					else if (drink == "3") currentMenu = 2;
					else if (drink == "4") currentMenu = 3;
					else if (drink == "5") currentMenu = 4;
					else if (drink == "6") currentMenu = 5;

					m[currentMenu]->Print();
					// �޴� ����
					SelectMenu(m[currentMenu]->menu, menu);

					if (menu == "0") back = true;   // ó������ ���ư���

					for (auto& a : m[currentMenu]->menu) {
						if (a.GetName() == menu) {
							Cafe sub = a;

							string taste;  // ���� �޴�
							if (!sub.GetSubMenu().empty()) {
								cout << endl;
								sub.PrintSub();
								// ���� �޴�(��) ����
								SelectTaste(sub, taste);

								if (taste == "0") {
									back = true;   // ó������ ���ư���
									break;
								}
							}

							string ice_hot;
							// ice / hot ����
							SelectIceHot(currentMenu, ice_hot);

							if (ice_hot == "0") {
								back = true;   // ó������ ���ư���
								break;
							}
							// ���μ���
							vector<string> toppings;
							if (!sub.GetSubMenu().empty()) {  // ���μ���(���� �޴��� ������ ��)
								for (auto& s : sub.GetSubMenu()) {
									if (s == taste) {
										FinalOrder a(drink, menu, taste, ice_hot, sub.GetPrice());  // �ֹ� ��Ͽ� ����
										SelectToppings(toppings, a);
										a.SetTopping(toppings);
										basket.push_back(a);
										cout << endl << " ** ";
										a.PrintFinal();
										found = true;
										break;
									}
								}
							}
							else {  // ���μ���(����޴��� �������� ���� ��)
								FinalOrder b(drink, menu, ice_hot, sub.GetPrice());  // �ֹ� ��Ͽ� ����
								SelectToppings(toppings, b);
								b.SetTopping(toppings);
								basket.push_back(b);
								cout << endl << " ** ";
								b.PrintFinal();
								found = true;
							}
							cout << "�� ���� ���� ��Ͽ� ��ҽ��ϴ�." << endl;
							break;
						}
					}
					if (back == true) { PrintReset(); continue; }  // ó������ ���ư���
					if (!found) { PrintError(); continue; }
				}
			}
			// ����Ʈ �ֹ�
			else if (oreder == "2") {
				dessert.Print();
				string menu;
				bool found = false;
				// ����Ʈ �޴� ����
				SelectMenu(dessert.menu, menu);

				if (menu == "0") back = true;  // ó������ ���ư���

				Cafe sub = dessert.menu[0];
				for (auto& a : dessert.menu) {
					if (a.GetName() == menu) {
						sub = a;

						string taste;  // ���� �޴� ���� ��
						if (!sub.GetSubMenu().empty()) {
							cout << endl;
							sub.PrintSub();
							// ���� �޴�(��) ����
							SelectTaste(sub, taste);

							if (taste == "0") back = true;   // ó������ ���ư���

							for (auto& s : sub.GetSubMenu()) {
								if (s == taste) {
									FinalOrder a(menu, taste, sub.GetPrice());  // (���� �޴��� ������ ��) �ֹ� ��Ͽ� ����
									basket.push_back(a);
									cout << endl << " ** ";
									a.PrintFinal();
									found = true;
									break;
								}
							}
						}
						else {
							FinalOrder b(menu, sub.GetPrice());  // (���� �޴��� ���� ��) �ֹ� ��Ͽ� ����
							basket.push_back(b);
							cout << endl << " ** ";
							b.PrintFinal();
							found = true;
						}
						cout << "�� ���� ���� ��Ͽ� ��ҽ��ϴ�." << endl;
						break;
					}
				}
				if (back == true) { PrintReset(); continue; }  // ó������ ���ư���
				if (!found) { PrintError(); continue; }  // ó������ ���ư���
			}
			else { PrintReset(); continue; }   // oreder == "3"�� �� ó������ ���ư���
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
			double sum = 0;  // ���� �ݾ�

			for (auto& a : basket) {
				sum += a.GetPrice();
			}

			if (sum == 0) {  // �ֹ� ����� ������� ��, ���� ��� & ó������ ���ư�
				cout << endl;
				cout << "�ֹ� ����� ����ֽ��ϴ�." << endl;
				continue;
			}
			else {  // �ֹ� ����� ������� ���� ��

				PrintOrderList(basket);  // ���� �ֹ� ����� ���

				cout << endl;
				cout << "���� ���� �ݾ��� �� " << sum << "�� �Դϴ�." << endl;
				
				string pay_ok;  // ���� ����
				SelectYes_No(pay_ok);   // ���� ���θ� ���
				if (pay_ok == "�ƴϿ�") { PrintReset(); continue; }  // ���� ��� �� ó������ ���ư�
				else {  // ���� ����
					while (1) {
						bool take_select = false;  // take_select == true�� �Ǹ� take out ���� �ٽ� ����
						string take;  // take out �� ���� or take in �� ����
						string pay_method;  // ���� ����
						SelectTake_out_In(take);  // take out ���� ����

						if (take == "2") {  // take out �� ��
							sum *= 0.95;  // ���� �ݾ��� 5% ����
							cout << endl << "Take Out �������� ���� ���� ���� �ݾ��� " << sum << "�� �Դϴ�. " << endl;
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
					cout << endl << "����� ����մϴ�.";
					PrintReset(); back = true;
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

// �޴� ����
void SelectMenu(vector<Cafe> c, string& menu) {
	cout << "���ϴ� �޴��� �����Ͻÿ� (���ڸ� �Է��Ͻÿ�. ���� ����)" << endl;
	cout << "(0�� �Է��ϸ� ó������ ���ư��ϴ�)" << endl;
	cout << " >> ";
	cin >> menu;

	if (menu == "0") { return; }

	int count = 0;
	for (auto& e : c) {
		if (e.GetName() == menu)	count++;
	}
	if (count == 0) {
		PrintError(); cout << endl;
		SelectMenu(c, menu);
	}
}

// ���� �޴�(��) ���� �� ����
void SelectTaste(Cafe& c, string& taste) {
	cout << "�ش� �޴����� ���ϴ� ���� �����Ͻÿ� (���ڸ� �Է��Ͻÿ�)" << endl;
	cout << "(0�� �Է��ϸ� ó������ ���ư��ϴ�)" << endl;
	cout << " >> ";
	cin >> taste;

	if (taste == "0") { return; }

	int count = 0;
	for (string s : c.GetSubMenu()) {
		if (s == taste) count++;
	}
	if (count == 0) {
		PrintError(); cout << endl;
		SelectTaste(c, taste);
	}
}

// ������ Ice/Hot ����
void SelectIceHot(int currentMenu, string& ice_hot) {
	if (currentMenu == 0 || currentMenu == 1 || currentMenu == 2) {
		cout << endl << "ICE / HOT �� �ϳ��� �����Ͻÿ�. (�빮�ڷ� �Է��Ͻÿ�)" << endl;
		cout << "(0�� �Է��ϸ� ó������ ���ư��ϴ�)" << endl;
		cout << " >> ";
		cin >> ice_hot;

		if (ice_hot == "0") { return; }

		if (ice_hot != "ICE" && ice_hot != "HOT") {
			PrintError();
			SelectIceHot(currentMenu, ice_hot);
		}
	}
	else ice_hot = "ICE";
}

// ������ ���� ����
void SelectToppings(vector<string>& toppings, FinalOrder& f) {
	map<string, pair<string, int>> options = {
	   {"1", {"Size UP", 800}},
	   {"2", {"�� �߰�", 500}},
	   {"3", {"����ũ�� �߰�", 300}},
	   {"4", {"�ٴҶ�÷� �߰�", 300}},
	   {"5", {"�� �߰�", 500}}
	};
	cout << endl << "���ϴ� �߰� �ɼ��� ��� �Է��Ͻÿ�. (���ڸ� �Է��Ͻÿ�. 6�� �Է��ϸ� ����˴ϴ�.)" << endl;
	cout << "1. Size UP(+800��)  2. �� �߰�(+500��)  3. ����ũ�� �߰�(+300��)  4. �ٴҶ�÷� �߰�(+300��)  5. �� �߰�(+500��)  6. NO" << endl;
	cout << " >> ";

	string inputTopping;
	while (cin >> inputTopping && inputTopping != "6") {
		if (options.find(inputTopping) == options.end()) {
			PrintError(); continue;
		}
		pair<string, int>& toppingInfo = options[inputTopping];
		string toppingName = toppingInfo.first;
		int price = toppingInfo.second;
		toppings.push_back(toppingName);
		f.IncreasePrice(price);
	}

	if (!toppings.empty()) {
		cout << endl << "�����Ͻ� �ɼ��� '";
		for (auto p = toppings.begin(); p != toppings.end(); ++p) {
			if (p == toppings.end() - 1) { cout << *p << "'"; }
			else cout << *p << ", ";
		}
		cout << "�Դϴ�." << endl;
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
	cin >> orderList;

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
	cout << endl;
	int n = 0;
	cout << "���� �ֹ� ���" << endl;
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

// �ֹ� ��� ����
void DeleteOrderList(vector<FinalOrder>& basket) {
	int del_Index;
	cout << endl << "�� ��° ����� �����Ͻðڽ��ϱ�?" << endl;
	cout << "(0�� �Է��ϸ� ó������ ���ư��ϴ�)" << endl;
	cout << " >> ";
	cin >> del_Index;

	if (del_Index == 0) {
		cout << endl << "�ֹ� ����� �������� �ʰ� ó������ ���ư��ϴ�." << endl; 
		return;
	}
	if (del_Index > basket.size() || del_Index < 0) {
		cout << endl << "�߸��� �Է��Դϴ�. ������ �����Ͽ����ϴ�." << endl;
		return;
	}
	else {
		cout << endl << " >> ";
		basket[del_Index - 1].PrintFinal();
		cout << "�� �����մϴ�." << endl;
		basket.erase(basket.begin() + del_Index - 1);
	}
}

// ���� ����
void SelectYes_No(string& yes_no) {
	cout << endl << "���� �ֹ� ����� �����Ͻðڽ��ϱ�? (�� / �ƴϿ�)" << endl;
	cout << " >> ";
	cin >> yes_no;

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
	cin >> take;

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
	cin >> pay_method;
	cout << endl;
	
	vector<string> v = { "1", "2", "3", "4", "5", "6" };
	try {
		CheckInput(v, pay_method);
	}
	catch(exception& e) {
		cout << endl << e.what() << endl;
		SelectPayMethod(pay_method, basket);
	}

	if (pay_method == "6") {
		cout << "������ ����մϴ�.";
		PrintReset();
		return;
	}
	else {
		string m;
		if (pay_method == "1") m = "����";
		else if (pay_method == "2") m = "�ſ�ī�� / üũī��";
		else if (pay_method == "3") m = "īī������";
		else if (pay_method == "4") m = "�Ｚ����";
		else  m = "��������";

		cout << "-- �ֹ� �޴� --" << endl;
		PrintOrderList(basket);
		cout << endl << m << "(��)�� ������ �Ϸ� �Ǿ����ϴ�. �޴��� ������� ������ ��ø� ��ٷ� �ּ���. :)" << endl;
	}
}

// ��� 2
// ���õ� �¼� �̸��� ���̰� �ҷ�����
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

// ���õ� �¼� �ҷ����� 
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

// �Է��� �¼��� �����ϴ��� Ȯ��
bool CheckSeats(string floor, string seat, set<string>& s) {
	bool check = false;
	if (floor == "1") {
		ifstream is_1{ "seats_floor_1.txt" };
		string s_1;
		while (is_1 >> s_1) {
			s.insert(s_1);
		}
		is_1.close();
	}
	else {
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
	cout << "���� ī�並 ã�ƿ� �ּż� �����մϴ�. �ȳ��� ������." << endl;
}

// ���� �� �����, ���� �� ����
void SelectFloor(string& floor) {
	cout << endl << "** 2���� ���θ� ���� ��ҷ� �ٸ� �մԵ鿡�� ���ذ� ���� �ʵ��� ������ ���ּ��� **" << endl;
	cout << endl << "1��, 2�� �� ���ϴ� ���� �����Ͻÿ�. (���ڸ� �Է��Ͻÿ�)" << endl;
	cout << "(Take Out�� ���ϴ� ���, 0�� �Է��Ͻÿ�. �ٽ� �ڷ� ���ư��ϴ�.)" << endl;
	cout << " >> ";
	cin >> floor;

	if (floor != "1" && floor != "2" && floor != "0") {
		cout << endl << "�߸��� �Է��Դϴ�. ��Ŀ� �°� �ٽ� �Է����ּ���." << endl;
		SelectFloor(floor);
	}
}

// ���� �� �����, ���� �¼� ����
void SelectSeat(string floor, string& seat, Floor* currentFloor) {
	cout << endl << floor << "������ ���ϴ� �¼��� �Է����ּ���. (�빮�ڷ� �Է��Ͻÿ�)" << endl;
	cout << "(���� �ٲٰ��� �ϴ� ��� 0�� �Է��Ͻÿ�.)" << endl;
	cout << " >> ";
	cin >> seat;

	bool check;
	bool checkSelected;
	if (seat == "0") return;

	check = currentFloor->CheckSeats(seat);

	if (check == true) return;
	else {
		checkSelected = currentFloor->CheckSelected(seat);
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
	cin >> floor;
	
	if (floor == "0") return;
	if (floor != "1" && floor != "2") {
		cout << endl << "�߸��� �Է��Դϴ�. �ٽ� �Է��� �ּ���." << endl;
		SelectExitFloor(floor);
	}

}

// ���忡�� ����� ��, ���� �¼� ����
void SelectExitSeats(string floor, string& seat, set<string>& seatList) {
	cout << endl << "�ɾҴ� �¼��� �Է��� �ּ���. (�빮�ڷ� �Է��Ͻÿ�)" << endl;
	cout << "(���� �ٲٰ��� �ϴ� ��� 0�� �Է��Ͻÿ�.)" << endl;
	cout << " >> ";
	cin >> seat;

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