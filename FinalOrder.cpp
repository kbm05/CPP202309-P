#include "FinalOrder.h"


FinalOrder::FinalOrder(int c, string m, string s, int p) {
	if (c == 1) { category = "커피"; }
	else if (c == 2) { category = "논커피"; }
	else if (c == 3) { category = "티"; }
	else if (c == 4) { category = "스무디"; }
	else if (c == 5) { category = "파르페"; }
	else if (c == 6) { category = "에이드"; }
	menu = m;
	sub = s;
	price = p;
}

FinalOrder::FinalOrder(int c, string m, int p) {
	if (c == 1) { category = "커피"; }
	else if (c == 2) { category = "논커피"; }
	else if (c == 3) { category = "티"; }
	else if (c == 4) { category = "스무디"; }
	else if (c == 5) { category = "파르페"; }
	else if (c == 6) { category = "에이드"; }
	menu = m;
	price = p;
}

FinalOrder::FinalOrder(string m, string s, int p) {
	category = "디저트";
	menu = m;
	sub = s;
	price = p;
}

FinalOrder::FinalOrder(string m, int p) {
	category = "디저트";
	menu = m;
	price = p;
}

int FinalOrder::GetPrice() { return price; }

void FinalOrder::PrintFinal() {
	if (sub == "") {
		cout << category << " - " << menu << " - " << price << "원";
	}
	else {
		cout << category << " - " << menu << " - " << sub << " - " << price << "원";
	}
}
