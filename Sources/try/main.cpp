#include "cafe.h"
#include "FinalOrder.h"

// Ŀ��
vector<Cafe> coffee{ Cafe("����������", 2500), Cafe("�Ƹ޸�ī��", 2500),
				Cafe("īǪġ��", 3000), Cafe("ī���", 3000), Cafe("������Ӷ�", 3500),
				Cafe("�ٴҶ��", 3500), Cafe("ī��Ḷ���ƶ�", 3500),
				Cafe("ī���ī", 3500), Cafe("��ü��", 3700) };

// non Ŀ��
vector<Cafe> non_coffee{ Cafe("���", 3300), Cafe("������", 3500), Cafe("�����", 3500),
						Cafe("���ڶ�", 3500), Cafe("�׸�Ƽ��", 3500), Cafe("��Ʈ���ڶ�", 3500) };

// ��(tea)
vector<Cafe> tea{ Cafe("���Ƽ", 2500), Cafe("ȫ��", 2500),
				Cafe("������Ƽ", 3000), Cafe("��ϰ���Ƽ", 3500) };

// ������
vector<Cafe> smoothie{ Cafe("������", 4000), Cafe("���Ʈ������", 4300) };

// ������
vector<Cafe> frappe{ Cafe("�ڹ�Ĩ������", 4500), Cafe("��Ű������", 4500),
					Cafe("��Ʈ����������", 4500), Cafe("�׸�Ƽ������", 4500) };

// ���̵�
vector<Cafe> ade{ Cafe("�ڸ����̵�", 4000), Cafe("�����̵�", 4000), Cafe("���ڿ��̵�", 4000),
				 Cafe("û�������̵�", 4000), Cafe("�м��ĸ������̵�", 4000) };

// ����Ʈ
vector<Cafe> dessert{ Cafe("��Ű", 1500), Cafe("��ī��", 2000),
					Cafe("����", 2500), Cafe("����", 2500), Cafe("����", 3000),
					Cafe("ũ����", 3300), Cafe("��������ũ", 4700) };

void PrintMenuCategory(int s, string category, vector<Cafe>& items) {
	cout << setw(s) << "<< " << category << " >>";
	if (category == "SMOOTHIE" || category == "FRAPPE" || category == "ADE") {
		cout << " ICE ONLY" << endl;
	}
	else cout << endl;
	cout << "-----------------------------------";
	for (auto& item : items) {
		item.PrintMenu();
	}
	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << endl;
}

void TotalMenuPrint() {
	// ��ü �޴� ���
	PrintMenuCategory(17, "COFFEE", coffee);
	PrintMenuCategory(15, "NON COFFEE", non_coffee);
	PrintMenuCategory(19, "TEA", tea);
	PrintMenuCategory(11, "SMOOTHIE", smoothie);
	PrintMenuCategory(12, "FRAPPE", frappe);
	PrintMenuCategory(13, "ADE", ade);
	PrintMenuCategory(17, "DESSERT", dessert);
}

vector<Cafe>& Order(int drink) {
	if (drink == 1) { PrintMenuCategory(17, "COFFEE", coffee); return coffee; }
	else if (drink == 2) { PrintMenuCategory(15, "NON COFFEE", non_coffee); return non_coffee; }
	else if (drink == 3) { PrintMenuCategory(19, "TEA", tea); return tea; }
	else if (drink == 4) { PrintMenuCategory(11, "SMOOTHIE", smoothie); return smoothie; }
	else if (drink == 5) { PrintMenuCategory(12, "FRAPPE", frappe); return frappe; }
	else if (drink == 6) { PrintMenuCategory(13, "ADE", ade); return ade; }
	else vector<Cafe> empty;
}

void PrintError() {
	cout << "�߸��� �Է��Դϴ�. ��Ŀ� �°� �ٽ� �Է����ּ���." << endl;
}



int main() {

	// Tea�� subMenu
	vector<string> herb{ "���۹�Ʈ", "ĳ����", "�����" };
	tea[0].SetSubMenu(herb);

	vector<string> black{ "����", "��׷���" };
	tea[1].SetSubMenu(black);

	vector<string> fruit{ "�ڸ�", "����", "����" };
	tea[3].SetSubMenu(fruit);

	// Smoothie�� SubMenu
	vector<string> plain{ "����", "����", "Ű��" };
	smoothie[0].SetSubMenu(plain);

	vector<string> yogurt{ "����", "����", "��纣��", "�÷���" };
	smoothie[1].SetSubMenu(yogurt);

	// Dessert�� SubMenu
	vector<string> macaron{ "����", "�ٴҶ�", "���ũ", "����", "����", "ī���" };
	dessert[1].SetSubMenu(macaron);

	vector<string> cake{ "��ũ��", "����", "ġ��", "����", "Ƽ��̽�" };
	dessert[6].SetSubMenu(cake);


	while (1) {
		int request;
		vector<FinalOrder> bucket;
		bool back = false;

		cout << endl;
		cout << "(���ڸ� �Է��Ͻÿ�)" << endl;
		cout << "1. �޴� & ����  2. �ֹ�  3. ���� ���� ���  4. ����  5. ����" << endl;
		cout << " >> ";
		cin >> request;

		if (request == 1) {
			TotalMenuPrint();
		}
		else if (request == 2) {
			int order;

			while (1) {
				cout << endl;
				cout << "������ �ֹ��Ͻðڽ��ϱ�? (���ڸ� �Է��Ͻÿ�)" << endl;
				cout << "1. ����  2. ����Ʈ  3. ó������ ���ư���" << endl;
				cout << " >> ";
				cin >> order;

				if (order > 3 || order < 1) { PrintError(); continue; }
				else break;
			}

			if (order == 1) {
				int drink;
				while (1) {
					cout << endl;
					cout << "(���ڸ� �Է��Ͻÿ�)" << endl;
					cout << "1. Ŀ��  2. ��Ŀ��  3. Ƽ  4. ������  5. ������  6. ���̵�  7. ó������ ���ư���" << endl;
					cout << " >> ";
					cin >> drink;

					if (drink > 7 || drink < 1) { PrintError(); continue; }
					else break;
				}

				if (drink == 7) { back = true; }
				else {
					vector<Cafe> c = Order(drink);
					string menu;

					while (1) {
						cout << endl;
						cout << "�ش� �޴����� ���ϴ� ���Ḧ �����Ͻÿ� (���ڸ� �Է��Ͻÿ�. ���� ����)" << endl;
						cout << " >> ";
						cin >> menu;

						int count = 0;
						for (auto& e : c) {
							if (e.GetName() == menu) {
								count++;
							}
						}

						if (count == 0) {
							PrintError(); continue;
						}
						else break;
					}

					string last;
					bool found = false;
					for (auto& e : c) {
						if (e.GetName() == menu) {
							Cafe s = e;

							if (!s.GetSubMenu().empty()) {
								s.PrintSub();

								while (1) {
									cout << endl;
									cout << "�ش� �޴����� ���ϴ� ���� �����Ͻÿ� (���ڸ� �Է��Ͻÿ�)" << endl;
									cout << " >> ";
									cin >> last;

									int count = 0;
									for (auto& t : s.GetSubMenu()) {
										if (t == last) {
											count++;
										}
									}

									if (count == 0) {
										PrintError(); continue;
									}
									else break;
								}

								for (auto& t : s.GetSubMenu()) {
									if (t == last) {
										cout << endl;
										FinalOrder a(drink, menu, last, e.GetPrice());
										cout << " ~~ ";
										a.PrintFinal();
										cout << "�� ���� ���� ��Ͽ� ��ҽ��ϴ�." << endl;
										found = true;
										break;
									}
								}
							}
							else {
								cout << endl;
								FinalOrder b(drink, menu, e.GetPrice());
								cout << " ~~ ";
								b.PrintFinal();
								cout << "�� ���� ���� ��Ͽ� ��ҽ��ϴ�." << endl;
								found = true;
							}
							break;
						}
					}
					if (!found) { PrintError(); continue; }
				}
			}
			else if (order == 2) {
				PrintMenuCategory(17, "DESSERT", dessert);
				string menu;

				while (1) {
					cout << endl;
					cout << "�ش� �޴����� ���ϴ� ����Ʈ�� �����Ͻÿ� (���ڸ� �Է��Ͻÿ�. ���� ����)" << endl;
					cout << " >> ";
					cin >> menu;

					int count = 0;
					for (auto& e : dessert) {
						if (e.GetName() == menu) {
							count++;
						}
					}

					if (count == 0) {
						PrintError(); continue;
					}
					else break;
				}

				string last;
				bool found = false;
				for (auto& e : dessert) {
					if (e.GetName() == menu) {
						Cafe s = e;

						if (!s.GetSubMenu().empty()) {
							s.PrintSub();

							while (1) {
								cout << endl;
								cout << "�ش� �޴����� ���ϴ� ���� �����Ͻÿ� (���ڸ� �Է��Ͻÿ�)" << endl;
								cout << " >> ";
								cin >> last;

								int count = 0;
								for (auto& t : s.GetSubMenu()) {
									if (t == last) {
										count++;
									}
								}

								if (count == 0) {
									PrintError(); continue;
								}
								else break;
							}

							for (auto& t : s.GetSubMenu()) {
								if (t == last) {
									cout << endl;
									FinalOrder a(menu, last, e.GetPrice());
									cout << " ~~ ";
									a.PrintFinal();
									cout << "�� ���� ���� ��Ͽ� ��ҽ��ϴ�." << endl;
									found = true;
									break;
								}
							}
						}
						else {
							cout << endl;
							FinalOrder b(menu, e.GetPrice());
							cout << " ~~ ";
							b.PrintFinal();
							cout << "�� ���� ���� ��Ͽ� ��ҽ��ϴ�." << endl;
							found = true;
						}
						break;
					}
				}
				if (!found) { PrintError(); continue; }
			}
			else { back = true; }
		}
		else if (request == 5) {
			cout << "�����մϴ�. ������ �� ã�� �ּ��� :D" << endl;
			break;
		}
		else { PrintError(); continue; }
		
		if (back) {
			cout << "�ٽ� ó������ ���ư��ϴ�." << endl; continue;
		}
	}
	return 0;
}