#ifndef MAIN_CPP    // 여러 헤더 파일이 중복해서 포함되는 것을 방지
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

// 기능 1
// 잘못 입력 시 출력
void PrintError();
// try-catch문을 이용한 입력 에러 체크
void CheckInput(vector<string> v, string input);
// 처음으로 돌아갈 시 출력
void PrintReset();
// 전체 메뉴 출력
void TotalMenuPrint();
// 메뉴 선택
void SelectMenu(vector<Cafe> c, string& menu);
// 서브 메뉴 존재 시 선택
void SelectTaste(Cafe& c, string& taste);
// 음료의 Ice/Hot 선택
void SelectIceHot(int currentMenu, string& ice_hot);
// 음료의 토핑 선택
void SelectToppings(vector<string>& toppings, FinalOrder& f);
// 주문 목록을 볼지 삭제할지 선택
void SelectOrderList(string& orderList);
// 주문 목록 출력
void PrintOrderList(vector<FinalOrder>& basket);
// 주문 목록 삭제
void DeleteOrderList(vector<FinalOrder>& basket);
// 결제 여부
void SelectYes_No(string& yes_no);
// 매장 내 섭취 선택
void SelectTake_out_In(string& take);
// 결제 수단
void SelectPayMethod(string& pay_method, vector<FinalOrder>& basket);

// 기능 2
// 선택된 좌석 이름이 보이게 불러오기
void SelectedSeatUpdate(Floor1& f1, Floor2& f2);
// 선택된 좌석 불러오기 
void UpdateSeat(Floor1& f1, Floor2& f2);
// 입력한 좌석이 존재하는지 확인
bool CheckSeats(string floor, string seat, set<string>& s);
// 퇴석시 출력
void PrintExit(string floor, string seat);
// 매장 내 섭취시, 앉을 층 선택
void SelectFloor(string& floor);
// 매장 내 섭취시, 앉을 좌석 선택
void SelectSeat(string floor, string& seat, Floor* currentFloor);
// 매장 내 섭취시, 앉을 좌석 txt파일에 추가
void AddSeat(string floor, string seat);
// 매장에서 퇴실할 시, 퇴석할 층 선택
void SelectExitFloor(string& floor);
// 매장에서 퇴실할 시, 퇴석할 좌석 선택
void SelectExitSeats(string floor, string& seat, set<string>& seatList);
// 매장에서 퇴실할 시, 퇴석할 좌석 txt파일에서 제거
void UpdateExitSeat(string floor, set<string>& selectedSeats, Floor1& f1, Floor2& f2);


int main() {
	vector<Menu*> m = { &coffee, &non_coffee, &tea, &smoothie, &frappe, &ade, &dessert };
	int currentMenu;

	vector<FinalOrder> basket;   // 주문 예정 메뉴들을 담음 (주문 목록)

	while (1) {
		Floor1 f1;
		Floor2 f2;

		UpdateSeat(f1, f2);  // txt파일을 읽어와 사용중인 좌석 업데이트 

		string choice;
		bool back = false;  // back이 true가 되면 처음으로 돌아옴

		UpdateSeat(f1, f2);

		try {
			cout << endl << "(숫자를 입력하시오)" << endl;
			cout << "1. 메뉴 & 가격  2. 주문  3. 주문 목록  4. 결제  5. 카페 내 여석  6. 퇴실  7. 종료" << endl;
			cout << " >> ";
			cin >> choice;

			vector<string> v1 = { "1", "2", "3", "4", "5", "6", "7"}; // 첫 번째 선택지 벡터
			CheckInput(v1, choice);  // 선택 & 선택지에 맞지 않은 입력 시 error
		}
		catch (exception& e) {   // 잘못된 입력으로 다시 선택
			cout << endl << e.what() << endl;
			continue; 
		}
		// 1. 메뉴와 가격 출력
		if (choice == "1") {
			TotalMenuPrint();
		}
		// 2. 주문
		else if (choice == "2") {
			string oreder;

			while (1) {
				try {
					cout << endl << "무엇을 주문하시겠습니까? (숫자를 입력하시오)" << endl;
					cout << "1. 음료  2. 디저트  3. 처음으로 돌아가기" << endl;
					cout << " >> ";
					cin >> oreder;

					vector<string> v2 = { "1", "2", "3" };  // 선택지를 저장한 벡터
					CheckInput(v2, oreder);  // 선택 & 선택지에 맞지 않은 입력 시 error
					break;
				}
				catch (exception& e) {   // 잘못된 입력으로 다시 선택
					cout << endl << e.what() << endl;
					continue;
				}
			}
			// 음료 주문
			if (oreder == "1") {
				string drink;
				bool found = false;
				while (1) {
					try {
						cout << endl << "(숫자를 입력하시오)" << endl;
						cout << "1. 커피  2. 논커피  3. 티  4. 스무디  5. 프라페  6. 에이드  7. 처음으로 돌아가기" << endl;
						cout << " >> ";
						cin >> drink;

						vector<string> v3 = { "1", "2", "3", "4", "5", "6", "7" };   // 선택지를 저장한 벡터
						CheckInput(v3, drink);  // 선택 & 선택지에 맞지 않은 입력 시 error
						break;
					}
					catch (exception& e) {   // 잘못된 입력으로 다시 선택
						cout << endl << e.what() << endl;
						continue;
					}
				}

				// 처음으로 돌아가기
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
					// 메뉴 선택
					SelectMenu(m[currentMenu]->menu, menu);

					if (menu == "0") back = true;   // 처음으로 돌아가기

					for (auto& a : m[currentMenu]->menu) {
						if (a.GetName() == menu) {
							Cafe sub = a;

							string taste;  // 서브 메뉴
							if (!sub.GetSubMenu().empty()) {
								cout << endl;
								sub.PrintSub();
								// 서브 메뉴(맛) 선택
								SelectTaste(sub, taste);

								if (taste == "0") {
									back = true;   // 처음으로 돌아가기
									break;
								}
							}

							string ice_hot;
							// ice / hot 선택
							SelectIceHot(currentMenu, ice_hot);

							if (ice_hot == "0") {
								back = true;   // 처음으로 돌아가기
								break;
							}
							// 토핑선택
							vector<string> toppings;
							if (!sub.GetSubMenu().empty()) {  // 토핑선택(서브 메뉴가 존재할 때)
								for (auto& s : sub.GetSubMenu()) {
									if (s == taste) {
										FinalOrder a(drink, menu, taste, ice_hot, sub.GetPrice());  // 주문 목록에 저장
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
							else {  // 토핑선택(서브메뉴가 존재하지 않을 때)
								FinalOrder b(drink, menu, ice_hot, sub.GetPrice());  // 주문 목록에 저장
								SelectToppings(toppings, b);
								b.SetTopping(toppings);
								basket.push_back(b);
								cout << endl << " ** ";
								b.PrintFinal();
								found = true;
							}
							cout << "을 구매 예정 목록에 담았습니다." << endl;
							break;
						}
					}
					if (back == true) { PrintReset(); continue; }  // 처음으로 돌아가기
					if (!found) { PrintError(); continue; }
				}
			}
			// 디저트 주문
			else if (oreder == "2") {
				dessert.Print();
				string menu;
				bool found = false;
				// 디저트 메뉴 선택
				SelectMenu(dessert.menu, menu);

				if (menu == "0") back = true;  // 처음으로 돌아가기

				Cafe sub = dessert.menu[0];
				for (auto& a : dessert.menu) {
					if (a.GetName() == menu) {
						sub = a;

						string taste;  // 서브 메뉴 존재 시
						if (!sub.GetSubMenu().empty()) {
							cout << endl;
							sub.PrintSub();
							// 서브 메뉴(맛) 선택
							SelectTaste(sub, taste);

							if (taste == "0") back = true;   // 처음으로 돌아가기

							for (auto& s : sub.GetSubMenu()) {
								if (s == taste) {
									FinalOrder a(menu, taste, sub.GetPrice());  // (서브 메뉴가 존재할 때) 주문 목록에 저장
									basket.push_back(a);
									cout << endl << " ** ";
									a.PrintFinal();
									found = true;
									break;
								}
							}
						}
						else {
							FinalOrder b(menu, sub.GetPrice());  // (서브 메뉴가 없을 때) 주문 목록에 저장
							basket.push_back(b);
							cout << endl << " ** ";
							b.PrintFinal();
							found = true;
						}
						cout << "을 구매 예정 목록에 담았습니다." << endl;
						break;
					}
				}
				if (back == true) { PrintReset(); continue; }  // 처음으로 돌아가기
				if (!found) { PrintError(); continue; }  // 처음으로 돌아가기
			}
			else { PrintReset(); continue; }   // oreder == "3"일 때 처음으로 돌아가기
		}
		// 주문 목록
		else if (choice == "3") {
			string orderList;
			SelectOrderList(orderList);

			if (orderList == "1") {  // 주문 목록 삭제
				PrintOrderList(basket);
				if (basket.empty()) {
					cout << endl << "현재 삭제할 수 있는 목록이 없습니다." << endl;
					 continue;
				}
				else DeleteOrderList(basket);
			}
			else if (orderList == "2") {  // 현재 주문 목록 출력
				PrintOrderList(basket);
			}
			else { PrintReset(); continue; }  //orderList == "3"일 때 처음으로 돌아가기
		}
		// 결제
		else if (choice == "4") {
			double sum = 0;  // 결제 금액

			for (auto& a : basket) {
				sum += a.GetPrice();
			}

			if (sum == 0) {  // 주문 목록이 비어있을 때, 결제 취소 & 처음으로 돌아감
				cout << endl;
				cout << "주문 목록이 비어있습니다." << endl;
				continue;
			}
			else {  // 주문 목록이 비어있지 않을 때

				PrintOrderList(basket);  // 현재 주문 목록을 출력

				cout << endl;
				cout << "현재 결제 금액은 총 " << sum << "원 입니다." << endl;
				
				string pay_ok;  // 결제 여부
				SelectYes_No(pay_ok);   // 결제 여부를 물어봄
				if (pay_ok == "아니요") { PrintReset(); continue; }  // 결제 취소 시 처음으로 돌아감
				else {  // 결제 진행
					while (1) {
						bool take_select = false;  // take_select == true가 되면 take out 여부 다시 선택
						string take;  // take out 할 건지 or take in 할 건지
						string pay_method;  // 지불 수단
						SelectTake_out_In(take);  // take out 여부 결정

						if (take == "2") {  // take out 할 때
							sum *= 0.95;  // 최종 금액의 5% 할인
							cout << endl << "Take Out 할인으로 현재 결제 예정 금액은 " << sum << "원 입니다. " << endl;
							SelectPayMethod(pay_method, basket);  // 결제 수단 선택

							if (pay_method == "6") back = true;  // 결제 취소시 처음으로 돌아감
							break;
						}
						else {  // take in 할 때 
							string floor;  // 선택한 층을 저장할 변수
							string seat;   // 선택한 좌석을 저장할 변수
							Floor* currentFloor = &f1;
							while (1) {
								SelectFloor(floor);  // 층 선택
								if (floor == "0") {   // take out 여부를 다시 선택
									take_select = true;
									break; 
								}
								else if (floor == "1") currentFloor = &f1;
								else currentFloor = &f2;

								currentFloor->PrintFloor();   // 선택한 층의 좌석 출력

								SelectSeat(floor, seat, currentFloor);  // 앉을 좌석 선택
								if (seat == "0") continue;  // 층 선택으로 돌아감
								else {
									currentFloor->SelectSeats(seat);   // 선택한 좌석 변경 "□"->"■"
									AddSeat(floor, seat);  // 선택한 좌석 txt 파일에 추가

									currentFloor->PrintFloor();  // 선택된 좌석이 변경된 (해당 층의) 전체 좌석 출력
									cout << endl << " ~~ " << floor << "층의 " << seat << " 좌석이 선택되었습니다." << endl;
									
									SelectPayMethod(pay_method, basket);  // 결제 수단 선택
									
									if (pay_method == "6") {  // 결제 취소

										set<string> list;  // txt 파일에 적힌 좌석 리스트(예정)
										set<string> updateList;  // 위에서 선택한 좌석을 제외한 좌석 리스트(예정)
										CheckSeats(floor, seat, list);  // txt 파일에서 좌석을 읽어와서 list에 저장

										for (string s : list) {  // 위에서 선택한 좌석을 제외한 list를 updateList에 저장
											if (s == seat);
											else updateList.insert(s);
										}

										currentFloor->ResetSeats(seat);  // 위에서 선택한 좌석 다시 변경 "■"->"□"

										UpdateExitSeat(floor, updateList, f1, f2);   // 선택된 좌석이 제거된 리스트를 다시 txt 파일에 저장(덮어쓰기)
										back = true;  // 처음으로 돌아감
										break;
									}
									else break;
								}
							}
							if (take_select == true) continue;   // take out 여부 선택으로 돌아감
							else break;
						}
					}
					if (back == true) {  // 처음으로 돌아감
						continue;
					}
					break;
				}
				
			}
		}
		// 현재 카페 내 좌석(여석) 출력
		else if (choice == "5") {
			f1.PrintFloor();
			cout << endl;
			f2.PrintFloor();
		}
		// 퇴실
		else if (choice == "6") {
			Floor1 f3; Floor2 f4;
			set<string> seatList;   // 사용중인 좌석들 리스트(예정)
			set<string> selectedSeats;   // 사용중인 좌석들에서 퇴석할 좌석을 제외한 리스트(예정)

			Floor* current_exitFloor = &f3;

			SelectedSeatUpdate(f3, f4);  // 선택된 좌석의 이름이 보이도록 업데이트
			while (1) {
				string exit_floor;  // 퇴석할 좌석의 층
				SelectExitFloor(exit_floor);  // 퇴석할 좌석의 층 선택

				if (exit_floor == "0") {  // 퇴실 취소, 처음으로 돌아감
					cout << endl << "퇴실을 취소합니다.";
					PrintReset(); back = true;
					break;
				}
				else if (exit_floor == "1") current_exitFloor = &f3;
				else current_exitFloor = &f4;

				current_exitFloor->PrintFloor();

				string exit_seat;  // 퇴석할 좌석
				SelectExitSeats(exit_floor, exit_seat, seatList);  // 퇴석할 좌석 선택, 현재 사용중인 좌석들 리스트 seatList에 저장

				if (exit_seat == "0") continue;  // 퇴석할 좌석의 층 선택으로 돌아감
				else {
					for (string s : seatList) {  // 퇴석할 좌석을 제외한 사용중인 좌석들 리스트 selectedSeats에 저장
						if (s == exit_seat);
						else selectedSeats.insert(s);
					}
				}
				current_exitFloor->ResetSeats(exit_seat);  // 퇴석할 좌석을 빈 좌석으로 업데이트 "■"->"□"

				UpdateExitSeat(exit_floor, selectedSeats, f3, f4);   // 퇴석할 좌석이 제거된 리스트를 다시 txt 파일에 저장(덮어쓰기)
				PrintExit(exit_floor, exit_seat);   // 퇴석할 층, 좌석, 감사의 인사말 출력
				break;
			}
			if (back == true) continue;  // 처음으로 돌아감
			else break;  // 종료
		}
		// choice == "7" 종료
		else {  
			cout << endl << "종료합니다. 다음에 또 찾아와 주세요. :D" << endl;
			break;
		}
	}
	return 0;
}


// 기능 1
// try-catch문을 이용한 입력 에러 체크
void CheckInput(vector<string> v, string input) {
	int count = 0;
	for (string& s : v) {
		if (s == input) count++;
	}
	if (count == 0) {
		throw exception("잘못된 입력입니다. 양식에 맞게 다시 입력해주세요.");
	}
}

// 잘못 입력 시 출력
void PrintError() {
	cout << endl << "잘못된 입력입니다. 양식에 맞게 다시 입력해주세요." << endl;
}

// 처음으로 돌아갈 시 출력
void PrintReset() {
	cout << endl << "처음 화면으로 돌아갑니다." << endl;
}

// 전체 메뉴 출력
void TotalMenuPrint() {
	coffee.Print();
	non_coffee.Print();
	tea.Print();
	smoothie.Print();
	frappe.Print();
	ade.Print();
	dessert.Print();
}

// 메뉴 선택
void SelectMenu(vector<Cafe> c, string& menu) {
	cout << "원하는 메뉴를 선택하시오 (문자를 입력하시오. 띄어쓰기 없이)" << endl;
	cout << "(0을 입력하면 처음으로 돌아갑니다)" << endl;
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

// 서브 메뉴(맛) 존재 시 선택
void SelectTaste(Cafe& c, string& taste) {
	cout << "해당 메뉴에서 원하는 맛을 선택하시오 (문자를 입력하시오)" << endl;
	cout << "(0을 입력하면 처음으로 돌아갑니다)" << endl;
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

// 음료의 Ice/Hot 선택
void SelectIceHot(int currentMenu, string& ice_hot) {
	if (currentMenu == 0 || currentMenu == 1 || currentMenu == 2) {
		cout << endl << "ICE / HOT 중 하나를 선택하시오. (대문자로 입력하시오)" << endl;
		cout << "(0을 입력하면 처음으로 돌아갑니다)" << endl;
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

// 음료의 토핑 선택
void SelectToppings(vector<string>& toppings, FinalOrder& f) {
	map<string, pair<string, int>> options = {
	   {"1", {"Size UP", 800}},
	   {"2", {"샷 추가", 500}},
	   {"3", {"휘핑크림 추가", 300}},
	   {"4", {"바닐라시럽 추가", 300}},
	   {"5", {"펄 추가", 500}}
	};
	cout << endl << "원하는 추가 옵션을 모두 입력하시오. (숫자를 입력하시오. 6을 입력하면 종료됩니다.)" << endl;
	cout << "1. Size UP(+800원)  2. 샷 추가(+500원)  3. 휘핑크림 추가(+300원)  4. 바닐라시럽 추가(+300원)  5. 펄 추가(+500원)  6. NO" << endl;
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
		cout << endl << "선택하신 옵션은 '";
		for (auto p = toppings.begin(); p != toppings.end(); ++p) {
			if (p == toppings.end() - 1) { cout << *p << "'"; }
			else cout << *p << ", ";
		}
		cout << "입니다." << endl;
	}
	else {
		cout << endl << "토핑을 추가하지 않았습니다." << endl;
	}
}

// 주문 목록을 볼지 삭제할지 선택
void SelectOrderList(string& orderList) {
	cout << endl << "(숫자를 입력하시오)" << endl;
	cout << "1. 주문 목록 삭제  2. 현재 주문 목록  3. 처음으로 돌아가기" << endl;
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

// 주문 목록 출력
void PrintOrderList(vector<FinalOrder>& basket) {
	cout << endl;
	int n = 0;
	cout << "현재 주문 목록" << endl;
	if (basket.empty()) {
		cout << " >> (없음)" << endl;
	}
	else {
		for (auto& e : basket) {
			cout << " >> " << ++n << ". ";
			e.PrintFinal();
			cout << endl;
		}
	}
}

// 주문 목록 삭제
void DeleteOrderList(vector<FinalOrder>& basket) {
	int del_Index;
	cout << endl << "몇 번째 목록을 삭제하시겠습니까?" << endl;
	cout << "(0을 입력하면 처음으로 돌아갑니다)" << endl;
	cout << " >> ";
	cin >> del_Index;

	if (del_Index == 0) {
		cout << endl << "주문 목록을 삭제하지 않고 처음으로 돌아갑니다." << endl; 
		return;
	}
	if (del_Index > basket.size() || del_Index < 0) {
		cout << endl << "잘못된 입력입니다. 삭제를 실패하였습니다." << endl;
		return;
	}
	else {
		cout << endl << " >> ";
		basket[del_Index - 1].PrintFinal();
		cout << "을 삭제합니다." << endl;
		basket.erase(basket.begin() + del_Index - 1);
	}
}

// 결제 여부
void SelectYes_No(string& yes_no) {
	cout << endl << "현재 주문 목록을 결제하시겠습니까? (네 / 아니요)" << endl;
	cout << " >> ";
	cin >> yes_no;

	if (yes_no != "네" && yes_no != "아니요") {
		PrintError();
		SelectYes_No(yes_no);
	}
}

// 매장 내 섭취 선택
void SelectTake_out_In(string& take) {
	cout << endl << "Take Out을 선택할 시, 구매하신 금액의 5%가 할인 됩니다." << endl;
	cout << "1. Take In  2. Take Out (숫자를 입력하시오)" << endl;
	cout << " >> ";
	cin >> take;

	if (take != "1" && take != "2") {
		PrintError();
		SelectTake_out_In(take);
	}
}

// 결제 수단
void SelectPayMethod(string& pay_method, vector<FinalOrder>& basket) {
	cout << endl << "결제 수단은 무엇으로 하시겠습니까? (숫자를 입력하시오)" << endl;
	cout << "1. 현금  2. 신용카드 / 체크카드  3. 카카오페이  4. 삼성페이  5. 애플페이  6. 결제 취소" << endl;
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
		cout << "결제를 취소합니다.";
		PrintReset();
		return;
	}
	else {
		string m;
		if (pay_method == "1") m = "현금";
		else if (pay_method == "2") m = "신용카드 / 체크카드";
		else if (pay_method == "3") m = "카카오페이";
		else if (pay_method == "4") m = "삼성페이";
		else  m = "애플페이";

		cout << "-- 주문 메뉴 --" << endl;
		PrintOrderList(basket);
		cout << endl << m << "(으)로 결제가 완료 되었습니다. 메뉴가 만들어질 때까지 잠시만 기다려 주세요. :)" << endl;
	}
}

// 기능 2
// 선택된 좌석 이름이 보이게 불러오기
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

// 선택된 좌석 불러오기 
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

// 입력한 좌석이 존재하는지 확인
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

// 퇴실시 출력
void PrintExit(string floor, string seat) {
	cout << endl << floor << "층의 " << seat << " 좌석에서 퇴석하겠습니다." << endl;
	cout << "저희 카페를 찾아와 주셔서 감사합니다. 안녕히 가세요." << endl;
}

// 매장 내 섭취시, 앉을 층 선택
void SelectFloor(string& floor) {
	cout << endl << "** 2층은 공부를 위한 장소로 다른 손님들에게 피해가 가지 않도록 조용히 해주세요 **" << endl;
	cout << endl << "1층, 2층 중 원하는 층을 선택하시오. (숫자를 입력하시오)" << endl;
	cout << "(Take Out을 원하는 경우, 0을 입력하시오. 다시 뒤로 돌아갑니다.)" << endl;
	cout << " >> ";
	cin >> floor;

	if (floor != "1" && floor != "2" && floor != "0") {
		cout << endl << "잘못된 입력입니다. 양식에 맞게 다시 입력해주세요." << endl;
		SelectFloor(floor);
	}
}

// 매장 내 섭취시, 앉을 좌석 선택
void SelectSeat(string floor, string& seat, Floor* currentFloor) {
	cout << endl << floor << "층에서 원하는 좌석을 입력해주세요. (대문자로 입력하시오)" << endl;
	cout << "(층을 바꾸고자 하는 경우 0을 입력하시오.)" << endl;
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
			cout << endl << "이미 선택된 좌석입니다. 다른 좌석을 선택해주세요." << endl;
		else
			cout << endl << "올바르지 않는 좌석 입력입니다. 다시 입력해주세요." << endl;
		SelectSeat(floor, seat, currentFloor);
	}
}

// 매장 내 섭취시, 앉을 좌석 txt파일에 추가
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

// 매장에서 퇴실할 시, 퇴석할 층 선택
void SelectExitFloor(string& floor) {
	cout << endl << "음료/디저트를 잘 즐기셨습니까? 앉았던 층수를 입력해 주세요. (숫자만 입력하시오)" << endl;
	cout << "(취소하고자 하는 경우 0을 입력하시오.)" << endl;
	cout << " >> ";
	cin >> floor;
	
	if (floor == "0") return;
	if (floor != "1" && floor != "2") {
		cout << endl << "잘못된 입력입니다. 다시 입력해 주세요." << endl;
		SelectExitFloor(floor);
	}

}

// 매장에서 퇴실할 시, 퇴석할 좌석 선택
void SelectExitSeats(string floor, string& seat, set<string>& seatList) {
	cout << endl << "앉았던 좌석을 입력해 주세요. (대문자로 입력하시오)" << endl;
	cout << "(층을 바꾸고자 하는 경우 0을 입력하시오.)" << endl;
	cout << " >> ";
	cin >> seat;

	bool check;
	if (seat == "0") return;

	check = CheckSeats(floor, seat, seatList);

	if (check == false) {
		cout << endl << seat << " 좌석에 대한 정보가 없습니다. 다시 입력해주세요." << endl;
		SelectExitSeats(floor, seat, seatList);
	}
}

// 매장에서 퇴실할 시, 퇴석할 좌석 txt파일에서 제거
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