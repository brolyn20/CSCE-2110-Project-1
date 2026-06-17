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
// #include "CampusMap.h"   // Emilio do this
// #include "StudentList.h" // Brolyn do this

void displayMenu();

int main() {
    QueueSystem advisingOffice;
    string mapFilename;
    string studentFilename;

    cout << "=========================================================\n";
    cout << "  Campus Exploration and Student Resource Management     \n";
    cout << "=========================================================\n\n";

    // mapFilename = "";
    //campusMap.loadFromFile(mapFilename);
    // TODO: Call  CampusMap loading function here: Emilio do this
    // studentFilename = "";
    // studentList.loadFromFile(studentFilename);
    // TODO: Call your StudentList loading function here: Brolyn do this

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
                // campusMap.display();
                
                break;
            case 2://Emilio do this
                cout << "\n[Feature] Exploring Location Coordinates...\n";
                // Explore logic
                break;
            case 3://Brolyn do this
                cout << "\n[Feature] Adding a New Student...\n";
                // studentList.addStudent();
                break;
            case 4://Brolyn do this
                cout << "\n[Feature] Removing a Student...\n";
                // studentList.removeStudent();
                break;
            case 5://Brolyn do this
                cout << "\n[Feature] Searching for a Student...\n";
                // studentList.searchStudent();
                break;
            case 6://Brolyn do this
                cout << "\n[Feature] Sorting Student Records...\n";
                // studentList.sortByID();
                break;
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
                // Example connection between statistics and your queue system module
                cout << "Pending Advising Requests: " << advisingOffice.getPendingCount() << "\n";
                cout << "Total Students: [Link StudentList data here]\n";
                cout << "Average GPA:    [Link StudentList data here]\n";
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
