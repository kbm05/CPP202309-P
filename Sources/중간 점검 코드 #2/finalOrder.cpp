#include "FinalOrder.h"


FinalOrder::FinalOrder(string c, string m, string s, string i_h, int p) {
	if (c == "1") { category = "Ŀ��"; }
	else if (c == "2") { category = "��Ŀ��"; }
	else if (c == "3") { category = "Ƽ"; }
	else if (c == "4") { category = "������"; }
	else if (c == "5") { category = "�ĸ���"; }
	else if (c == "6") { category = "���̵�"; }
	menu = m;
	sub = s;
	temp = i_h;
	price = p;
}

FinalOrder::FinalOrder(string c, string m, string i_h, int p) {
	if (c == "1") { category = "Ŀ��"; }
	else if (c == "2") { category = "��Ŀ��"; }
	else if (c == "3") { category = "Ƽ"; }
	else if (c == "4") { category = "������"; }
	else if (c == "5") { category = "�ĸ���"; }
	else if (c == "6") { category = "���̵�"; }
	menu = m;
	temp = i_h;
	price = p;
}

FinalOrder::FinalOrder(string m, string s, int p) {
	category = "����Ʈ";
	menu = m;
	sub = s;
	price = p;
}

FinalOrder::FinalOrder(string m, int p) {
	category = "����Ʈ";
	menu = m;
	price = p;
}

int FinalOrder::GetPrice() { return price; }

void FinalOrder::IncreasePrice(int increase) {
	price += increase;
}

void FinalOrder::SetTopping(vector<string>& t) {
	topping = t;
}

void FinalOrder::PrintTopping() {
	if (!topping.empty()) {
		cout << " (";
		for (auto p = topping.begin(); p != topping.end(); ++p) {
			if (p == topping.end() - 1) { cout << *p << ")"; }
			else cout << *p << "/";
		}
	}
}

string FinalOrder::PrintTemp() {
	if (temp == "ICE" || temp == "HOT") {
		return "(" + temp + ")";
	}
	else return "";
}

void FinalOrder::PrintFinal() {
	if (sub == "") {
		cout << category << " - " << menu << PrintTemp() << " - " << price << "��";
		PrintTopping();
	}
	else {
		cout << category << " - " << menu << " - " << sub << PrintTemp() << " - " << price << "��";
		PrintTopping();
	}
}
