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

void PrintOrderList(vector<FinalOrder>& bucket) {
	cout << endl;
	int n = 0;
	cout << "현재 구매 예정 목록" << endl;
	if (bucket.empty()) {
		cout << " >> (없음)" << endl;
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
	cout << endl << "잘못된 입력입니다. 양식에 맞게 다시 입력해주세요." << endl;
}

void SelectToppings(vector<string>& toppings, FinalOrder& f) {
	vector<int> addT;

	while (1) {
		bool error = false;
		int six_count = 0;

		int input;
		cout << "원하는 추가 옵션을 모두 입력하시오. (숫자를 입력하시오. 6을 입력하면 종료됩니다.)" << endl;
		cout << "1. Size UP(+800원)  2. 샷 추가(+500원)  3. 휘핑크림 추가(+300원)  4. 바닐라시럽 추가(+300원)  5. 펄 추가(+500원)  6. NO" << endl;
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
			toppings.push_back("샷 추가");
			f.IncreasePrice(500);
		}
		else if (e == 3) {
			toppings.push_back("휘핑크림 추가");
			f.IncreasePrice(300);
		}
		else if (e == 4) {
			toppings.push_back("바닐라시럽 추가");
			f.IncreasePrice(300);
		}
		else if (e == 5) {
			toppings.push_back("펄 추가");
			f.IncreasePrice(500);
		}
		else {
			if (!toppings.empty()) {
				cout << "추가 옵션 선택을 종료합니다. 선택하신 옵션은 ";
				f.PrintTopping();
				cout << "입니다." << endl;
			}
			else {
				cout << "추가적으로 선택하지 않았습니다." << endl;
			}
		}
	}
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

	vector<FinalOrder> bucket;  // 구매 예정 메뉴들을 담음

	while (1) {
		int request;
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

				if (drink == 7) { cout << endl; back = true; }
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
					string ice_hot;
					for (auto& e : c) {
						if (e.GetName() == menu) {
							Cafe s = e;

							if (!s.GetSubMenu().empty()) {
								cout << endl;
								s.PrintSub();

								while (1) {
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

								while (1) {
									if (drink == 1 || drink == 2 || drink == 3) {
										cout << endl << "ICE / HOT 중 하나를 선택하시오. (대문자로 입력하시오)" << endl;
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
										cout << "을 구매 예정 목록에 담았습니다." << endl;
										found = true;
										break;
									}
								}
							}
							else {
								while (1) {
									if (drink == 1 || drink == 2 || drink == 3) {
										cout << endl << "ICE / HOT 중 하나를 선택하시오. (대문자로 입력하시오)" << endl;
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
							cout << endl;
							s.PrintSub();

							while (1) {
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
									bucket.push_back(a);
									cout << " ** ";
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
							bucket.push_back(b);
							cout << " ** ";
							b.PrintFinal();
							cout << "을 구매 예정 목록에 담았습니다." << endl;
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
				cout << "(숫자를 입력하시오)" << endl;
				cout << "1. 구매 목록 삭제  2. 현재 구매 목록  3. 처음으로 돌아가기" << endl;
				cout << " >> ";
				cin >> orderList;

				if (orderList > 3 || orderList < 1) { PrintError(); continue; }

				if (orderList == 1) {
					while (1) {
						PrintOrderList(bucket);

						int del_Index;
						cout << endl;
						cout << "몇 번째 목록을 삭제하시겠습니까?" << endl;
						cout << " >> ";
						cin >> del_Index;
						cout << endl;

						if (del_Index > bucket.size() || del_Index <= 0) {
							cout << "잘못된 입력입니다. 삭제를 실패하였습니다." << endl;
							break;
						}
						else {
							cout << " >> ";
							bucket[del_Index - 1].PrintFinal();
							cout << "을 삭제합니다." << endl;
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
				cout << "주문 목록이 비어있습니다. ";
				back = true;
			}
			else {
				PrintOrderList(bucket);

				cout << endl;
				cout << "현재 결제 금액은 총 " << sum << "원 입니다." << endl;

				while (1) {
					cout << endl;
					cout << "현재 주문 목록을 결제하시겠습니까? (네 / 아니요)" << endl;
					cout << " >> ";
					cin >> pay;

					if (pay == "네" || pay == "아니요") {
						break;
					}
					else { PrintError(); continue; }
				}

				if (pay == "네") {
					int method;
					
					int take;
					while (1) {
						cout << endl << "Take Out을 선택할 시, 구매하신 금액의 5%가 할인 됩니다." << endl;
						cout << "1. Take In  2. Take Out (숫자를 입력하시오)" << endl;
						cout << " >> ";
						cin >> take;

						if (take != 1 && take != 2) {
							PrintError(); continue;
						}
						else break;
					}

					if (take == 2) {
						sum *= 0.95;
						cout << endl << "Take Out 할인으로 현재 결제 예정 금액은 " << sum << "원 입니다. " << endl;
					}
					else {
						// 카페 내에서 앉을 좌석을 선택할 코드 -> 기능 2
					}

					while (1) {
						cout << endl;
						cout << "결제 수단은 무엇으로 하시겠습니까? (숫자를 입력하시오)" << endl;
						cout << "1. 현금  2. 신용카드 / 체크카드  3. 카카오페이  4. 삼성페이  5. 애플페이  6. 결제 취소" << endl;
						cout << " >> ";
						cin >> method;
						cout << endl;

						if (method < 1 || method > 6) {
							PrintError(); continue;
						}
						else break;
					}

					if (method == 6) {
						cout << "결제를 취소합니다. ";
						back = true;
					}
					else {
						string m;
						if (method == 1) m = "현금";
						else if (method == 2) m = "신용카드 / 체크카드";
						else if (method == 3) m = "카카오페이";
						else if (method == 4) m = "삼성페이";
						else  m = "애플페이";

						cout << m << "(으)로 결제가 완료 되었습니다. 메뉴가 만들어질 때까지 잠시만 기다려 주세요. :)" << endl;
						break;

					}
				}
				else cout << endl; back = true;
			}
		}
		else if (request == 5) {
			cout << endl;
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