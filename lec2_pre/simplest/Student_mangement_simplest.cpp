#include <iostream>
#include <cstring>
#include <fstream>  // For file I/O
using namespace std;

int main() {
    // ====== Phase 1: Open File and Read Student Data ======
    cout << "=== Student Management System (Raw Version + File IO) ===" << endl;
    cout << "Reading data from ../students.txt..." << endl;

    ifstream infile("../students.txt");
    
    // Check if file opened successfully
    if (!infile.is_open()) {
        cout << "Error: Cannot open ../students.txt file!" << endl;
        return 1;
    }

    // Skip the first line (header: "Students Info")
//array


    char header[50];
    infile.getline(header, 50);

    // ----- Student 1 variables -----
    int sid_1;
    char name_1[20];
    char major_1[20];
    char college_1[20];

    // ----- Student 2 variables -----
    int sid_2;
    char name_2[20];
    char major_2[20];
    char college_2[20];

    // ----- Student 3 variables -----
    int sid_3;
    char name_3[20];
    char major_3[20];
    char college_3[20];

    // ----- Student 4 variables -----
    int sid_4;
    char name_4[20];
    char major_4[20];
    char college_4[20];

    // ----- Student 5 variables -----
    int sid_5;
    char name_5[20];
    char major_5[20];
    char college_5[20];

    // ====== Phase 2: Read 5 Students from File (MANUAL, NO LOOPS) ======
    // Read student 1
    infile >> name_1 >> college_1 >> major_1 >> sid_1;
    // Read student 2
    infile >> name_2 >> college_2 >> major_2 >> sid_2;
    // Read student 3
    infile >> name_3 >> college_3 >> major_3 >> sid_3;
    // Read student 4
    infile >> name_4 >> college_4 >> major_4 >> sid_4;
    // Read student 5
    infile >> name_5 >> college_5 >> major_5 >> sid_5;

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

    // ====== Phase 4: Execute Function (ALL MANUAL, NO LOOPS) ======
    /* if */

    // ----- Function 1: Count NA College Students (one by one) -----
    if (strcmp(command, "NA") == 0) {  //int strcmp(const char *str1, const char *str2); 
        int count = 0;

        // Check student 1
        if (strcmp(college_1, "NA") == 0) {
            count = count + 1;
        }
        // Check student 2
        if (strcmp(college_2, "NA") == 0) {
            count = count + 1;
        }
        // Check student 3
        if (strcmp(college_3, "NA") == 0) {
            count = count + 1;
        }
        // Check student 4
        if (strcmp(college_4, "NA") == 0) {
            count = count + 1;
        }
        // Check student 5
        if (strcmp(college_5, "NA") == 0) {
            count = count + 1;
        }

        cout << "Total number of students in NA college: " << count << endl;
    }

    // ----- Function 2: Count EE Major Students (one by one) -----
    else if (strcmp(command, "EE") == 0) {
        int count = 0;

        // Check student 1
        if (strcmp(major_1, "EE") == 0) {
            count = count + 1;
        }
        // Check student 2
        if (strcmp(major_2, "EE") == 0) {
            count = count + 1;
        }
        // Check student 3
        if (strcmp(major_3, "EE") == 0) {
            count = count + 1;
        }
        // Check student 4
        if (strcmp(major_4, "EE") == 0) {
            count = count + 1;
        }
        // Check student 5
        if (strcmp(major_5, "EE") == 0) {
            count = count + 1;
        }

        cout << "Total number of students in EE major: " << count << endl;
    }

    // ----- Function 3: Search Student by SID (one by one comparison) -----
    else if (strcmp(command, "info") == 0) {
        int target_sid;
        cout << "Enter the SID to search: ";
        cin >> target_sid;

        int found = 0;  // 0 = not found, 1 = found

        // Check student 1
        if (found == 0 && sid_1 == target_sid) {
            cout << "SID: " << sid_1 << endl;
            cout << "Name: " << name_1 << endl;
            cout << "Major: " << major_1 << endl;
            cout << "College: " << college_1 << endl;
            found = 1;
        }

        // Check student 2
        if (found == 0 && sid_2 == target_sid) {
            cout << "SID: " << sid_2 << endl;
            cout << "Name: " << name_2 << endl;
            cout << "Major: " << major_2 << endl;
            cout << "College: " << college_2 << endl;
            found = 1;
        }

        // Check student 3
        if (found == 0 && sid_3 == target_sid) {
            cout << "SID: " << sid_3 << endl;
            cout << "Name: " << name_3 << endl;
            cout << "Major: " << major_3 << endl;
            cout << "College: " << college_3 << endl;
            found = 1;
        }

        // Check student 4
        if (found == 0 && sid_4 == target_sid) {
            cout << "SID: " << sid_4 << endl;
            cout << "Name: " << name_4 << endl;
            cout << "Major: " << major_4 << endl;
            cout << "College: " << college_4 << endl;
            found = 1;
        }

        // Check student 5
        if (found == 0 && sid_5 == target_sid) {
            cout << "SID: " << sid_5 << endl;
            cout << "Name: " << name_5 << endl;
            cout << "Major: " << major_5 << endl;
            cout << "College: " << college_5 << endl;
            found = 1;
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