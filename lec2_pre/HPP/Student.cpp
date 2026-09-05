#include "Student.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// ====== Function Implementations ======

vector<Student> readStudentsFromFile(const string& filename) {
    vector<Student> students;
    
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Error: Cannot open " << filename << " file!" << endl;
        return students;
    }

    // Skip header line
    string header;
    getline(infile, header);

    // Read students - assumes name has NO space (e.g., "AliceChen")
    Student s;
    while (infile >> s.name >> s.college >> s.major >> s.sid) {
        students.push_back(s);
    }

    infile.close();
    return students;
}

int countByCollege(const vector<Student>& students, const string& college_name) {
    int count = 0;
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].college == college_name) {
            count = count + 1;
        }
    }
    return count;
}

int countByMajor(const vector<Student>& students, const string& major_name) {
    int count = 0;
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].major == major_name) {
            count = count + 1;
        }
    }
    return count;
}

void searchBySID(const vector<Student>& students, int target_sid) {
    int found = 0;
    
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].sid == target_sid) {
            cout << "===== Student Found =====" << endl;
            cout << "SID:     " << students[i].sid << endl;
            cout << "Name:    " << students[i].name << endl;
            cout << "Major:   " << students[i].major << endl;
            cout << "College: " << students[i].college << endl;
            cout << "========================" << endl;
            found = 1;
            break;
        }
    }
    
    if (found == 0) {
        cout << "Student with SID " << target_sid << " not found." << endl;
    }
}

void printAllStudents(const vector<Student>& students) {
    cout << "\n===== All Students (" << students.size() << " total) =====" << endl;
    for (int i = 0; i < (int)students.size(); i++) {
        cout << "SID: " << students[i].sid 
             << " | Name: " << students[i].name
             << " | College: " << students[i].college
             << " | Major: " << students[i].major << endl;
    }
    cout << "====================================\n" << endl;
}

void showMenu() {
    cout << "=== System Function Menu ===" << endl;
    cout << "Colleges: NA, UC, CC" << endl;
    cout << "Majors:   EE, CS, IE, LLB, MAE, IBBA, MATH" << endl;
    cout << "Enter 'info' to search by SID" << endl;
    cout << "Enter 'all' to list all students" << endl;
    cout << "Enter 'exit' to quit" << endl;
    cout << "Please select a function: ";
}