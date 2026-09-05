#include <iostream>
#include <cstring>
#include <fstream>  // For file I/O
using namespace std;

int main() {
    // ====== Phase 1: Open File and Read Student Data ======
    cout << "=== Student Management System ===" << endl;
    cout << "Reading data from ../students.txt..." << endl;

    ifstream infile("../students.txt");
    
    // Check if file opened successfully
    if (!infile.is_open()) {
        cout << "Error: Cannot open ../students.txt file!" << endl;
        return 1;
    }

    // Skip the first line (header: "Students Info")
    char header[50];
    infile.getline(header, 50);

    // Declare arrays for 5 students
    int sid[5];
    char name[5][20];
    char major[5][20];
    char college[5][20];

    // ====== Phase 2: Read 5 Students from File (USING FOR LOOP) ======
    for (int i = 0; i < 5; i++) {
        // Read: name college major sid (matching file format)
        infile >> name[i] >> college[i] >> major[i] >> sid[i];
    }

    infile.close();
    cout << "Data loaded successfully!\n" << endl;

    // ====== Phase 3: Ask Staff Which Function to Use ======
    cout << "=== System Function Menu ===" << endl;
    cout << "Enter NA  -> Count students in NA college" << endl;
    cout << "Enter EE  -> Count students in EE major" << endl;
    cout << "Enter info -> Search student by SID" << endl;
    cout << "Please select a function: ";

    char command[20];
    cin >> command;

    // ====== Phase 4: Execute Function (USING FOR LOOPS) ======

    // ----- Function 1: Count NA College Students (USING FOR LOOP) -----
    if (strcmp(command, "NA") == 0) {
        int count = 0;

        for (int i = 0; i < 5; i++) {
            if (strcmp(college[i], "NA") == 0) {
                count = count + 1;
            }
        }

        cout << "Total number of students in NA college: " << count << endl;
    }

    // ----- Function 2: Count EE Major Students (USING FOR LOOP) -----
    else if (strcmp(command, "EE") == 0) {
        int count = 0;

        for (int i = 0; i < 5; i++) {
            if (strcmp(major[i], "EE") == 0) {
                count = count + 1;
            }
        }

        cout << "Total number of students in EE major: " << count << endl;
    }

    // ----- Function 3: Search Student by SID (USING FOR LOOP) -----
    else if (strcmp(command, "info") == 0) {
        int target_sid;
        cout << "Enter the SID to search: ";
        cin >> target_sid;

        int found = 0;  // 0 = not found, 1 = found

        for (int i = 0; i < 5; i++) {
            if (found == 0 && sid[i] == target_sid) {
                cout << "SID: " << sid[i] << endl;
                cout << "Name: " << name[i] << endl;
                cout << "Major: " << major[i] << endl;
                cout << "College: " << college[i] << endl;
                found = 1;
            }
        }

        if (found == 0) {
            cout << "Student with SID " << target_sid << " not found." << endl;
        }
    }

    else {
        cout << "Invalid command. Please enter NA, EE, or info." << endl;
    }

    return 0;
}