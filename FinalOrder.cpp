#include "FinalOrder.h"


FinalOrder::FinalOrder(int c, string m, string s, int p) {
	if (c == 1) { category = "Ŀ��"; }
	else if (c == 2) { category = "��Ŀ��"; }
	else if (c == 3) { category = "Ƽ"; }
	else if (c == 4) { category = "������"; }
	else if (c == 5) { category = "�ĸ���"; }
	else if (c == 6) { category = "���̵�"; }
	menu = m;
	sub = s;
	price = p;
}

FinalOrder::FinalOrder(int c, string m, int p) {
	if (c == 1) { category = "Ŀ��"; }
	else if (c == 2) { category = "��Ŀ��"; }
	else if (c == 3) { category = "Ƽ"; }
	else if (c == 4) { category = "������"; }
	else if (c == 5) { category = "�ĸ���"; }
	else if (c == 6) { category = "���̵�"; }
	menu = m;
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

void FinalOrder::PrintFinal() {
	if (sub == "") {
		cout << category << " - " << menu << " - " << price << "��";
	}
	else {
		cout << category << " - " << menu << " - " << sub << " - " << price << "��";
	}
}
