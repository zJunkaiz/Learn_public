#include "Student.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// ====== Constructor Implementations ======

// Default constructor
Student::Student() {
    sid = 0;
    name = "";
    major = "";
    college = "";
}

// Parameterized constructor
Student::Student(int s, string n, string m, string c) {
    sid = s;
    name = n;
    major = m;
    college = c;
}

// ====== Getter Implementations ======

int Student::getSID() const {
    return sid;
}

string Student::getName() const {
    return name;
}

string Student::getMajor() const {
    return major;
}

string Student::getCollege() const {
    return college;
}

// ====== Setter Implementations ======

void Student::setSID(int s) {
    sid = s;
}

void Student::setName(string n) {
    name = n;
}

void Student::setMajor(string m) {
    major = m;
}

void Student::setCollege(string c) {
    college = c;
}

// ====== Display Function Implementation ======

void Student::print() const {
    cout << "SID:     " << sid << endl;
    cout << "Name:    " << name << endl;
    cout << "Major:   " << major << endl;
    cout << "College: " << college << endl;
}

// ====== Global Function Implementations ======

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
    int sid;
    string name, major, college;
    while (infile >> name >> college >> major >> sid) {
        Student s(sid, name, major, college);  // Use parameterized constructor
        students.push_back(s);
    }

    infile.close();
    return students;
}

int countByCollege(const vector<Student>& students, const string& college_name) {
    int count = 0;
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].getCollege() == college_name) {  // Use getter
            count = count + 1;
        }
    }
    return count;
}

int countByMajor(const vector<Student>& students, const string& major_name) {
    int count = 0;
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].getMajor() == major_name) {  // Use getter
            count = count + 1;
        }
    }
    return count;
}

void searchBySID(const vector<Student>& students, int target_sid) {
    int found = 0;
    
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].getSID() == target_sid) {  // Use getter
            cout << "===== Student Found =====" << endl;
            students[i].print();  // Use print() method
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
        cout << "SID: " << students[i].getSID()
             << " | Name: " << students[i].getName()
             << " | College: " << students[i].getCollege()
             << " | Major: " << students[i].getMajor() << endl;
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