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
		cout << setw(18) << menu << setw(10) << price << "��";
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
	
	// Ŀ��
	vector<Cafe> coffee{ Cafe("����������", 2500), Cafe("�Ƹ޸�ī��", 2500),
					Cafe("īǪġ��", 3000), Cafe("ī���", 3000), Cafe("������Ӷ�", 3500),
					Cafe("�ٴҶ��", 3500), Cafe("ī��Ḷ���ƶ�", 3500), 
					Cafe("ī���ī", 3500), Cafe("��ü��", 3700) };

	cout << setw(27) << "<< COFFEE >>\n";
	Print(coffee);

	// non Ŀ��
	vector<Cafe> non_coffee{ Cafe("���", 3300), Cafe("������", 3500), Cafe("�����", 3500),
							Cafe("���ڶ�", 3500), Cafe("�׸�Ƽ��", 3500), Cafe("��Ʈ���ڶ�", 3500) };

	cout << setw(29) << "<< NON COFFEE >>\n";
	Print(non_coffee);

	// ��(tea)
	vector<Cafe> tea{ Cafe("���Ƽ", 2500), Cafe("ȫ��", 2500),
					Cafe("������Ƽ", 3000), Cafe("��� ����Ƽ", 3500) };
	
	vector<string> herb{ "���۹�Ʈ", "ĳ����", "�����" };
	tea[0].SetSubMenu(herb);

	vector<string> black{ "����", "��׷���" };
	tea[1].SetSubMenu(black);

	vector<string> fruit{ "�ڸ�", "����", "����" };
	tea[3].SetSubMenu(fruit);

	cout << setw(26) << "<< TEA >>\n";
	Print(tea);

	// ������
	vector<Cafe> smoothie{ Cafe("������", 4000), Cafe("���Ʈ ������", 4300) };

	vector<string> plain{ "����", "����", "Ű��" };
	smoothie[0].SetSubMenu(plain);
	
	vector<string> yogurt{ "����", "����", "��纣��", "�÷���" };
	smoothie[1].SetSubMenu(yogurt);

	cout << setw(32) << "<< SMOOTHIE >> ONLY ICE\n";
	Print(smoothie);

	// ������
	vector<Cafe> frappe{ Cafe("�ڹ�Ĩ ������", 4500), Cafe("��Ű ������", 4500),
						Cafe("��Ʈ���� ������", 4500), Cafe("�׸�Ƽ ������", 4500) };

	cout << setw(31) << "<< FRAPPE >> ONLY ICE\n";
	Print(frappe);

	// ���̵�
	vector<Cafe> ade{ Cafe("�ڸ� ���̵�", 4000), Cafe("���� ���̵�", 4000), Cafe("���� ���̵�", 4000),
					 Cafe("û���� ���̵�", 4000), Cafe("�м��ĸ��� ���̵�", 4000) };

	cout << setw(30) << "<< ADE >> ONLY ICE\n";
	Print(ade);

	// ����Ʈ
	vector<Cafe> dessert{ Cafe("��Ű", 1500), Cafe("��ī��", 2000),
						Cafe("����", 2500), Cafe("����", 2500), Cafe("����", 3000),
						Cafe("ũ����", 3300), Cafe("���� ����", 4700) };

	cout << setw(27) << "<< DESSERT >>\n";
	Print(dessert);

	return 0;
}