//main
#include <iostream>
#include <string>
#include <limits>
#include <map> //to use map
#include <iostream> // I/O: cin, cout, endl
#include <vector> // container
#include <algorithm> // sorting
#include <iostream> // for input output
#include <cmath> // for math
#include<cstring>// for c-strings
#include <cstdlib> // for random , rand function
#include <stdio.h>  // for printf  printf(“format string”, parameters)
#include <ctime> // for random
#include <cassert> // for testing
#include <iomanip>
#include <sstream> // for stringstream
#include <fstream> //for file reading
#include <vector> // container
#include <algorithm> // sorting
#include <queue>        //Yes I am aware most of these might be unnessary but I'll clear them out after checkpoint one once we have a working model so I can truly Determin what is and isn't needed -ZDS
// Include project modules
#include "QueueSystem.h"
using namespace std;
#include "CampusMap.h"   // Emilio do this
#include "StudentList.h"
#include "FileManager.h"

void displayMenu();
int main() {
    QueueSystem advisingOffice;
    StudentList studentList; // declaring student list, won't commpile otherwise(brolyn)
    string mapFilename;
    string studentFilename;

    cout << "=========================================================\n";
    cout << "  Campus Exploration and Student Resource Management     \n";
    cout << "=========================================================\n\n";

    // mapFilename = ""; this stays
    //campusMap.loadFromFile(mapFilename);
    // TODO: Call  CampusMap loading function here:
    // studentFilename = ""; and this
    // studentList.loadFromFile(studentFilename);
    // TODO: Call your StudentList loading function here:
    // Najeeb do this
    studentFilename = "students.txt";
    FileManager:: loadStudents(studentFilename, studentList);

    int choice = 0;
    while (choice != 10) {
        displayMenu();
        cout << "Enter your choice (1-10): ";
        
        // Input validation loop to prevent infinite loops on non-integer inputs
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1://Emilio do this
                cout << "\n[Feature] Displaying Campus Map...\n";
                campusMap.displayMap();
                break;
            
            case 2: {//Emilio do this
                cout << "\n[Feature] Exploring Location Coordinates...\n";

                int row, col;
                cout << "Enter row and column: ";
                if (!(cin >> row >> col)) {
                    cout << "Invalid coordinates. Returning to menu.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (!campusMap.isValidLocation(row, col)) {
                    cout << "Those coordinates are outside the map. ";
                    cout << "Rows go from 0 to " << campusMap.getRows() - 1;
                    cout << " and columns go from 0 to " << campusMap.getCols() - 1 << "\n";
                    break;
                }

                char symbol = campusMap.getSymbol(row, col);
                cout << "Location Type: " << campusMap.getLocationName(symbol) << "\n";

                if (campusMap.isBlocked(row, col)) {
                    cout << "This location is BLOCKED. You cannot walk here.\n";
                }
                else {
                    cout << "This location is open.\n";
                }

                campusMap.showNeighbors(row, col);
                break;
            }
            
            case 3: {//Brolyn do this
                cout << "\n[Feature] Adding a New Student...\n";
                // studentList.addStudent();

                int id;
                cout << "Enter Student ID: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID. Returning to menu.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                string name, major;
                cout << "Enter Student Name: ";
                getline(cin, name);
                cout << "Enter Major: ";
                getline(cin, major);

                float gpa;
                cout << "Enter GPA: ";
                if (!(cin >> gpa)) {
                    cout << "Invalid GPA. Returning to menu.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (studentList.addStudent(id, name, major, gpa)) {
                    cout << "Student added successfully.\n";
                }
                else {
                    cout << "A student with ID " << id << " already exists. Student not added.\n";
                }
                break;
            }
            
            case 4: {//Brolyn do this
                cout << "\n[Feature] Removing a Student...\n";
                // studentList.removeStudent();

                int id;
                cout << "Enter Student ID to remove: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID. Returning to menu.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (studentList.removeStudent(id)) {
                    cout << "Student removed successfully.\n";
                }
                else {
                    cout << "No student found with ID " << id << ".\n";
                }
                break;
            }
            
            case 5: {//Brolyn do this
                cout << "\n[Feature] Searching for a Student...\n";
                // studentList.searchStudent();
                int id;
                cout << "Enter Student ID to search for: ";
                if (!(cin >> id)) {
                    cout << "Invalid ID. Returning to menu.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Student* found = studentList.searchStudent(id);
                if (found != nullptr) {
                    cout << "\nStudent Found:\n";
                    cout << "ID:    " << found->id << "\n";
                    cout << "Name:  " << found->name << "\n";
                    cout << "Major: " << found->major << "\n";
                    cout << "GPA:   " << found->gpa << "\n";
                }
                else {
                    cout << "No student found with ID " << id << ".\n";
                }
                break;
            }
            
            case 6: {//Brolyn do this
                cout << "\n[Feature] Sorting Student Records...\n";
                // studentList.sortByID();

                studentList.sortByID();
                studentList.displayAll();
                break;
            }
            
            case 7: {
                int id;
                string issue;
                cout << "\nEnter Student ID for advising request: ";
                cin >> id;
                cin.ignore (numeric_limits<streamsize>::max(),  '\n'); // Clear newline buffer
                cout << "Enter brief issue description: ";
                getline(cin, issue);
                advisingOffice.addRequest(id, issue);
                break;
            }
            case 8:
                advisingOffice.processNextRequest();
                break;
            
            case 9:
                cout << "\n================ CAMPUS STATISTICS ================\n";
                cout << "Pending Advising Requests: " << advisingOffice.getPendingCount() << "\n";
                cout << "Total Students: [Link StudentList data here]\n"; //Brolyn do this
                cout << "Average GPA:    [Link StudentList data here]\n";//Brolyn do this
                cout << "===================================================\n";
                break;
            
            case 10:
                cout << "\nExiting the system. Thank you!\n";
                break;
            
            default:
                cout << "Invalid choice! Please select an option between 1 and 10.\n";
                break;
        }
    }
    return 0;
}
void displayMenu() {
    cout << "\n--- MAIN SYSTEM MENU ---\n";
    cout << "1. Display Campus Map\n";
    cout << "2. Explore Location\n";
    cout << "3. Add Student\n";
    cout << "4. Remove Student\n";
    cout << "5. Search Student\n";
    cout << "6. Sort Students\n";
    cout << "7. Add Advising Request\n";
    cout << "8. Process Advising Request\n";
    cout << "9. Display Statistics\n";
    cout << "10. Exit\n";
}
