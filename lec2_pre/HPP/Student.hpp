#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>

using namespace std;

// ====== Data Structure Definition ======
struct Student {
    int sid;
    string name;
    string major;
    string college;
};

// ====== Function Declarations ======

// Read all students from file, return vector of students
vector<Student> readStudentsFromFile(const string& filename);

// Count students by college (works for ANY college name)
int countByCollege(const vector<Student>& students, const string& college_name);

// Count students by major (works for ANY major name)
int countByMajor(const vector<Student>& students, const string& major_name);

// Search student by SID, print info if found
void searchBySID(const vector<Student>& students, int target_sid);

// Print all students (for debugging)
void printAllStudents(const vector<Student>& students);

// Show menu
void showMenu();

#endif // STUDENT_HPP