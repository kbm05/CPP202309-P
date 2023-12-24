#ifndef MENU_H
#define MENU_H

#include "cafe.h"

class Menu {
public:
	string name;
	vector<Cafe> menu;
	virtual void Print();
};

class Coffee :public Menu {
public:
	Coffee();
	void Print() override;
};

class NonCoffee :public Menu {
public:
	NonCoffee();
	void Print() override;
};

class Tea :public Menu {
public:
	Tea();
	void Print() override;
};

class Smoothie :public Menu {
public:
	Smoothie();
	void Print() override;
};

class Frappe :public Menu {
public:
	Frappe();
	void Print() override;
};

class Ade :public Menu {
public:
	Ade();
	void Print() override;
};

class Dessert :public Menu {
public:
	Dessert();
	void Print() override;
};

#endif // MENU_H