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
NonLocalStudent::NonLocalStudent() : LocalStudent(), continent("") {}

// 带参数构造函数
NonLocalStudent::NonLocalStudent(int sid, const std::string& name, 
                                  const std::string& college,
                                  const std::string& major,
                                  const std::string& continent)
    : LocalStudent(sid, name, college, major), continent(continent) {}

// 析构函数
NonLocalStudent::~NonLocalStudent() {}

// Getter/Setter
std::string NonLocalStudent::getContinent() const { return continent; }
void NonLocalStudent::setContinent(const std::string& continent) {
    this->continent = continent;
}

// 重写打印信息
void NonLocalStudent::printInfo() const {
    std::cout << "[Non-Local Student]" << std::endl;
    Student::printInfo();  // 调用基类打印
    std::cout << "Continent: " << continent << std::endl;
}

// 重写获取类型
std::string NonLocalStudent::getType() const {
    return "Non-Local Student (from " + continent + ")";
}

// 从文件读取非本地学生
std::vector<NonLocalStudent> NonLocalStudent::readFromFile(const std::string& filename) {
    std::vector<NonLocalStudent> students;
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
        std::string name, college, major, continent;
        int sid;
        
        // 格式: name, college, major, sid, continent
        std::getline(ss, name, ',');
        std::getline(ss, college, ',');
        std::getline(ss, major, ',');
        ss >> sid;
        ss.ignore(); // 忽略逗号
        std::getline(ss, continent, ',');

        students.push_back(NonLocalStudent(sid, trim(name), trim(college), trim(major), trim(continent)));
    }

    infile.close();
    return students;
}

// 按大洲统计
int NonLocalStudent::countByContinent(const std::vector<NonLocalStudent>& students,
                                      const std::string& continent) {
    int count = 0;
    for (const auto& student : students) {
        if (student.getContinent() == continent) {
            ++count;
        }
    }
    return count;
}
