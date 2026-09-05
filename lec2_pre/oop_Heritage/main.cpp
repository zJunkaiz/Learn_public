#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include "LocalStudent.hpp"
#include "NonLocalStudent.hpp"

using namespace std;

void showMenu() {
    cout << "\n=== Student System ===" << endl;
    cout << "1. Local: count by college" << endl;
    cout << "2. Local: count by major" << endl;
    cout << "3. Local: search by SID" << endl;
    cout << "4. NonLocal: count by college" << endl;
    cout << "5. NonLocal: count by major" << endl;
    cout << "6. NonLocal: search by SID" << endl;
    cout << "7. NonLocal: count by continent" << endl;
    cout << "8. Exit" << endl;
    cout << "Select: ";
}

int main() {
    vector<LocalStudent> localStudents;
    vector<NonLocalStudent> nonLocalStudents;

    if (ifstream localFile("oop_Heritage/local_students.txt"); localFile.is_open()) {
        localStudents = LocalStudent::readFromFile("oop_Heritage/local_students.txt");
    } else {
        localStudents = LocalStudent::readFromFile("local_students.txt");
    }

    if (ifstream nonLocalFile("oop_Heritage/nonlocal_students.txt"); nonLocalFile.is_open()) {
        nonLocalStudents = NonLocalStudent::readFromFile("oop_Heritage/nonlocal_students.txt");
    } else {
        nonLocalStudents = NonLocalStudent::readFromFile("nonlocal_students.txt");
    }

    cout << "Loaded local students: " << localStudents.size() << endl;
    cout << "Loaded non-local students: " << nonLocalStudents.size() << endl;

    if (localStudents.empty() && nonLocalStudents.empty()) {
        cout << "No data loaded. Please check the input files." << endl;
        return 1;
    }

    while (true) {
        int choice;
        showMenu();

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input." << endl;
            continue;
        }

        if (choice == 1) {
            string college;
            cout << "Enter college code: ";
            cin >> college;
            cout << "Local students in college " << college << ": "
                 << LocalStudent::countByCollege(localStudents, college) << endl;
        } else if (choice == 2) {
            string major;
            cout << "Enter major code: ";
            cin >> major;
            cout << "Local students in major " << major << ": "
                 << LocalStudent::countByMajor(localStudents, major) << endl;
        } else if (choice == 3) {
            int sid;
            cout << "Enter SID: ";
            cin >> sid;
            LocalStudent::searchBySID(localStudents, sid);
        } else if (choice == 4) {
            string college;
            cout << "Enter college code: ";
            cin >> college;
            cout << "Non-local students in college " << college << ": "
                 << LocalStudent::countByCollege(nonLocalStudents, college) << endl;
        } else if (choice == 5) {
            string major;
            cout << "Enter major code: ";
            cin >> major;
            cout << "Non-local students in major " << major << ": "
                 << LocalStudent::countByMajor(nonLocalStudents, major) << endl;
        } else if (choice == 6) {
            int sid;
            cout << "Enter SID: ";
            cin >> sid;
            LocalStudent::searchBySID(nonLocalStudents, sid);
        } else if (choice == 7) {
            string continent;
            cout << "Enter continent: ";
            cin >> continent;
            cout << "Non-local students in continent " << continent << ": "
                 << NonLocalStudent::countByContinent(nonLocalStudents, continent) << endl;
        } else if (choice == 8) {
            cout << "Bye." << endl;
            break;
        } else {
            cout << "Please choose 1-8." << endl;
        }
    }

    return 0;
}
