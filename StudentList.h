#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <string>

// This is for the individual student records
struct Student {
    int id;
    std::string name;
    std::string major;
    float gpa;
};

// A single node in the singly linked list.
// Each node owns one Student record and points to the next node.
struct Node {
    Student data;
    Node* next;
};


// The class for all Node memory 
class StudentList {
public:
    StudentList();   // creates an empty list (head = nullptr)
    ~StudentList();  // frees every node so there are no memory leaks

    // Adds a new student to the end of the list(if id is alr being used then it returns nothing).
    bool addStudent(int id, const std::string& name, const std::string& major, float gpa);

    // Removes the student with the given id ( true if found/removed otherwise false).
    bool removeStudent(int id);

    // Searches the list for a student with the given id (pointer if found nullptr otheerwise).
    Student* searchStudent(int id);

    //// Prints every student currently in list or a message if list empty
    void displayAll() const;

    // true if a student with this id already exists.
    bool idExists(int id) const;

    // Returns how many students are currently stored.
    // (Useful later for Part 5 statistics: total students.)
    int getCount() const;

   
    // Avg Gpa
    float getAverageGPA() const;

   
    //We will sort the student's ID's via Bubble sort
    void sortByID();

private:
    Node* head;
};

#endif
