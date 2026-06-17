//QueueSystem.cpp ZDS
#include "QueueSystem.h"
#include <iostream>
#include <map> //to use map
#include <iostream> // I/O: cin, cout, endl
#include <vector> // container
#include <algorithm> // sorting
#include <iostream> // for input output
#include <cmath> // for math
#include<cstring>// for c-strings
#include <string>  // for strings
#include <cstdlib> // for random , rand function
#include <stdio.h>  // for printf  printf(“format string”, parameters)
#include <ctime> // for random
#include <cassert> // for testing
#include <iomanip>
#include <sstream> // for stringstream
#include <fstream> //for file reading
#include <vector> // container
#include <algorithm> // sorting
#include <queue>
#include <string>

using namespace std;
void QueueSystem::addRequest(int studentId, const string& description) {
    AdvisingRequest newRequest = {studentId, description};
    advisingQueue.push(newRequest);
    cout << "Successfully added advising request for Student ID: " << studentId << "\n";
}

void QueueSystem::processNextRequest() {
    // Testing requirement guardrail: Handle empty structures safely
    if (advisingQueue.empty()) {
        cout << "Notice: The advising queue is currently empty. No requests to process.\n";
        return;
    }

    AdvisingRequest currentRequest = advisingQueue.front();
    cout << "\n--- Processing Advising Request ---\n";
    cout << "Student ID: " << currentRequest.studentId << "\n";
    cout << "Issue Description: " << currentRequest.issueDescription << "\n";
    cout << "-----------------------------------\n";

    advisingQueue.pop();
    cout << "Request processed and removed from queue.\n";
}

void QueueSystem::displayAllRequests() const {
    if (advisingQueue.empty()) {
        cout << "No pending advising requests.\n";
        return;
    }

    // Since queue doesn't allow direct iteration, we copy it to safely traverse and print
    queue<AdvisingRequest> tempQueue = advisingQueue;
    int position = 1;

    cout << "\n--- Pending Advising Requests ---\n";
    while (!tempQueue.empty()) {
        AdvisingRequest req = tempQueue.front();
        cout << position << ". Student ID: " << req.studentId
                  << " | Issue: " << req.issueDescription << "\n";
        tempQueue.pop();
        position++;
    }
    cout << "---------------------------------\n";
}

int QueueSystem::getPendingCount() const {
    return advisingQueue.size();
}
