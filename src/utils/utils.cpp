#include "utils.h"
#include <iostream>

// 颜色定义（ANSI 标准，Linux/Mac 通用）
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define WHITE   "\033[37m"

void Utils::init() {
  // 调用自身的日志打印
  log_info("初始化模块成功");
}

//打印普通日志信息(WHITE)
void Utils::log_info(const char* msg) {
  // 专业格式输出 [模块名] 信息
  std::cout << WHITE << "[Utils INFO] " << msg << std::endl;
}

void Utils::log_success(const char* msg){
  std::cout << GREEN << "[Utils SUCCESS] " << msg << std::endl;
}

// 打印错误信息（预留）
void Utils::log_error(const char* msg) {
  std::cout << "[Utils ERROR]" << msg << std::endl;
}