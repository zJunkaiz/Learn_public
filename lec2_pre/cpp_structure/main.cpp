#include <iostream>
#include "rectangle.hpp"

int main() {
    // 一个简单的场景：
    // 假设我们有一个长 5 米、宽 3 米的矩形。
    const double length = 5.0;
    const double width = 3.0;

    // 调用 rectangle.cpp 中实现的函数。
    // main.cpp 只关心“调用什么函数”，不需要关心内部计算细节。
    const double area = calculateArea(length, width);

    // std::cout 用于向终端输出内容。
    std::cout << "Rectangle length: " << length << " m\n";
    std::cout << "Rectangle width:  " << width << " m\n";
    std::cout << "Rectangle area:   " << area << " square meters\n";

    // 返回 0，表示程序正常结束。
    return 0;
}

