#include "solver.h"
#include <iostream>

// 核心求解函数：接收网格坐标 + 节点数量
void Solver::solve(const double *x_coords, int node_num) {
  // 1. 重置结果数组大小（和网格节点数一致）
  result.resize(node_num);

  // 2. 遍历所有网格节点，执行计算
  // 示例：最简单的线性计算 result = 2 * x （可替换为任意TCAD物理模型）
  for (int i = 0; i < node_num; i++) {
    result[i] = 2.0 * x_coords[i];
  }
}

// 打印求解结果
void Solver::print_result() const {
  std::cout << "\n[Solver]数值求解完成！计算结果：" << std::endl;
  for (int i = 0; i < result.size(); i++) {
    std::cout << " 节点 " << i << " : " << result[i] << std::endl;
  }
}

// 获取结果（对外接口）
const std::vector<double> &Solver::get_result() const { return result; }