#ifndef FLOOR_1_H
#define FLOOR_1_H

#include "floor.h"

class Floor1 :public Floor {
private:
	string floor1[26][4];
public:
	Floor1();
	void PrintSeats(string line) override;
	void PrintSeats(string line, int space) override;
	void PrintNaming(string line) override;
	void PrintFloor() override;
	bool CheckSeats(string seatSelect) override;
	bool CheckSelected(string seatSelect) override;
	void SelectSeats(string seatSelect) override;
	void ExitSeats(string seatSelect) override;
	void ResetSeats(string seatSelect) override;
};

#endif // FLOOR_1_H