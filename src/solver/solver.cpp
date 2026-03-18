#include "solver.h"
#include <iostream>

void Solver::set_linear_model(){
  model_ = LINEAR;
//   std::cout << "linear model" << std::endl;
}
void Solver::set_quadratic_model(){
  model_ = QUADRATIC;
//   std::cout << "quadratic model" << std::endl;
}

// 核心求解函数：接收网格坐标 + 节点数量
void Solver::solve(const double *x_coords, int node_num) {
  // 1. 重置结果数组大小（和网格节点数一致）
  result_.resize(node_num);

  // 2. 遍历所有网格节点，执行计算
  // 示例：最简单的线性计算 result = 2 * x （可替换为任意TCAD物理模型）
  for (int i = 0; i < node_num; i++) {
    if (model_ == LINEAR){
        result_[i] = 2.0 *x_coords[i];  // 线性模型（原模型）
    } else{
        result_[i] = x_coords[i] *x_coords[i]; // 二次模型（新增）
    }
    
  }
}

// 打印求解结果
void Solver::print_result() const {
  std::cout << "\n[Solver]数值求解完成！计算结果：" << std::endl;
  for (int i = 0; i < result_.size(); i++) {
    std::cout << " 节点 " << i << " : " << result_[i] << std::endl;
  }
}

// 获取结果（对外接口）
const std::vector<double> &Solver::get_result() const { return result_; }