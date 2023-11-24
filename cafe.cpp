#include "cafe.h"

Cafe::Cafe(string m, int p) {
	menu = m;
	price = p;
}

string Cafe::GetName() { return menu; }

int Cafe::GetPrice() { return price; }

void Cafe::SetSubMenu(vector<string>& v) {
	subMenu = v;
}

vector<string> Cafe::GetSubMenu() {
	return subMenu;
}

void Cafe::PrintMenu() {
	cout << endl;
	cout << setw(18) << menu << setw(10) << price << "¿ø";
	if (!subMenu.empty()) {
		cout << setw(5) << "(";
		for (auto p = subMenu.begin(); p != subMenu.end(); ++p) {
			if (p == subMenu.end() - 1) { cout << *p << ")"; }
			else cout << *p << "/";
		}
	}
}

void Cafe::PrintSub() {
	cout << " -> ";
	for (auto p = subMenu.begin(); p != subMenu.end(); ++p) {
		if (p == subMenu.end() - 1) { cout << " " << *p << endl; }
		else cout << " " << *p << " /";
	}
	cout << endl;
}