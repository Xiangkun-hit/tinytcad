#ifndef TINYTCAD_MESH_H
#define TINYTCAD_MESH_H

#include <vector>

class Mesh1D{
// 私有成员变量：内部数据，外部不能直接访问（封装特性）
private:
    int node_num;       // 网格总节点数
    double x_start;     // 网格起始坐标
    double x_end;       // 网格结束坐标
    std::vector<double> x_coords;   // 动态数组：存储所有节点的坐标

// 公有函数：外部可以调用的接口
public:
    Mesh1D();
    ~Mesh1D() = default;
    
    // 创建均匀网格（核心函数）
    void create_mesh();
    // 打印网格信息
    void print_mesh();

    // getter 接口：外部获取网格数据（后面求解器要用）
    int get_node_num() const;
    // 获取数组指针（兼容后续计算）
    double* get_x_coords();
    const double* get_x_coords() const;
};


#endif