#include "io.h"
#include "../mesh/mesh.h"
#include "../solver/solver.h"

#include <fstream>
#include <iostream>

// 核心：写入结果文件
void IO::write_file(const Mesh1D &mesh, const Solver &solver) {
  // 1. 创建文件（覆盖模式）
  std::ofstream file("result.txt");
  if (!file.is_open()) {
    std::cerr << "[IO ERROR] 文件打开失败！" << std::endl;
    return;
  }

  // 2. 获取数据
  int node_num = mesh.get_node_num();
  const double *coords = mesh.get_x_coords();
  const auto &result = solver.get_result();

  // 3. 写入文件标题
  file << "==========================" << std::endl;
  file << "tinytcad 仿真结果文件" << std::endl;
  file << "节点数量" << node_num << std::endl;
  file << "==========================" << std::endl;
  file << "节点编号\t坐标值\t\t计算结果" << std::endl;

  // 4. 循环写入所有数据
  for (int i = 0; i < node_num; ++i) {
    file << i << "\t\t" << coords[i] << "\t\t" << result[i] << std::endl;
  }

  // 5. 关闭文件
  file.close();
  std::cout << "[IO] 结果已保存到 result.txt" << std::endl;
}