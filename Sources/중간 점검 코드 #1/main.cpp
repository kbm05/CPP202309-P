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

void PrintOrderList(vector<FinalOrder>& bucket) {
	cout << endl;
	int n = 0;
	cout << "���� ���� ���� ���" << endl;
	if (bucket.empty()) {
		cout << " >> (����)" << endl;
	}
	else {
		for (auto& e : bucket) {
			cout << " >> " << ++n << ". ";
			e.PrintFinal();
			cout << endl;
		}
	}
}

void PrintError() {
	cout << endl << "�߸��� �Է��Դϴ�. ��Ŀ� �°� �ٽ� �Է����ּ���." << endl;
}

void SelectToppings(vector<string>& toppings, FinalOrder& f) {
	vector<int> addT;

	while (1) {
		bool error = false;
		int six_count = 0;

		int input;
		cout << "���ϴ� �߰� �ɼ��� ��� �Է��Ͻÿ�. (���ڸ� �Է��Ͻÿ�. 6�� �Է��ϸ� ����˴ϴ�.)" << endl;
		cout << "1. Size UP(+800��)  2. �� �߰�(+500��)  3. ����ũ�� �߰�(+300��)  4. �ٴҶ�÷� �߰�(+300��)  5. �� �߰�(+500��)  6. NO" << endl;
		cout << " >> ";
		while (1) {
			cin >> input;
			if (input == 6) break;
			addT.push_back(input);
		}

		for (auto& e : addT) {
			if (e < 1 || e > 6) {
				error = true;
				break;
			}
		}

		if (error == true) {
			PrintError(); 
			addT.clear();
			continue;
		}
		else break;
	}

	for (auto& e : addT) {
		if (e == 1) {
			toppings.push_back("Size UP");
			f.IncreasePrice(800);
		}
		else if (e == 2) {
			toppings.push_back("�� �߰�");
			f.IncreasePrice(500);
		}
		else if (e == 3) {
			toppings.push_back("����ũ�� �߰�");
			f.IncreasePrice(300);
		}
		else if (e == 4) {
			toppings.push_back("�ٴҶ�÷� �߰�");
			f.IncreasePrice(300);
		}
		else if (e == 5) {
			toppings.push_back("�� �߰�");
			f.IncreasePrice(500);
		}
		else {
			if (!toppings.empty()) {
				cout << "�߰� �ɼ� ������ �����մϴ�. �����Ͻ� �ɼ��� ";
				f.PrintTopping();
				cout << "�Դϴ�." << endl;
			}
			else {
				cout << "�߰������� �������� �ʾҽ��ϴ�." << endl;
			}
		}
	}
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

	vector<FinalOrder> bucket;  // ���� ���� �޴����� ����

	while (1) {
		int request;
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

				if (drink == 7) { cout << endl; back = true; }
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
					string ice_hot;
					for (auto& e : c) {
						if (e.GetName() == menu) {
							Cafe s = e;

							if (!s.GetSubMenu().empty()) {
								cout << endl;
								s.PrintSub();

								while (1) {
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

								while (1) {
									if (drink == 1 || drink == 2 || drink == 3) {
										cout << endl << "ICE / HOT �� �ϳ��� �����Ͻÿ�. (�빮�ڷ� �Է��Ͻÿ�)" << endl;
										cout << " >> ";
										cin >> ice_hot;

										if (ice_hot == "ICE" || ice_hot == "HOT") {
											break;
										}
										else {
											PrintError(); continue;
										}
									}
									else { ice_hot = "ICE"; break; }
								}

								for (auto& t : s.GetSubMenu()) {
									if (t == last) {
										vector<string> topping;
										FinalOrder a(drink, menu, last, ice_hot, e.GetPrice());
										SelectToppings(topping, a);
										a.SetTopping(topping);

										bucket.push_back(a);
										cout << endl << " ** ";
										a.PrintFinal();
										cout << "�� ���� ���� ��Ͽ� ��ҽ��ϴ�." << endl;
										found = true;
										break;
									}
								}
							}
							else {
								while (1) {
									if (drink == 1 || drink == 2 || drink == 3) {
										cout << endl << "ICE / HOT �� �ϳ��� �����Ͻÿ�. (�빮�ڷ� �Է��Ͻÿ�)" << endl;
										cout << " >> ";
										cin >> ice_hot;

										if (ice_hot == "ICE" || ice_hot == "HOT") {
											break;
										}
										else {
											PrintError(); continue;
										}
									}
									else { ice_hot = "ICE"; break; }
								}

								cout << endl;
								vector<string> topping;
								FinalOrder b(drink, menu, ice_hot, e.GetPrice());
								SelectToppings(topping, b);
								b.SetTopping(topping);

								bucket.push_back(b);
								cout << endl << " ** ";
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
							cout << endl;
							s.PrintSub();

							while (1) {
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
									bucket.push_back(a);
									cout << " ** ";
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
							bucket.push_back(b);
							cout << " ** ";
							b.PrintFinal();
							cout << "�� ���� ���� ��Ͽ� ��ҽ��ϴ�." << endl;
							found = true;
						}
						break;
					}
				}
				if (!found) { PrintError(); continue; }
			}
			else { cout << endl; back = true; }
		}
		else if(request == 3){

			int orderList;
			while (1) {
				cout << endl;
				cout << "(���ڸ� �Է��Ͻÿ�)" << endl;
				cout << "1. ���� ��� ����  2. ���� ���� ���  3. ó������ ���ư���" << endl;
				cout << " >> ";
				cin >> orderList;

				if (orderList > 3 || orderList < 1) { PrintError(); continue; }

				if (orderList == 1) {
					while (1) {
						PrintOrderList(bucket);

						int del_Index;
						cout << endl;
						cout << "�� ��° ����� �����Ͻðڽ��ϱ�?" << endl;
						cout << " >> ";
						cin >> del_Index;
						cout << endl;

						if (del_Index > bucket.size() || del_Index <= 0) {
							cout << "�߸��� �Է��Դϴ�. ������ �����Ͽ����ϴ�." << endl;
							break;
						}
						else {
							cout << " >> ";
							bucket[del_Index - 1].PrintFinal();
							cout << "�� �����մϴ�." << endl;
							bucket.erase(bucket.begin() + del_Index - 1);

							break;
						}
					}
				}
				else if (orderList == 2) {
					PrintOrderList(bucket);
					continue;
				}
				else { cout << endl; back = true; break; }
			}
		}
		else if (request == 4) {
			double sum = 0;

			for (auto& e : bucket) {
				sum += e.GetPrice();
			}

			string pay;

			if (sum == 0) {
				cout << endl;
				cout << "�ֹ� ����� ����ֽ��ϴ�. ";
				back = true;
			}
			else {
				PrintOrderList(bucket);

				cout << endl;
				cout << "���� ���� �ݾ��� �� " << sum << "�� �Դϴ�." << endl;

				while (1) {
					cout << endl;
					cout << "���� �ֹ� ����� �����Ͻðڽ��ϱ�? (�� / �ƴϿ�)" << endl;
					cout << " >> ";
					cin >> pay;

					if (pay == "��" || pay == "�ƴϿ�") {
						break;
					}
					else { PrintError(); continue; }
				}

				if (pay == "��") {
					int method;
					
					int take;
					while (1) {
						cout << endl << "Take Out�� ������ ��, �����Ͻ� �ݾ��� 5%�� ���� �˴ϴ�." << endl;
						cout << "1. Take In  2. Take Out (���ڸ� �Է��Ͻÿ�)" << endl;
						cout << " >> ";
						cin >> take;

						if (take != 1 && take != 2) {
							PrintError(); continue;
						}
						else break;
					}

					if (take == 2) {
						sum *= 0.95;
						cout << endl << "Take Out �������� ���� ���� ���� �ݾ��� " << sum << "�� �Դϴ�. " << endl;
					}
					else {
						// ī�� ������ ���� �¼��� ������ �ڵ� -> ��� 2
					}

					while (1) {
						cout << endl;
						cout << "���� ������ �������� �Ͻðڽ��ϱ�? (���ڸ� �Է��Ͻÿ�)" << endl;
						cout << "1. ����  2. �ſ�ī�� / üũī��  3. īī������  4. �Ｚ����  5. ��������  6. ���� ���" << endl;
						cout << " >> ";
						cin >> method;
						cout << endl;

						if (method < 1 || method > 6) {
							PrintError(); continue;
						}
						else break;
					}

					if (method == 6) {
						cout << "������ ����մϴ�. ";
						back = true;
					}
					else {
						string m;
						if (method == 1) m = "����";
						else if (method == 2) m = "�ſ�ī�� / üũī��";
						else if (method == 3) m = "īī������";
						else if (method == 4) m = "�Ｚ����";
						else  m = "��������";

						cout << m << "(��)�� ������ �Ϸ� �Ǿ����ϴ�. �޴��� ������� ������ ��ø� ��ٷ� �ּ���. :)" << endl;
						break;

					}
				}
				else cout << endl; back = true;
			}
		}
		else if (request == 5) {
			cout << endl;
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