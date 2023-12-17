#ifndef FINALORDER_H
#define FINALORDER_H

#include <iostream>
#include <vector>
using namespace std;

class FinalOrder {
private:
	string category;
	string menu;
	string sub = "";
	int price;
	string temp;
	vector<string> topping;
public:
	FinalOrder(string c, string m, string s, string i_h, int p);
	FinalOrder(string c, string m, string i_h, int p);
	FinalOrder(string m, string s, int p);
	FinalOrder(string m, int p);
	int GetPrice();
	void IncreasePrice(int increase);
	void SetTopping(vector<string>& t);
	void PrintTopping();
	string PrintTemp();
	void PrintFinal();
};

#endif