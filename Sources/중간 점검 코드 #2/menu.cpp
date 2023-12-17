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
	menu = { Cafe("����������", 2500), Cafe("�Ƹ޸�ī��", 2500),
			Cafe("īǪġ��", 3000), Cafe("ī���", 3000), Cafe("������Ӷ�", 3500),
			Cafe("�ٴҶ��", 3500), Cafe("ī��Ḷ���ƶ�", 3500),
			Cafe("ī���ī", 3500), Cafe("��ü��", 3700) };
}
void Coffee::Print() {
	PrintCategory(17, name, menu);
}


NonCoffee::NonCoffee() {
	name = "NON_COFFEE";
	menu = { Cafe("���", 3300), Cafe("������", 3500), Cafe("�����", 3500),
			Cafe("���ڶ�", 3500), Cafe("�׸�Ƽ��", 3500), Cafe("��Ʈ���ڶ�", 3500) };
}
void NonCoffee::Print() {
	PrintCategory(15, name, menu);
}


Tea::Tea() {
	name = "TEA";
	menu = { Cafe("���Ƽ", 2500), Cafe("ȫ��", 2500),
			Cafe("������Ƽ", 3000), Cafe("��ϰ���Ƽ", 3500) };

	vector<string> herb{ "���۹�Ʈ", "ĳ����", "�����" };
	menu[0].SetSubMenu(herb);

	vector<string> black{ "����", "��׷���" };
	menu[1].SetSubMenu(black);

	vector<string> fruit{ "�ڸ�", "����", "����" };
	menu[3].SetSubMenu(fruit);
}
void Tea::Print() {
	PrintCategory(19, name, menu);
}


Smoothie::Smoothie() {
	name = "SMOOTHIE";
	menu = { Cafe("������", 4000), Cafe("���Ʈ������", 4300) };
	
	vector<string> plain{ "����", "����", "Ű��" };
	menu[0].SetSubMenu(plain);

	vector<string> yogurt{ "����", "����", "��纣��", "�÷���" };
	menu[1].SetSubMenu(yogurt);
}
void Smoothie::Print() {
	PrintCategory(11, name, menu);
}


Frappe::Frappe() {
	name = "FRAPPE";
	menu = { Cafe("�ڹ�Ĩ������", 4500), Cafe("��Ű������", 4500),
			Cafe("��Ʈ����������", 4500), Cafe("�׸�Ƽ������", 4500) };
}
void Frappe::Print() {
	PrintCategory(12, name, menu);
}


Ade::Ade() {
	name = "ADE";
	menu = { Cafe("�ڸ����̵�", 4000), Cafe("�����̵�", 4000), Cafe("���ڿ��̵�", 4000),
			 Cafe("û�������̵�", 4000), Cafe("�м��ĸ������̵�", 4000) };
}
void Ade::Print() {
	PrintCategory(13, name, menu);
}


Dessert::Dessert() {
	name = "DESSERT";
	menu = { Cafe("��Ű", 1500), Cafe("��ī��", 2000),
			Cafe("����", 2500), Cafe("����", 2500), Cafe("����", 3000),
			Cafe("ũ����", 3300), Cafe("��������ũ", 4700) };

	vector<string> macaron{ "����", "�ٴҶ�", "���ũ", "����", "����", "ī���" };
	menu[1].SetSubMenu(macaron);

	vector<string> cake{ "��ũ��", "����", "ġ��", "����", "Ƽ��̽�" };
	menu[6].SetSubMenu(cake);
}
void Dessert::Print() {
	PrintCategory(17, name, menu);
}