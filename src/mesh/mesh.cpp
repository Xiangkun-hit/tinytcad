#include "mesh.h"
#include <iostream>

// 构造函数：初始化默认参数
Mesh1D::Mesh1D() {
  node_num = 10;
  x_start = 0.0;
  x_end = 1.0;
  // vector 自动初始化，无需手动置空
}

// ======================
// 核心：生成均匀网格（vector版本）
// ======================
void Mesh1D::create_mesh() {
  // ✅ 重置vector大小
  x_coords.resize(node_num);
  double step = (x_end - x_start) / (node_num - 1);

  for (int i = 0; i < node_num; ++i) {
    x_coords[i] = x_start + i * step;
  }
}

// 打印网格信息
void Mesh1D::print_mesh() {
  std::cout << "[Mesh1D]网格节点数量:" << node_num << std::endl;
  std::cout << "[Mesh1D]坐标范围:[" << x_start << "," << x_end << "]"
            << std::endl;
  std::cout << "[Mesh1D]网格节点坐标:" << std::endl;
  for (int i = 0; i < node_num; ++i) {
    std::cout << "节点" << i << " : " << x_coords[i] << std::endl;
  }
}

// ======================
// 接口函数
// ======================
// getter 接口：外部获取网格数据（后面求解器要用）
int Mesh1D::get_node_num() const { return node_num; }
// 获取数组指针（兼容后续计算）
double *Mesh1D::get_x_coords() {
  // vector 原生支持获取底层数组指针
  return x_coords.data();
}
const double *Mesh1D::get_x_coords() const { return x_coords.data(); }
