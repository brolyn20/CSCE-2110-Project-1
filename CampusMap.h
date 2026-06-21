
#ifndef CAMPUSMAP_H
#define CAMPUSMAP_H

#include <string>
#include <vector>

using namespace std;

class CampusMap {
private:
    int numRows;
    int numCols;
    vector<vector<char>> grid;

public:
    CampusMap();

    bool loadFromFile(const string& fileName);
    void displayMap() const;
    bool isValidLocation(int row, int col) const;
    char getSymbol(int row, int col) const;
    string getLocationName(char symbol) const;
    bool isBlocked(int row, int col) const;
    void showNeighbors(int row, int col) const;
    int countSymbol(char symbol) const;
    void displaySummaryCounts() const;

    int getRows() const;
    int getCols() const;
};

#endif
