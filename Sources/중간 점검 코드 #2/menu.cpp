#include "menu.h"

void PrintCategory(int s, string name, vector<Cafe>& c) {
	cout << setw(s) << "<< " << name << " >>";
	if (name == "SMOOTHIE" || name == "FRAPPE" || name == "ADE") {
		cout << " ICE ONLY";
	}
	cout << endl << "-----------------------------------";
	for (auto& a : c) {
		a.PrintMenu();
	}
	cout << endl << "-----------------------------------" << endl;
	cout << endl;
}


void Menu::Print() {
	PrintCategory(15, name, menu);
}

Coffee::Coffee() {
	name = "COFFEE";
	menu = { Cafe("에스프레소", 2500), Cafe("아메리카노", 2500),
			Cafe("카푸치노", 3000), Cafe("카페라떼", 3000), Cafe("헤이즐넛라떼", 3500),
			Cafe("바닐라라떼", 3500), Cafe("카라멜마끼아또", 3500),
			Cafe("카페모카", 3500), Cafe("돌체라떼", 3700) };
}
void Coffee::Print() {
	PrintCategory(17, name, menu);
}


NonCoffee::NonCoffee() {
	name = "NON_COFFEE";
	menu = { Cafe("곡물라떼", 3300), Cafe("고구마라떼", 3500), Cafe("딸기라떼", 3500),
			Cafe("초코라떼", 3500), Cafe("그린티라떼", 3500), Cafe("민트초코라떼", 3500) };
}
void NonCoffee::Print() {
	PrintCategory(15, name, menu);
}


Tea::Tea() {
	name = "TEA";
	menu = { Cafe("허브티", 2500), Cafe("홍차", 2500),
			Cafe("복숭아티", 3000), Cafe("허니과일티", 3500) };

	vector<string> herb{ "페퍼민트", "캐모마일", "로즈마리" };
	menu[0].SetSubMenu(herb);

	vector<string> black{ "다즐링", "얼그레이" };
	menu[1].SetSubMenu(black);

	vector<string> fruit{ "자몽", "레몬", "유자" };
	menu[3].SetSubMenu(fruit);
}
void Tea::Print() {
	PrintCategory(19, name, menu);
}


Smoothie::Smoothie() {
	name = "SMOOTHIE";
	menu = { Cafe("스무디", 4000), Cafe("요거트스무디", 4300) };
	
	vector<string> plain{ "딸기", "망고", "키위" };
	menu[0].SetSubMenu(plain);

	vector<string> yogurt{ "딸기", "망고", "블루베리", "플레인" };
	menu[1].SetSubMenu(yogurt);
}
void Smoothie::Print() {
	PrintCategory(11, name, menu);
}


Frappe::Frappe() {
	name = "FRAPPE";
	menu = { Cafe("자바칩프라페", 4500), Cafe("쿠키프라페", 4500),
			Cafe("민트초코프라페", 4500), Cafe("그린티프라페", 4500) };
}
void Frappe::Print() {
	PrintCategory(12, name, menu);
}


Ade::Ade() {
	name = "ADE";
	menu = { Cafe("자몽에이드", 4000), Cafe("레몬에이드", 4000), Cafe("유자에이드", 4000),
			 Cafe("청포도에이드", 4000), Cafe("패션후르츠에이드", 4000) };
}
void Ade::Print() {
	PrintCategory(13, name, menu);
}


Dessert::Dessert() {
	name = "DESSERT";
	menu = { Cafe("쿠키", 1500), Cafe("마카롱", 2000),
			Cafe("스콘", 2500), Cafe("머핀", 2500), Cafe("와플", 3000),
			Cafe("크로플", 3300), Cafe("조각케이크", 4700) };

	vector<string> macaron{ "초코", "바닐라", "쿠앤크", "녹차", "딸기", "카라멜" };
	menu[1].SetSubMenu(macaron);

	vector<string> cake{ "생크림", "초코", "치즈", "고구마", "티라미슈" };
	menu[6].SetSubMenu(cake);
}
void Dessert::Print() {
	PrintCategory(17, name, menu);
}