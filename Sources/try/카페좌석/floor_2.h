#ifndef FLOOR_2_H
#define FLOOR_2_H

#include "floor.h"

class Floor2 :public Floor {
private:
	string floor2_seats[7][7];
	string floor2[49][4];
public:
	Floor2();
	void PrintSeats(string line) override;
	void PrintNaming(string line) override;
	void PrintFloor() override;
	bool CheckSeats(string seatSelect) override;
	bool CheckSelected(string seatSelect) override;
	void SelectSeats(string seatSelect) override;
	void ExitSeats(string seatSelect) override;
	void ResetSeats(string seatSelect) override;
};

#endif // FLOOR_2_H