#include "StudentList.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::left;
using std::setw;
using std::string;

StudentList::StudentList() : head(nullptr) {}

StudentList::~StudentList() {
    // Walk the list and free every node so the program doesn't leak memory.
    Node* current = head;
    while (current != nullptr) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

bool StudentList::idExists(int id) const {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.id == id) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool StudentList::addStudent(int id, const string& name, const string& major, float gpa) {
    // making sures ID's are unique, wont let you add otherwise
    if (idExists(id)) {
        return false;
    }

    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.name = name;
    newNode->data.major = major;
    newNode->data.gpa = gpa;
    newNode->next = nullptr;

    if (head == nullptr) {
  
        head = newNode;
    } else {
        // keeps students in the order they were added/loaded
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    return true;
}

bool StudentList::removeStudent(int id) {
    if (head == nullptr) {
        return false; // nothing to remove from an empty list
    }

    if (head->data.id == id) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return true;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data.id != id) {
        current = current->next;
    }

    if (current->next == nullptr) {
        return false; // walked off the end without finding the id
    }

    Node* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
    return true;
}

Student* StudentList::searchStudent(int id) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data.id == id) {
            return &current->data;
        }
        current = current->next;
    }
    return nullptr; // not found
}

void StudentList::displayAll() const {
    if (head == nullptr) {
        cout << "No students on record.\n";
        return;
    }

    cout << left
         << setw(8)  << "ID"
         << setw(20) << "Name"
         << setw(20) << "Major"
         << setw(6)  << "GPA" << "\n";
    cout << string(54, '-') << "\n";

    Node* current = head;
    while (current != nullptr) {
        cout << left
             << setw(8)  << current->data.id
             << setw(20) << current->data.name
             << setw(20) << current->data.major
             << setw(6)  << current->data.gpa << "\n";
        current = current->next;
    }
}

int StudentList::getCount() const {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

float StudentList::getAverageGPA() const {
    int count = 0;
    float total = 0.0f;
    Node* current = head;
    while (current != nullptr) {
        total += current->data.gpa;
        count++;
        current = current->next;
    }
    return (count == 0) ? 0.0f : total / count;
}

void StudentList::sortByID() {
    // Nothing to sort if the list is empty or has only one student.
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // Bubble Sort:
    bool swapped = true;
    while (swapped) {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data.id > current->next->data.id) {
                Student temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    }
}