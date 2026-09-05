#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>     // For dynamic array
#include <string>     // For string operations
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

// Show menu and get user command
void showMenu();

// ====== Main Function ======
int main() {
    cout << "=== Student Management System (Structured + Function Version) ===" << endl;
    cout << "Reading data from ../students_total.txt..." << endl;

    // Read all students from file
    vector<Student> students = readStudentsFromFile("../students_total.txt");

    // Check if data loaded successfully
    if (students.empty()) {
        cout << "Error: No student data loaded!" << endl;
        return 1;
    }

    cout << "Successfully loaded " << students.size() << " students!\n" << endl;

    // ====== Main interaction loop ======
    while (true) {
        showMenu();

        char command[20];
        cin >> command;

        // ----- Function 1: Count by College (works for ANY college) -----
        if (strcmp(command, "NA") == 0 || 
            strcmp(command, "UC") == 0 || 
            strcmp(command, "CC") == 0) {
            
            string college_name = command;
            int count = countByCollege(students, college_name);
            cout << "Total number of students in " << college_name 
                 << " college: " << count << endl;
            cout << endl;
        }

        // ----- Function 2: Count by Major (works for ANY major) -----
        else if (strcmp(command, "EE") == 0 ||
                 strcmp(command, "CS") == 0 ||
                 strcmp(command, "IE") == 0 ||
                 strcmp(command, "LLB") == 0 ||
                 strcmp(command, "MAE") == 0 ||
                 strcmp(command, "IBBA") == 0 ||
                 strcmp(command, "MATH") == 0) {
            
            string major_name = command;
            int count = countByMajor(students, major_name);
            cout << "Total number of students in " << major_name 
                 << " major: " << count << endl;
            cout << endl;
        }

        // ----- Function 3: Search by SID -----
        else if (strcmp(command, "info") == 0) {
            int target_sid;
            cout << "Enter the SID to search: ";
            cin >> target_sid;
            searchBySID(students, target_sid);
            cout << endl;
        }

        // ----- Function 4: Print all students (hidden feature) -----
        else if (strcmp(command, "all") == 0) {
            printAllStudents(students);
        }

        // ----- Function 5: Exit -----
        else if (strcmp(command, "exit") == 0) {
            cout << "Exiting system. Goodbye!" << endl;
            break;
        }

        else {
            cout << "Invalid command." << endl;
            cout << "Enter NA, UC, CC (colleges), or EE, CS, IE, LLB, MAE, IBBA, MATH (majors)" << endl;
            cout << "Or enter 'info' to search by SID, 'all' to list all, 'exit' to quit" << endl;
            cout << endl;
        }
    }

    return 0;
}

// ====== Function Implementations ======

// Read all students from file, return vector of students
vector<Student> readStudentsFromFile(const string& filename) {
    vector<Student> students;
    
    ifstream infile(filename);
    if (!infile.is_open()) {
        cout << "Error: Cannot open " << filename << " file!" << endl;
        return students;  // Return empty vector
    }

    // Skip the first line (header: "Students Info")
    string header;
    getline(infile, header);

    // Read all students until end of file
    Student s;
    while (infile >> s.name >> s.college >> s.major >> s.sid) {
        students.push_back(s);
    }

    infile.close();
    return students;
}

// Count students by college (works for ANY college name)
int countByCollege(const vector<Student>& students, const string& college_name) {
    int count = 0;
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].college == college_name) {
            count = count + 1;
        }
    }
    return count;
}

// Count students by major (works for ANY major name)
int countByMajor(const vector<Student>& students, const string& major_name) {
    int count = 0;
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].major == major_name) {
            count = count + 1;
        }
    }
    return count;
}

// Search student by SID, print info if found
void searchBySID(const vector<Student>& students, int target_sid) {
    int found = 0;  // 0 = not found, 1 = found
    
    for (int i = 0; i < (int)students.size(); i++) {
        if (students[i].sid == target_sid) {
            cout << "===== Student Found =====" << endl;
            cout << "SID:     " << students[i].sid << endl;
            cout << "Name:    " << students[i].name << endl;
            cout << "Major:   " << students[i].major << endl;
            cout << "College: " << students[i].college << endl;
            cout << "========================" << endl;
            found = 1;
            break;  // SID is unique, can stop searching
        }
    }
    
    if (found == 0) {
        cout << "Student with SID " << target_sid << " not found." << endl;
    }
}

// Print all students (for debugging)
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

// Show menu and get user command
void showMenu() {
    cout << "=== System Function Menu ===" << endl;
    cout << "Colleges: NA, UC, CC" << endl;
    cout << "Majors:   EE, CS, IE, LLB, MAE, IBBA, MATH" << endl;
    cout << "Enter 'info' to search by SID" << endl;
    cout << "Enter 'all' to list all students" << endl;
    cout << "Enter 'exit' to quit" << endl;
    cout << "Please select a function: ";
}