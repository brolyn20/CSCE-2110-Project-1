#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>
#include "StudentList.h"
#include "CampusMap.h"
 //included campus map

class FileManager {
public:
    static bool loadStudents(const std::string& filename, StudentList& studentList);
    static bool loadCampusMap(const std::string& filename, CampusMap& campusMap);
//reads campus map and loads

static bool saveStudents(const std::string& filename, const StudentList& studentList); //save student data
};

#endif //
