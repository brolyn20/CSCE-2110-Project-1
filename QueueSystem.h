//QueueSystem.h ZDS
#ifndef QUEUE_SYSTEM_H
#define QUEUE_SYSTEM_H
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
using namespace std;
// Struct representing an advising request 
struct AdvisingRequest {
    int studentId;
    std::string issueDescription;
};

class QueueSystem {
private:
    std::queue<AdvisingRequest> advisingQueue;

public:
    // Adds a new advising request to the back of the queue
    void addRequest(int studentId, const std::string& description);

    // Processes and removes the next request from the front of the queue
    void processNextRequest();

    // Displays all currently pending requests in the queue
    void displayAllRequests() const;

    // Returns the total number of pending requests (useful for Campus Statistics)
    int getPendingCount() const;
};

#endif // QUEUE_SYSTEM_H
