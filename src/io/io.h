#ifndef TINYTCAD_IO_H
#define TINYTCAD_IO_H

// 前置声明：告诉编译器这两个类存在（无需包含头文件，减少依赖）
class Mesh1D;
class Solver;

// 文件IO模块：负责结果导出
class IO{
public:
    IO() = default;
    ~IO() = default;

    // 核心函数：将网格+求解结果写入文件
    void write_file(const Mesh1D& mesh, const Solver& solver);
};



#endif