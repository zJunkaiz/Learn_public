 #ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <vector>
#include <iostream>

class Student {
protected:
    int sid;                 
    std::string name;
    std::string college;
    std::string major;

public:
    // 构造函数
    Student();
    Student(int sid, const std::string& name, const std::string& college,
            const std::string& major);
    
    // 虚析构函数
    virtual ~Student();

    // Getter方法
    int getSID() const;
    std::string getName() const;
    std::string getCollege() const;
    std::string getMajor() const;

    // Setter方法
    void setSID(int sid);
    void setName(const std::string& name);
    void setCollege(const std::string& college);
    void setMajor(const std::string& major);

    // 虚函数 - 支持多态
    virtual void printInfo() const;
    virtual std::string getType() const;

    // 静态方法：从文件读取学生
    static std::vector<Student*> readFromFile(const std::string& filename);
};

#endif