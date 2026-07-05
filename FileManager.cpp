// FileManager.cpp
// Najeeb Rafeeq

#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using std::string;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::getline;
using std::ofstream;

bool FileManager::loadStudents(const string& filename, StudentList& studentList) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error: Could not open student file \"" << filename << "\".\n";
        return false;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, name, major, gpaStr;

        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, major, ',');
        getline(ss, gpaStr, ',');

        // Crash Guard: skip this line instead of crashing if any info is missing or typo
        
        if (idStr.empty() || name.empty() || major.empty() || gpaStr.empty()) {
            cout << "Warning: Skipping malformed line in \"" << filename << "\".\n";
            continue;
        }

        int id = std::stoi(idStr);
        float gpa = std::stof(gpaStr);

        studentList.addStudent(id, name, major, gpa);
    }

    file.close();
    return true;
}
bool FileManager::loadCampusMap(const string& filename, CampusMap& campusMap) {
    return campusMap.loadFromFile(filename);
       
}

bool FileManager::saveStudents(const string& filename, const StudentList& studentList) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open student file \"" << filename << "\" for writing.\n";
        return false;
    }
    Node* current = studentList.getHead();
    while (current != nullptr) {
        file << current->data.id << ","
             << current->data.name << ","
             << current->data.major << ","
             << current->data.gpa << "\n";
        current = current->next;
    }
    file.close();
    return true;
}
