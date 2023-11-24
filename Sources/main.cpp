#include "cafe.h"
#include "FinalOrder.h"

// 커피
vector<Cafe> coffee{ Cafe("에스프레소", 2500), Cafe("아메리카노", 2500),
				Cafe("카푸치노", 3000), Cafe("카페라떼", 3000), Cafe("헤이즐넛라떼", 3500),
				Cafe("바닐라라떼", 3500), Cafe("카라멜마끼아또", 3500),
				Cafe("카페모카", 3500), Cafe("돌체라떼", 3700) };

// non 커피
vector<Cafe> non_coffee{ Cafe("곡물라떼", 3300), Cafe("고구마라떼", 3500), Cafe("딸기라떼", 3500),
						Cafe("초코라떼", 3500), Cafe("그린티라떼", 3500), Cafe("민트초코라떼", 3500) };

// 차(tea)
vector<Cafe> tea{ Cafe("허브티", 2500), Cafe("홍차", 2500),
				Cafe("복숭아티", 3000), Cafe("허니과일티", 3500) };

// 스무디
vector<Cafe> smoothie{ Cafe("스무디", 4000), Cafe("요거트스무디", 4300) };

// 프라페
vector<Cafe> frappe{ Cafe("자바칩프라페", 4500), Cafe("쿠키프라페", 4500),
					Cafe("민트초코프라페", 4500), Cafe("그린티프라페", 4500) };

// 에이드
vector<Cafe> ade{ Cafe("자몽에이드", 4000), Cafe("레몬에이드", 4000), Cafe("유자에이드", 4000),
				 Cafe("청포도에이드", 4000), Cafe("패션후르츠에이드", 4000) };

// 디저트
vector<Cafe> dessert{ Cafe("쿠키", 1500), Cafe("마카롱", 2000),
					Cafe("스콘", 2500), Cafe("머핀", 2500), Cafe("와플", 3000),
					Cafe("크로플", 3300), Cafe("조각케이크", 4700) };

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
	// 전체 메뉴 출력
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
	cout << "잘못된 입력입니다. 양식에 맞게 다시 입력해주세요." << endl;
}



int main() {

	// Tea의 subMenu
	vector<string> herb{ "페퍼민트", "캐모마일", "로즈마리" };
	tea[0].SetSubMenu(herb);

	vector<string> black{ "다즐링", "얼그레이" };
	tea[1].SetSubMenu(black);

	vector<string> fruit{ "자몽", "레몬", "유자" };
	tea[3].SetSubMenu(fruit);

	// Smoothie의 SubMenu
	vector<string> plain{ "딸기", "망고", "키위" };
	smoothie[0].SetSubMenu(plain);

	vector<string> yogurt{ "딸기", "망고", "블루베리", "플레인" };
	smoothie[1].SetSubMenu(yogurt);

	// Dessert의 SubMenu
	vector<string> macaron{ "초코", "바닐라", "쿠앤크", "녹차", "딸기", "카라멜" };
	dessert[1].SetSubMenu(macaron);

	vector<string> cake{ "생크림", "초코", "치즈", "고구마", "티라미슈" };
	dessert[6].SetSubMenu(cake);


	while (1) {
		int request;
		vector<FinalOrder> bucket;
		bool back = false;

		cout << endl;
		cout << "(숫자를 입력하시오)" << endl;
		cout << "1. 메뉴 & 가격  2. 주문  3. 구매 예정 목록  4. 결제  5. 종료" << endl;
		cout << " >> ";
		cin >> request;

		if (request == 1) {
			TotalMenuPrint();
		}
		else if (request == 2) {
			int order;

			while (1) {
				cout << endl;
				cout << "무엇을 주문하시겠습니까? (숫자를 입력하시오)" << endl;
				cout << "1. 음료  2. 디저트  3. 처음으로 돌아가기" << endl;
				cout << " >> ";
				cin >> order;

				if (order > 3 || order < 1) { PrintError(); continue; }
				else break;
			}

			if (order == 1) {
				int drink;
				while (1) {
					cout << endl;
					cout << "(숫자를 입력하시오)" << endl;
					cout << "1. 커피  2. 논커피  3. 티  4. 스무디  5. 프라페  6. 에이드  7. 처음으로 돌아가기" << endl;
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
						cout << "해당 메뉴에서 원하는 음료를 선택하시오 (문자를 입력하시오. 띄어쓰기 없이)" << endl;
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
									cout << "해당 메뉴에서 원하는 맛을 선택하시오 (문자를 입력하시오)" << endl;
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
										cout << "을 구매 예정 목록에 담았습니다." << endl;
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
								cout << "을 구매 예정 목록에 담았습니다." << endl;
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
					cout << "해당 메뉴에서 원하는 디저트를 선택하시오 (문자를 입력하시오. 띄어쓰기 없이)" << endl;
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
								cout << "해당 메뉴에서 원하는 맛을 선택하시오 (문자를 입력하시오)" << endl;
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
									cout << "을 구매 예정 목록에 담았습니다." << endl;
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
							cout << "을 구매 예정 목록에 담았습니다." << endl;
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
			cout << "종료합니다. 다음에 또 찾아 주세요 :D" << endl;
			break;
		}
		else { PrintError(); continue; }
		
		if (back) {
			cout << "다시 처음으로 돌아갑니다." << endl; continue;
		}
	}
	return 0;
}