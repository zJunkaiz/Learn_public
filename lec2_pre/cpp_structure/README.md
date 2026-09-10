# C++ 代码结构与编译过程示例

这个文件夹用一个非常简单的场景讲解 C++ 程序的基本结构：

> 已知一个矩形的长和宽，计算它的面积，并在屏幕上输出结果。

虽然例子很小，但它包含了实际项目中最常见的三个部分：

```text
cpp_structure/
├── README.md          # 教学说明
├── main.cpp           # 程序入口，负责组织程序流程
├── rectangle.hpp      # 头文件，放类、函数等声明
└── rectangle.cpp      # 源文件，放函数等具体实现
```

## 一、C++ 程序的基本结构

### 1. 预处理指令

```cpp
#include "rectangle.hpp"
```

`#include` 是预处理指令。编译正式开始前，预处理器会把 `rectangle.hpp`
的内容放到 `main.cpp` 的对应位置。

尖括号和双引号通常有这样的区别：

```cpp
#include <iostream>       // 优先查找编译器或系统提供的头文件
#include "rectangle.hpp"  // 优先查找当前项目中的头文件
```

### 2. 头文件

头文件通常保存“声明”，也就是告诉其他文件：

- 有哪些函数；
- 函数叫什么；
- 函数接收什么参数；
- 函数返回什么类型。

例如：

```cpp
double calculateArea(double length, double width);
```

这句话只声明了一个函数，没有写函数体。它的意思是：

> 有一个叫 `calculateArea` 的函数，接收两个 `double`，返回一个 `double`。

### 3. 源文件

源文件通常保存“定义”，也就是函数真正做什么：

```cpp
double calculateArea(double length, double width) {
    return length * width;
}
```

声明和定义可以分开放在不同文件中。这样做的好处是：

- 头文件可以被多个源文件使用；
- 实现细节集中在源文件中；
- 修改实现时，项目结构更清晰；
- 大型项目可以分模块编译。

### 4. `main` 函数

```cpp
int main() {
    // 程序从这里开始执行
}
```

每个可执行的 C++ 程序都需要一个程序入口，通常就是 `main` 函数。

`int` 表示 `main` 最后返回一个整数：

- 返回 `0`：通常表示程序正常结束；
- 返回非 `0`：通常表示程序出现了某种问题。

### 5. 命名空间

```cpp
std::cout
```

`cout` 属于 `std` 命名空间。写成 `std::cout` 可以明确表示：

> 使用标准库 `std` 中的 `cout`。

教学代码中推荐保留 `std::`，这样可以减少命名冲突。

## 二、三个文件是如何配合的

### `rectangle.hpp`

只告诉别人“可以使用什么”：

```cpp
double calculateArea(double length, double width);
```

### `rectangle.cpp`

负责实现计算方法：

```cpp
#include "rectangle.hpp"

double calculateArea(double length, double width) {
    return length * width;
}
```

### `main.cpp`

负责读取数据、调用函数和输出结果：

```cpp
#include "rectangle.hpp"

int main() {
    double area = calculateArea(5.0, 3.0);
    return 0;
}
```

调用函数时，`main.cpp` 不需要知道计算细节，只需要知道函数声明即可。

## 三、代码是如何编译的

假设当前 PowerShell 所在目录是项目根目录：

```text
D:\RoboMaster\培训\lec2_prepare
```

### 方式一：一步完成

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic `
    cpp_structure\main.cpp cpp_structure\rectangle.cpp `
    -o cpp_structure\rectangle_app
```

启动程序：

```powershell
.\cpp_structure\rectangle_app.exe
```

也可以先进入示例目录：

```powershell
cd cpp_structure
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp rectangle.cpp -o rectangle_app
.\rectangle_app.exe
```

### 方式二：分步骤完成

真实项目中，编译器通常会经历以下几个阶段。

#### 第一步：预处理

```powershell
g++ -std=c++17 -E cpp_structure\main.cpp -o cpp_structure\main.i
```

预处理器会处理：

- `#include`；
- `#define`；
- 条件编译；
- 注释删除。

生成的 `main.i` 是经过预处理后的代码，通常会比原文件长很多，因为头文件内容已经被展开。

#### 第二步：编译成汇编代码

```powershell
g++ -std=c++17 -S cpp_structure\main.cpp -o cpp_structure\main.s
```

这一步会把 C++ 代码翻译成汇编代码。汇编代码已经比较接近 CPU 能理解的指令，但还不是最终的机器码文件。

#### 第三步：汇编成目标文件

```powershell
g++ -std=c++17 -c cpp_structure\main.cpp -o cpp_structure\main.o
g++ -std=c++17 -c cpp_structure\rectangle.cpp -o cpp_structure\rectangle.o
```

现在会得到两个目标文件：

```text
main.o
rectangle.o
```

目标文件中已经有机器码，但还不能直接运行，因为不同源文件之间的函数调用关系还没有完全连接起来。

#### 第四步：链接

```powershell
g++ cpp_structure\main.o cpp_structure\rectangle.o `
    -o cpp_structure\rectangle_app
```

链接器会完成这些工作：

- 把 `main.o` 和 `rectangle.o` 合并；
- 找到 `main.cpp` 中调用的 `calculateArea`；
- 把这个调用连接到 `rectangle.cpp` 中真正的函数实现；
- 连接 C++ 标准库；
- 生成最终的可执行文件。

最终得到：

```text
rectangle_app.exe
```

## 四、为什么必须同时编译两个 `.cpp` 文件

如果只编译 `main.cpp`：

```powershell
g++ -std=c++17 cpp_structure\main.cpp -o cpp_structure\rectangle_app
```

编译器可以看到 `calculateArea` 的声明，但链接器找不到它的具体实现，
通常会出现类似错误：

```text
undefined reference to `calculateArea(...)`
```

所以必须把实现所在的 `rectangle.cpp` 也交给编译器：

```powershell
g++ cpp_structure\main.cpp cpp_structure\rectangle.cpp `
    -o cpp_structure\rectangle_app
```

## 五、编译错误和链接错误的区别

### 编译错误

编译器还没有生成目标文件时发现的问题，例如：

- 少写了分号；
- 括号没有配对；
- 函数声明和调用的参数不匹配；
- 变量没有声明。

### 链接错误

每个源文件都能单独编译，但合并成程序时发现实现找不到，例如：

- 忘记把 `rectangle.cpp` 加入编译命令；
- 函数声明和函数定义的名字不一致；
- 函数定义的参数类型不一致。

### 运行时错误

程序已经成功生成并启动，但运行过程中发生问题，例如：

- 除数为零；
- 访问了错误的内存；
- 打开文件失败后仍然继续读取。

## 六、编译选项的作用

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp rectangle.cpp -o rectangle_app
```

- `g++`：GNU C++ 编译器；
- `-std=c++17`：使用 C++17 标准；
- `-Wall`：打开常见警告；
- `-Wextra`：打开更多额外警告；
- `-pedantic`：尽量按照标准检查代码；
- `-o rectangle_app`：指定输出文件名。

警告不一定会阻止程序生成，但它们经常能提前提醒潜在问题，建议学习阶段保留。

## 七、建议的练习顺序

1. 先运行原程序，观察输出。
2. 修改 `main.cpp` 中的长和宽。
3. 修改 `rectangle.cpp` 中的计算公式，观察结果变化。
4. 故意不编译 `rectangle.cpp`，观察链接错误。
5. 故意删除一个分号，观察编译错误。
6. 给头文件中的函数增加一个参数，并同步修改声明、定义和调用。

