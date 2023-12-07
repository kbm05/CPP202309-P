#include <iostream>
#include <vector>
using namespace std;

void PrintSeats(int i, int k) {
    if (i % 3 == 0) {
        for (int j = 0; j < k; j++) {
            cout << "  бр бр  ";
        }
    }
    else if (i % 3 == 1) {
        for (int j = 0; j < k; j++) {
            cout << "   бр  ";
        }
    }
    else {
        for (int j = 0; j < k; j++) {
            cout << " бр бр бр  ";
        }
    }
    cout << endl;
}

int main() {
    vector<vector<string>> floor1 = { { "A", "B", "C", "D", "E" }, { "F", "G", "H", "I", "J", "K" }, { "L", "M", "N", "O" },
                                        { "P", "Q", "R", "S", "T" }, { "U", "V", "W", "X", "Y", "Z" } };

    cout << "  <1├■>  " << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < floor1.size(); ++i) {
        cout << endl;
        if (i % 3 == 0) {
            PrintSeats(i, floor1[i].size());
            for (int j = 0; j < floor1[i].size(); ++j) {
                cout << " [  " << floor1[i][j] << "  ] ";
            }
            cout << endl;
            PrintSeats(i, floor1[i].size());
        }
        else if (i % 3 == 1) {
            cout << " ";
            PrintSeats(i, floor1[i].size());
            cout << " ";
            for (int j = 0; j < floor1[i].size(); ++j) {
                cout << " [ " << floor1[i][j] << " ] ";
            }
            cout << endl;
            PrintSeats(i, floor1[i].size());
        }
        else {
            cout << " ";
            PrintSeats(i, floor1[i].size());
            for (int j = 0; j < floor1[i].size(); ++j) {
                cout << " [   " << floor1[i][j] << "   ] ";
            }
            cout << endl;
            PrintSeats(i, floor1[i].size());
        }
    }
    cout << endl << endl;

    cout << "  <2├■>  -Study Only-  " << endl;
    cout << "---------------------------------------------------------------" << endl;
    string floor2[7][7];
    char eng = 'A';
    for (int i = 0; i < 7; i++) {
        char num = '1';
        for (int j = 0; j < 7; j++) {
            floor2[i][j] += eng;
            floor2[i][j] += num;
            num++;
        }
        eng++;
    }

    for (int j = 0; j < 7; j++) {
        cout << endl;
        for (int i = 0; i < 7; i++) {
            if (i == 3) {
                cout << "|      |";
            }
            cout << " [ " << floor2[i][j] << " ] ";
        }
        cout << endl;
        cout << "   бр      бр      бр   |      |   бр      бр      бр      бр   " << endl;
    }

    return 0;   
}