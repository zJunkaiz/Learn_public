#ifndef LOCAL_STUDENT_HPP
#define LOCAL_STUDENT_HPP

#include "Student.hpp"
#include <string>
#include <vector>

class LocalStudent : public Student {
public:
    // 构造函数
    LocalStudent();
    LocalStudent(int sid, const std::string& name, const std::string& college,
                 const std::string& major);
    
    // 析构函数
    ~LocalStudent();

    // 重写虚函数
    void printInfo() const override;
    std::string getType() const override;

    // 静态方法：从文件读取本地学生
    static std::vector<LocalStudent> readFromFile(const std::string& filename);

    template <typename T>
    static int countByCollege(const std::vector<T>& students, const std::string& college) {
        int count = 0;
        for (const auto& student : students) {
            if (student.getCollege() == college) {
                ++count;
            }
        }
        return count;
    }

    template <typename T>
    static int countByMajor(const std::vector<T>& students, const std::string& major) {
        int count = 0;
        for (const auto& student : students) {
            if (student.getMajor() == major) {
                ++count;
            }
        }
        return count;
    }

    template <typename T>
    static void searchBySID(const std::vector<T>& students, int target_sid) {
        for (const auto& student : students) {
            if (student.getSID() == target_sid) {
                std::cout << "===== Student Found =====" << std::endl;
                student.printInfo();
                std::cout << "=========================" << std::endl;
                return;
            }
        }

        std::cout << "Student with SID " << target_sid << " not found." << std::endl;
    }
};

#endif
