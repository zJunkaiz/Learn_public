#include "Student.hpp"
#include "LocalStudent.hpp"
#include "NonLocalStudent.hpp"
#include <fstream>
#include <sstream>
#include <cctype>

namespace {
std::string trim(const std::string& text) {
    std::size_t start = 0;
    while (start < text.size() && std::isspace(static_cast<unsigned char>(text[start]))) {
        ++start;
    }

    std::size_t end = text.size();
    while (end > start && std::isspace(static_cast<unsigned char>(text[end - 1]))) {
        --end;
    }

    return text.substr(start, end - start);
}
}

// 默认构造函数
Student::Student() : sid(0), name(""), college(""), major("") {}

// 带参数构造函数
Student::Student(int sid, const std::string& name, const std::string& college,
                 const std::string& major)
    : sid(sid), name(name), college(college), major(major) {}

// 析构函数
Student::~Student() {}

// Getter实现
int Student::getSID() const { return sid; }
std::string Student::getName() const { return name; }
std::string Student::getCollege() const { return college; }
std::string Student::getMajor() const { return major; }

// Setter实现
void Student::setSID(int sid) { this->sid = sid; }
void Student::setName(const std::string& name) { this->name = name; }
void Student::setCollege(const std::string& college) { this->college = college; }
void Student::setMajor(const std::string& major) { this->major = major; }

// 打印信息
void Student::printInfo() const {
    std::cout << "SID: " << sid << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "College: " << college << std::endl;
    std::cout << "Major: " << major << std::endl;
}

// 获取类型
std::string Student::getType() const {
    return "Student";
}

// 从文件读取（静态方法）- 自动识别类型
std::vector<Student*> Student::readFromFile(const std::string& filename) {
    std::vector<Student*> students;
    std::ifstream infile(filename);
    
    if (!infile.is_open()) {
        std::cout << "Cannot open file: " << filename << std::endl;
        return students;
    }

    std::string line;
    // 跳过标题行
    std::getline(infile, line);

    while (std::getline(infile, line)) {
        if (line.empty()) continue;
        
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> fields;

        while (std::getline(ss, field, ',')) {
            fields.push_back(trim(field));
        }

        if (fields.size() == 4) {
            int sid = std::stoi(fields[3]);
            students.push_back(new LocalStudent(sid, fields[0], fields[1], fields[2]));
        } else if (fields.size() >= 5) {
            int sid = std::stoi(fields[3]);
            students.push_back(new NonLocalStudent(sid, fields[0], fields[1], fields[2], fields[4]));
        }
    }

    infile.close();
    return students;
}
