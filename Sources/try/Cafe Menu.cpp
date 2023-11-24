#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Cafe {
private:
	string menu;
	int price;
	vector<string> subMenu{""};
public:
	Cafe(string m, int p) {
		menu = m;
		price = p;
	}
	void PrintMenu() {
		cout << endl;
		cout << setw(18) << menu << setw(10) << price << "원";
	}
	string GetName() {
		return menu;
	}
	void SetSubMenu(vector<string> v) {
		subMenu.pop_back();
		for (auto& e:v){
			subMenu.push_back(e);
		}
	}
	auto GetSubMenu() {
		return subMenu[0];
	}
	void PrintSubMenu() {
		cout << setw(5) << "(";
		for (auto p = subMenu.begin(); p != subMenu.end(); ++p) {
			if (p == subMenu.end() - 1) { cout << *p << ")"; }
			else cout << *p << "/";
		}
	}
};

void Print(vector<Cafe> v) {
	cout << "-----------------------------------";
	for (auto& e : v) {
		e.PrintMenu();
		if(e.GetSubMenu() != "")	e.PrintSubMenu();
	}
	cout << endl;
	cout << "-----------------------------------" << endl;
	cout << endl;
}

int main() {
	
	// 커피
	vector<Cafe> coffee{ Cafe("에스프레소", 2500), Cafe("아메리카노", 2500),
					Cafe("카푸치노", 3000), Cafe("카페라떼", 3000), Cafe("헤이즐넛라떼", 3500),
					Cafe("바닐라라떼", 3500), Cafe("카라멜마끼아또", 3500), 
					Cafe("카페모카", 3500), Cafe("돌체라떼", 3700) };

	cout << setw(27) << "<< COFFEE >>\n";
	Print(coffee);

	// non 커피
	vector<Cafe> non_coffee{ Cafe("곡물라떼", 3300), Cafe("고구마라떼", 3500), Cafe("딸기라떼", 3500),
							Cafe("초코라떼", 3500), Cafe("그린티라떼", 3500), Cafe("민트초코라떼", 3500) };

	cout << setw(29) << "<< NON COFFEE >>\n";
	Print(non_coffee);

	// 차(tea)
	vector<Cafe> tea{ Cafe("허브티", 2500), Cafe("홍차", 2500),
					Cafe("복숭아티", 3000), Cafe("허니 과일티", 3500) };
	
	vector<string> herb{ "페퍼민트", "캐모마일", "로즈마리" };
	tea[0].SetSubMenu(herb);

	vector<string> black{ "다즐링", "얼그레이" };
	tea[1].SetSubMenu(black);

	vector<string> fruit{ "자몽", "레몬", "유자" };
	tea[3].SetSubMenu(fruit);

	cout << setw(26) << "<< TEA >>\n";
	Print(tea);

	// 스무디
	vector<Cafe> smoothie{ Cafe("스무디", 4000), Cafe("요거트 스무디", 4300) };

	vector<string> plain{ "딸기", "망고", "키위" };
	smoothie[0].SetSubMenu(plain);
	
	vector<string> yogurt{ "딸기", "망고", "블루베리", "플레인" };
	smoothie[1].SetSubMenu(yogurt);

	cout << setw(32) << "<< SMOOTHIE >> ONLY ICE\n";
	Print(smoothie);

	// 프라페
	vector<Cafe> frappe{ Cafe("자바칩 프라페", 4500), Cafe("쿠키 프라페", 4500),
						Cafe("민트초코 프라페", 4500), Cafe("그린티 프라페", 4500) };

	cout << setw(31) << "<< FRAPPE >> ONLY ICE\n";
	Print(frappe);

	// 에이드
	vector<Cafe> ade{ Cafe("자몽 에이드", 4000), Cafe("레몬 에이드", 4000), Cafe("유자 에이드", 4000),
					 Cafe("청포도 에이드", 4000), Cafe("패션후르츠 에이드", 4000) };

	cout << setw(30) << "<< ADE >> ONLY ICE\n";
	Print(ade);

	// 디저트
	vector<Cafe> dessert{ Cafe("쿠키", 1500), Cafe("마카롱", 2000),
						Cafe("스콘", 2500), Cafe("머핀", 2500), Cafe("와플", 3000),
						Cafe("크로플", 3300), Cafe("조각 케익", 4700) };

	cout << setw(27) << "<< DESSERT >>\n";
	Print(dessert);

	return 0;
}