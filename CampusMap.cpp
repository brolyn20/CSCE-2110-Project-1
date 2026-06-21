#include <iostream>
#include <fstream>
#include <sstream>
#include "CampusMap.h"

using namespace std;

CampusMap::CampusMap() {
    numRows = 0;
    numCols = 0;
}

bool CampusMap::loadFromFile(const string& fileName) {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << "Error: could not open file " << fileName << endl;
        return false;
    }

    inputFile >> numRows >> numCols;

    if (numRows <= 0 || numCols <= 0) {
        cout << "Error: invalid map size in file." << endl;
        return false;
    }

    grid.resize(numRows);
    for (int i = 0; i < numRows; i++) {
        grid[i].resize(numCols);
    }

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            char symbol;
            inputFile >> symbol;
            grid[row][col] = symbol;
        }
    }

    inputFile.close();
    return true;
}

void CampusMap::displayMap() const {
    cout << "\nCampus Map:\n";

    cout << "    ";
    for (int col = 0; col < numCols; col++) {
        cout << col << "  ";
    }
    cout << endl;

    for (int row = 0; row < numRows; row++) {
        cout << row << " | ";
        for (int col = 0; col < numCols; col++) {
            cout << grid[row][col] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

bool CampusMap::isValidLocation(int row, int col) const {
    if (row < 0 || row >= numRows) {
        return false;
    }
    if (col < 0 || col >= numCols) {
        return false;
    }
    return true;
}

char CampusMap::getSymbol(int row, int col) const {
    return grid[row][col];
}

string CampusMap::getLocationName(char symbol) const {
    if (symbol == 'R') {
        return "Road";
    } else if (symbol == 'B') {
        return "Building";
    } else if (symbol == 'C') {
        return "Classroom";
    } else if (symbol == 'L') {
        return "Library";
    } else if (symbol == 'P') {
        return "Parking Lot";
    } else if (symbol == 'X') {
        return "Blocked Area";
    } else {
        return "Unknown";
    }
}

bool CampusMap::isBlocked(int row, int col) const {
    if (!isValidLocation(row, col)) {
        return true;
    }
    return grid[row][col] == 'X';
}

void CampusMap::showNeighbors(int row, int col) const {
    cout << "Neighboring Locations:" << endl;

    cout << "Up: ";
    if (isValidLocation(row - 1, col)) {
        cout << getLocationName(getSymbol(row - 1, col)) << endl;
    } else {
        cout << "None" << endl;
    }

    cout << "Down: ";
    if (isValidLocation(row + 1, col)) {
        cout << getLocationName(getSymbol(row + 1, col)) << endl;
    } else {
        cout << "None" << endl;
    }

    cout << "Left: ";
    if (isValidLocation(row, col - 1)) {
        cout << getLocationName(getSymbol(row, col - 1)) << endl;
    } else {
        cout << "None" << endl;
    }

    cout << "Right: ";
    if (isValidLocation(row, col + 1)) {
        cout << getLocationName(getSymbol(row, col + 1)) << endl;
    } else {
        cout << "None" << endl;
    }
}

int CampusMap::countSymbol(char symbol) const {
    int count = 0;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (grid[row][col] == symbol) {
                count++;
            }
        }
    }
    return count;
}

void CampusMap::displaySummaryCounts() const {
    cout << "\nCampus Map Summary:" << endl;
    cout << "Roads: " << countSymbol('R') << endl;
    cout << "Buildings: " << countSymbol('B') << endl;
    cout << "Classrooms: " << countSymbol('C') << endl;
    cout << "Libraries: " << countSymbol('L') << endl;
    cout << "Parking Lots: " << countSymbol('P') << endl;
    cout << "Blocked Areas: " << countSymbol('X') << endl;
}

int CampusMap::getRows() const {
    return numRows;
}

int CampusMap::getCols() const {
    return numCols;
}
