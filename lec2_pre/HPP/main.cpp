#include <iostream>
#include <string>
#include <vector>
#include "Student.hpp"

using namespace std;

int main() {
    cout << "=== Student Management System (Structured + Function Version) ===" << endl;
    cout << "Reading data from ../students_total.txt..." << endl;

    vector<Student> students = readStudentsFromFile("../students_total.txt");

    if (students.empty()) {
        cout << "Error: No student data loaded!" << endl;
        cout << "Please make sure ../students_total.txt exists and has valid data." << endl;
        return 1;
    }

    cout << "Successfully loaded " << students.size() << " students!\n" << endl;

    while (true) {
        showMenu();

        string command;
        cin >> command;

        // Check if command is a college name
        if (command == "NA" || command == "UC" || command == "CC") {
            int count = countByCollege(students, command);
            cout << "Total number of students in " << command 
                 << " college: " << count << endl;
            cout << endl;
        }
        // Check if command is a major name
        else if (command == "EE" || command == "CS" || command == "IE" ||
                 command == "LLB" || command == "MAE" || command == "IBBA" ||
                 command == "MATH") {
            int count = countByMajor(students, command);
            cout << "Total number of students in " << command 
                 << " major: " << count << endl;
            cout << endl;
        }
        else if (command == "info") {
            int target_sid;
            cout << "Enter the SID to search: ";
            cin >> target_sid;
            searchBySID(students, target_sid);
            cout << endl;
        }
        else if (command == "all") {
            printAllStudents(students);
        }
        else if (command == "exit") {
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