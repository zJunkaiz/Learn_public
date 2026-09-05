#include "LocalStudent.hpp"
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
LocalStudent::LocalStudent() : Student() {}

// 带参数构造函数
LocalStudent::LocalStudent(int sid, const std::string& name, 
                           const std::string& college,
                           const std::string& major)
    : Student(sid, name, college, major) {}

// 析构函数
LocalStudent::~LocalStudent() {}

// 重写打印信息
void LocalStudent::printInfo() const {
    std::cout << "[Local Student]" << std::endl;
    Student::printInfo();  // 调用基类打印
}

// 重写获取类型
std::string LocalStudent::getType() const {
    return "Local Student";
}

// 从文件读取本地学生
std::vector<LocalStudent> LocalStudent::readFromFile(const std::string& filename) {
    std::vector<LocalStudent> students;
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
        std::string name, college, major;
        int sid;
        
        // 格式: name, college, major, sid
        std::getline(ss, name, ',');
        std::getline(ss, college, ',');
        std::getline(ss, major, ',');
        ss >> sid;

        students.push_back(LocalStudent(sid, trim(name), trim(college), trim(major)));
    }

    infile.close();
    return students;
}
