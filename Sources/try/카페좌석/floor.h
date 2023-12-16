#ifndef FLOOR_H
#define FLOOR_H

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Floor {
public:
    virtual void PrintSeats(string line);
    virtual void PrintSeats(string line, int space);
    virtual void PrintNaming(string line);
    virtual void PrintFloor();
    virtual bool CheckSeats(string seatSelect);
    virtual bool CheckSelected(string seatSelect);
    virtual void SelectSeats(string seatSelect);
    virtual void ExitSeats(string seatSelect);
    virtual void ResetSeats(string seatSelect);
};

#endif // FLOOR_H