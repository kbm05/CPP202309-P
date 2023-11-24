#include <iostream>
using namespace std;

class FinalOrder {
private:
	string category;
	string menu;
	string sub = "";
	int price;
public:
	FinalOrder(int c, string m, string s, int p);
	FinalOrder(int c, string m, int p);
	FinalOrder(string m, string s, int p);
	FinalOrder(string m, int p);
	int GetPrice();
	void PrintFinal();
};