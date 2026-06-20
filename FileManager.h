#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include <string>
#include "StudentList.h"
 //include campus map when its done

class FileManager {
public:
    static bool loadStudents(const std::string& filename, StudentList& studentList);
};

#endif //
