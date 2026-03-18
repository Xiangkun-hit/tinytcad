#include "io.h"
#include "mesh.h"
#include "solver.h"
#include "utils.h"
#include <iostream>
#include <cstdlib>

// 命令行参数用法提示
void show_usage(){
  std::cout << "用法: ./tinytcad [节点数] [起始坐标] [结束坐标]" << std::endl;
  std::cout << "示例: ./tinytcad 20 0.0 2.0" << std::endl;
  std::cout << "默认: ./tinytcad (使用10节点 0~1范围)" << std::endl;
}

int main(int argc, char* argv[]) {  //支持命令行参数
  //========== 1.工具Utils初始化 ======
  Utils utils;
  utils.init();
  utils.log_info("tinytcad 主程序启动成功");

  //========= 命令行参数解析 =========
  int node_num = 10;
  double start_x = 0.0;
  double end_x = 1.0;
  if(argc == 4){
    node_num = std::atoi(argv[1]);
    start_x = std::atof(argv[2]);
    end_x = std::atof(argv[3]);
    utils.log_info("使用自定义网格参数");
  }else if (argc != 1){
    show_usage();
    return 1;
  }
  
  // ========== 2.网格模块 ==========
  // 自定义：20个节点，坐标范围 0 ~ 2
  Mesh1D mesh(node_num, start_x, end_x);
  mesh.print_mesh();

  // ========== 3.求解器计算 ==========
  Solver solver;
  solver.set_quadratic_model(); //切换模型
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
  utils.log_success("仿真流程全完成");
  std::cout << "====================" << std::endl;

  return 0;
}