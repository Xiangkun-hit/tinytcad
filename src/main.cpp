#include "io.h"
#include "mesh.h"
#include "solver.h"
#include "utils.h"
#include <iostream>

int main() {
  //========== 1.工具Utils初始化 ======
  Utils utils;
  utils.init();
  utils.log_info("tinytcad 主程序启动成功");

  // ========== 2.网格模块 ==========
  Mesh1D mesh;
  mesh.create_mesh();
  mesh.print_mesh();

  // ========== 3.求解器计算 ==========
  Solver solver;
  // 从网格获取数据，传递给求解器
  solver.solve(mesh.get_x_coords(), mesh.get_node_num());
  // 打印求解结果
  solver.print_result();

  // ============ 4.保存结果到文件 ========
  IO io;
  io.write_file(mesh, solver);

  // std::cout << "====================" << std::endl;
  // std::cout << "tinytcad 框架运行成功" << std::endl;
  // std::cout << "====================" << std::endl;
  utils.log_info("程序运行完成");
  std::cout << "====================" << std::endl;

  return 0;
}