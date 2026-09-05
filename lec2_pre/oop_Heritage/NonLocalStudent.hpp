#ifndef NONLOCAL_STUDENT_HPP
#define NONLOCAL_STUDENT_HPP

#include "Student.hpp"
#include "LocalStudent.hpp"

class NonLocalStudent : public LocalStudent {
private:
    std::string continent;  // 来自大洲

public:
    // 构造函数
    NonLocalStudent();
    NonLocalStudent(int sid, const std::string& name, const std::string& college,
                    const std::string& major, const std::string& continent);
    
    // 析构函数
    ~NonLocalStudent();

    // Getter/Setter
    std::string getContinent() const;
    void setContinent(const std::string& continent);

    // 重写虚函数
    void printInfo() const override;
    std::string getType() const override;

    // 静态方法：从文件读取非本地学生
    static std::vector<NonLocalStudent> readFromFile(const std::string& filename);

    // 静态方法：按大洲统计
    static int countByContinent(const std::vector<NonLocalStudent>& students,
                                const std::string& continent);
};

#endif
