// src/solver/solver.h
// 求解器模块：
// TCAD微型仿真框架
#ifndef TINYTCAD_SOLVER_H
#define TINYTCAD_SOLVER_H

#include <vector>

class Solver{
private:
    // 存储计算结果（自动内存管理，安全！）
    std::vector<double> result;

public:
    Solver() = default;
    ~Solver() = default;

    // 核心求解函数：接收网格坐标 + 节点数量
    void solve(const double* x_coords, int node_num);
    // 打印求解结果
    void print_result()const;
    // 获取结果（对外接口）
    const std::vector<double>& get_result() const;
};



#endif