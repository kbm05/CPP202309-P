#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Cafe {
private:
	string menu;
	int price;
	vector<string> subMenu;
public:
	Cafe(string m, int p);
	string GetName();
	int GetPrice();
	void SetSubMenu(vector<string>& v);
	vector<string> GetSubMenu();
	void PrintMenu();
	void PrintSub();
};
