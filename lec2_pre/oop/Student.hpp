#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>

using namespace std;

// ====== Student Class Definition ======
class Student {
private:
    // ====== Private Member Variables (Properties) ======
    int sid;
    string name;
    string major;
    string college;

public:
    // ====== Constructors ======
    Student();                                    // Default constructor
    Student(int s, string n, string m, string c); // Parameterized constructor

    // ====== Getter Functions (Accessors) ======
    int getSID() const;
    string getName() const;
    string getMajor() const;
    string getCollege() const;

    // ====== Setter Functions (Mutators) ======
    void setSID(int s);
    void setName(string n);
    void setMajor(string m);
    void setCollege(string c);

    // ====== Display Function ======
    void print() const;
};

// ====== Global Functions (Operating on vector<Student>) ======

// Read all students from file, return vector of Student objects
vector<Student> readStudentsFromFile(const string& filename);

// Count students by college (works for ANY college name)
int countByCollege(const vector<Student>& students, const string& college_name);

// Count students by major (works for ANY major name)
int countByMajor(const vector<Student>& students, const string& major_name);

// Search student by SID, print info if found
void searchBySID(const vector<Student>& students, int target_sid);

// Print all students
void printAllStudents(const vector<Student>& students);

// Show menu
void showMenu();

#endif // STUDENT_HPP